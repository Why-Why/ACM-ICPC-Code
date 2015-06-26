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
// Created Time  : 2015年05月11日 星期一 09时32分16秒
// File Name     : 1836.cpp

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

int dp[1010],dp1[1010];
int N;
double num[1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans;
	int maxn;

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%lf",&num[i]);

		dp[0]=0;

		for(int i=1;i<=N;++i)
		{
			maxn=0;

			for(int j=1;j<i;++j)
				if(num[j]<num[i])
					maxn=max(maxn,dp[j]);

			dp[i]=maxn+1;
		}

		for(int i=N;i>=1;--i)
		{
			maxn=0;

			for(int j=N;j>i;--j)
				if(num[j]<num[i])
					maxn=max(maxn,dp1[j]);

			dp1[i]=maxn+1;
		}

		ans=max(dp[N],dp1[1]);

		for(int i=2;i<N;++i)
			ans=max(ans,dp[i]+dp1[i]-1);

		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				if(num[i]==num[j])
					ans=max(ans,dp[i]+dp1[j]);

		printf("%d\n",N-ans);
	}
	
	return 0;
}
