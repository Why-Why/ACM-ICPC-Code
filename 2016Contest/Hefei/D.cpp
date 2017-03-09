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
// Created Time  : 2016年11月17日 星期四 00时47分57秒
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

const long long INF=5000000000000000000LL;

long long a1,b1,a2,b2;
long long maxn,minn;

inline long long f1(long long x,long long y) {
	return b1*x*y+a1*x*x;
}

inline long long f2(long long x,long long y) {
	return (a1*b2+a2*b1)*x*y+a1*a2*x*x+b1*b2*y*y;
}

inline bool read(long long &ret) {
	int c=getchar(),sgn;
	if(c==-1) return 0;
	while(c!='-' && (c<'0' || c>'9')) {
		if(c==-1) return 0;
		c=getchar();
	}

	sgn=(c=='-') ? -1 : 1;
	ret=(c=='-') ? 0 : c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	ret*=sgn;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long (*f)(long long,long long);
	long long base,t;
	long long N,x,y;

	//while(~scanf("%I64 %I64 %I64 %I64",&a1,&b1,&a2,&b2)) {
	while(read(a1)) {
		read(b1); read(a2); read(b2);

		if(b1==0) {
			swap(a1,a2);
			swap(b1,b2);
		}

		if(b2==0) f=f1,base=abs(b1);
		else f=f2,base=abs(a2*b1-a1*b2);

		maxn=-INF;
		minn=INF;

		read(N);
		while(N--) {
			read(x); read(y);
			t=f(x,y);
			minn=min(minn,t);
			maxn=max(maxn,t);
		}

		printf("%.0f\n",(maxn-minn+0.0)/base);
	}

	return 0;
}
