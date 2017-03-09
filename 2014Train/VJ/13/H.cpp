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

	Point operator - (const Point &a) const
	{
		return Point(x-a.x,y-a.y);
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
	Line(Point &_s,Point &_e):s(_s),e(_e) {}
};

bool inter(Line &L1,Line &L2)
{
	return
		max(L1.s.x,L1.e.x)>=min(L2.s.x,L2.e.x) &&
		max(L2.s.x,L2.e.x)>=min(L1.s.x,L1.e.x) &&
		max(L1.s.y,L1.e.y)>=min(L2.s.y,L2.e.y) &&
		max(L2.s.y,L2.e.y)>=min(L1.s.y,L1.e.y) &&
		sgn((L2.s-L1.e)^(L1.s-L1.e))*sgn((L2.e-L1.e)^(L1.s-L1.e))<=0 &&
		sgn((L1.s-L2.e)^(L2.s-L2.e))*sgn((L1.e-L2.e)^(L2.s-L2.e))<=0;
}

bool judge(double a,double b,double c,double d,Point &t)
{
	if(sgn(t.x-c)<=0 && sgn(t.x-a)>=0 && sgn(t.y-b)<=0 && sgn(t.y-d)>=0)
		return 1;

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	Line L,Lt[5];
	double a,b,c,d;
	bool ok;

	scanf("%d",&n);

	while(n--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&L.s.x,&L.s.y,&L.e.x,&L.e.y,&a,&b,&c,&d);

		if(sgn(a-c)>0)
			swap(a,c);
		if(sgn(b-d)<0)
			swap(b,d);

		Lt[1].s.x=Lt[1].e.x=Lt[2].s.x=Lt[4].e.x=a;
		Lt[1].s.y=Lt[3].e.y=Lt[4].s.y=Lt[4].e.y=b;
		Lt[3].s.x=Lt[3].e.x=Lt[2].e.x=Lt[4].s.x=c;
		Lt[3].s.y=Lt[2].e.y=Lt[2].s.y=Lt[1].e.y=d;

		ok=0;

		for(int i=1;i<=4;++i)
			if(inter(Lt[i],L))
				ok=1;

		if(!ok && (judge(a,b,c,d,L.s) || judge(a,b,c,d,L.e)))
			ok=1;

		printf("%c\n",ok ? 'T' : 'F');
	}
	
	return 0;
}
