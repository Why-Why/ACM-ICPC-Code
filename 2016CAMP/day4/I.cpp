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
// Created Time  : 2017年02月16日 星期四 10时01分17秒
// File Name     : I.cpp

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

const int MaxN=1000005;

const long long INF=100000000000000000LL;

int N;
long long a[MaxN],dp[MaxN][2];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		long long ans=-INF;
		scanf("%d",&N);
		dp[0][0]=0;
		dp[0][1]=-INF;

		for(int i=1;i<=N;++i) {
			scanf("%lld",a+i);
			dp[i][0]=max(0LL,dp[i-1][1]+a[i]);
			dp[i][1]=max(dp[i-1][0]+a[i],a[i]);

			ans=max(ans,dp[i][1]);
		}

		printf("%lld\n",ans);
	}

	return 0;
}
