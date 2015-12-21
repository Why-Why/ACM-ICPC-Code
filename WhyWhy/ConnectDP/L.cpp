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
// Created Time  : 2015年12月12日 星期六 21时05分17秒
// File Name     : L.cpp

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

long long dp[2][2055];
int N,M;

void getnum(int flag,int y) {
	int a,b;

	for(int i=0;i<(1<<M);++i) {
		a=(y==1) ? 1 : (i & (1<<(y-2)));
		b=(i & (1<<(y-1)));

		if(a || !b) dp[flag^1][i^(1<<(y-1))]+=dp[flag][i];
		else dp[flag^1][i^(1<<(y-2))]+=dp[flag][i],dp[flag^1][i^(1<<(y-1))]+=dp[flag][i];
	}
}

long long getans() {
	int flag=0;
	memset(dp[0],0,sizeof(dp[0]));
	dp[0][(1<<M)-1]=1;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j) {
			memset(dp[flag^1],0,sizeof(dp[0]));
			getnum(flag,j);
			flag^=1;
		}
	return dp[flag][(1<<M)-1];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&M)) {
		if(N<M) swap(N,M);
		printf("%lld\n",getans());
	}
	
	return 0;
}
