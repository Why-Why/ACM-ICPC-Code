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
// Created Time  : 2015年06月23日 星期二 23时52分46秒
// File Name     : 3352.cpp

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

const int MaxN=1010;
const int MaxM=2010;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int Index,DFN[MaxN],LOW[MaxN];
int couBridge;
bool Bridge[MaxM];

void Tarjan(int u,int pre)
{
	int v;

	DFN[u]=LOW[u]=++Index;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)
			continue;

		if(!DFN[v])
		{
			Tarjan(v,u);
			LOW[u]=min(LOW[u],LOW[v]);

			if(DFN[u]<LOW[v])
			{
				Bridge[i]=1;
				Bridge[i^1]=1;
				++couBridge;
			}
		}
		else if(DFN[v]<LOW[u])
			LOW[u]=DFN[v];
	}
}

int Belong[MaxN];
int Bcou;
int du[MaxN];

void dfs(int u)
{
	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		if(Bridge[i])
			continue;

		v=E[i].to;

		if(Belong[v]==0)
		{
			Belong[v]=Bcou;
			dfs(v);
		}
	}
}

int getans(int N)
{
	for(int i=1;i<=N;++i)
		if(!DFN[i])
			Tarjan(i,i);

	memset(Belong,0,sizeof(Belong));
	Bcou=0;

	for(int i=1;i<=N;++i)
		if(!Belong[i])
		{
			++Bcou;
			Belong[i]=Bcou;
			dfs(i);
		}

	int v;

	for(int u=1;u<=N;++u)
		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(Belong[u]!=Belong[v])
			{
				++du[Belong[u]];
				++du[Belong[v]];
			}
		}

	int cou=0;

	for(int i=1;i<=Bcou;++i)
		if(du[i]==2)
			++cou;

	return (cou+1)/2;
}

void init(int N)
{
	Index=0;
	Ecou=0;
	couBridge=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		Bridge[i]=0;
		DFN[i]=0;
	}
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M;
	int a,b;

	scanf("%d %d",&N,&M);

	init(N);

	while(M--)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	printf("%d\n",getans(N));
	
	return 0;
}
