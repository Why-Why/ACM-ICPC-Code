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
// Created Time  : 2015年06月18日 星期四 23时59分18秒
// File Name     : 2983.cpp

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

const int MaxN=1100;
const int MaxM=300005;

struct Edge
{
	int to,next;
	int cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].cost=c;
	head[u]=Ecou++;
}

int stack[MaxN*10];
int top;
bool vis[MaxN];
int couNode[MaxN];

bool SPFA(int lowcost[],int N,int start)
{
	for(int i=1;i<=N;++i)
	{
		couNode[i]=0;
		vis[i]=0;
		lowcost[i]=-1;
	}

	couNode[start]=1;
	lowcost[start]=0;
	vis[start]=1;
	stack[top++]=start;
	
	int u,v;

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
					++couNode[v];

					if(couNode[v]>N)
						return 0;
				}
			}
		}
	}

	return 1;
}

int lowcost[MaxN];
int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M;
	int a,b,c,d;
	char s[10];

	while(~scanf("%d %d",&N,&M))
	{
		init();

		while(M--)
		{
			scanf("%s",s);

			if(s[0]=='P')
			{
				scanf("%d %d %d",&a,&b,&c);
				addEdge(b,a,c);
				addEdge(a,b,-c);
			}
			else
			{
				scanf("%d %d",&a,&b);
				addEdge(b,a,1);
			}
		}

		for(int i=1;i<=N;++i)
			addEdge(N+1,i,0);

		if(SPFA(lowcost,N+1,N+1))
			puts("Reliable");
		else
			puts("Unreliable");
	}
	
	return 0;

}
