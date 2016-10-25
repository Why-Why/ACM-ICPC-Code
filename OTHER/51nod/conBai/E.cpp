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
// Created Time  : 2016年05月20日 星期五 19时41分10秒
// File Name     : E.cpp

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
int num[MaxN];
int Cj[MaxN<<1],Co[MaxN<<1];

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int C[],int x) {
	x+=N+1;
	for(;x<=((N<<1)|1);x+=lowbit(x)) ++C[x];
}

inline long long find(int C[],int x) {
	x+=N+1;
	long long ret=0;
	for(;x;x-=lowbit(x)) ret+=C[x];
	return ret;
}

inline long long getnum(long long M) {
	long long ret=0;
	int sum=0,d;
	for(int i=1;i<=((N<<1)|1);++i) Cj[i]=Co[i]=0;
	for(int i=1;i<=N;++i) {
		if(num[i]>=M) ++sum;
		d=sum+sum-i;
		if(i&1) {
			ret+=find(Co,d-1);
			if(d>=1) ++ret;
			add(Cj,d);
		}
		else {
			ret+=find(Cj,d-1);
			add(Co,d);
		}
	}
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %lld",&N,&K);
	for(int i=1;i<=N;++i) scanf("%d",num+i);

	long long L=0,R=2147483647LL,M,t;

	while(R>L) {
		M=(L+R+1)>>1;
		t=getnum(M);
		if(t<K) R=M-1;
		else L=M;
	}
	printf("%lld\n",L);
	
	return 0;
}
