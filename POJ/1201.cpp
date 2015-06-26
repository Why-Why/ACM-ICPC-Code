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
// Created Time  : 2015年06月18日 星期四 22时54分22秒
// File Name     : 1201.cpp

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

const int MaxN=50014;

struct Edge
{
	int next,to;
	int cost;
};

Edge E[MaxN*5];
int head[MaxN],Ecou;
int N;

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int stack[MaxN];
int top;
int vis[MaxN];

void SPFA(int lowcost[],int N,int start)
{
	for(int i=0;i<=N;++i)
	{
		lowcost[i]=-1;
		vis[i]=0;
	}

	top=0;

	int u,v;

	stack[top++]=start;
	vis[start]=1;
	lowcost[start]=0;

	while(top)
	{
		u=stack[--top];
		vis[u]=0;

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(lowcost[v]<lowcost[u]+E[i].cost)
			{
				lowcost[v]=lowcost[u]+E[i].cost;

				if(vis[v]==0)
				{
					vis[v]=1;
					stack[top++]=v;
				}
			}
		}
	}
}

int ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;
	int maxn=0,minn=1000000000;

	init();

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
	{
		scanf("%d %d %d",&a,&b,&c);
		++b;
		addEdge(a,b,c);
		maxn=max(maxn,b);
		minn=min(minn,a);
	}

	for(int i=0;i<maxn;++i)
	{
		addEdge(i,i+1,0);
		addEdge(i+1,i,-1);
	}

	SPFA(ans,maxn+1,minn);

	printf("%d\n",ans[maxn]);

	return 0;
}
