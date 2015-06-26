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
// Created Time  : 2015年06月09日 星期二 22时57分36秒
// File Name     : 1039.cpp

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

bool Seg_inter_Line(const Line &L1,const Line &L2)
{
	return sgn((L2.s-L1.e)^(L1.s-L1.e))*sgn((L2.e-L1.e)^(L1.s-L1.e))<0;
}

bool Seg_inter_Line1(const Line &L1,const Line &L2)
{
	return sgn((L2.s-L1.e)^(L1.s-L1.e))*sgn((L2.e-L1.e)^(L1.s-L1.e))<=0;
}

int N;
Point P[30],P1[30];
Line TL[30],TL1[30];

inline double getnum(Line L)
{
	if(Seg_inter_Line1(L,Line(P[1],P1[1]))==0)
		return 0;

	for(int i=1;i<N;++i)
	{
		if(Seg_inter_Line(L,TL[i]))
			return (L&TL[i]).x;

		if(Seg_inter_Line(L,TL1[i]))
			return (L&TL1[i]).x;
	}

	return P[N].x;
}

double getans()
{
	double ans=0.0;
	double temp;

	for(int i=1;i<=N;++i)
		for(int j=i+1;j<=N;++j)
		{
			ans=max(ans,getnum(Line(P[i],P[j])));
			cout<<ans<<endl;
			ans=max(ans,getnum(Line(P[i],P1[j])));
			ans=max(ans,getnum(Line(P1[i],P[j])));
			ans=max(ans,getnum(Line(P1[i],P1[j])));

		}

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double ans;

	while(~scanf("%d",&N) && N)
	{
		for(int i=1;i<=N;++i)
		{
			scanf("%lf %lf",&P[i].x,&P[i].y);
			P1[i].x=P[i].x;
			P1[i].y=P[i].y+1.0;
		}

		for(int i=1;i<N;++i)
		{
			TL[i].s=P[i];
			TL[i].e=P[i+1];
			TL1[i].s=P1[i];
			TL1[i].e=P1[i+1];
		}

		ans=getans();

		if(sgn(ans-P[N].x)>=0)
			puts("Through all the pipe.");
		else
			printf("%.2f\n",ans+eps);
	}
	
	return 0;
}
