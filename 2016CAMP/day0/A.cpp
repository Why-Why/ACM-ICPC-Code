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
// Created Time  : 2017年02月12日 星期日 09时55分13秒
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

int x[3],y[3];

double dist(int a,int b) {
	double dx=x[a]-x[b];
	double dy=y[a]-y[b];
	return sqrt(dx*dx+dy*dy);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);


	while(~scanf("%d %d",x,y)) {
		scanf("%d %d",x+1,y+1);
		scanf("%d %d",x+2,y+2);

		printf("%.9f\n",dist(0,2)+2.0*dist(1,2));
	}

	return 0;
}
