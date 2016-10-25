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
// Created Time  : 2016年09月18日 星期日 14时35分52秒
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

const int MaxN=333;

long long dp[MaxN][MaxN];
bool can[MaxN][MaxN];
int N;
int key[MaxN],val[MaxN];

int gcd(int a,int b) {
	if(!a) return b;
	return gcd(b%a,a);
}

int remgcd[MaxN][MaxN];

inline void getans(int L,int R) {
	long long t=0;

	if(remgcd[L][R]!=1 && (L+1==R || can[L+1][R-1])) {
		can[L][R]=1;
		t=max(t,val[L]+(long long)val[R]+dp[L+1][R-1]);
	}

	for(int i=L;i<R;++i) {
		if(can[L][i] && can[i+1][R]) can[L][R]=1;
		t=max(t,dp[L][i]+dp[i+1][R]);
	}

	dp[L][R]=t;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);

		for(int i=1;i<=N;++i) scanf("%d",key+i);
		for(int i=1;i<=N;++i) scanf("%d",val+i);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j) {
				dp[i][j]=can[i][j]=0;

				remgcd[i][j]=gcd(key[i],key[j]);
			}

		//for(int i=1;i<=N;++i) dp[i][i]=0,can[i][i]=0;

		for(int len=2;len<=N;++len)
			for(int i=1;i+len-1<=N;++i)
				getans(i,i+len-1);

		printf("%I64d\n",dp[1][N]);
	}

	return 0;
}
