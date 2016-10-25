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
// Created Time  : 2016年09月03日 星期六 16时14分51秒
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

const int MaxN=100005;

long long N,S;
int x[MaxN];
long long a01,a10,a11,a00;

void show() {
	for(int i=0;i<=N;++i) {
		for(int j=0;j<x[i];++j) putchar('1');
		if(i<N) putchar('0');
	}
	puts("");
}

inline long long getsqrt(long long x) {
	long long t=sqrt(x);
	if(t*t==x) return t;
	++t;
	if(t*t==x) return t;
	t-=2;
	if(t*t==x) return t;
	return -1;
}

long long getnum(long long a) {
	long long t=getsqrt(1+8*a);
	if(t==-1) return -1;
	if((t+1)%2) return -1;

	return (t+1)/2;
}

bool getans() {
	memset(x,0,sizeof(x));

	if(N<0 || S<0 || (N*S!=a10+a01))
		return 0;

	if(N==0) {
		if(S==0) return 0;
		x[0]=S;
		show();
		return 1;
	}

	long long sum=S,a=a10;

	for(int i=0;i<N;++i) {
		x[i]=min(a/(N-i),sum);
		sum-=x[i];
		a-=x[i]*(N-i);
	}
	x[N]=sum;

	show();

	return 1;
}

int MAIN() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>a00>>a01>>a10>>a11;

	N=getnum(a00);
	S=getnum(a11);
	if(getans()) return 0;

	if(a00==0) N=0;
	if(getans()) return 0;

	N=getnum(a00);
	if(a11==0) S=0;
	if(getans()) return 0;

	puts("Impossible");

	return 0;
}

int main() {
	MAIN();
	return 0;
}
