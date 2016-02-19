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
// Created Time  : 2016年01月27日 星期三 16时19分41秒
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

const int MaxN=2005;
const int INF=0x3fffffff;

int N,K;
long long num[MaxN];
int dp[MaxN];

bool judge(long long x) {
	if(N-1<=K) return 1;
	dp[1]=0;
	for(int i=2;i<=N;++i) {
		dp[i]=i-1;
		for(int j=1;j<i;++j)
			if(abs(num[i]-num[j])<=x*(i-j))
				dp[i]=min(dp[i],dp[j]+i-j-1);
		if(dp[i]+N-i<=K) return 1;
	}
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;++i) scanf("%I64d",num+i);

	long long L=0,R=2000000000,M;

	while(R>L) {
		M=(L+R)>>1;
		if(judge(M)) R=M;
		else L=M+1;
	}

	printf("%I64d\n",L);
	
	return 0;
}
