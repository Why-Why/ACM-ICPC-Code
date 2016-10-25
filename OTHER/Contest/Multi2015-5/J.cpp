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
// Created Time  : 2016年05月06日 星期五 23时28分25秒
// File Name     : J.cpp

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

const int MaxN=800;

// 求最小费用的最大流，复杂度 O(V＊V＊kE)。
// 输入：N，S，T，边集E。
// 输出：最大流，在最大流基础上的最小费用。
// 注意：求最小流或者最大费用可以取相反数，先init，然后addEdge。
// 原理：使用SPFA求每次的增广路。

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

int map1[205][205];
int N,M,K;
int rem[505];
int que[1000],first,last;

int bfsvis[MaxN],flag;

void bfs(int u,int cou) {
	first=last=0;
	que[last++]=u;
	++flag;
	bfsvis[u]=flag;

	while(last-first) {
		u=que[first++];
		addEdge(u,N+cou,1,0);
		for(int i=1;i<=N;++i)
			if(map1[u][i] && bfsvis[i]!=flag) {
				bfsvis[i]=flag;
				que[last++]=i;
			}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int TT,a,b,c,d;
	scanf("%d",&TT);

	while(TT--) {
		scanf("%d %d %d",&N,&M,&K);
		memset(map1,0,sizeof(map1));
		init(N+M+2,1,1);
		int cou=0;
		while(M--) {
			scanf("%d",&a);
			if(a==1) {
				++cou;
				scanf("%d",&b);
				bfs(b,cou);
			}
			else if(a==2) {
				scanf("%d %d",&a,&b);
				map1[a][b]=map1[b][a]=1;
			}
			else {
				scanf("%d",&b);
				while(b--) {
					scanf("%d %d",&c,&d);
					map1[d][c]=map1[c][d]=0;
				}
			}
		}
		S=N+cou+1;
		T=N+cou+2;
		for(int i=1;i<=N;++i) addEdge(S,i,1,0);
		for(int i=1;i<=cou;++i) addEdge(N+i,T,K,cou+1-i),rem[i]=Ecou-1;

		int t;
		int ans=MinCostMaxFlow(N+cou+2,t);
		printf("%d\n",ans);
		printf("%d",E[rem[1]^1].flow);
		for(int i=2;i<=cou;++i) printf(" %d",E[rem[i]^1].flow);
		puts("");
	}
	
	return 0;
}
