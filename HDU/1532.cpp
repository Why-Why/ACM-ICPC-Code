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

const int MaxN=210;
const int INF=10e8;

int cost[MaxN][MaxN];
int pre[MaxN];
int S,T;
int dis[MaxN],gap[MaxN],cur[MaxN];

void update(int remm)
{
	int u=T;

	while(u!=S)
	{
		cost[pre[u]][u]-=remm;
		cost[u][pre[u]]+=remm;

		u=pre[u];
	}
}

int SAP(int N)
{
	int ret=0,u,remm=INF,mindis;

	u=pre[S]=S;
	gap[0]=N;

	while(dis[S]<N)
	{
		loop:
		for(int v=cur[u];v<=N;++v)
			if(cost[u][v] && dis[u]==dis[v]+1)
			{
				remm=min(remm,cost[u][v]);
				pre[v]=u;
				u=cur[u]=v;
				
				if(u==T)
				{
					ret+=remm;
					update(remm);
					u=S;
					remm=INF;
				}

				goto loop;
			}

		mindis=N-1;				/////
		for(int v=1;v<=N;++v)
			if(cost[u][v] && mindis>dis[v])
			{
				cur[u]=v;
				mindis=dis[v];
			}
		if(--gap[dis[u]]==0)
			break;
		dis[u]=mindis+1;
		++gap[dis[u]];
		u=pre[u];
	}

	return ret;
}

void init(int N,int _S,int _T)
{
	for(int i=1;i<=N;++i)
	{
		gap[i]=dis[i]=0;
		cur[i]=1;

		for(int j=1;j<=N;++j)
			cost[i][j]=0;
	}

	S=_S;
	T=_T;
}

void addEdge(int u,int v,int c)
{
	cost[u][v]+=c;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M,a,b,c;

	while(~scanf("%d %d",&M,&N))
	{
		init(N,1,N);

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c);
		}

		printf("%d\n",SAP(N));
	}
	
	return 0;
}
