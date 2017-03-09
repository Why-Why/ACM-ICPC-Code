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
// Created Time  : 2017年02月21日 星期二 17时13分30秒
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

inline long long _pow(long long a,long long n) {
	a%=mod;
	long long ret=1;

	for(;n;n>>=1,(a*=a)%=mod)
		if(n&1) (ret*=a)%=mod;

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int N,M,K;

	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&N,&M,&K);

		long long sum=0;

		for(int i=1;i<=K;++i) (sum+=_pow(i-1,N+M-2)*_pow(K,N*M-(N+M-1))%mod)%=mod;
		(sum*=N*M)%=mod;
		(sum+=_pow(K,N*M))%=mod;

		printf("Case #%d: %d\n",cas++,(int)sum);
	}

	return 0;
}
