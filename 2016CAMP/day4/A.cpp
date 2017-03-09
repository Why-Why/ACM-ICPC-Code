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
// Created Time  : 2017年02月16日 星期四 11时10分02秒
// File Name     : A.cpp

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

const double eps=1e-3;

double h,a,b,c,va,vb,vc;

inline double cal(double x,double y) {
	return sqrt(c*c+(h-y)*(h-y))/vc+sqrt(b*b+(y-x)*(y-x))/vb;
}

inline double cal(double M) {
	double L=M,R=h,M1,M2;

	for(int i=1;i<=20;++i) {
		M1=(L+L+R)/3.0;
		M2=(L+R+R)/3.0;

		if(cal(M,M1)<cal(M,M2)) R=M2;
		else L=M1;
	}

	return cal(M,L)+sqrt(a*a+M*M)/va;
}

inline int read() {
	char c=0;
	while(c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	T=read();

	while(T--) {
		h=read(); a=read(); b=read(); c=read(); va=read(); vb=read(); vc=read();

		double L=0,R=h,M1,M2;

		for(int i=1;i<=20;++i) {
			M1=(L+L+R)/3.0;
			M2=(L+R+R)/3.0;

			if(cal(M1)<cal(M2)) R=M2;
			else L=M1;
		}

		printf("%.10f\n",cal(L));
	}

	return 0;
}
