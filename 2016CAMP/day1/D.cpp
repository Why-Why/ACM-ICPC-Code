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
// Created Time  : 2017年02月15日 星期三 16时18分55秒
// File Name     : D.cpp

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
#include <bitset>

using namespace std;

const int MaxN=360363*15;

int N,a[17];
int k[17],kv[17],kN;
int r[17],rv[17],rN;

bitset <MaxN> dp[16],ans1,ans2;

long long gcd(long long a,long long b) {
	if(!a) return b;
	return gcd(b%a,a);
}

inline long long lcm(long long a,long long b) {
	long long t=gcd(a,b);
	return a/t*b;
}

void getans(int N,int a[],bitset <MaxN> & ret) {
	dp[0].reset();
	dp[0].set(0);

	for(int i=1;i<=N;++i)
		for(int j=0;j<=a[i];++j)
			dp[i]|=dp[i-1]<<(j*i);

	ret=dp[N];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i) scanf("%d",a+i);

		long long L=1;
		for(int i=2;i<=N;++i) L=lcm(L,i);

		kN=rN=0;
		for(int i=1;i<=N;++i) {
			if(a[i]>=L-1) {
				k[++kN]=(a[i]-L+1)/L;
				kv[kN]=i;

				r[++rN]=a[i]-(k[kN]*L+L-1);
				rv[rN]=i;
			}
			else {
				r[++rN]=a[i];
				rv[rN]=i;
			}
		}


	}

	return 0;
}
