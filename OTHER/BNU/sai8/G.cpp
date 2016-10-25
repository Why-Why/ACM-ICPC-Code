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
// Created Time  : 2016年10月07日 星期五 12时37分14秒
// File Name     : G.cpp

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

const double PI=atan2(1.0,1.0)*4.0;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double S;

	while(~scanf("%lf",&S)) {
		double r=sqrt(S)/sqrt(PI)*0.5;
		double l=S/(PI*r)-r;
		double h=sqrt(l*l-r*r);
		double V=PI*r*r*h/3.0;

		printf("%.2f\n%.2f\n%.2f\n",V,h,r);
	}

	return 0;
}
