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
// Created Time  : 2015年09月24日 星期四 16时22分20秒
// File Name     : C.cpp

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
	return x<-eps ? -1 : x>eps;
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

struct Line
{
	Point s,e;
	
	Line() {}
	Line(Point _s,Point _e):s(_s),e(_e) {}

	// 两直线求交点，第一个值为0表示重合，1表示平行，2表示相交。
	pair <int,Point> operator & (const Line &b) const
	{
		Point ret=s;

		if(sgn((s-e)^(b.s-b.e))==0)
			if(sgn((s-b.e)^(b.s-b.e))==0)
				return make_pair(0,ret);
			else
				return make_pair(1,ret);

		double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));

		ret.x+=(e.x-s.x)*t;
		ret.y+=(e.y-s.y)*t;

		return make_pair(2,ret);
	}
};

// 两点间距离。
double dist(const Point &a,const Point &b)
{
	return sqrt((a-b)*(a-b));
}

// 判断线段相交。
bool inter(Line &L1,Line &L2)
{
	return
		max(L1.s.x , L1.e.x) >= min(L2.s.x , L2.e.x) &&
		max(L2.s.x , L2.e.x) >= min(L1.s.x , L1.e.x) &&
		max(L1.s.y , L1.e.y) >= min(L2.s.y , L2.e.y) &&
		max(L2.s.y , L2.e.y) >= min(L1.s.y , L1.e.y) &&
		sgn((L2.s-L1.e)^(L1.s-L1.e)) * sgn((L2.e-L1.e)^(L1.s-L1.e)) <=0 &&
		sgn((L1.s-L2.e)^(L2.s-L2.e)) * sgn((L1.e-L2.e)^(L2.s-L2.e)) <=0;
}

bool Seg_inter_Line(Line L1,Line L2)		// 判断直线L1和线段L2是否相交。
{
	return sgn((L2.s-L1.e)^(L1.s-L1.e)) * sgn((L2.e-L1.e)^(L1.s-L1.e)) <= 0;
}

// 返回点到直线的最近点。
Point PointTOLine(Point &P,Line &L)
{
	Point ret;
	double t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));

	ret.x=L.s.x+(L.e.x-L.s.x)*t;
	ret.y=L.s.y+(L.e.y-L.s.y)*t;

	return ret;
}

// 返回点到线段的最近点。
Point PointToSeg(Point &P,Line &L)
{
	Point ret;
	double t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));

	if(t>=0 && t<=1)
	{
		ret.x=L.s.x+(L.e.x-L.s.x)*t;
		ret.y=L.s.y+(L.e.y-L.s.y)*t;
	}
	else
		if(dist(P,L.s) < dist(P,L.e))
			ret=L.s;
		else
			ret=L.e;

	return ret;
}

// 计算n边形的面积，编号 0~(n-1),注意P在多边形中必须是有序的。
double CalcArea(Point P[],int n)
{
	double ret=0;

	for(int i=0;i<n;++i)
		ret+=(P[i]^P[(i+1)%n])/2.0;

	return fabs(ret);
}

// 判断点在线段上。
bool OnSeg(Point &P,Line &L)			// 注意！！！当P不太准确时这个函数十分不准确。
{
	return
		sgn((L.s-P)^(L.e-P))==0 &&
		sgn((P.x-L.s.x)*(P.x-L.e.x)) <=0 &&
		sgn((P.y-L.s.y)*(P.y-L.e.y)) <=0;
}

// 判断a点是否在凸n边形内。
// 多边形为凸，点集逆时针排序(顺时针的话<0改为>0)。
// 返回 -1：在外面，0：在边界上，1：在里面。
int InConvexPoly(Point &a,Point P[],int n)
{
	for(int i=0;i<n;++i)
		if(sgn((P[i]-a)^(P[(i+1)%n]-a))<0)
			return -1;
		else if(OnSeg(a,Line(P[i],P[(i+1)%n])))
			return 0;

	return 1;
}

// 判断点a是否在任意n边形内。
// 射线法，点集>=3。
// 返回 -1：在外面，0：在边界上，1：在里面。
int InPoly(Point &a,Point P[],int n)
{
	int cou=0;
	Line ray,side;
	
	ray.s=a;
	ray.e.y=a.y;
	ray.e.x=-100000000000.0;

	for(int i=0;i<n;++i)
	{
		side.s=P[i];
		side.e=P[(i+1)%n];

		if(OnSeg(a,side))					// Maybe Wrong.
			return 0;

		if(sgn(side.s.y-side.e.y)==0)
			continue;

		if(OnSeg(side.s,ray))
		{
			if(sgn(side.s.y-side.e.y)>0)
				++cou;
		}
		else if(OnSeg(side.e,ray))
		{
			if(sgn(side.e.y-side.s.y)>0)
				++cou;
		}
		else if(inter(ray,side))
			++cou;
	}

	if(cou&1)
		return 1;
	return -1;
}

///////////////////////////////////////////////////

const int MaxN=200005;

struct Node
{
	double x,y;

	bool operator < (const Node & b) const
	{
		if(sgn(b.x)==0) return 0;
		if(sgn(x)==0) return sgn(b.x);
		return sgn(y*b.x-x*b.y)<0;
	}

	bool operator == (const Node & b) const
	{
		return sgn(y*b.x-x*b.y)==0;
	}
};

struct Range
{
	Node a,b;

	bool operator < (const Range & y) const
	{
		if(a==y.a) return b>y.b;
		return a<y.a;
	}
};

Range ran[MaxN];
int N;
double d;

Point P;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	double a;
	Node t1,t2,t3;

	while(~scanf("%d %lf",&N.&d))
	{
		for(int i=1;i<=N;++i)
		{
			scanf("%lf %lf",&P.x,&P.y);
			a=sqrt((P.x*P.x)+(P.y*P.y)-d*d);
			t1.x=d*P.x-a*P.y;
			t1.y=d*P.y+a*P.x;
			t2.x=d*P.x+a*P.y;
			t2.y=d*P.y-a*P.x;

			if(P.y>d
		}
	}
	
	return 0;
}
