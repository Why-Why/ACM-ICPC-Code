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
// Created Time  : 2015年06月03日 星期三 15时13分06秒
// File Name     : E_1.cpp

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

const int MaxN=100005;
const int MaxM=400005;

struct Edge
{
	int to,next;
};

Edge E[1000005];
int head[MaxN],Ecou;

bool vis[1000005];
int N,M;

int remN[1000005],Ncou=0;
int ru[MaxN],chu[MaxN],zong[MaxN];
int ansA[1000005],ansB[1000005],anscou=0;

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u)
{
	for(int i=head[u];i!=-1;i=E[i].next)
	{
		if(vis[i]==0)
		{
			vis[i]=vis[i^1]=1;
			dfs(E[i].to);
		}

		while(E[i].next!=-1 && vis[E[i].next])
			E[i].next=E[E[i].next].next;
	}

	remN[Ncou++]=u;
}

void chuli()
{
	int rem=-1;

	for(int i=1;i<=N;++i)
		if(zong[i] & 1)
		{
			if(rem==-1)
				rem=i;
			else
			{
				addEdge(rem,i);
				addEdge(i,rem);
				++zong[rem];
				++zong[i];

				rem=-1;
			}
		}
}

void check()
{
	bool t=1;
	int a,b;

	for(int i=0;i<Ncou-1;++i,t=!t)
	{
		if(t)
		{
			a=remN[i];
			b=remN[i+1];
		}
		else
		{
			a=remN[i+1];
			b=remN[i];
		}

		ansA[anscou]=a;
		ansB[anscou++]=b;
		++ru[b];
		++chu[a];
	}

	for(int i=1;i<=N;++i)
		if(ru[i] & 1)
		{
			ansA[anscou]=i;
			ansB[anscou++]=i;
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&N,&M);

	init();

	for(int i=1;i<=M;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);

		++zong[a];
		++zong[b];
	}

	chuli();
	dfs(1);
	check();

	printf("%d\n",anscou);

	for(int i=0;i<anscou;++i)
		printf("%d %d\n",ansA[i],ansB[i]);
	
	return 0;
}
