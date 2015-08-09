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
// Created Time  : 2015年08月03日 星期一 18时19分02秒
// File Name     : 1947.cpp

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

const int MaxN=160;
const int INF=10000000;

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N,P;
int dp[MaxN][MaxN];

int ans;

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int dfs(int u,int pre)
{
	int v;
	int ret=0,t;

	for(int i=0;i<=N;++i)
		dp[u][i]=INF;
	dp[u][0]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			v=E[i].to;
			t=dfs(v,u);
			ret+=t;

			for(int i=N;i>=1;--i)
				for(int j=1;j<=i;++j)
					dp[u][i]=min(dp[u][i],dp[u][i-j]+dp[v][j]);
		}
	dp[u][ret+1]=min(dp[u][ret+1],1);

	if(ret+1-P>=0)
		ans=min(ans,dp[u][ret+1-P]+(u!=1));

	return ret+1;
}

int getans()
{
	ans=INF;
	dfs(1,-1);

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&P))
	{
		init();
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
