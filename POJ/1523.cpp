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
// Created Time  : 2015年06月23日 星期二 23时02分23秒
// File Name     : 1523.cpp

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
const int MaxM=100005;

struct Edge
{
	int to,next;
};

Edge E[MaxN];
int head[MaxN],Ecou;

int LOW[MaxN],DFN[MaxN],Index;
bool cutp[MaxN];
int add_block[MaxN];

void Tarjan(int u,int pre)
{
	int v;
	int couSon=0;

	LOW[u]=DFN[u]=++Index;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)
			continue;

		if(!DFN[v])
		{
			++couSon;
			Tarjan(v,u);
			LOW[u]=min(LOW[u],LOW[v]);

			if(u!=pre && DFN[u]<=LOW[v])
			{
				cutp[u]=1;
				++add_block[u];
			}
		}
		else if(DFN[v]<LOW[u])
			LOW[u]=DFN[v];
	}

	if(u==pre && couSon>1)
	{
		cutp[u]=1;
		add_block[u]=couSon-1;
	}
}

void init(int N)
{
	Ecou=0;
	Index=0;

	for(int i=1;i<=N;++i)
	{
		add_block[i]=0;
		DFN[i]=0;
		cutp[i]=0;
		head[i]=-1;
	}
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int dui[MaxN];
int zhu[MaxN];
int rem1[MaxM],rem2[MaxM];

void getans(int N)
{
	int cou=0;

	for(int i=1;i<=N;++i)
		if(!DFN[i])
		{
			++cou;
			Tarjan(i,i);
		}

	bool ok=0;

	for(int i=1;i<=N;++i)
		if(cutp[i])
		{
			ok=1;
			printf("  SPF node %d leaves %d subnets\n",dui[i],cou+add_block[i]);
		}

	if(!ok)
		puts("  No SPF nodes");
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int M;
	int cas=1;

	while(1)
	{
		M=0;
		memset(zhu,0,sizeof(zhu));

		for(scanf("%d",&a);a;scanf("%d",&a))
		{
			scanf("%d",&b);
			
			rem1[M]=a;
			rem2[M++]=b;
			zhu[a]=zhu[b]=1;
		}

		if(!M)
			break;

		int N=0;

		for(int i=1;i<=1000;++i)
			if(zhu[i])
			{
				dui[++N]=i;
				zhu[i]=N;
			}

		init(N);

		for(int i=0;i<M;++i)
		{
			addEdge(zhu[rem2[i]],zhu[rem1[i]]);
			addEdge(zhu[rem1[i]],zhu[rem2[i]]);
		}

		printf("Network #%d\n",cas++);
		getans(N);
		puts("");
	}
	
	return 0;
}
