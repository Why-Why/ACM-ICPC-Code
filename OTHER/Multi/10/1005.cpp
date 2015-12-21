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
// Created Time  : 2015年08月20日 星期四 13时04分57秒
// File Name     : 1005.cpp

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
const int MaxM=2010;
const long long INF=1000000000000000000LL;

int M,N;
int W[MaxN],A[MaxN],B[MaxN];
long long dp[MaxN][MaxM];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	long long t;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&M,&N);
		for(int i=1;i<=N;++i)
			scanf("%d %d %d",&W[i],&A[i],&B[i]);

		for(int i=0;i<=N;++i)
			for(int j=0;j<=M;++j)
				dp[i][j]=-INF;
		for(int i=0;i<=N;++i)
			dp[i][0]=0;

		for(int i=1;i<=N;++i)
			for(int j=W[i];j<=M;++j)
				dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-W[i]]+A[i]+B[i],dp[i][j-W[i]]+A[i]));

		t=0;
		for(int i=1;i<=M;++i)
			t=max(t,dp[N][i]);
		printf("%I64d\n",t);
	}
	
	return 0;
}
