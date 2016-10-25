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
// Created Time  : 2016年07月20日 星期三 19时06分57秒
// File Name     : 1009.cpp

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

const int mod=1000000007;

long long dp[2][(1<<16)+5];
int ans1[17][17];
int ans2[17][17];

inline void add(long long & x,long long t) {
	x+=t;
	if(x>=mod) x-=mod;
}

inline void del(long long & x,long long t) {
	x-=t;
	if(x<0) x+=mod;
}

inline void add(int & x,long long t) {
	x+=t;
	if(x>=mod) x-=mod;
}

inline void del(int & x,long long t) {
	x-=t;
	if(x<0) x+=mod;
}

void calc(int M) {
	int flag=0;
	memset(dp[0],0,sizeof(dp[0]));
	dp[0][(1<<M)-1]=1;

	for(int i=0;i<16;++i) {
		for(int j=0;j<M;++j) {
			memset(dp[flag^1],0,sizeof(dp[flag^1]));

			for(int s=0;s<(1<<M);++s) {
				if(s&(1<<j)) add(dp[flag^1][s^(1<<j)],dp[flag][s]);
				if(i && !(s&(1<<j))) add(dp[flag^1][s^(1<<j)],dp[flag][s]);
				if(j && !(s&(1<<(j-1))) && (s&(1<<j))) add(dp[flag^1][s|(1<<(j-1))|(1<<j)],dp[flag][s]);
			}

			flag^=1;
		}

		ans1[i+1][M]=dp[flag][(1<<M)-1];
	}
}

int len[17],lcou;
long long dp2[17];

void calc2(int N) {
	for(int s=0;s<(1<<(N-1));++s) {
		lcou=1;
		len[0]=0;
		for(int i=0;i<(N-1);++i)
			if(s&(1<<i)) len[lcou++]=i+1;
		len[lcou]=N;
		for(int i=0;i<lcou;++i) len[i]=len[i+1]-len[i];

		long long t;

		for(int i=1;i<=16;++i) {
			dp2[i]=1;
			for(int j=0;j<lcou;++j) (dp2[i]*=ans1[len[j]][i])%=mod;

			for(int j=1;j<i;++j) {
				t=dp2[j];
				for(int k=0;k<lcou;++k) (t*=ans1[len[k]][i-j])%=mod;

				del(dp2[i],t);
			}

			if(lcou&1) add(ans2[N][i],dp2[i]);
			else del(ans2[N][i],dp2[i]);
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<=16;++i) calc(i);
	for(int i=1;i<=16;++i) calc2(i);

	int N,M;
	while(~scanf("%d %d",&N,&M))
		printf("%d\n",ans2[N][M]);

	return 0;
}
