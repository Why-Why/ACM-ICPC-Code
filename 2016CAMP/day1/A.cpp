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
// Created Time  : 2017年02月15日 星期三 11时49分19秒
// File Name     : A.cpp

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

int N,w[2003];
long long dp[2003][2][2003],inv[2003];

long long inv1(long long a,long long m) {
	if(a==1) return 1;
	return inv1(m%a,m)*(m-m/a)%m;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<2003;++i) inv[i]=inv1(i,mod);

	long long sum;

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i) scanf("%d",w+i);

		for(int i=1;i<=N;++i)
			for(int j=0;j<2;++j)
				for(int k=1;k<=N;++k) dp[i][j][k]=0;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(i>=j) ++dp[2][0][i];
				else ++dp[2][1][j];

		for(int i=3;i<=N;++i) {
			sum=0;

			for(int a=N;a>=1;--a) {
				(sum+=w[a]*dp[i-1][0][a]%mod*inv[a]%mod)%=mod;
				(dp[i][0][a]+=sum*a+dp[i-1][1][a]*w[a]%mod*a)%=mod;
				(dp[i][1][a]+=sum*(a-1))%=mod;
			}

			sum=0;
			for(int a=1;a<=N;++a) {
				(dp[i][1][a]+=sum*w[a])%=mod;
				(sum+=dp[i-1][0][a]+dp[i-1][1][a])%=mod;
			}
		}

		sum=0;
		for(int i=1;i<=N;++i)
			(sum+=dp[N][0][i]+dp[N][1][i])%=mod;
		printf("%lld\n",sum);
	}

	return 0;
}
