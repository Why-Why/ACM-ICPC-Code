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
// Created Time  : 2017年02月26日 星期日 15时51分50秒
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

const int MaxN=105;
const int MaxM=30005;
const double INF=1e20;

struct Edge {
	int to,next,cap,flow;
	double cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int pre[MaxN],couNode[MaxN];
double lowcost[MaxN];
bool vis[MaxN];
int S,T;

void init(int N,int _S,int _T) {
	Ecou=0;
	S=_S;
	T=_T;
	for(int i=1;i<=N;++i) head[i]=-1;
}

void addEdge(int u,int v,int cap,double cost) {
	E[Ecou].to=v;
	E[Ecou].cap=cap;
	E[Ecou].cost=cost;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=0;
	E[Ecou].cost=-cost;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

int que[1000000];
int first,last;

const double eps=1e-8;

bool SPFA(int N) {
	first=last=0;

	int u,v;
	double c;

	for(int i=1;i<=N;++i) {
		lowcost[i]=INF; vis[i]=0; couNode[i]=0; pre[i]=-1;
	}

	vis[S]=1; lowcost[S]=0; couNode[S]=1;
	que[last++]=S;

	while(last-first) {
		u=que[first++];

		vis[u]=0;
		for(int i=head[u];i!=-1;i=E[i].next) {
			v=E[i].to;
			c=E[i].cost;

			if(E[i].cap>E[i].flow && lowcost[v]>lowcost[u]+c+eps) {			// !!!!!!
				lowcost[v]=lowcost[u]+c;
				pre[v]=i;

				if(!vis[v]) {
					vis[v]=1;
					++couNode[v];
					que[last++]=v;
					if(couNode[v]>=N) return 0;
				}
			}
		}
	}

	if(pre[T]==-1) return 0;
	return 1;
}

void update(int remm,double &minCost) {
	for(int i=pre[T];i!=-1;i=pre[E[i^1].to]) {
		E[i].flow+=remm;
		E[i^1].flow-=remm;
		minCost+=E[i].cost*remm;
	}
}

const double flag=-log(0.005);

int getans(int N,double &minCost) {
	int ret=0,remm;
	int cou=0;
	minCost=0;

	while(SPFA(N)) {
		remm=0x3f3f3f3f;
		for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
			remm=min(remm,E[i].cap-E[i].flow);
		update(remm,minCost);

		if(minCost>=flag) {
			minCost=INF;
			return 0;
		}

		ret+=remm;
	}
	return ret;
}

inline int read() {
	char c=0;
	while(c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,M,a,b,c;
	double p;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		init(N+2,N+1,N+2);

		for(int i=1;i<=N;++i) {
			scanf("%d %d",&a,&b);

			if(a>b) addEdge(N+1,i,a-b,0);
			else if(a<b) addEdge(i,N+2,b-a,0);
		}
		while(M--) {
			scanf("%d %d %d %lf",&a,&b,&c,&p);
			if(a==b) continue;
			if(c<=0) continue;
			addEdge(a,b,1,0);
			if(c>1) addEdge(a,b,c-1,-log(1.0-p));
		}

		getans(N+2,p);
		p=1.0-exp(-p);
		printf("%.2f\n",p+1e-8);
	}

	return 0;
}
