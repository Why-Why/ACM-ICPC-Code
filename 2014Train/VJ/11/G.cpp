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

const int MaxN=100105;
const int MaxM=300105;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int gap[MaxN],dis[MaxN],cur[MaxN],pre[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		gap[i]=0;
		dis[i]=0;
	}
}

inline void addEdge(int u,int v,int c,int rc=0)
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

inline void update(int remm)
{
	for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
	{
		E[i].flow+=remm;
		E[i^1].flow-=remm;
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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Tcas;
	int N,M;
	int start,end;
	int minx,maxx,x,y,c;

	scanf("%d",&Tcas);

	while(Tcas--)
	{
		scanf("%d %d",&N,&M);

		minx=1000000;
		maxx=-1000000;

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&x,&y);

			if(minx>x)
			{
				minx=x;
				start=i;
			}

			if(maxx<x)
			{
				maxx=x;
				end=i;
			}
		}

		init(N,start,end);

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&x,&y,&c);

			addEdge(x,y,c,c);
		}

		printf("%d\n",SAP(N));
	}
	
	return 0;
}
