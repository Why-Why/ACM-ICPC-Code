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
// Created Time  : 2016年10月02日 星期日 16时22分08秒
// File Name     : I.cpp

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

long long ans[10];
int N;
int a[10],b[10];

int num[10];
int r[10];

long long dp[7][1003];

int getlis() {
	int dp[10]={};
	int maxn,ret=0;

	for(int i=1;i<=N;++i) {
		maxn=0;
		for(int j=1;j<i;++j)
			if(num[j]<num[i]) maxn=max(maxn,dp[j]);
		dp[i]=maxn+1;

		ret=max(ret,dp[i]);
	}

	return ret;
}

void getans() {
	for(int i=1;i<=N;++i) r[num[i]]=i;
	//memset(dp,0,sizeof(dp));

	for(int i=0;i<=1000;++i) dp[1][i]=0;
	for(int i=a[r[1]];i<=b[r[1]];++i) dp[1][i]=1;
	for(int i=1;i<=1000;++i) dp[1][i]+=dp[1][i-1];

	int t;

	for(int i=2;i<=N;++i) {
		for(int j=0;j<=1000;++j) dp[i][j]=0;
		for(int j=a[r[i]];j<=b[r[i]];++j) {
			if(r[i-1]>r[i]) t=0;
			else t=1;

			dp[i][j]=dp[i-1][j-t];
		}

		for(int j=1;j<=1000;++j) dp[i][j]+=dp[i][j-1];
	}

	ans[getlis()]+=dp[N][1000];
}

void dfs(int p,int sta) {
	if(p>N) {
		getans();
		return;
	}

	for(int i=1;i<=N;++i)
		if(sta&(1<<i));
		else {
			num[p]=i;
			dfs(p+1,sta|(1<<i));
		}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d %d",a+i,b+i);

	dfs(1,0);

	for(int i=1;i<N;++i) printf("%lld ",ans[i]);
	printf("%lld\n",ans[N]);

	return 0;
}
