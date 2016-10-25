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
// Created Time  : 2016年05月06日 星期五 00时16分34秒
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

using namespace std;

const int MaxN=100005;

int N;
long long K;
long long a[MaxN],b[MaxN];

inline bool judge(long long M) {
	long long sum=K;

	for(int i=1;i<=N;++i) {
		if(a[i]*M>b[i]) sum-=(a[i]*M-b[i]);
		if(sum<0) return 0;
	}
	if(sum<0) return 0;
	return 1;
}

long long getans() {
	long long L=0,R=2000000000,M;

	while(R>L) {
		M=(L+R+1)>>1;
		if(judge(M)) L=M;
		else R=M-1;
	}
	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %lld",&N,&K);
	for(int i=1;i<=N;++i) scanf("%lld",a+i);
	for(int i=1;i<=N;++i) scanf("%lld",b+i);

	printf("%lld\n",getans());
	
	return 0;
}
