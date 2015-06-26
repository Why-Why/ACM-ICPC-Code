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
const int MaxM=100005;
const int INF=10e8;

struct Edge
{
	int to,next,cost;
};

struct Node
{
	int dis,id;

	Node(int _id=0,int _dis=INF):dis(_dis),id(_id)
	{}

	bool operator < (const Node & a) const
	{
		return dis>a.dis;
	}
};

Edge E[MaxM],E1[MaxM*5];
int head[MaxN],Ecou,head1[MaxN],Ecou1;

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

void init1(int N)
{
	Ecou1=0;

	for(int i=1;i<=N;++i)
		head1[i]=-1;
}

void addEdge1(int u,int v,int cost)
{
	E1[Ecou1].to=v;
	E1[Ecou1].cost=cost;
	E1[Ecou1].next=head1[u];
	head1[u]=Ecou1++;

	E1[Ecou1].to=u;
	E1[Ecou1].cost=0;
	E1[Ecou1].next=head1[v];
	head1[v]=Ecou1++;
}

void Dijkstra(int lowcost[],int N,int start)
{
	priority_queue <Node> que;
	Node t;
	int u,v,c;

	for(int i=1;i<=N;++i)
		lowcost[i]=INF;

	lowcost[start]=0;
	que.push(Node(start,0));

	while(!que.empty())
	{
		t=que.top();
		que.pop();

		u=t.id;

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(lowcost[v]>lowcost[u]+E[i].cost)
			{
				lowcost[v]=lowcost[u]+E[i].cost;
				que.push(Node(v,lowcost[v]));
			}
		}
	}
}

int A,B;
int N;
int ans[MaxN];
int cou=0;

void Build(int N)
{
	int v;

	for(int u=1;u<=N;++u)
		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			if(ans[v]==ans[u]+E[i].cost)
			{
				addEdge1(v,u,1);
			}
		}
}

bool vis[MaxN];
int pre[MaxN];

bool BFS()
{
	queue <int> que;
	int t;

	memset(vis,0,sizeof(vis));

	que.push(B);
	vis[B]=1;
	pre[B]=-1;

	while(!que.empty())
	{
		t=que.front();
		que.pop();

		if(t==A)
			return 1;

		for(int i=head1[t];i!=-1;i=E1[i].next)
			if(!vis[E1[i].to] && E1[i].cost)
			{
				vis[E1[i].to]=1;
				pre[E1[i].to]=i;
				que.push(E1[i].to);
			}
	}

	return 0;
}

void update()
{
	for(int u=A;u!=B;u=E1[pre[u]^1].to)
	{
		E1[pre[u]].cost=0;
	//	E1[pre[u]^1].cost=1;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b,c;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&B);

		init(N);
		init1(N);
		cou=0;

		while(B--)
		{
			scanf("%d %d %d",&a,&b,&c);

			if(a!=b)
				addEdge(a,b,c);
		}

		scanf("%d %d",&A,&B);

		Dijkstra(ans,N,A);
		
		Build(N);

		while(BFS())
		{
			++cou;
			update();
		}

		printf("%d\n",cou);
	}
	
	return 0;
}
