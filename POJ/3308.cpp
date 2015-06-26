// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年06月24日 星期三 22时54分02秒
// File Name     : 3308.cpp

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

const int MaxN=700;
const int MaxM=50000;
const double eps=1e-10;
const double INF=1e12;

struct Edge
{
	int to,next;
	double cap,flow;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int gap[MaxN],dis[MaxN],cur[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	Ecou=0;
	S=_S;
	T=_T;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		gap[i]=0;
		dis[i]=-1;
	}
}

void addEdge(int u,int v,double c)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].cap=c;
	E[Ecou].flow=0;
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].next=head[v];
	E[Ecou].cap=0;
	E[Ecou].flow=0;
	head[v]=Ecou++;
}

int que[MaxN],first,last;

void BFS()
{
	int u,v;

	gap[0]=1;
	dis[T]=0;
	first=last=0;
	que[last++]=T;

	while(last-first)
	{
		u=que[first++];

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

int Stack[MaxN],top;

inline void update(double remm)
{
	for(int i=0;i<top;++i)
	{
		E[Stack[i]].flow+=remm;
		E[Stack[i]^1].flow-=remm;
	}
}

double SAP(int N)
{
	BFS();

	for(int i=1;i<=N;++i)
		cur[i]=head[i];

	int u,v,mindis,inser;
	double remm=INF,ret=0;

	top=0;
	u=S;
	
	while(dis[S]<N)
	{
loop:
		for(int i=cur[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(E[i].cap-E[i].flow>eps && dis[u]==dis[v]+1)
			{
				cur[u]=i;
				Stack[top++]=i;
				u=v;

				if(u==T)
				{
					for(int i=0;i<top;++i)
						if(remm>E[Stack[i]].cap-E[Stack[i]].flow)
						{
							remm=E[Stack[i]].cap-E[Stack[i]].flow;
							inser=i;
						}

					ret+=remm;
					update(remm);

					top=inser;
					u=E[Stack[top]^1].to;
					remm=INF;
				}

				goto loop;
			}
		}

		mindis=N-1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].cap-E[i].flow>eps && mindis>dis[E[i].to])
			{
				mindis=dis[E[i].to];
				cur[u]=i;
			}

		if(--gap[dis[u]]==0)
			break;

		dis[u]=mindis+1;
		++gap[dis[u]];

		if(u!=S)
			u=E[Stack[--top]^1].to;
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,N,M,L;
	double t;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&N,&M,&L);

		init(N+M+L+2,N+M+L+1,N+M+L+2);

		for(int i=1;i<=N;++i)
		{
			scanf("%lf",&t);
			addEdge(N+M+L+1,i,log(t));
		}

		for(int i=1;i<=M;++i)
		{
			scanf("%lf",&t);
			addEdge(N+L+i,N+M+L+2,log(t));
		}

		for(int i=1;i<=L;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,N+i,INF);
			addEdge(N+i,N+L+b,INF);
		}

		printf("%.4f\n",exp(SAP(N+M+L+2)));
	}
	
	return 0;
}
