// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年09月15日 星期二 17时03分30秒
// File Name     : 4046.cpp

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
const int MaxM=20004;
const long long INF=1000000000000000LL;

struct Edge
{
	int to,next,c;
};

Edge E[MaxM<<1];
int head[MaxN],Ecou;
int nrem[MaxN];

int N,M;

long long ans[MaxN][MaxN];

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].c=c;
	head[u]=Ecou++;
}

int que[MaxN<<2];
int first,last;
int vis[MaxN],flag=0;

void Dijkstra(int lowcost[],int N,int start)
{
	first=last=0;
	int u,v;
	++flag;

	lowcost[start]=nrem[start];
	que[last++]=start;
	vis[start]=flag;

	while(last-first)
	{
		u=que[first++];
		vis[u]=0;
		
		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
		}
	}
}

void getans()
{
	for(int i=1;i<=N;++i)
		Dijkstra(ans[i],N,i);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	while(~scanf("%d %d",&N,&M))
	{
		init();
		for(int i=1;i<=N;++i)
			scanf("%d",&nrem[i]);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				ans[i][j]=INF;

		while(M--)
		{
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		getans();

		scanf("%d",&M);

		while(M--)
		{
			scanf("%d %d",&a,&b);
			printf("%lld\n",ans[a][b]);
		}
	}
	
	return 0;
}
