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
// Created Time  : 2015年05月12日 星期二 23时36分50秒
// File Name     : 3176.cpp

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

int dp[400][400];
int N;
int num[400][400];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=i;++j)
			{
				scanf("%d",&num[i][j]);
				dp[i][j]=0;
			}

		memset(dp[N+1],0,sizeof(dp[N+1]));

		for(int i=N;i>=1;--i)
			for(int j=1;j<=i;++j)
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+num[i][j];

		printf("%d\n",dp[1][1]);
	}

	return 0;
}
