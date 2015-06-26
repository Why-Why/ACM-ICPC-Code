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

const int MaxN=70;
const int MaxM=4900;
const int INF=10e8;

struct Edge
{
	int to,next,cap,flow;
	bool fan;
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
	E[Ecou].fan=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=rc;
	E[Ecou].flow=0;
	E[Ecou].fan=1;
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

int P,N;
int lx[MaxN][15],ly[MaxN][15],lc[MaxN];

inline void getnum(int x)
{
	int t;

	scanf("%d",&lc[x]);

	for(int i=0;i<P;++i)
		scanf("%d",&lx[x][i]);

	for(int i=0;i<P;++i)
		scanf("%d",&ly[x][i]);
}

bool judge(int x,int y)
{
	for(int i=0;i<P;++i)
		if(ly[x][i]!=lx[y][i] && lx[y][i]!=2)
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&P,&N);

	init(2*N+2,2*N+1,2*N+2);

	for(int i=1;i<=N;++i)
		getnum(i);

	bool ok;
	
	for(int i=1;i<=N;++i)
	{
		addEdge(i,i+N,lc[i]);

		ok=1;
		for(int j=0;j<P;++j)
			if(ly[i][j]!=1)
				ok=0;

		if(ok)
			addEdge(i+N,2*N+2,INF);
		
		ok=1;
		for(int j=0;j<P;++j)
			if(lx[i][j]!=0 && lx[i][j]!=2)
				ok=0;

		if(ok)
			addEdge(2*N+1,i,INF);

		for(int j=1;j<=N;++j)
			if(i!=j && judge(i,j))
				addEdge(i+N,j,INF);
	}

	int ans=SAP(2*N+2);
	int cou=0;

	for(int u=N+1;u<=N+N;++u)
		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].flow && E[i].fan==0 && E[i].to<=N && E[i].to>=1)
				++cou;

	printf("%d %d\n",ans,cou);

	for(int u=1+N;u<=N+N;++u)
		for(int i=head[u];i!=-1;i=E[i].next)
		{
			if(E[i].to>N || E[i].fan || E[i].to<1)
				continue;

			if(E[i].flow>0)
				printf("%d %d %d\n",u-N,E[i].to,E[i].flow);
			else if(E[i].flow<0)
				printf("%d %d %d\n",E[i].to,u-N,E[i^1].flow);
		}
	
	return 0;
}
