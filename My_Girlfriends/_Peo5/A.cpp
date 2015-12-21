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
//       ┃       ┗━━━┓点我点我。
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年10月09日 星期五 21时51分18秒
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

const int MaxN=5005;

struct Point
{
	double x,y,z;
}P[MaxN];

int N;

double dist(const Point &a,const Point &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double minn=1e100;

	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%lf %lf %lf",&P[i].x,&P[i].y,&P[i].z);
	for(int i=2;i<=N;++i)
		for(int j=i+1;j<=N;++j)
			minn=min(minn,dist(P[1],P[i])+dist(P[1],P[j])+dist(P[i],P[j]));
	printf("%.10f\n",minn/2.0);
	
	return 0;
}
