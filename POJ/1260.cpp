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
// Created Time  : 2015年05月12日 星期二 22时05分06秒
// File Name     : 1260.cpp

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

const int INF=0x3f3f3f3f;

int dp[110];
int a[110],p[110];
int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int sum;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%d %d",&a[i],&p[i]);

		dp[N+1]=0;

		for(int i=N;i>=1;--i)
		{
			dp[i]=INF;
			sum=10;

			for(int j=i;j<=N;++j)
			{
				sum+=a[j];
				dp[i]=min(dp[i],sum*p[j]+dp[j+1]);
			}
		}

		printf("%d\n",dp[1]);
	}
	
	return 0;
}
