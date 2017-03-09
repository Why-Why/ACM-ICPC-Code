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

const int MaxN=2020;
const int MaxM=300000;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next,cap,flow,cost;
};

Edge E[MaxM];
int Ecou;
int head[MaxN];
int gap[1000006],dis[MaxN],pre[MaxN],cur[MaxN];
int S,T;
int zuida;

void init(int N)
{
	//S=_S;
	//T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		dis[i]=0;
	}

//	for(int i=0;i<=zuida;++i)
//		gap[i]=0;
}

void init1(int _S,int _T)
{
	S=_S;
	T=_T;
}

void addEdge(int u,int v,int cost,int c,int rc=0)		// 单向边三个参数，双向边四个。
{
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	E[Ecou].cost=cost;
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=rc;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	E[Ecou].cost=cost;
	head[v]=Ecou++;
}

inline void update(int remm)
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

	while(dis[S]<INF)
	{
		loop:
		for(int i=cur[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(E[i].cap-E[i].flow && dis[u]==dis[v]+E[i].cost)	//!!!
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
					u=S;				// ???
					remm=INF;
				}

				goto loop;
			}
		}

		mindis=INF;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].cap-E[i].flow && mindis>dis[E[i].to]+E[i].cost)
			{
				cur[u]=i;
				mindis=dis[E[i].to]+E[i].cost;
			}
		
	//	if(--gap[dis[u]]==0)
	//		break;

		dis[u]=mindis;
	//	++gap[dis[u]];

		if(u!=S)
			u=E[pre[u]^1].to;
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int n,m;
	int a,b,c;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&n,&m);

		init(n);

		while(m--)
		{
			scanf("%d %d %d",&a,&b,&c);

			addEdge(a,b,c,1);
		}

		scanf("%d %d",&a,&b);

		init1(a,b);

		printf("%d\n",SAP(n));
	}
	
	return 0;
}
