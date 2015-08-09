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
// Created Time  : 2015年07月20日 星期一 10时39分58秒
// File Name     : 2948.cpp

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

const int MaxN=510;

int N,M;
int C1[MaxN][MaxN];
int C2[MaxN][MaxN];
int dp[MaxN][MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int maxn;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				scanf("%d",&C1[i][j]);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				scanf("%d",&C2[i][j]);

		memset(dp,0,sizeof(dp));

		for(int i=1;i<=M;++i)
		{
			for(int j=2;j<=N;++j)
				C2[j][i]+=C2[j-1][i];

			for(int j=N-1;j>=1;--j)
				C1[j][i]+=C1[j+1][i];
		}

		for(int i=M;i>=1;--i)
			for(int j=0;j<=N;++j)
			{
				maxn=0;

				for(int k=j;k<=N;++k)
					maxn=max(maxn,dp[i+1][k]);

				dp[i][j]=maxn+C2[j][i]+C1[j+1][i];
			}

		maxn=0;

		for(int i=0;i<=N;++i)
			maxn=max(maxn,dp[1][i]);

		printf("%d\n",maxn);
	}
	
	return 0;
}
