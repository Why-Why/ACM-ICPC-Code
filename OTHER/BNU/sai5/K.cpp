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
// Created Time  : 2015年10月07日 星期三 11时05分57秒
// File Name     : K.cpp

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

const double eps=1e-8;
const double PI=acos(-1.0);

inline int sgn(double x)
{
	if(fabs(x)<eps)
		return 0;

	if(x<0)
		return -1;

	return 1;
}

struct Point
{
	double x,y;
	
	Point() {}
	Point(double _x,double _y):x(_x),y(_y) {}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	double operator ^ (const Point &b) const	// 叉乘。
	{
		return x*b.y-y*b.x;
	}

	double operator * (const Point &b) const	// 点乘。
	{
		return x*b.x+y*b.y;
	}

	void trangXY(double B)				// 绕原点旋转B弧度。
	{
		double tx=x,ty=y;
		
		x=tx*cos(B)-ty*sin(B);
		y=tx*sin(B)+ty*cos(B);
	}
};

Point P[4];

double dist(Point &a,Point &b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool bian()
{
	double D[4];
	for(int i=0;i<4;++i) D[i]=dist(P[i],P[(i+1)%4]);
	for(int i=1;i<4;++i)
		if(sgn(D[i]-D[0])) return 0;
	return 1;
}

bool jiao()
{
	Point tp[4];

	for(int i=0;i<4;++i)
		tp[i]=P[(i+1)%4]-P[i];

	for(int i=0;i<4;++i)
		if(sgn(tp[i]*tp[(i+1)%4]))
			return 0;
	return 1;
}

bool ping()
{
	if(sgn((P[1]-P[0])^(P[3]-P[2]))) return 0;
	if(sgn((P[2]-P[1])^(P[0]-P[3]))) return 0;
	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	bool ok1,ok2,ok3;
	
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<4;++i)
			scanf("%lf %lf",&P[i].x,&P[i].y);

		ok1=bian();
		ok2=jiao();
		ok3=ping();

		printf("Case #%d: ",cas++);
		if(ok1 && ok2) puts("Square");
		else if(ok1 && !ok2) puts("Diamond");
		else if(!ok1 && ok2) puts("Rectangle");
		else if(!ok1 && !ok2 && ok3) puts("Parallelogram");
		else puts("Others");
	}
	
	return 0;
}
