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
// Created Time  : 2016年03月01日 星期二 22时37分09秒
// File Name     : E.cpp

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

const int MaxN=100;
const int MaxM=10000;
const int INF=0x3f3f3f3f;

struct Edge {
	int to,next,cap,flow;
}E[MaxM];

int head[MaxN],Ecou;
int dis[MaxN],gap[MaxN],cur[MaxN],pre[MaxN];

void init(int N) {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1;
}

void _addEdge(int u,int v,int c) {
	E[Ecou].flow=0;
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
	for(int u=T;u!=S;u=E[pre[u]^1].to) E[pre[u]].flow+=remm,E[pre[u]^1].flow-=remm;
}

int SAP(int N,int S,int T) {
	for(int i=1;i<=N;++i) cur[i]=head[i],dis[i]=gap[i]=0;

	int u=S,v,ret=0,remm=INF,mindis;
	gap[0]=N;
	pre[S]=-1;

	while(dis[S]<N) {
loop:
		for(int i=cur[u];i!=-1;i=E[i].next) {
			v=E[i].to;
			if(E[i].cap-E[i].flow && dis[v]+1==dis[u]) {
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

int in[MaxN];
int N;

inline bool judge(int M,int sum) {
	for(int i=0;i<Ecou;++i) E[i].flow=0;
	E[Ecou-2].cap=M;
	return SAP(N+4,N+3,N+4)==sum;
}

int getans(int sum) {
	int L=0,R=E[Ecou-2].flow,M;

	while(R>L) {
		M=(L+R)>>1;
		if(judge(M,sum)) R=M;
		else L=M+1;
	}
	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b,c;
	char s[10],s1[10];

	while(~scanf("%d %d",&N,&M) && N+M) {
		int sum=0;
		memset(in,0,sizeof(in));
		init(N+4);
		while(M--) {
			scanf("%s %s %d",s,s1,&c);
			if(s[0]=='+') a=N+1;
			else if(s[0]=='-') a=N+2;
			else sscanf(s,"%d",&a);
			if(s1[0]=='+') b=N+1;
			else if(s1[0]=='-') b=N+2;
			else sscanf(s1,"%d",&b);

			addEdge(a,b,INF);
			in[b]+=c;
			in[a]-=c;
		}
		for(int i=1;i<=N+2;++i)
			if(in[i]>0) addEdge(N+3,i,in[i]),sum+=in[i];
			else if(in[i]<0) addEdge(i,N+4,-in[i]);
		addEdge(N+2,N+1,INF);

		if(SAP(N+4,N+3,N+4)!=sum) puts("impossible");
		else printf("%d\n",getans(sum));
	}
	
	return 0;
}
