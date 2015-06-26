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

const int MaxN=500;
const int MaxM=250000;
const long long INF=10000000000000000LL;

namespace name1
{

struct Edge
{
	int to,next;
	long long cap,flow;
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

void addEdge(int u,int v,long long c,long long rc=0)
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

inline void update(long long remm)
{
	for(int i=0;i<top;++i)
	{
		E[stack[i]].flow+=remm;
		E[stack[i]^1].flow-=remm;
	}
}

long long SAP(int N)
{
	BFS();

	for(int i=1;i<=N;++i)
		cur[i]=head[i];

	int u,v,inser,mindis;
	long long ret=0,remm=INF;

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

}

/*
namespace name2
{

struct Edge
{
	int next,to;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int rem[MaxN];
int que[MaxN],front,last;

void BFS(int S)
{
	int temp;

	front=last=0;
	que[last++]=S;
	rem[S]=1;

	while(last-front)
	{
		temp=que[front++];

		for(int i=head[temp];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(rem[v])
			{
			}
		}
	}
}

}*/

using namespace name1;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M;
	int a,b,c;

	while(~scanf("%d %d",&N,&M))
	{
		scanf("%d %d",&a,&b);

		init(2*N,a*2-1,b*2);

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&a);
			addEdge(i*2-1,i*2,a);
		}

		while(M--)
		{
			scanf("%d %d",&a,&b);

			addEdge(a*2,b*2-1,INF);
			addEdge(b*2,a*2-1,INF);
		}

//		cout<<SAP(2*N)<<endl;
		printf("%I64d\n",SAP(2*N));
	}
	
	return 0;
}
