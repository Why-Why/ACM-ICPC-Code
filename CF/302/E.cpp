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
// Created Time  : 2015年05月31日 星期日 14时08分57秒
// File Name     : E.cpp

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

int n,m;
char s[30][30];
int map1[30][30];
int dp[(1<<21)];
int pre[30][30],cost[30][30];

void chuli(int sta,int low)
{
	int temp;

	for(int i=1;i<=m;++i)
	{
		dp[sta]=min(dp[sta],dp[sta^(1<<low)]+map1[low][i]);
		dp[sta]=min(dp[sta],dp[sta&(~pre[low][i])]+cost[low][i]);
	}
}

void init()
{
	int temp,sum,maxn;

	for(int i=0;i<n;++i)
		for(int j=1;j<=m;++j)
		{
			temp=0;
			sum=0;
			maxn=0;

			for(int k=0;k<n;++k)
				if(s[k][j]==s[i][j])
				{
					sum+=map1[k][j];
					maxn=max(maxn,map1[k][j]);
					temp^=(1<<k);
				}

			pre[i][j]=temp;
			cost[i][j]=sum-maxn;
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&n,&m);

	for(int i=0;i<n;++i)
		scanf("%s",s[i]+1);

	for(int i=0;i<n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&map1[i][j]);

	init();

	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;

	for(int i=1;i<(1<<n);++i)
		for(int k=0;k<n;++k)
			if(i & (1<<k))
			{
				chuli(i,k);
				break;
			}

	printf("%d\n",dp[(1<<n)-1]);

	return 0;
}
