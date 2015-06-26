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

const int MaxN=100005*10;
const int MaxM=100005*10;
const int INF=10e9+7;

struct Edge
{
	int to,next,cost;
};

struct Node
{
	int v,val;

	Node(int _v=0,int _val=0):v(_v),val(_val) {}

	bool operator < (const Node &a) const
	{
		return val>a.val;
	}
};

Edge E[MaxM];
int head[MaxN],Ecou;

void init(int N)
{
	Ecou=0;

	for(int i=1;i<=N;++i)
		head[i]=-1;
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool vis[MaxN];

void Dijkstra(int lowcost[],int N,int start)
{
	priority_queue <Node> que;
	Node temp;
	int u,v,c;
	int len;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
	}

	lowcost[start]=0;
	que.push(Node(start,0));

	while(!que.empty())
	{
		temp=que.top();
		que.pop();

		u=temp.v;
		
		if(vis[u])
			continue;

		vis[u]=1;
		
		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			c=E[i].cost;

			if(!vis[v] && lowcost[v]> lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;
				que.push(Node(v,lowcost[v]));
			}
		}
	}
}

int ans[MaxN];
bool have[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,M,C;
	int u,v,c;
	int cas=1;

	scanf("%d",&T);

	while(T--)
	{

		scanf("%d %d %d",&N,&M,&C);

		init(3*N);
		memset(have,0,sizeof(have));

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&u);
			
			addEdge(i,N+2*u-1,0);
			addEdge(N+2*u,i,0);

			have[u]=1;
		}

		for(int i=1;i<N;++i)
			if(have[i] && have[i+1])
			{
				addEdge(N+2*i-1,N+2*(i+1),C);
				addEdge(N+2*(i+1)-1,N+2*i,C);
			}

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&u,&v,&c);

			addEdge(u,v,c);
			addEdge(v,u,c);
		}

		Dijkstra(ans,3*N,1);

		printf("Case #%d: %d\n",cas++,ans[N]==INF ? -1 : ans[N]);
	}

	return 0;
}
