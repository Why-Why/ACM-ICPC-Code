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
// Created Time  : 2016年09月03日 星期六 01时05分29秒
// File Name     : 1012_1.cpp

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

const int MaxN=411;
const int MaxM=MaxN*MaxN;
const int INF=0x3f3f3f3f;

struct Edge {
	int to,next,cap,flow;
};

Edge E[MaxM];
int Ecou;
int head[MaxN];
int gap[MaxN],dis[MaxN],pre[MaxN],cur[MaxN];
int S,T;

void init(int N,int _S,int _T) {
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i) head[i]=-1;
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

inline void update(int remm) {
	int u=T;

	while(u!=S) {
		E[pre[u]].flow+=remm;
		E[pre[u]^1].flow-=remm;

		u=E[pre[u]^1].to;
	}
}

int SAP(int N) {
	for(int i=1;i<=N;++i)
		cur[i]=head[i],gap[i]=dis[i]=0;

	int u,v,ret=0,remm=INF,mindis;
	
	u=S;
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
					for(int i=pre[u];i!=-1;i=pre[E[i^1].to])
						remm=min(remm,E[i].cap-E[i].flow);
					ret+=remm;
					update(remm);
					u=S;				// ???
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
		
		if(--gap[dis[u]]==0)
			break;

		dis[u]=mindis+1;
		++gap[dis[u]];

		if(u!=S)
			u=E[pre[u]^1].to;
	}

	return ret;
}

int N,M,K;
int pay[MaxN],t[MaxN],sum,maxt,rem[MaxN];
int pro[MaxN];

inline int judge(int p) {
	for(int i=0;i<Ecou;++i) E[i].flow=0;			// !!!
	for(int i=1;i<=N;++i)
		if(t[i]<=p) E[rem[i]].cap=pay[i];
		else E[rem[i]].cap=INF;

	return SAP(N+M+2);
}

void getans() {
	int at,ap;
	int L=1,R=maxt,M;
	int temp;


	while(R>L) {
		M=(L+R)>>1;
		temp=sum-judge(M);
		if(temp>=K) R=M;
		else L=M+1;
	}

	at=L;
	ap=sum-judge(L);

	if(ap<K) puts("impossible");
	else printf("%d %d\n",at,ap);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int k,a;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&N,&M,&K);
		sum=0;
		maxt=0;
		init(N+M+2,N+M+1,N+M+2);
		for(int i=1;i<=N;++i) {
			scanf("%d %d",pay+i,t+i);
			maxt=max(maxt,t[i]);
			addEdge(M+i,N+M+2,INF);
			rem[i]=Ecou-2;
		}
		for(int i=1;i<=M;++i) {
			scanf("%d %d",pro+i,&k);
			addEdge(N+M+1,i,pro[i]);
			sum+=pro[i];
			while(k--) {
				scanf("%d",&a);
				addEdge(i,M+a,INF);
			}
		}

		printf("Case #%d: ",cas++);
		getans();
	}

	return 0;
}
