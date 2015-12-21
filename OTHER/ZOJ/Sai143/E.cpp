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
// Created Time  : 2015年10月15日 星期四 15时47分38秒
// File Name     : E.cpp

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

const double eps=1e-7;
const double PI=atan2(1.0,1.0)*4.0;

inline int sgn(double x)
{
	return x<-eps ? -1 : x>eps;
}

struct Point
{
	double x,y;
};

inline double dist(const Point &a,const Point &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

Point P[4];
double c1f,c2f;

double getaf(const Point &p1,const Point &p2,const Point &p)
{
	double ret=dist(p1,p)+dist(p2,p);
	ret=ret*ret/4.0;
	return ret;
}

double dist2(const Point &a,const Point &b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double getmidy(double x)
{
	if(sgn(P[0].x-P[1].x)==0) return (P[0].y+P[1].y)/2.0;
	double k=(P[1].y-P[0].y)/(P[1].x-P[0].x);
	return k*(x-P[0].x)+P[0].y;
}

void gety(Point &p1,Point &p2,double x,double b1f)
{
	p1.x=p2.x=x;
	double my=getmidy(x);
	double L=my,R=500.0,M;
	double a1d=2.0*sqrt(b1f+c1f);

	while(R-L>eps)
	{
		M=(L+R)/2.0;
		p1.y=M;
		if(dist(p1,P[0])+dist(p1,P[1])<=a1d) L=M;
		else R=M;
	}

	L=-500.0;
	R=my;

	while(R-L>eps)
	{
		M=(L+R)/2.0;
		p2.y=M;
		if(dist(p2,P[0])+dist(p2,P[1])<=a1d) R=M;
		else L=M;
	}
}

double geta(double x,double b1f)
{
	Point tp1,tp2;
	gety(tp1,tp2,x,b1f);

	return min(dist(tp1,P[2])+dist(tp1,P[3]),dist(tp2,P[2])+dist(tp2,P[3]))/2.0;
}

double getb2f(double lt1,double lt2,double b1f)
{
	double L=lt1,R=lt2,M1,M2;
	double a1,a2;

	while(R-L>1e-6)
	{
		M1=(R+2.0*L)/3.0;
		M2=(2.0*R+L)/3.0;

		a1=geta(M1,b1f);
		a2=geta(M2,b1f);

		if(a1>a2) L=M1;
		else R=M2;
	}
	return a1*a1-c2f;
}

double getlt1(double b1f)
{
	double L=-500.0,R=min(P[0].x,P[1].x),M;
	double a1f=b1f+c1f;
	Point tp;
	tp.y=P[0].y;

	while(R-L>eps)
	{
		M=(L+R)/2.0;
		tp.x=2.0*M-P[0].x;
		if(a1f>=dist2(tp,P[1])/4.0) R=M;
		else L=M;
	}
	return L;
}

double getlt2(double b1f)
{
	double L=max(P[0].x,P[1].x),R=500.0,M;
	double a1f=b1f+c1f;
	Point tp;
	tp.y=P[0].y;

	while(R-L>eps)
	{
		M=(L+R)/2.0;
		tp.x=2.0*M-P[0].x;
		if(a1f>=dist2(tp,P[1])/4.0) L=M;
		else R=M;
	}
	return L;
}

double get2area(double b1f)
{
	double lt1=getlt1(b1f),lt2=getlt2(b1f);
	double b2f=getb2f(lt1,lt2,b1f);
	return (c1f+b1f)*b1f*(c2f+b2f)*b2f;
}

double getans()
{
	double L=0,R,M1,M2;
	double s1=0,s2=0;
	R=min(getaf(P[0],P[1],P[2]),getaf(P[0],P[1],P[3]))-c1f;

	while(R-L>1e-6)
	{
		M1=(R+2.0*L)/3.0;
		M2=(2.0*R+L)/3.0;

		s1=get2area(M1);
		s2=get2area(M2);

		if(s1>s2) R=M2;
		else L=M1;
	}
	return PI*PI*sqrt(s1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		for(int i=0;i<4;++i) scanf("%lf %lf",&P[i].x,&P[i].y);
		c1f=(P[1].x-P[0].x)*(P[1].x-P[0].x)+(P[1].y-P[0].y)*(P[1].y-P[0].y);
		c1f/=4.0;
		c2f=(P[3].x-P[2].x)*(P[3].x-P[2].x)+(P[3].y-P[2].y)*(P[3].y-P[2].y);
		c2f/=4.0;
		printf("%.10f\n",getans());
	}
	
	return 0;
}
