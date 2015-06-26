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
// Created Time  : 2015年05月31日 星期日 11时00分11秒
// File Name     : 2451.cpp

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

inline int sgn(double x)
{
	return x<-eps ? -1 : x>eps;
}

struct Point
{
	double x,y;

	Point() {}
	Point(double a,double b):x(a),y(b)
	{}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	double operator ^ (const Point &b) const
	{
		return x*b.y-y*b.x;
	}
};

struct Line
{
	Point s,e;
	double ang;

	Line() {}
	Line(const Point &a,const Point &b):s(a),e(b)
	{
		ang=atan2(e.y-s.y,e.x-s.x);
	}

	Point operator & (const Line &b) const
	{
		Point ret=s;
		double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));

		ret.x+=t*(e.x-s.x);
		ret.y+=t*(e.y-s.y);

		return ret;
	}

	bool operator < (const Line &b) const
	{
		if(sgn(ang-b.ang))
			return ang<b.ang;

		return ((s-b.s)^(b.e-b.s))<0;
	}
};

const int MaxN=20010;

Line que[MaxN];
int first,last;

inline bool OnLeft(const Point &a,const Line &b)
{
	return sgn((b.e-b.s)^(a-b.s))>0;
}

// line从0开始，ret从0开始。

int HPI(Line line[],int N,Point ret[])
{
	int cou=1;
	int retnum=0;

	sort(line,line+N);

	for(int i=1;i<N;++i)
		if(sgn(line[i].ang-line[i-1].ang))
			line[cou++]=line[i];

	first=last=0;
	que[last++]=line[0];
	que[last++]=line[1];				// cou>1;

	for(int i=2;i<cou;++i)
	{
		if(sgn((que[last-1].e-que[last-1].s)^(que[last-2].e-que[last-2].s))==0 || sgn((que[first].e-que[first].s)^(que[first+1].e-que[first+1].s))==0)
			return 0;

		while(first<last-1 && !OnLeft(que[last-1] & que[last-2],line[i]))
			--last;

		while(first<last-1 && !OnLeft(que[first] & que[first+1],line[i]))
			++first;

		que[last++]=line[i];
	}

	while(first<last-1 && !OnLeft(que[last-1] & que[last-2],que[first]))
		--last;

	while(first<last-1 && !OnLeft(que[first] & que[first+1],que[last-1]))
		++first;

	if(last<=first+2)
		return 0;

	for(int i=first;i<last-1;++i)
		ret[retnum++]=que[i] & que[i+1];

	if(first<last-2)
		ret[retnum++]=que[first] & que[last-1];

	return retnum;
}

int N;
Line line[MaxN+10];
Point ans[MaxN+10];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double a,b,c,d;

	scanf("%d",&N);

	for(int i=0;i<N;++i)
	{
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		line[i]=Line(Point(a,b),Point(c,d));
	}

	line[N++]=Line(Point(0.0,0.0),Point(10000.0,0.0));
	line[N++]=Line(Point(10000.0,0.0),Point(10000.0,10000.0));
	line[N++]=Line(Point(10000.0,10000.0),Point(0.0,10000.0));
	line[N++]=Line(Point(0.0,10000.0),Point(0.0,0.0));

	N=HPI(line,N,ans);

	double ret=0;

	for(int i=0;i<N;++i)
		ret+=(ans[i]^ans[(i+1)%N])/2;

	printf("%.1f\n",ret);
	
	return 0;
}
