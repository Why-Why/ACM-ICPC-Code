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
// Created Time  : 2016年11月13日 星期日 17时34分15秒
// File Name     : D_1.cpp

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

long long gcd(long long a,long long b) {
	if(!a) return b;
	return gcd(b%a,a);
}

long long getS(long long x) {
	long long t=sqrt(double(x)),tt;

	for(int i=-2;i<=2;++i) {
		tt=t+i;
		if(tt>=0 && tt*tt==x) return tt;			// !!!
	}

	return -1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long a,b,t,m,n,dit,sdit,x,y;

	while(~scanf("%I64d %I64d",&a,&b)) {
		if(a==b) {
			printf("0 %I64d\n",a);
			continue;
		}

		t=gcd(a,b);
		a/=t;
		b/=t;

		m=a;
		dit=a*a-4*b;
		sdit=getS(dit);

		if(sdit==-1 || (a-sdit)%2) {
			puts("No Solution");
			continue;
		}

		n=(a-sdit)/2;

		x=n*t;
		y=a*t-x;

		printf("%I64d %I64d\n",x,y);
	}

	return 0;
}
