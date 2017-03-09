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
// Created Time  : 2017年02月18日 星期六 13时48分29秒
// File Name     : H.cpp

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

int N,K,len;
char s[30];

long long dp[29][29][26*26+3];
long long jie[30];

inline void add(long long &a,long long b) {
	a+=b;
	if(a>=mod) a-=mod;
}

inline long long solve(int x) {
	int need=K-len;
	int have=s[0]-'a';

	for(int i=1;i<len;++i)
		if(s[i]<s[0]) need-=N+1-(x+1+i),--have;

	if(need<0) return 0;

	for(int i=0;i<=have;++i)
		for(int j=0;j<=need;++j) dp[0][i][j]=0;
	dp[0][0][0]=1;

	for(int i=1;i<=N;++i) {
		for(int k=0;k<=need;++k) dp[i][0][k]=0;
		dp[i][0][0]=1;

		for(int j=1;j<=have;++j)
			for(int k=0;k<=need;++k) {
				dp[i][j][k]=dp[i-1][j][k];
				if(k>=N+1-i && (i<=x || i>x+len)) add(dp[i][j][k],dp[i-1][j-1][k-(N+1-i)]);
			}
	}

	return dp[N][have][need]*jie[have]%mod*jie[N-len-have]%mod;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	jie[0]=1;
	for(int i=1;i<30;++i)
		jie[i]=jie[i-1]*i%mod;

	long long ans=0;

	scanf("%d %d",&N,&K);
	scanf("%s",s);
	len=strlen(s);

	for(int x=0;x+len<=N;++x)
		add(ans,solve(x));

	printf("%lld\n",ans);

	return 0;
}
