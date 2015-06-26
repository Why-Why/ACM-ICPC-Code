// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年06月11日 星期四 23时36分25秒
// File Name     : 1584.cpp

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

const double eps=1e-10;

inline int sgn(double x)
{
	return x<-eps ? -1 : x>eps;
}

struct Point
{
	double x,y;

	Point() {}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	double operator ^ (const Point &b) const
	{
		return x*b.y-y*b.x;
	}

	double operator * (const Point &b) const
	{
		return x*b.x+y*b.y;
	}
};

struct Line
{
	Point s,e;

	Line() {}
	Line(const Point &a,const Point &b):s(a),e(b) {}
};

Point peg;
double R;
Point P[300];
int N;

bool judge()
{
	bool s[3]={0};

	for(int i=0;i<N;++i)
	{
		s[sgn((P[(i+1)%N]-P[i])^(P[(i+2)%N]-P[i]))+1]=1;

		if(s[0] && s[2])
			return 1;
	}

	return 0;
}

double dist(const Point &a,const Point &b)
{
	return sqrt((a-b)*(a-b));
}

Point PointToSeg(const Point &P,const Line &L)
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

bool OnSeg(const Point &P,const Line &L)
{
	return
		sgn((L.s-P)^(L.e-P))==0 &&
		sgn((P.x-L.s.x)*(P.x-L.e.x)) <=0 &&
		sgn((P.y-L.s.y)*(P.y-L.e.y)) <=0;
}

int InConvexPoly(Point &a,Point P[],int n)
{
	bool s[2]={0};

	for(int i=0;i<n;++i)
		if(sgn((P[i]-a)^(P[(i+1)%n]-a))<0)
			s[0]=1;
		else if(OnSeg(a,Line(P[i],P[(i+1)%n])))
			return 0;
		else
			s[1]=1;

	if(s[0]&s[1])
		return 0;

	return 1;
}

int getans()
{
	if(judge())
		return 0;

	if(InConvexPoly(peg,P,N)!=1)
		return 2;

	Point tP;

	for(int i=0;i<N;++i)
	{
		tP=PointToSeg(peg,Line(P[i],P[(i+1)%N]));

		if(sgn(dist(tP,peg)-R)<0)
			return 2;
	}

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N) && N>=3)
	{
		scanf("%lf %lf %lf",&R,&peg.x,&peg.y);

		for(int i=0;i<N;++i)
			scanf("%lf %lf",&P[i].x,&P[i].y);

		int ans=getans();

		if(ans==0)
			puts("HOLE IS ILL-FORMED");
		else if(ans==1)
			puts("PEG WILL FIT");
		else
			puts("PEG WILL NOT FIT");
	}
	
	return 0;
}
