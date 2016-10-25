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
// Created Time  : 2016年07月28日 星期四 14时04分58秒
// File Name     : 1005.cpp

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

int N;
long long x,y;

int p[20],a[20];
int pos[20],pcou;

long long inv(long long a,long long m) {
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

long long mul(long long a,long long b,long long m) {
	long long ret=0;
	a%=m;
	b%=m;

	while(b) {
		if(b&1) ret+=a;
		while(ret>=m) ret-=m;

		a<<=1;
		while(a>=m) a-=m;
		b>>=1;
	}

	return ret;
}

inline long long getnum(long long x,long long y) {
	long long M=1;
	for(int i=0;i<pcou;++i) M*=p[pos[i]];

	long long v=0,t;
	for(int i=0;i<pcou;++i) {
		t=inv(M/p[pos[i]]%p[pos[i]],p[pos[i]]);
		(v+=mul(a[pos[i]],M/p[pos[i]]*t,M))%=M;
	}

	if(y<v) return 0;

	x=(x+M-v-1)/M;
	y=(y-v)/M;

	if(x>y) return 0;
	return y-x+1;
}

inline long long getans(long long x,long long y) {
	x=(x+6)/7;
	y=y/7;

	if(y<x) return 0;
	long long ret=y-x+1;

	for(int s=1;s<(1<<N);++s) {
		pcou=0;
		for(int i=0;i<N;++i)
			if(s&(1<<i)) pos[pcou++]=i+1;

		if(pcou&1) ret-=getnum(x,y);
		else ret+=getnum(x,y);
	}

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %I64d %I64d",&N,&x,&y);
		for(int i=1;i<=N;++i) scanf("%d %d",p+i,a+i);
		for(int i=1;i<=N;++i) a[i]=inv(7%p[i],p[i])*a[i]%p[i];

		printf("Case #%d: %I64d\n",cas++,getans(x,y));
	}

	return 0;
}
