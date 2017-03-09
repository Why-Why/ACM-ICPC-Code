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
// Created Time  : 2017年01月17日 星期二 15时49分27秒
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

const int MaxN=1005;
const long long INF=100000000000000LL;

struct Edge {
	int to,next;
	long long w;
};

Edge E[20004];
int head[MaxN],Ecou;
bool vis[MaxN];
int couNode[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c) {
	E[Ecou].to=v;
	E[Ecou].w=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int que[20000000],first,last;

void SPFA(long long lowcost[],int n,int start) {
	first=last=0;

	int u,v;
	long long c;

	for(int i=1;i<=n;++i) {
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
	}
	lowcost[start]=0;
	vis[start]=1;
	couNode[start]=1;

	que[last++]=start;

	while(last-first) {
		u=que[first++];

		vis[u]=0;

		for(int i=head[u];i!=-1;i=E[i].next) {
			v=E[i].to;
			c=E[i].w;
			if(c==0) c=INF;

			if(lowcost[v]>lowcost[u]+c) {
				lowcost[v]=lowcost[u]+c;

				if(!vis[v]) {
					vis[v]=1;
					++couNode[v];
					que[last++]=v;

					if(couNode[v]>n) return;
				}
			}
		}
	}
}

long long lowcost[MaxN];
bool use[20004];

inline void showAns(long long p) {
	puts("YES");
	for(int i=0;i<Ecou;i+=2)
		printf("%d %d %I64d\n",E[i^1].to-1,E[i].to-1,E[i].w ? E[i].w : p);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M,L,s,t;
	int a,b,c;

	scanf("%d %d %d %d %d",&N,&M,&L,&s,&t);
	++s,++t;
	init();

	for(int i=1;i<=M;++i) {
		scanf("%d %d %d",&a,&b,&c);
		++a,++b;
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	SPFA(lowcost,N,s);

	if(lowcost[t]<L) {
		puts("NO");
		return 0;
	}
	if(lowcost[t]==L) {
		showAns(INF);
		return 0;
	}

	for(int u=1;u<=N;++u)
		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].w==0 && use[i]==0) {
				use[i]=use[i^1]=1;
				E[i].w=E[i^1].w=1;

				SPFA(lowcost,N,s);
				if(lowcost[t]<=L) {
					E[i].w=E[i^1].w=L-lowcost[t]+1;
					showAns(INF);
					return 0;
				}
			}

	puts("NO");
	return 0;
}
