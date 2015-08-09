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
// Created Time  : 2015年05月19日 星期二 11时27分12秒
// File Name     : D.cpp

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

struct Edge
{
	int to,next;
	int id;
	bool zheng;
};

const int MaxN=100005;
const int MaxM=300005;

Edge E[600005],E1[MaxM<<1];
int head[MaxN],Ecou;
int vis[MaxM<<1];
int N,M;
int ans[MaxM<<1];
int anscou=0;

int nvis[MaxN],flag;

int zans[MaxN];

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v,int d,bool zheng)
{
	E[Ecou].id=d;
	E[Ecou].to=v;
	E[Ecou].zheng=zheng;
	E[Ecou].next=head[u];

	E1[Ecou].id=d;
	E1[Ecou].to=v;
	E1[Ecou].zheng=zheng;
	E1[Ecou].next=head[u];
	
	head[u]=Ecou++;
}

void dfs(int u)
{
	nvis[u]=flag;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		if(vis[E[i].id]==0)
		{
			vis[E[i].id]=1;
			dfs(E[i].to);
		}

		while(vis[E[E[i].next].id])
			E[i].next=E[E[i].next].next;
	}

	ans[anscou++]=u;
}

void getans()
{
	for(int i=1;i<=N;++i)
		cout<<
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		++flag;
		anscou=0;
		scanf("%d %d",&N,&M);
		init();

		for(int i=1;i<=N;++i)
		{
			zans[i]=-1;
		}

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b,i,1);
			addEdge(b,a,i,0);
		}

		for(int i=1;i<=N;++i)
			if(nvis[i]!=flag)
				dfs(i);

		getans();

		for(int i=1;i<=N;++i)
			printf("%d\n",zans[i]);
	}
	
	return 0;
}
