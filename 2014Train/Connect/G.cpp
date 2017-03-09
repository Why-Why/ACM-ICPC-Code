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
// Created Time  : 2016年01月24日 星期日 11时29分00秒
// File Name     : G.cpp

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

const int MaxN=200005;

struct Edge {
	int to,next;
	int u;
}E[MaxN<<1];

int head[MaxN],Ecou;
int N;

int LOW[MaxN],DFN[MaxN];
int Index;
bool bridge[MaxN<<1];
int coubridge;		// !!!
int belong[MaxN],bcou;

void init() {
	Ecou=Index=coubridge=bcou=0;
	for(int i=1;i<=N;++i) head[i]=-1,DFN[i]=belong[i]=0;
}

void addEdge(int u,int v) {
	bridge[Ecou]=0;
	E[Ecou].u=u;
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void Tarjan(int u,int reme) {
	DFN[u]=LOW[u]=++Index;
	for(int i=head[u];i!=-1;i=E[i].next)
		if((i^1)!=reme) 
			if(!DFN[E[i].to]) {
				Tarjan(E[i].to,i);
				LOW[u]=min(LOW[u],LOW[E[i].to]);
				if(DFN[u]<LOW[E[i].to]) {
					bridge[i]=bridge[i^1]=1;
					++coubridge;
				}
			}
			else LOW[u]=min(LOW[u],DFN[E[i].to]);
}

void bfs(int u,int brem) {
	queue <int> que;
	que.push(u);
	belong[u]=brem;

	while(!que.empty()) {
		u=que.front();
		que.pop();
		for(int i=head[u];i!=-1;i=E[i].next)
			if(!bridge[i] && !belong[E[i].to]) {
				que.push(E[i].to);
				belong[E[i].to]=brem;
			}
	}
}

void getans() {
	for(int i=1;i<=N;++i) if(!DFN[i]) Tarjan(i,-1);
	for(int i=1;i<=N;++i) if(!belong[i]) bfs(i,++bcou);
}

namespace TTT {

int fa[MaxN];
Edge E[MaxN];
int dep[MaxN],ff[MaxN];
int Ecou,head[MaxN];

void init() {
	Ecou=0;
	for(int i=1;i<=bcou;++i) head[i]=-1,fa[i]=i;
}

void addEdge(int u,int v) {
	if(u==v) return;
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre) {
	dep[u]=dep[pre]+1;
	ff[u]=pre;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs(E[i].to,u);
}

int rem[MaxN],rcou;

int getans(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	int ret=0;
	rcou=0;
	while(1) {
		if(a==b) break;
		if(dep[a]==dep[b]) {
			if(fa[b]!=b) b=fa[b];
			else {
				rem[rcou++]=b;
				b=ff[b],++ret;
			}
		}
		while(dep[a]>dep[b]) {
			if(fa[a]!=a) a=fa[a];
			else {
				rem[rcou++]=a;
				a=ff[a],++ret;
			}
		}
		swap(a,b);
	}
	for(int i=0;i<rcou;++i) fa[rem[i]]=fa[a];
	return ret;
}

void getans() {
	dep[0]=0;
	dfs(1,1);
	int Q,a,b;
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d %d",&a,&b);
		if(belong[a]!=belong[b]) coubridge-=getans(belong[a],belong[b]);
		printf("%d\n",coubridge);
	}
}

};

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;
	int M,a,b;
	while(~scanf("%d %d",&N,&M) && N+M) {
		init();
		while(M--) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}
		getans();
		printf("Case %d:\n",cas++);
		TTT::init();
		for(int i=0;i<Ecou;++i) if(bridge[i]) TTT::addEdge(belong[E[i].u],belong[E[i].to]);
		TTT::getans();
		puts("");
	}
	
	return 0;
}
