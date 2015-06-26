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
// Created Time  : 2015年05月30日 星期六 12时45分44秒
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

const double eps=1e-8;
const double PI=atan2(1.0,1.0)*4.0;

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
	double ang;

	int id;

	Line() {}

	Line(Point a,Point b,int c)
	{
		s=a;
		e=b;

		id=c;

		ang=atan2(e.y-s.y,e.x-s.x);
	}

	Point operator & (const Line &b) const
	{
		Point ret=s;

		double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));

		ret.x+=(e.x-s.x)*t;
		ret.y+=(e.y-s.y)*t;

		return ret;
	}

	bool operator < (const Line &b) const
	{
		if(fabs(ang-b.ang)>eps)
			return ang<b.ang;

		return ((s-b.s)^(b.e-b.s))<0;
	}
};

const int MaxN=200005;

Line que[MaxN];
int first,last;

int ans[MaxN];

// line从0开始，有n个。
int HPI(Line line[],int n,Point ret[])
{
	int cou=1;
	
	first=last=0;
	
	sort(line,line+n);

	for(int i=1;i<n;++i)
		if(fabs(line[i].ang>line[i-1].ang)>eps)
			line[cou++]=line[i];

	que[last++]=line[0];
	que[last++]=line[1];

	for(int i=2;i<cou;++i)
	{
		if(sgn((que[last-1].e-que[last-1].s)^(que[last-2].e-que[last-2].s))==0 || sgn((que[first].e-que[first].s)^(que[first+1].e-que[first+1].s))==0)
			return 0;

		while(first+1<last && (((que[last-1] & que[last-2])-line[i].s)^(line[i].e-line[i].s))>eps)
			--last;

		while(first+1<last && (((que[first] & que[first+1])-line[i].s)^(line[i].e-line[i].s))>eps)
			++first;

		que[last++]=line[i];
	}

	while(first+1<last && (((que[last-1] & que[last-2])-que[first].s)^(que[first].e-que[first].s))>eps)
		--last;

	while(first+1<last && (((que[first] & que[first+1])-que[last-1].s)^(que[last-1].e-que[last-1].s))>eps)
		++first;

	if(last<=first+2)
		return 0;

	cou=0;

	for(int i=first;i<last;++i)
		ans[cou++]=que[i].id;

	sort(ans,ans+cou);

	for(int i=0;i<cou;++i)
		if(ans[i])
			printf("%d ",ans[i]);
	puts("");

	cou=0;

	for(int i=first;i<last-1;++i)
		ret[cou++]=que[i] & que[i+1];

	if(first<last-2)
		ret[cou++]=que[first] & que[last-1];

	return cou;
}

Line L[MaxN+10];
Point tret[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	int cou=0;
	double s,r;

	L[cou++]=Line(Point(0.0,0.0),Point(100.0,0.0),0);
	L[cou++]=Line(Point(100.0,0.0),Point(100.0,100.0),0);
	L[cou++]=Line(Point(0.0,100.0),Point(0.0,0.0),0);

	scanf("%d",&n);

	for(int i=1;i<=n;++i)
	{
		scanf("%lf %lf",&s,&r);
		L[cou++]=Line(Point(100.0,100000000.0/r),Point(0.0,100000000.0/s),i);
	}

	HPI(L,cou,tret);
	
	return 0;
}
