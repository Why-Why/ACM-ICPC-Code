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
// Created Time  : 2015年06月19日 星期五 23时06分09秒
// File Name     : 2516.cpp

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

const int MaxN=200;
const int MaxM=10000;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next;
	int cap,flow,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int pre[MaxN],couNode[MaxN],lowcost[MaxN];
bool vis[MaxN];
int S,T;

void init(int _S,int _T)
{
	Ecou=0;
	S=_S;
	T=_T;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int cap,int cost)
{
	E[Ecou].cost=cost;
	E[Ecou].cap=cap;
	E[Ecou].to=v;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].cost=-cost;
	E[Ecou].cap=0;
	E[Ecou].to=u;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

int stack[MaxN];
int top;

bool SPFA(int N)
{
	int u,v;

	for(int i=1;i<=N;++i)
	{
		pre[i]=-1;
		couNode[i]=0;
		lowcost[i]=INF;
		vis[i]=0;
	}

	top=0;
	couNode[S]=1;
	lowcost[S]=0;
	vis[S]=1;

	stack[top++]=S;

	while(top)
	{
		u=stack[--top];
		vis[u]=0;

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(E[i].cap>E[i].flow && lowcost[v]>lowcost[u]+E[i].cost)
			{
				lowcost[v]=lowcost[u]+E[i].cost;
				pre[v]=i;
				
				if(!vis[v])
				{
					vis[v]=1;
					stack[top++]=v;
					++couNode[v];

					if(couNode[v]>N)
						return 0;
				}
			}
		}
	}

	if(pre[T]==-1)
		return 0;

	return 1;
}

void update(int remm,int &ret)
{
	for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
	{
		E[i].flow+=remm;
		E[i^1].flow-=remm;
		ret+=E[i].cost*remm;
	}
}

int MCMF(int N,int &ans)
{
	int ret=0,remm;
	ans=0;

	while(SPFA(N))
	{
		remm=INF;
		
		for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
			remm=min(remm,E[i].cap-E[i].flow);

		update(remm,ans);
		ret+=remm;
	}

	return ret;
}

int N,M,K;
int Nrem[60][60];
int Mrem[60][60];
int map1[60][60][60];

int getans()
{
	int temp,sum;
	int ans=0;

	for(int i=1;i<=K;++i)
	{
		sum=0;
		init(M+N+1,M+N+2);

		for(int j=1;j<=M;++j)
			addEdge(N+M+1,j,Mrem[j][i],0);

		for(int j=1;j<=N;++j)
		{
			sum+=Nrem[j][i];
			addEdge(M+j,N+M+2,Nrem[j][i],0);
		}

		for(int j=1;j<=N;++j)
			for(int k=1;k<=M;++k)
				addEdge(k,M+j,INF,map1[i][j][k]);
		sum-=MCMF(N+M+2,temp);

		if(sum)
			return -1;

		ans+=temp;
	}

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d",&N,&M,&K) && N+M+K)
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=K;++j)
				scanf("%d",&Nrem[i][j]);

		for(int i=1;i<=M;++i)
			for(int j=1;j<=K;++j)
				scanf("%d",&Mrem[i][j]);

		for(int i=1;i<=K;++i)
			for(int j=1;j<=N;++j)
				for(int k=1;k<=M;++k)
					scanf("%d",&map1[i][j][k]);

		printf("%d\n",getans());
	}
	
	return 0;
}
