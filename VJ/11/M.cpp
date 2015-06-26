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
const int MaxM=1800105;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int gap[MaxN],dis[MaxN],cur[MaxN];
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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,m,nn;
	int a,b;

	while(~scanf("%d %d",&n,&m))
	{
		nn=(n-1)/10+1;

		init(nn+m+2,nn+m+1,nn+m+2);

		for(int i=1;i<=nn;++i)
		{
			addEdge(nn+m+1,i,);

			for(int j=1;j<=m;++j)
			{
				scanf("%d",&a);

				if(a)
					addEdge(i,n+j,INF);
			}
		}

		for(int i=1;i<=m;++i)
		{
			scanf("%d",&a);

			addEdge(n+i,n+m+2,a);
		}

		if(SAP(n+m+2)==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
