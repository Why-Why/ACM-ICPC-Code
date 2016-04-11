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
// Created Time  : 2016年02月29日 星期一 23时17分35秒
// File Name     : C.cpp

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

const int MaxN=5000;
const int MaxM=100000;
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

inline void _addEdge(int u,int v,int c) {
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
	for(int u=T;u!=S;u=E[pre[u]^1].to)
		E[pre[u]].cap-=remm,E[pre[u]^1].cap+=remm;
}

int SAP(int N,int S,int T) {
	for(int i=1;i<=N;++i) cur[i]=head[i],dis[i]=gap[i]=0;

	int u=S,v,ret=0,remm=INF,mindis;
	pre[S]=-1;
	gap[0]=N;

	while(dis[S]<N) {
loop:
		for(int i=cur[u];i!=-1;i=E[i].next) {
			v=E[i].to;
			if(E[i].cap && dis[v]+1==dis[u]) {
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
			if(E[i].cap && mindis>dis[E[i].to])
				cur[u]=i,mindis=dis[E[i].to];
		if(--gap[dis[u]]==0) break;
		dis[u]=mindis+1;
		++gap[dis[u]];
		if(u!=S) u=E[pre[u]^1].to;
	}
	return ret;
}

long long in[MaxN];
int maxn[MaxN],minn[MaxN];

inline void make(int u,char c,int a) {
	if(c=='<') maxn[u]=min(maxn[u],a-1);
	if(c=='>') minn[u]=max(minn[u],a+1);
	if(c=='=') maxn[u]=min(maxn[u],a),minn[u]=max(minn[u],a);
}

int rans[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,M,a,b,c,D;
	char s[10];
	int NN;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		init(N*M+N+M+4);
		NN=N*M+N+M+2;
		memset(in,0,sizeof(in));

		for(int i=1;i<=N*M;++i) maxn[i]=INF,minn[i]=0;

		for(int i=1;i<=N;++i) {
			scanf("%d",&a);
			in[N*M+i]+=a,in[NN-1]-=a;
		}
		for(int i=1;i<=M;++i) {
			scanf("%d",&a);
			in[N*M+N+i]-=a;
			in[NN]+=a;
		}
		for(int i=1;i<=N*M;++i) {
			rans[i]=Ecou+1;
			addEdge(i,N*M+N+(i-1)%M+1,INF);
		}
		scanf("%d",&D);
		while(D--) {
			scanf("%d %d %s %d",&a,&b,s,&c);
			if(a && b) make((a-1)*M+b,s[0],c);
			else if(a) for(int i=1;i<=M;++i) make((a-1)*M+i,s[0],c);
			else if(b) for(int i=1;i<=N;++i) make((i-1)*M+b,s[0],c);
			else for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) make((i-1)*M+j,s[0],c);
		}

		bool ok=1;
		for(int i=1;i<=N*M;++i)
			if(maxn[i]<minn[i]) { ok=0; break; }
			else {
				addEdge(N*M+(i-1)/M+1,i,maxn[i]-minn[i]);
				in[i]+=minn[i];
				in[N*M+(i-1)/M+1]-=minn[i];
			}
		if(!ok) { puts("IMPOSSIBLE"); if(T) puts(""); continue; }			// !!!!!

		int sum=0;
		for(int i=1;i<=NN;++i) {
			if(in[i]>0) addEdge(NN+1,i,in[i]),sum+=in[i];
			else if(in[i]<0) addEdge(i,NN+2,-in[i]);
		}
		addEdge(NN,NN-1,INF);

		if(SAP(NN+2,NN+1,NN+2)==sum) {
			for(int i=1;i<=N;++i)
				for(int j=1;j<=M;++j) {
					printf("%d",E[rans[(i-1)*M+j]].cap);
					putchar(j==M ? '\n' : ' ');
				}
		}
		else puts("IMPOSSIBLE");
		if(T) puts("");
	}
	
	return 0;
}
