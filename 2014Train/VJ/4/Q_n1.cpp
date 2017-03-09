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

const int MaxN=5010;
const int MaxM=500005;
const int INF=10e8;

namespace first
{

struct Edge
{
	int to,next,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int vis[MaxN];

void init(int N)
{
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		vis[i]=0;
	}
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void SPFA(int lowcost[],int N,int start)
{
	queue <int> que;
	int u,v,c;

	for(int i=1;i<=N;++i)
		lowcost[i]=INF;
	lowcost[start]=0;

	que.push(start);
	vis[start]=1;

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		vis[u]=0;

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			c=E[i].cost;

			if(lowcost[v]>lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;

				if(!vis[v])
				{
					que.push(v);
					vis[v]=1;
				}
			}
		}
	}
}

}

namespace second
{

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int Ecou,head[MaxN];
int gap[MaxN],dis[MaxN],pre[MaxN],cur[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		gap[i]=dis[i]=0;
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

void update(int remm)
{
	int u=T;

	while(u!=S)
	{
		E[pre[u]].flow+=remm;
		E[pre[u]^1].flow-=remm;
		u=E[pre[u]^1].to;
	}
}

int SAP(int N)
{
	for(int i=1;i<=N;++i)
		cur[i]=head[i];

	int u,v,ret=0,remm=INF,mindis;

	u=S;
	pre[S]=-1;
	gap[0]=N;

	while(dis[S]<N)
	{
		loop:
		for(int i=cur[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			
			if(E[i].cap-E[i].flow && dis[u]==dis[v]+1)
			{
				pre[v]=i;
				cur[u]=i;
				u=v;

				if(u==T)
				{
					for(int i=pre[u];i!=-1;i=pre[E[i^1].to])
						remm=min(remm,E[i].cap-E[i].flow);

					ret+=remm;
					update(remm);
					u=S;
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
			u=E[pre[u]^1].to;
	}

	return ret;
}

}

int lowcost[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	int N,M;
	int A,B;
	int a,b,c;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);

		first::init(N);

		{
			using namespace first;

			while(M--)
			{
				scanf("%d %d %d",&a,&b,&c);

				addEdge(a,b,c);
			}

			scanf("%d %d",&A,&B);

			SPFA(lowcost,N,A);

			second::init(N,A,B);

			for(int u=1;u<=N;++u)
				for(int i=head[u];i!=-1;i=E[i].next)
					if(lowcost[E[i].to]==lowcost[u]+E[i].cost)
						second::addEdge(u,E[i].to,1);
		}

		{
			using namespace second;

			printf("%d\n",SAP(N));
		}
	}

	return 0;
}
