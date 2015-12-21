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
// Created Time  : 2015年09月22日 星期二 19时37分06秒
// File Name     : E_1.cpp

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

	double Angle(Point &b)
	{
		return atan2(b.y-y,b.x-x);
	}
};

struct Line
{
	Point s,e;
	
	Line() {}
	Line(Point _s,Point _e):s(_s),e(_e) {}
};

inline double dist(const Point &a,const Point &b)
{
	return sqrt((a-b)*(a-b));
}

Point Inter(Point u1,Point u2,Point v1,Point v2)
{
	Point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));

	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;

	return ret;
}

bool Inter(Line &L1,Line &L2)
{
	return
		max(L1.s.x , L1.e.x) >= min(L2.s.x , L2.e.x) &&
		max(L2.s.x , L2.e.x) >= min(L1.s.x , L1.e.x) &&
		max(L1.s.y , L1.e.y) >= min(L2.s.y , L2.e.y) &&
		max(L2.s.y , L2.e.y) >= min(L1.s.y , L1.e.y) &&
		sgn((L2.s-L1.e)^(L1.s-L1.e)) * sgn((L2.e-L1.e)^(L1.s-L1.e)) <=0 &&
		sgn((L1.s-L2.e)^(L2.s-L2.e)) * sgn((L1.e-L2.e)^(L2.s-L2.e)) <=0;
}

bool OnSeg(const Point &P,const Line &L)
{
	return
		sgn((L.s-P)^(L.e-P))==0 &&
		sgn((P.x-L.s.x)*(P.x-L.e.x)) <=0 &&
		sgn((P.y-L.s.y)*(P.y-L.e.y)) <=0;
}

int InPoly(const Point &a,Point P[],int n)
{
	int cou=0;
	Line ray,side;
	
	ray.s=a;
	ray.e.y=a.y;
	ray.e.x=-1e100;

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
		else if(Inter(ray,side))
			++cou;
	}

	if(cou&1)
		return 1;
	return -1;
}

inline double InCircle(const Point & c,double R,const Point & b)
{
	return (c-b)*(c-b)<=R*R;
}

void Line_I_Circle(Point c,double r,Point l1,Point l2,Point& p1,Point& p2)
{
	Point p=c;
	double t;

	p.x+=l1.y-l2.y;
	p.y+=l2.x-l1.x;
	p=Inter(p,c,l1,l2);
	t=sqrt(r*r-dist(p,c)*dist(p,c))/dist(l1,l2);

	p1.x=p.x+(l2.x-l1.x)*t;
	p1.y=p.y+(l2.y-l1.y)*t;
	p2.x=p.x-(l2.x-l1.x)*t;
	p2.y=p.y-(l2.y-l1.y)*t;
}

Point PointToSeg(Point &P,const Line &L)
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

/////////////////////////////////////////

const int MaxN=1010;

int N;
Point P[MaxN],C;
double R;

double sta[MaxN<<1];
int cou;

bool OnSeg(Point &x,Point &a,Point &b)
{
	double minn=min(a.x,b.x);
	double maxn=max(a.x,b.x);

	return x.x<=maxn+eps && x.x>=minn-eps;
}

double getnum(Point a,Point b)
{
	bool t1=InCircle(C,R,a),t2=InCircle(C,R,b);

	if(t1 && t2) return dist(a,b);

	Point j1,j2;
	Line_I_Circle(C,R,a,b,j1,j2);				// Not good.

	if(!t1 && !t2)
	{
		if(dist(PointToSeg(C,Line(a,b)),C)>=R) return 0.0;			// !!!

		sta[cou++]=C.Angle(j1);
		sta[cou++]=C.Angle(j2);
		
		return dist(j1,j2);
	}

	//if(OnSeg(j1,Line(a,b))==0) j1=j2;
	if(OnSeg(j1,a,b)==0) j1=j2;
	sta[cou++]=C.Angle(j1);

	if(!t1) a=b;

	return dist(a,j1);
}

bool judge()
{
	if(cou==0) return 1;

	double mid=(sta[0]+sta[1])/2.0;
	Point p=C;
	p.x+=R*cos(mid);
	p.y+=R*sin(mid);

	return InPoly(p,P+1,N)!=-1;
}

double getans()
{
	if(N==1) return 0.0/0.0;
	double ret=0;
	double temp;
	cou=0;

	P[N+1]=P[1];
	for(int i=1;i<=N;++i)
	{
		temp=getnum(P[i],P[i+1]);
		ret+=temp;
	}

	temp=ret;

	sort(sta,sta+cou);
	double sum=0;
	for(int i=0;i<cou;i+=2)
		sum+=sta[i+1]-sta[i];
	if(judge()==0) sum=2.0*PI-sum;
	ret+=sum*R;

	if(sgn(ret)==0 && InPoly(C,P+1,N)==1 && N>2)
		ret=2*PI*R;

	return ret;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int cou=0;

	while(~scanf("%d",&N) && N)
	{
		for(int i=1;i<=N;++i)
			scanf("%lf %lf",&P[i].x,&P[i].y);
		scanf("%lf %lf %lf",&C.x,&C.y,&R);

		printf("%.0f\n",getans());
	}
	
	return 0;
}
