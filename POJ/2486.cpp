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
// Created Time  : 2015年08月04日 星期二 10时41分29秒
// File Name     : 2486.cpp

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

const int MaxN=110;

int dp[MaxN][210][2];
int N,K;

int val[MaxN];

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(dp,0,sizeof(dp));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre)
{
	int v;
	dp[u][0][1]=dp[u][0][0]=val[u];

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			v=E[i].to;
			dfs(v,u);

			for(int j=K;j>=0;--j)
				for(int k=0;k<=j;++k)
				{
					if(j-k-2>=0) dp[u][j][0]=max(dp[u][j][0],dp[v][k][0]+dp[u][j-k-2][0]);				// !!!!!	
					if(j-k-1>=0) dp[u][j][1]=max(dp[u][j][1],dp[v][k][1]+dp[u][j-k-1][0]);				// !!!!!	
					if(j-k-2>=0) dp[u][j][1]=max(dp[u][j][1],dp[v][k][0]+dp[u][j-k-2][1]);				// !!!!!	
				}
		}
}

int getans()
{
	dfs(1,-1);

	int ret=0;
	
	for(int i=0;i<=K;++i)
		ret=max(ret,dp[1][i][1]);
	
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int a,b;

	while(~scanf("%d %d",&N,&K))
	{
		init();
		for(int i=1;i<=N;++i)
			scanf("%d",&val[i]);

		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		printf("%d\n",getans());
	}
	
	return 0;
}
