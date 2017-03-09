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
const int MaxM=MaxN*MaxN;
const int INF=10e8;

struct Edge
{
	int to,next,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;
bool vis[MaxN];
int couNode[MaxN];
bool cir[MaxN];

void init(int N)
{
	Ecou=0;

	for(int i=1;i<=N;++i)
		head[i]=-1,vis[i]=0,cir[i]=0;
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u)
{
	cir[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!cir[E[i].to])
			dfs(E[i].to);
}

bool SPFA(int lowcost[],int N,int start)
{
	queue <int> que;
	int u,v,c;

	for(int i=1;i<=N;++i)
		lowcost[i]=INF,couNode[i]=0;
	lowcost[start]=0;

	que.push(start);
	vis[start]=1;
	couNode[start]=1;

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		vis[u]=0;			// !!!

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			c=E[i].cost;

			if(cir[v])
				continue;

			if(lowcost[v]>lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;

				if(!vis[v])
				{
					vis[v]=1;
					que.push(v);

					++couNode[v];

					if(couNode[v]>N)
						dfs(v);
				}
			}
		}
	}

	return 1;
}

int ans[MaxN];
int val[MaxN];

inline int cube(int x)
{
	return x*x*x;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,Q,M;
	int a,b;
	int cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		init(N);

		for(int i=1;i<=N;++i)
			scanf("%d",&val[i]);

		scanf("%d",&M);
		while(M--)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b,cube(val[b]-val[a]));
		}

		SPFA(ans,N,1);

		scanf("%d",&Q);

		printf("Case %d:\n",cas++);

		while(Q--)
		{
			scanf("%d",&a);

			if(cir[a] || ans[a]<3 || ans[a]==INF)
				printf("?\n");
			else
				printf("%d\n",ans[a]);
		}
	}
	
	return 0;
}
