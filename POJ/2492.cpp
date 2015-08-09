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
// Created Time  : 2015年07月17日 星期五 20时49分42秒
// File Name     : 2492.cpp

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

const int MaxN=2010;

int map1[MaxN][MaxN];
int flag=0;
int vis[MaxN];
int N;
int que[MaxN],first,last;

bool bfs(int u)
{
	int v;

	first=last=0;
	que[last++]=u;
	vis[u]=1;

	while(last-first)
	{
		u=que[first++];

		for(v=1;v<=N;++v)
			if(map1[u][v]==flag && v!=u)
			{
				if(vis[v]==vis[u])
					return 1;

				if(!vis[v])
				{
					vis[v]=-vis[u];
					que[last++]=v;
				}
			}
	}

	return 0;
}

bool getans()
{
	memset(vis,0,sizeof(vis));
	first=last=0;

	for(int i=1;i<=N;++i)
		if(!vis[i])
			if(bfs(i))
				return 1;

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int Q;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&Q);
		++flag;

		while(Q--)
		{
			scanf("%d %d",&a,&b);
			map1[a][b]=map1[b][a]=flag;
		}

		printf("Scenario #%d:\n",cas++);

		if(getans())
			puts("Suspicious bugs found!\n");
		else
			puts("No suspicious bugs found!\n");
	}
	
	return 0;
}
