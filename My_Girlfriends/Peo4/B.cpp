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
// Created Time  : 2015年11月29日 星期日 13时00分14秒
// File Name     : B.cpp

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

int N,M;
int P[15][15];
int dp[2][5001][503];

int gcd(int a,int b) {
	if(!a) return b;
	return gcd(b%a,a);
}

void update(int po,int a,int b,int c,int ttt) {
	int t;
	for(int i=1;i<=N;++i)
		if(b & (1<<(i-1))) continue;
		else {
			t=c+P[a+1][i];
			if(t>M) t=M;
			dp[1-po][b | (1<<(i-1))][t]+=ttt;
		}
}

int jie[15];

void init() {
	jie[0]=1;
	for(int i=1;i<=12;++i) jie[i]=jie[i-1]*i;
}

inline int cou(int x) {
	int ret=0;
	for(;x;x>>=1)
		if(x&1) ++ret;
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j) scanf("%d",&P[i][j]);

		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		int po=0;

		for(int i=0;i<N;++i,po=1-po)
			for(int j=0;j<(1<<N);++j)
				if(cou(j)==i)
					for(int k=0;k<=M;++k)
						if(dp[po][j][k])
							update(po,i,j,k,dp[po][j][k]);

		int ans=dp[po][(1<<N)-1][M];
		if(ans) {
			int t=gcd(jie[N],ans);
			printf("%d/%d\n",jie[N]/t,ans/t);
		}
		else puts("No solution");
	}
	
	return 0;
}
