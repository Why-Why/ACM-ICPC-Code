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
// Created Time  : 2017年03月03日 星期五 19时28分04秒
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

const int MaxN=200;
const int MaxM=200000;
const int INF=10e8;

struct Edge
{
	int to,next,cap,flow,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int pre[MaxN],couNode[MaxN],lowcost[MaxN];
bool vis[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	Ecou=0;
	S=_S;
	T=_T;

	for(int i=1;i<=N;++i)
		head[i]=-1;
}

void addEdge(int u,int v,int cap,int cost)
{
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

bool SPFA(int N)
{
	queue <int> que;
	int u,v,c;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
		pre[i]=-1;
	}
	vis[S]=1;
	lowcost[S]=0;
	couNode[S]=1;

	que.push(S);

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		vis[u]=0;
		
		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			c=E[i].cost;

			if(E[i].cap>E[i].flow && lowcost[v]>lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;
				pre[v]=i;

				if(!vis[v])
				{
					vis[v]=1;
					++couNode[v];
					que.push(v);

					if(couNode[v]>N)
						return 0;
				}
			}
		}
	}

	if(pre[T]==-1)
		return 0;
	return 1;
}

void update(int remm,int &minCost)
{
	for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
	{
		E[i].flow+=remm;
		E[i^1].flow-=remm;
		minCost+=E[i].cost*remm;
	}
}

int MinCostMaxFlow(int N,int &minCost)		//返回最大流，minCost是在最大流时的最小费用。
{
	int ret=0,remm;
	minCost=0;

	while(SPFA(N))
	{
		remm=INF;

		for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
			remm=min(remm,E[i].cap-E[i].flow);
		update(remm,minCost);
		ret+=remm;
	}

	return ret;
}

////////////////////////////////////////////

inline void addEdgeN(int u,int v,int H,int L) {
	if(H<=0) return;
	if(L<=0) addEdge(u,v,H,0);
	else {
		if(H-L) addEdge(u,v,H-L,0);
		addEdge(u,T,L,0);
		addEdge(S,v,L,0);
	}
}

typedef pair<int,int> pii;

int N;
int map1[55][55];
int Rl[55],Rh[55],Cl[55],Ch[55];
int R[55],C[55];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d;

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&map1[i][j]);

		for(int i=1;i<=N;++i) {
			R[i]=C[i]=0;
			for(int j=1;j<=N;++j) R[i]+=map1[i][j],C[i]+=map1[j][i];
		}

		init(N+N+4,N+N+3,N+N+4);
		int tS=N+N+1,tT=N+N+2;

		for(int i=1;i<=N;++i) {
			scanf("%d %d",Rl+i,Rh+i);

			addEdgeN(tS,i,R[i]-Rl[i],R[i]-Rh[i]);
			addEdgeN(i,tT,Rh[i]-R[i],Rl[i]-R[i]);
		}

		for(int i=1;i<=N;++i) {
			scanf("%d %d",Cl+i,Ch+i);

			addEdgeN(tS,N+i,C[i]-Cl[i],C[i]-Ch[i]);
			addEdgeN(N+i,tT,Ch[i]-C[i],Cl[i]-C[i]);
		}

		for(int i=N*N/2;i>=1;--i) {
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(map1[a][b]==map1[c][d]) continue;

			if(a==c) {
				if(map1[a][b]) addEdge(N+b,N+d,1,1);
				else addEdge(N+d,N+b,1,1);
			}
			else {
				if(map1[a][b]) addEdge(a,c,1,1);
				else addEdge(c,a,1,1);
			}
		}
		addEdge(tT,tS,INF,0);

		int ans;
		int sum=0;
		for(int i=head[S];i!=-1;i=E[i].next) sum+=E[i].cap;

		if(sum!=MinCostMaxFlow(N+N+4,ans)) {
			puts("-1");
			continue;
		}
		else printf("%d\n",ans);
	}

	return 0;
}
