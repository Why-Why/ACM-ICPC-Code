// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2016年01月23日 星期六 10时34分07秒
// File Name     : A.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MaxN=50005;
const int MaxM=20005;

struct Edge {
	int to,next;
	bool type;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int LOW[MaxN],DFN[MaxN];
int couBridge;
bool bridge[MaxM];
int Index;
int belong[MaxN],bcou,du[MaxN];

int N,M;

void init() {
	Ecou=0;
	couBridge=Index=0;
	for(int i=1;i<=N;++i) 
		head[i]=-1,DFN[i]=belong[i]=du[i]=0;
}

void addEdge(int u,int v,bool type) {
	bridge[Ecou]=0;
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].type=type;
	head[u]=Ecou++;

	bridge[Ecou]=0;
	E[Ecou].to=u;
	E[Ecou].next=head[v];
	E[Ecou].type=type;
	head[v]=Ecou++;
}

void Tarjan(int u,int pre) {
	LOW[u]=DFN[u]=++Index;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			if(!DFN[E[i].to]) {
				Tarjan(E[i].to,u);
				LOW[u]=min(LOW[u],LOW[E[i].to]);
				if(DFN[u]<LOW[E[i].to] && E[i].type==0) {
					++couBridge;
					bridge[i]=bridge[i^1]=1;
				}
			}
			else LOW[u]=min(LOW[u],DFN[E[i].to]);
		}
}

void getBridge() {
	for(int i=1;i<=N;++i) if(!DFN[i]) Tarjan(i,i);
}

void bfs(int u,int cou) {
	queue <int> que;
	que.push(u);
	belong[u]=cou;

	while(!que.empty()) {
		u=que.front();
		que.pop();
		for(int i=head[u];i!=-1;i=E[i].next)
			if(!belong[E[i].to] && bridge[i]==0) {
				belong[E[i].to]=cou;
				que.push(E[i].to);
			}
	}
}

int getans() {
	bcou=0;
	for(int i=1;i<=N;++i) if(!belong[i]) bfs(i,++bcou);
	for(int i=0;i<Ecou;i+=2)
		if(bridge[i])
			++du[belong[E[i].to]],++du[belong[E[i^1].to]];
	int ret=0;
	for(int i=1;i<=bcou;++i) if(du[i]==1) ++ret;
	return (ret+1)/2;
}

typedef pair <int,int> pii;
pii remEdge[MaxM];

void unique() {
	init();
	int k=2,cou=0;
	for(int i=2;i<=M;++i)
		if(remEdge[i]==remEdge[i-1]) ++cou;
		else addEdge(remEdge[i-1].first,remEdge[i-1].second,cou),cou=0;
	addEdge(remEdge[M].first,remEdge[M].second,cou);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;++i) scanf("%d %d",&remEdge[i].first,&remEdge[i].second);
	unique();
	getBridge();
	printf("%d\n",getans());
	
	return 0;
}
