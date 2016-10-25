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
// Created Time  : 2016年08月29日 星期一 20时38分38秒
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

const int MaxN=105;
const long long INF=1000000000000000LL;

long long dp[2][MaxN][MaxN];
int N,M,K;

int map1[MaxN][MaxN];
int col[MaxN];

int flag;

long long min1[MaxN],min2[MaxN],rem[MaxN];

inline void update(long long &ans,int j,int c,long long num) {
	long long tm=INF;

	if(c==rem[j-1]) tm=min2[j-1];
	else tm=min1[j-1];

	tm=min(tm,dp[flag][j][c]);

	ans=min(ans,tm+num);
}

inline void solve(long long dp[MaxN][MaxN]) {
	for(int i=0;i<MaxN;++i) {
		min1[i]=min2[i]=INF;
		rem[i]=-1;
	}

	for(int i=1;i<=K;++i) {
		for(int j=1;j<=M;++j)
			if(dp[i][j]<min1[i]) {
				min2[i]=min1[i];
				min1[i]=dp[i][j];
				rem[i]=j;
			}
			else if(dp[i][j]<min2[i])
				min2[i]=dp[i][j];
	}
}

inline void reset(long long dp[MaxN][MaxN]) {
	for(int i=0;i<MaxN;++i)
		for(int j=0;j<MaxN;++j)
			dp[i][j]=INF;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&M,&K);
	for(int i=1;i<=N;++i) scanf("%d",col+i);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			scanf("%d",&map1[i][j]);

	reset(dp[0]);
	if(col[1]) dp[0][1][col[1]]=0;
	else
		for(int k=1;k<=M;++k) dp[0][1][k]=map1[1][k];
	flag=0;
	solve(dp[flag]);

	for(int i=2;i<=N;++i) {
		reset(dp[flag^1]);

		for(int j=1;j<=K;++j) {
			if(col[i]) update(dp[flag^1][j][col[i]],j,col[i],0);
			else
				for(int k=1;k<=M;++k)
					update(dp[flag^1][j][k],j,k,map1[i][k]);
		}

		flag^=1;
		solve(dp[flag]);
	}

	long long ans=INF;
	for(int i=1;i<=M;++i) ans=min(ans,dp[flag][K][i]);

	if(ans!=INF) cout<<ans<<endl;
	else puts("-1");

	return 0;
}
