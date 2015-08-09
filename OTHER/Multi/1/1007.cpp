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
// Created Time  : 2015年07月21日 星期二 14时03分09秒
// File Name     : 1007.cpp

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

const int MaxN=2010;
const int INF=10e8;
const int MaxM=60004<<1;

namespace ZDL
{

struct Node
{
	int v,val;

	Node(int _v=0,int _val=0):v(_v),val(_val) {}
	bool operator < (const Node &a) const
	{
		return val>a.val;
	}
};

struct Edge
{
	int v,cost;

	Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};

vector <Edge> E[MaxN];
bool vis[MaxN];

void init(int N)
{
	for(int i=0;i<=N;++i)
		E[i].clear();
}

void Dijkstra(int lowcost[],int n,int start)
{
	priority_queue <Node> que;
	Node qtemp;
	int len;
	int u,v,cost;

	for(int i=1;i<=n;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
	}
	lowcost[start]=0;

	que.push(Node(start,0));

	while(!que.empty())
	{
		qtemp=que.top();
		que.pop();

		u=qtemp.v;

		if(vis[u])
			continue;

		vis[u]=1;

		len=E[u].size();

		for(int i=0;i<len;++i)
		{
			v=E[u][i].v;
			cost=E[u][i].cost;

			if(!vis[v] && lowcost[v]>lowcost[u]+cost)
			{
				lowcost[v]=lowcost[u]+cost;
				que.push(Node(v,lowcost[v]));
			}
		}
	}
}

inline void addEdge(int u,int v,int c)
{
	E[u].push_back(Edge(v,c));
}

};

namespace FLOW
{

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int gap[MaxN],dis[MaxN],cur[MaxN];
int S,T;

int ans1;

void init(int N,int _S,int _T)
{
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		gap[i]=0;
		dis[i]=-1;
	}
}

void addEdge(int u,int v,int c,int rc=0)
{
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=rc;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

int que[MaxN],front,last;

void BFS()
{
	int u,v;

	gap[0]=1;
	dis[T]=0;
	front=last=0;
	que[last++]=T;

	while(front!=last)
	{
		u=que[front++];

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(dis[v]!=-1)
				continue;

			dis[v]=dis[u]+1;
			++gap[dis[v]];
			que[last++]=v;
		}
	}
}

int stack[MaxN],top;

inline void update(int remm)
{
	for(int i=0;i<top;++i)
	{
		E[stack[i]].flow+=remm;
		E[stack[i]^1].flow-=remm;
	}
}

int SAP(int N)
{
	BFS();
	ans1=dis[S];

	for(int i=1;i<=N;++i)
		cur[i]=head[i];

	int u,v,ret=0,remm=INF,mindis,inser;

	top=0;
	u=S;
	gap[0]=N;

	while(dis[S]<N)
	{
loop:
		for(int i=cur[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(E[i].cap-E[i].flow && dis[u]==dis[v]+1)
			{
				cur[u]=i;
				stack[top++]=i;
				u=v;

				if(u==T)
				{
					for(int i=0;i<top;++i)
						if(remm>E[stack[i]].cap-E[stack[i]].flow)
						{
							remm=E[stack[i]].cap-E[stack[i]].flow;
							inser=i;
						}

					ret+=remm;
					update(remm);
					top=inser;
					u=E[stack[top]^1].to;
					remm=INF;
				}

				goto loop;
			}
		}

		mindis=N-1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].cap-E[i].flow && mindis>dis[E[i].to])
			{
				cur[u]=i;
				mindis=dis[E[i].to];
			}

		if(--gap[dis[u]]==0)
			break;

		dis[u]=mindis+1;
		++gap[dis[u]];

		if(u!=S)
			u=E[stack[--top]^1].to;
	}

	return ret;
}

};

int lowcost[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;
	int ans1,ans2;
	int len,v,cost;
	int N,M;

	while(~scanf("%d %d",&N,&M))
	{
		ZDL::init(N);

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			ZDL::addEdge(a,b,c);
			ZDL::addEdge(b,a,c);
		}

		ZDL::Dijkstra(lowcost,N,1);
		FLOW::init(N,1,N);

		for(int i=1;i<=N;++i)
		{
			len=ZDL::E[i].size();

			for(int j=0;j<len;++j)
			{
				v=ZDL::E[i][j].v;
				cost=ZDL::E[i][j].cost;

				if(lowcost[v]==lowcost[i]+cost)
					FLOW::addEdge(i,v,1);
			}
		}

		ans2=FLOW::SAP(N);
		ans1=FLOW::ans1;

		printf("%d %d\n",ans2,M-ans1);
	}
	
	return 0;
}
