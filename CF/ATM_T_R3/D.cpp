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
// Created Time  : 2016年09月09日 星期五 00时17分14秒
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

const int MaxN=300;
const int MaxM=200000;
const int INF=10e8;

struct Edge {
	int to,next,cap,flow,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int pre[MaxN],couNode[MaxN],lowcost[MaxN];
bool vis[MaxN];
int S,T;

void init(int N,int _S,int _T) {
	Ecou=0;
	S=_S;
	T=_T;

	for(int i=1;i<=N;++i) head[i]=-1;
}

void addEdge(int u,int v,int cap,int cost) {
	cout<<u<<' '<<v<<' '<<cap<<' '<<cost<<endl;

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

bool SPFA(int N) {
	queue <int> que;
	int u,v,c;

	for(int i=1;i<=N;++i) {
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
		pre[i]=-1;
	}
	vis[S]=1;
	lowcost[S]=0;
	couNode[S]=1;

	que.push(S);

	while(!que.empty()) {
		u=que.front();
		que.pop();

		vis[u]=0;
		
		for(int i=head[u];i!=-1;i=E[i].next) {
			v=E[i].to;
			c=E[i].cost;

			if(E[i].cap>E[i].flow && lowcost[v]>lowcost[u]+c) {
				lowcost[v]=lowcost[u]+c;
				pre[v]=i;

				if(!vis[v]) {
					vis[v]=1;
					++couNode[v];
					que.push(v);

					if(couNode[v]>N) return 0;
				}
			}
		}
	}

	if(pre[T]==-1) return 0;
	return 1;
}

void update(int remm,int &minCost) {
	for(int i=pre[T];i!=-1;i=pre[E[i^1].to]) {
		E[i].flow+=remm;
		E[i^1].flow-=remm;
		minCost+=E[i].cost*remm;
	}
}

int MinCostMaxFlow(int N,int &minCost) {
	int ret=0,remm;

	while(SPFA(N)) {
		remm=INF;

		for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
			remm=min(remm,E[i].cap-E[i].flow);
		update(remm,minCost);
		ret+=remm;
	}

	return ret;
}

int N,M;
int du[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d;
	int ans=0;

	scanf("%d %d",&N,&M);
	init(N+2,N+1,N+2);

	while(M--) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		du[a]-=d;
		du[b]+=d;

		if(c>=d) {
			addEdge(a,b,c-d,1);
			addEdge(a,b,INF,2);
			addEdge(b,a,d,1);
		}
		else {
			ans+=d-c;
			addEdge(a,b,INF,2);
			addEdge(b,a,d-c,0);
			addEdge(b,a,c,1);
		}
	}
	//addEdge(N,1,INF,0);

	addEdge(N+1,1,-du[1],10000000);
	addEdge(N,N+2,du[N],10000000);
	addEdge(1,N,INF,0);
	for(int i=2;i<N;++i)
		if(du[i]<0) addEdge(N+1,i,-du[i],0);
		else if(du[i]>0) addEdge(i,N+2,du[i],0);

	MinCostMaxFlow(N+2,ans);
	printf("%d\n",ans%10000000);

	return 0;
}
