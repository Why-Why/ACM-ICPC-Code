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
const int MaxM=1510;
const int INF=10e8;

struct Edge
{
	int to,next,cost,flow;
};

Edge E[MaxM];
int Ecou;
int head[MaxN];
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

void addEdge(int u,int v,int c,int rc=0)		// 单向边三个参数，双向边四个。
{
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cost=rc;
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
		cur[i]=head[i];				/////

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

			if(E[i].cost-E[i].flow && dis[u]==dis[v]+1)	//!!!
			{
				if(remm>E[i].cost-E[i].flow)			// 注意这里有一个问题：就是DFS过程中可能求出remm比最终路径最小边小(因为可能这条边已经不经过了)，所以可以在最后u==T时再寻找remm，这样就可以使用remmp了。
					remm=E[i].cost-E[i].flow;

				pre[v]=i;
				cur[u]=i;
				u=v;

				if(u==T)
				{
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
			if(E[i].cost-E[i].flow && mindis>dis[E[i].to])
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
