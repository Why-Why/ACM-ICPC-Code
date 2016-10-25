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
// Created Time  : 2016年09月16日 星期五 00时15分07秒
// File Name     : A_1.cpp

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
	long long ret=1;
	for(;n;n>>=1,(a*=a)%=mod) if(n&1) (ret*=a)%=mod;
	return ret;
}

long long inv(long long a,long long m) {
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,M;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		printf("%d\n",(int)((_pow(M,N+1)+mod-1LL)%mod*inv(M-1,mod)%mod));
	}

	return 0;
}
