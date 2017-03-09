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

const int MaxN=410;
const int MaxM=(20000+400)*2;
const int INF=10e8;

struct Edge
{
	int next,to,cap,flow;
};

Edge E[MaxM];
int Ecou,head[MaxN];
int gap[MaxN],cur[MaxN],pre[MaxN],dis[MaxN];
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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,F,D;
	int Ft,Dt;
	int a;

	scanf("%d %d %d",&N,&F,&D);

	init(F+D+N+N+2,F+D+N+N+1,F+D+N+N+2);

	for(int i=1;i<=N;++i)
	{
		scanf("%d %d",&Ft,&Dt);

		for(int j=1;j<=Ft;++j)
		{
			scanf("%d",&a);

			addEdge(a,F+D+i,1);
		}

		for(int j=1;j<=Dt;++j)
		{
			scanf("%d",&a);

			addEdge(F+D+N+i,F+a,1);
		}
	}

	for(int i=1;i<=N;++i)
	{
		addEdge(F+D+i,F+D+N+i,1);
	}

	for(int i=1;i<=F;++i)
		addEdge(F+D+N+N+1,i,1);

	for(int i=1;i<=D;++i)
		addEdge(F+i,F+D+N+N+2,1);

	printf("%d\n",SAP(F+D+N+N+2));
	
	return 0;
}
