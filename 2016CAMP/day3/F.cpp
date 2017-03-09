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
// Created Time  : 2017年02月14日 星期二 19时17分06秒
// File Name     : F.cpp

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

const int MaxN=400005;

int rem[MaxN];
int N;
int dp[MaxN],num[MaxN];
int dmax;
int ans[MaxN];

inline void update(int p) {
	num[p]=1;
	dp[p]=max(dp[(p<<1)],0)+max(dp[(p<<1)|1],0)+1;
	dmax=max(dmax,dp[p]);

	for(p>>=1;p;p>>=1) {
		dp[p]=max(dp[p<<1],0)+max(dp[(p<<1)|1],0)+num[p];
		dmax=max(dmax,dp[p]);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;

	while(~scanf("%d",&N)) {
		for(int i=1;i<=(N+N+1);++i) dp[i]=0;
		for(int i=1;i<=N;++i) {
			dp[i]=-1;
			num[i]=-1;
			scanf("%d",&t);
			rem[t]=i;
		}

		dmax=-1;
		int p=0;

		for(int i=N;i>=1;--i) {
			update(rem[i]);
			while(p<dmax) ans[p++]=i;
		}

		for(int i=0;i<N;++i) printf("%d ",ans[i]);
		puts("");
	}

	return 0;
}
