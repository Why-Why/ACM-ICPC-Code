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
// Created Time  : 2015年06月10日 星期三 22时54分37秒
// File Name     : 1408.cpp

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
};

struct Line
{
	Point s,e;

	Line() {}
	Line(const Point &a,const Point &b)
	{
		s=a;
		e=b;
	}

	Point operator & (const Line &b) const
	{
		Point ret=s;
		double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));

		ret.x+=(e.x-s.x)*t;
		ret.y+=(e.y-s.y)*t;

		return ret;
	}
};

double CalArea(Point P[],int n)
{
	double ret=0;

	for(int i=0;i<n;++i)
		ret+=(P[i]^P[(i+1)%n])/2.0;

	return fabs(ret);
}

int N;
Line heng[40],shu[40];

double getans()
{
	Point tp[10];
	double ret=0;

	for(int i=0;i<N-1;++i)
		for(int j=0;j<N-1;++j)
		{
			tp[0]=heng[i]&shu[j];
			tp[1]=heng[i]&shu[j+1];
			tp[2]=heng[i+1]&shu[j+1];
			tp[3]=heng[i+1]&shu[j];

			ret=max(ret,CalArea(tp,4));
		}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double t2;

	while(~scanf("%d",&N) && N)
	{
		for(int i=1;i<=N;++i)
		{
			scanf("%lf",&shu[i].s.x);
			shu[i].s.y=0.0;
		}

		for(int i=1;i<=N;++i)
		{
			scanf("%lf",&shu[i].e.x);
			shu[i].e.y=1.0;
		}

		shu[0].s.x=shu[0].e.x=0;
		shu[0].s.y=shu[N+1].s.y=0;
		shu[0].e.y=shu[N+1].e.y=1;
		shu[N+1].s.x=shu[N+1].e.x=1;

		for(int i=1;i<=N;++i)
		{
			scanf("%lf",&heng[i].s.y);
			heng[i].s.x=0;
		}

		for(int i=1;i<=N;++i)
		{
			scanf("%lf",&heng[i].e.y);
			heng[i].e.x=1;
		}

		heng[0].s.y=heng[0].e.y=0;
		heng[N+1].s.y=heng[N+1].e.y=1;
		heng[0].s.x=heng[N+1].s.x=0;
		heng[0].e.x=heng[N+1].e.x=1;

		N+=2;

		printf("%.6f\n",getans());
	}
	
	return 0;
}
