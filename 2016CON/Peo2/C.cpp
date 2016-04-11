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
// Created Time  : 2016年02月27日 星期六 12时49分29秒
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

const long long INF=1000000000000000LL;
const int MaxN=555;

int N,v[MaxN];
long long B,w[MaxN];
long long dp[5555];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %I64d",&N,&B);
		for(int i=1;i<=N;++i) scanf("%I64d %d",w+i,v+i);
		dp[0]=0;
		for(int i=1;i<=5000;++i) dp[i]=INF;

		for(int i=1;i<=N;++i)
			for(int j=5000;j>=v[i];--j)
				dp[j]=min(dp[j],dp[j-v[i]]+w[i]);

		for(int i=5000;i>=0;--i)
			if(dp[i]<=B) {
				printf("%d\n",i);
				break;
			}
	}
	
	return 0;
}
