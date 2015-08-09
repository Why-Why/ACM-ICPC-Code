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
// Created Time  : 2015年08月01日 星期六 10时52分43秒
// File Name     : 1655.cpp

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

const int MaxN=20004;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N;
int dp[MaxN],minn;
int rem[MaxN];

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
	int minn=INF;
	int sum=0;
	int t,maxn=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			v=E[i].to;
			t=dfs(v,u);
			maxn=max(maxn,t);
			sum+=t;
			
			if(dp[v]<minn)
			{
				minn=dp[v];
				rem[u]=rem[v];
			}
			else if(dp[v]==minn && rem[v]<rem[u])
				rem[u]=rem[v];
		}

	maxn=max(maxn,N-1-sum);

	if(maxn<minn)
	{
		minn=maxn;
		rem[u]=u;
	}
	else if(maxn==minn && u<rem[u])
		rem[u]=u;

	dp[u]=minn;

	return sum+1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b,c;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		init();

		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		dfs(1,-1);
		printf("%d %d\n",rem[1],dp[1]);
	}
	
	return 0;
}
