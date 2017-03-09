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

const int MaxN=30004;
const int MaxM=150004;
const int INF=10e9+7;

struct Node
{
	int id,val;

	Node(int _id=0,int _val=0):id(_id),val(_val) {}

	bool operator < (const Node & a) const
	{
		return val>a.val;
	}
};

struct Edge
{
	int to,next,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int vis[MaxN];

void Dijkstra(int lowcost[],int N,int start)
{
	priority_queue <Node> que;
	Node temp;
	int u,v,c;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
	}

	que.push(Node(start,0));
	lowcost[start]=0;

	while(!que.empty())
	{
		temp=que.top();
		que.pop();

		u=temp.id;

		if(vis[u])
			continue;

		vis[u]=1;

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			c=E[i].cost;

			if(lowcost[v]>lowcost[u]+c && !vis[v])
			{
				lowcost[v]=lowcost[u]+c;
				que.push(Node(v,lowcost[v]));
			}
		}
	}
}

void init(int N)
{
	for(int i=1;i<=N;++i)
		head[i]=-1;
	Ecou=0;
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int N,M;
	int a,b,c;

	scanf("%d %d",&N,&M);

	init(N);

	while(M--)
	{
		scanf("%d %d %d",&a,&b,&c);
		addEdge(a,b,c);
	}

	Dijkstra(ans,N,1);

	printf("%d\n",ans[N]);

	return 0;
}
