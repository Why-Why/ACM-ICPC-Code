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
// Created Time  : 2016年07月28日 星期四 23时36分13秒
// File Name     : 1010.cpp

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

const int MaxN=100005;

int N,num[MaxN];
int tnum[MaxN],tcou;

int C[1100005];

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int x,int d) {
	for(;x<=1100000;x+=lowbit(x)) C[x]=max(C[x],d);
}

inline int sum(int x) {
	int ret=0;
	for(;x;x-=lowbit(x)) ret=max(ret,C[x]);
	return ret;
}

int dp[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int cou;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		cou=0;
		tcou=0;
		memset(C,0,sizeof(C));

		for(int i=1;i<=N;++i) {
			scanf("%d",num+i);
			if(num[i]==0) ++cou;
			else tnum[++tcou]=num[i]-cou;
		}

		for(int i=1;i<=tcou;++i) {
			dp[i]=sum(tnum[i]+100000)+1;
			add(tnum[i]+100001,dp[i]);
		}

		int ans=cou;
		for(int i=1;i<=tcou;++i) ans=max(ans,dp[i]+cou);

		printf("Case #%d: %d\n",cas++,ans);
	}

	return 0;
}
