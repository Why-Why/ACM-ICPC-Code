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

const int MaxN=1010;
const int MaxM=30100;
const int INF=1000000009;

struct Edge
{
	int to,next,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;

bool vis[MaxN];
int couNode[MaxN];

void init(int N)
{
	Ecou=0;
	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		couNode[i]=0;
		vis[i]=0;
	}
}

void addEdge(int u,int v,int w)
{
	E[Ecou].to=v;
	E[Ecou].cost=w;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool SPFA(int lowcost[],int N,int start)
{
	int t,v;
	queue <int> que;

	for(int i=1;i<=N;++i)
		lowcost[i]=INF;
	lowcost[start]=0;

	que.push(start);
	couNode[start]=1;
	vis[start]=1;

	while(!que.empty())
	{
		t=que.front();
		que.pop();

		vis[t]=0;

		for(int i=head[t];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			
			if(lowcost[v]>lowcost[t]+E[i].cost)
			{
				lowcost[v]=lowcost[t]+E[i].cost;

				if(!vis[v])
				{
					vis[v]=1;
					couNode[v]+=1;
					que.push(v);

					if(couNode[v]>N)
						return 0;
				}
			}
		}
	}

	return 1;
}

int ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int N,ML,MD;
	int a,b,c;

	scanf("%d %d %d",&N,&ML,&MD);

	init(N);

	for(int i=1;i<=ML;++i)
	{
		scanf("%d %d %d",&a,&b,&c);

		addEdge(a,b,c);
	}

	for(int i=1;i<=MD;++i)
	{
		scanf("%d %d %d",&a,&b,&c);

		addEdge(b,a,-c);
	}

	for(int i=1;i<=N-1;++i)
		addEdge(i+1,i,0);

	if(!SPFA(ans,N,1))
		printf("-1\n");
	else if(ans[N]!=INF)
		printf("%d\n",ans[N]);
	else
		printf("-2\n");

	return 0;
}
