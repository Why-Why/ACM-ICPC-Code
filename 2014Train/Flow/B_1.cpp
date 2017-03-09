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
// Created Time  : 2016年02月29日 星期一 22时28分58秒
// File Name     : B_1.cpp

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
const int MaxM=150000;
const int INF=0x3f3f3f3f;

struct Edge {
	int to,next,cap;
}E[MaxM];

int head[MaxN],Ecou;
int gap[MaxN],dis[MaxN],pre[MaxN],cur[MaxN];

void init(int N) {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1;
}

void addEdge(int u,int v,int c,int rc=0) {
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=rc;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

inline void update(int S,int T,int remm) {
	for(int u=T;u!=S;u=E[pre[u]^1].to) {
		E[pre[u]].cap-=remm;
		E[pre[u]^1].cap+=remm;
	}
}

int SAP(int N,int S,int T) {
	for(int i=1;i<=N;++i) cur[i]=head[i],gap[i]=dis[i]=0;

	int u,v,ret=0,remm=INF,mindis;
	u=S;
	pre[S]=-1;
	gap[0]=N;
	while(dis[S]<N) {
loop:
		for(int i=cur[u];i!=-1;i=E[i].next) {
			v=E[i].to;
			if(E[i].cap && dis[u]==dis[v]+1) {
				pre[v]=i;
				cur[u]=i;
				u=v;
				if(u==T) {
					for(int i=pre[u];i!=-1;i=pre[E[i^1].to]) remm=min(remm,E[i].cap);
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
			if(E[i].cap && mindis>dis[E[i].to]) {
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

int in[MaxN];
int base[MaxM],rem[MaxM];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M,a,b,c,d;
	while(~scanf("%d %d",&N,&M)) {
		int sum=0,remE,bcou=0;

		init(N+M+4);
		memset(in,0,sizeof(in));
		for(int i=1;i<=M;++i) {
			scanf("%d",&a);
			addEdge(N+i,N+M+2,INF);
			in[N+M+2]+=a;
			in[N+i]-=a;
		}
		for(int i=1;i<=N;++i) {
			scanf("%d %d",&a,&b);
			addEdge(N+M+1,i,b);
			while(a--) {
				scanf("%d %d %d",&b,&c,&d);
				rem[bcou]=Ecou;
				base[bcou++]=c;
				addEdge(i,N+b+1,d-c);
				in[i]-=c;
				in[N+b+1]+=c;
			}
		}
		remE=Ecou;

		for(int i=1;i<=N+M+2;++i)
			if(in[i]>0) addEdge(N+M+3,i,in[i]),sum+=in[i];
			else if(in[i]<0) addEdge(i,N+M+4,-in[i]);
		addEdge(N+M+2,N+M+1,INF);

		if(SAP(N+M+4,N+M+3,N+M+4)==sum) {
			for(int i=1;i<=N+M+2;++i)
				while(head[i]>=remE) head[i]=E[head[i]].next;
			SAP(N+M+2,N+M+1,N+M+2);

			int ans=0;
			for(int i=head[N+M+1];i!=-1;i=E[i].next) ans+=E[i^1].cap;
			printf("%d\n",ans);
			for(int i=0;i<bcou;++i) printf("%d\n",E[rem[i]^1].cap+base[i]);
		}
		else puts("-1");
		puts("");
	}
	
	return 0;
}
