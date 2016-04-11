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
// Created Time  : 2016年02月29日 星期一 18时44分48秒
// File Name     : B.cpp

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

const int MaxN=1400;
const int MaxM=1700000;
const int INF=0x3f3f3f3f;

struct Edge {
	int to,next,cap,flow;
};

Edge E[MaxM];
int Ecou,head[MaxN];
int gap[MaxN],dis[MaxN],pre[MaxN],cur[MaxN];
int S,T;

void init(int N,int _S,int _T) {
	Ecou=0;
	S=_S;
	T=_T;
	for(int i=1;i<=N;++i)
		head[i]=-1;
}

void addEdge(int u,int v,int c,int rc=0) {
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=rc;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

void update(int rem) {
	int u=T;
	while(u!=S) {
		E[pre[u]].flow+=rem;
		E[pre[u]^1].flow-=rem;
		u=E[pre[u]^1].to;
	}
}

int SAP(int N) {
	for(int i=1;i<=N;++i) cur[i]=head[i],gap[i]=dis[i]=0;

	int u,v,ret=0,rem=INF,mindis;
	u=S;
	pre[S]=-1;
	gap[0]=N;

	while(dis[S]<N) {
loop:
		for(int i=cur[u];i!=-1;i=E[i].next) {
			v=E[i].to;
			if(v>N || i>=Ecou) continue;
			if(E[i].cap-E[i].flow && dis[u]==dis[v]+1) {
				pre[v]=i;
				cur[u]=i;
				u=v;
				if(u==T) {
					for(int i=pre[u];i!=-1;i=pre[E[i^1].to])
						rem=min(rem,E[i].cap-E[i].flow);
					ret+=rem;
					update(rem);
					u=S;
					rem=INF;
				}
				goto loop;
			}
		}
		mindis=N-1;
		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].to<=N && i<Ecou)
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

int rem[377][1005];
int ttrem[377][1005];
int trem[377];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M;
	int C,D,G;
	int TT,L,R;
	int sum,tans;

	while(~scanf("%d %d",&N,&M)) {
		sum=0;
		tans=0;
		init(N+M+4,N+M+3,N+M+4);
		for(int i=1;i<=M;++i) {
			scanf("%d",&G);
			addEdge(N+i,N+M+4,G);
			addEdge(N+M+3,N+M+2,G);
			addEdge(N+i,N+M+2,INF);
			sum+=G;
			tans+=G;
		}
		for(int i=1;i<=N;++i) {
			scanf("%d %d",&C,&D);
			addEdge(N+M+1,i,D);
			trem[i]=C;

			for(int j=1;j<=C;++j) {
				scanf("%d %d %d",&TT,&L,&R);
				++TT;
				rem[i][j]=Ecou;
				ttrem[i][j]=L;
				addEdge(i,N+TT,R-L);
				addEdge(i,N+M+4,L);
				addEdge(N+M+3,N+TT,L);
				sum+=L;
			}
		}
		addEdge(N+M+2,N+M+1,INF);		// !!!

		if(SAP(N+M+4)>=sum) {
			S=N+M+1;
			T=N+M+2;			// !!!
			Ecou-=2;
			printf("%d\n",tans+SAP(N+M+2));
			for(int i=1;i<=N;++i)
				for(int j=1;j<=trem[i];++j)
					printf("%d\n",ttrem[i][j]+E[rem[i][j]].flow);
		}
		else puts("-1");
		puts("");
	}
	
	return 0;
}
