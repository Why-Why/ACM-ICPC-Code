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

const int MaxN=110;
const int MaxM=110*110;
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
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
		head[i]=-1;
}

void addEdge(int u,int v,int cap,int cost)
{
	E[Ecou].to=v;
	E[Ecou].cap=cap;
	E[Ecou].flow=0;
	E[Ecou].cost=cost;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=0;
	E[Ecou].flow=0;
	E[Ecou].cost=-cost;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

bool SPFA(int N)
{
	queue<int> que;
	int u,v,c;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
		pre[i]=-1;
	}

	vis[S]=1;
	couNode[S]=1;
	lowcost[S]=0;

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

int MinCostMaxFlow(int N,int &minCost)
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

int N,M,K;
int need[60][60],give[60][60];
int sum[60];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int temp;
	int ans,tans;

	while(~scanf("%d %d %d",&N,&M,&K) && N+M+K)
	{
		ans=0;
		memset(sum,0,sizeof(sum));

		for(int i=1;i<=N;++i)
			for(int j=1;j<=K;++j)
			{
				scanf("%d",&need[i][j]);
				sum[j]+=need[i][j];
			}

		for(int i=1;i<=M;++i)
			for(int j=1;j<=K;++j)
				scanf("%d",&give[i][j]);

		for(int k=1;k<=K;++k)
		{
			init(N+M+2,N+M+1,N+M+2);

			for(int i=1;i<=M;++i)
				addEdge(N+M+1,i,give[i][k],0);

			for(int i=1;i<=N;++i)
				addEdge(M+i,N+M+2,need[i][k],0);

			for(int i=1;i<=N;++i)
				for(int j=1;j<=M;++j)
				{
					scanf("%d",&temp);

					addEdge(j,M+i,INF,temp);
				}

			temp=MinCostMaxFlow(N+M+2,tans);

			if(temp<sum[k])
				ans=-1;

			if(ans!=-1)
				ans+=tans;
		}

		printf("%d\n",ans);
	}
	
	return 0;
}
