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
// Created Time  : 2016年09月23日 星期五 00时24分38秒
// File Name     : C.cpp

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

const int MaxN=3003;
const long long INF=1000000000000000LL;

int num[MaxN],N;
int rem[MaxN*3],rcou;

long long dp[MaxN][MaxN*3];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d",num+i);
		num[i]-=i;
		rem[++rcou]=num[i];
		rem[++rcou]=num[i]-1;
		rem[++rcou]=num[i]+1;
	}

	sort(rem+1,rem+rcou+1);
	rcou=unique(rem+1,rem+rcou+1)-rem-1;

	long long minn;

	for(int i=1;i<=N;++i) {
		minn=INF;
		for(int j=1;j<=rcou;++j) {
			minn=min(minn,dp[i-1][j]);
			dp[i][j]=minn+abs(rem[j]-(long long)num[i]);
		}
	}

	minn=INF;
	for(int j=1;j<=rcou;++j) minn=min(minn,dp[N][j]);
	printf("%I64d\n",minn);

	return 0;
}
