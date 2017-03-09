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
// Created Time  : 2017年02月16日 星期四 12时53分41秒
// File Name     : F.cpp

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

const double eps=1e-12;

double x[1003],y[1003];
int N;

inline double dist(double x,double y) {
	return sqrt(x*x+y*y);
}

inline double cal1(double x0,double y0) {
	double ans=0;

	for(int i=1;i<=N;++i)
		ans+=dist(x0-x[i],y0-y[i]);

	return ans;
}

inline double cal(double x,double & ay) {
	double L=-1000006.0,R=1000006.0,M1,M2;

	for(int i=1;i<=80;++i) {
		M1=(L+L+R)/3.0;
		M2=(L+R+R)/3.0;

		if(cal1(x,M1)<cal1(x,M2)) R=M2;
		else L=M1;
	}

	ay=L;
	return cal1(x,L);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	double ay;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%lf %lf",x+i,y+i);

		double L=-1000006.0,R=1000006.0,M1,M2;

		for(int i=1;i<=80;++i) {
			M1=(L+L+R)/3.0;
			M2=(L+R+R)/3.0;

			if(cal(M1,ay)<cal(M2,ay)) R=M2;
			else L=M1;
		}

		cal(L,ay);
		printf("%.10f %.10f\n",L,ay);
	}

	return 0;
}
