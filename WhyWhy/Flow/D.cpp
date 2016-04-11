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
// Created Time  : 2016年03月01日 星期二 20时44分35秒
// File Name     : D.cpp

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

const int MaxN=1111;
const int MaxM=20000;
const int INF=0x3f3f3f3f;

struct Edge {
	int to,next,cap,flow;
}E[MaxM];

int Ecou,head[MaxN];
int dis[MaxN],gap[MaxN],cur[MaxN],pre[MaxN];

void init(int N) {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1;
}

void _addEdge(int u,int v,int c) {
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void addEdge(int u,int v,int c) {
	_addEdge(u,v,c);
	_addEdge(v,u,0);
}

inline void update(int S,int T,int remm) {
	for(int u=T;u!=S;u=E[pre[u]^1].to) {
		E[pre[u]].flow+=remm;
		E[pre[u]^1].flow-=remm;
	}
}

int SAP(int N,int S,int T) {
	for(int i=1;i<=N;++i) dis[i]=gap[i]=0,cur[i]=head[i];

	int u=S,v,ret=0,remm=INF,mindis;
	pre[S]=-1;
	gap[0]=N;
	while(dis[S]<N) {
loop:
		for(int i=cur[u];i!=-1;i=E[i].next) {
			v=E[i].to;
			if(E[i].cap-E[i].flow && dis[u]==dis[v]+1) {
				pre[v]=i;
				cur[u]=i;
				u=v;
				if(u==T) {
					for(int i=pre[u];i!=-1;i=pre[E[i^1].to]) remm=min(remm,E[i].cap-E[i].flow);
					ret+=remm;
					update(S,T,remm);
					u=S;
					remm=INF;
				}
				goto loop;
			}
		}
		mindis=N-1;
		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].cap-E[i].flow && mindis>dis[E[i].to]) {
				cur[u]=i;
				mindis=dis[E[i].to];
			}
		if(--gap[dis[u]]==0) break;
		dis[u]=mindis+1;
		++gap[dis[u]];
		if(u!=S) u=E[pre[u]^1].to;
	}
	return ret;
}

int ru[MaxN],chu[MaxN];
int N;

inline bool judge(int M) {
	for(int i=0;i<Ecou;++i) E[i].flow=0;
	E[Ecou-2].cap=M;
	return SAP(N+N+5,N+N+4,N+N+5)==N;
}

int getans() {
	int L=0,R=N,M;

	while(R>L) {
		M=(L+R)>>1;
		if(judge(M)) R=M;
		else L=M+1;
	}
	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b;
	while(~scanf("%d %d",&N,&M) && N+M) {
		init(N*2+5);
		for(int i=1;i<=N;++i) {
			addEdge(i,i+N,INF);
			addEdge(N+N+4,i+N,1);
			addEdge(i,N+N+5,1);
			ru[i]=chu[i]=0;
		}
		while(M--) {
			scanf("%d %d",&a,&b);
			addEdge(a+N,b,INF);
			++chu[a];
			++ru[b];
		}
		for(int i=1;i<=N;++i) {
			if(ru[i]==0) addEdge(N+N+1,i,INF);
			if(chu[i]==0) addEdge(N+i,N+N+2,INF);
		}
		addEdge(N+N+3,N+N+1,INF);
		addEdge(N+N+2,N+N+3,0);
		printf("%d\n",getans());
	}
	
	return 0;
}
