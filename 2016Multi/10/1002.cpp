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
// Created Time  : 2016年08月18日 星期四 13时51分31秒
// File Name     : 1002.cpp

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

double dis(double x1,double y1,double x2,double y2) {
	double dx=x1-x2;
	double dy=y1-y2;
	return sqrt(dx*dx+dy*dy);
}

inline bool judge(double L,double x,double y) {
	if(dis(x,y,L/2,L/2)>L/2) return 0;
	if(dis(x,y,L,0)>L) return 1;
	if(dis(x,y,0,L)>L) return 1;
	return 0;
}

double func(double x,double L) {
	return x/2.0*sqrt(L*L/4-x*x)+L*L/8*asin(2*x/L)-x/2*sqrt(L*L-x*x)-L*L/2*asin(x/L)+sqrt(2.0)/2*L*x;
}

double getnum(double L) {
	return func(L*sqrt(7.0/32.0),L)*4.0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,l;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&l);
		printf("%.2f\n",getnum(l));
	}

	return 0;
}
