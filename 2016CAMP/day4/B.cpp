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
// Created Time  : 2017年02月16日 星期四 10时33分14秒
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

const int INF=0x3f3f3f3f;

char s1[1000006];
char s2[1003];

int dp[1003][1003];
int rp[1000006][26];
int N;
int len;

inline int findA(int L,char c) {
	if(L>len) return INF;
	return rp[L][c-'a'];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%s %s",s1+1,s2+1);
		N=strlen(s1+1);
		len=N;

		for(int i=0;i<26;++i) rp[N+1][i]=INF;
		for(int i=N;i>=1;--i) {
			for(int j=0;j<26;++j) rp[i][j]=rp[i+1][j];
			rp[i][s1[i]-'a']=i;
		}

		N=strlen(s2+1);
		for(int i=0;i<=N;++i) {
			dp[i][0]=0;
			for(int j=1;j<=N;++j) dp[i][j]=INF;
		}

		for(int i=1;i<=N;++i)
			for(int j=1;j<=i;++j)
				dp[i][j]=min(dp[i-1][j],findA(dp[i-1][j-1]+1,s2[i]));

		int ans;
		for(int i=0;i<=N;++i)
			if(dp[N][i]!=INF) ans=i;
		printf("%d\n",ans);
	}

	return 0;
}
