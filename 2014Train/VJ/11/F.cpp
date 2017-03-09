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

const int MaxN=510;
const int MaxM=510*510;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int gap[MaxN],cur[MaxN],dis[MaxN],pre[MaxN];
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

int n,np,nc,m;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;
	char s[200];

	while(~scanf("%d %d %d %d",&n,&np,&nc,&m))
	{
		init(n+2,n+1,n+2);

		for(int i=1;i<=m;++i)
		{
			scanf("%s",s);
			sscanf(s+1,"%d,%d",&a,&b);
			sscanf(strstr(s,")")+1,"%d",&c);

			addEdge(a+1,b+1,c);
		}

		for(int i=1;i<=np;++i)
		{
			scanf("%s",s);
			sscanf(s+1,"%d",&a);
			sscanf(strstr(s,")")+1,"%d",&b);

			addEdge(n+1,a+1,b);
		}

		for(int i=1;i<=nc;++i)
		{
			scanf("%s",s);
			sscanf(s+1,"%d",&a);
			sscanf(strstr(s,")")+1,"%d",&b);

			addEdge(a+1,n+2,b);
		}

		printf("%d\n",SAP(n+2));
	}
	
	return 0;
}
