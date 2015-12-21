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
// Created Time  : 2015年09月26日 星期六 14时35分57秒
// File Name     : 1009.cpp

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

double dist(double x1,double y1,double x2,double y2)
{
	double dx=x2-x1,dy=y2-y1;
	return sqrt(dx*dx+dy*dy);
}

double getans(double a,double b)
{
	double c=sqrt(a*a-b*b);
	double R=a*b/c;
	double ang=atan2(c,b)*2.0;

	return c+R*ang;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	double x1,x2,x3,y1,y2,y3;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
		printf("Case #%d: %.4f\n",cas++,getans(dist(x1,y1,x2,y2),dist(x2,y2,x3,y3)/2.0));
	}
	
	return 0;
}
