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
// Created Time  : 2016年02月25日 星期四 16时09分00秒
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

const int MaxN=205;
const int MaxM=140000;
const int INF=0x3f3f3f3f;

struct Edge {
	int to,next;
	int cap,flow;
	int id;
}E[MaxM];

int Ecou,head[MaxN];
int gap[MaxN],dis[MaxN],pre[MaxN],cur[MaxN];
int S,T;

void init(int N) {
	Ecou=0;				// !!!
	for(int i=1;i<=N;++i) {
		head[i]=-1;
		gap[i]=dis[i]=0;
	}
}

void addEdge(int u,int v,int c,int id,int rc=0) {
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	E[Ecou].id=id;
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=rc;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	E[Ecou].id=0;
	head[v]=Ecou++;
}

void update(int remm) {
	int u=T;
	while(u!=S) {
		E[pre[u]].flow+=remm;
		E[pre[u]^1].flow-=remm;
		u=E[pre[u]^1].to;
	}
}

int SAP(int N,int _S,int _T) {
	S=_S;
	T=_T;
	for(int i=1;i<=N;++i) cur[i]=head[i];
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

int sum;
int base[MaxM];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,N,M,a,b,c,d;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		init(N+2);
		sum=0;
		for(int i=1;i<=M;++i) {
			scanf("%d %d %d %d",&a,&b,&c,&d);
			addEdge(a,b,d-c,i);
			addEdge(a,N+2,c,0);
			addEdge(N+1,b,c,0);
			sum+=c;
			base[i]=c;
		}

		if(SAP(N+2,N+1,N+2)==sum) {
			puts("YES");
			for(int i=0;i<Ecou;++i) base[E[i].id]+=E[i].flow;
			for(int i=1;i<=M;++i) printf("%d\n",base[i]);
		}
		else puts("NO");

		if(T) puts("");
	}
	
	return 0;
}
