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
	if(fabs(x)<eps)
		return 0;

	if(x<0)
		return -1;

	return 1;
}

inline double min(double a,double b)
{
	if(sgn(a-b)<=0)
		return a;
	
	return b;
}

inline double max(double a,double b)
{
	if(sgn(a-b)<=0)
		return b;

	return a;
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
	if(sgn(L1.s.x-L2.s.x)==0 && sgn(L1.s.y-L2.s.y)==0)
		return 1;
	if(sgn(L1.s.x-L2.e.x)==0 && sgn(L1.s.y-L2.e.y)==0)
		return 1;
	if(sgn(L1.e.x-L2.s.x)==0 && sgn(L1.e.y-L2.s.y)==0)
		return 1;
	if(sgn(L1.e.x-L2.e.x)==0 && sgn(L1.e.y-L2.e.y)==0)
		return 1;

	return
		sgn(max(L1.s.x,L1.e.x) - min(L2.s.x,L2.e.x))>=0 &&
		sgn(max(L2.s.x,L2.e.x) - min(L1.s.x,L1.e.x))>=0 &&
		sgn(max(L1.s.y,L1.e.y) - min(L2.s.y,L2.e.y))>=0 &&
		sgn(max(L2.s.y,L2.e.y) - min(L1.s.y,L1.e.y))>=0 &&
		sgn((L2.s-L1.e)^(L1.s-L1.e)) * sgn((L2.e-L1.e)^(L1.s-L1.e)) <=0 &&
		sgn((L1.s-L2.e)^(L2.s-L2.e)) * sgn((L1.e-L2.e)^(L2.s-L2.e)) <=0;
}

int n;
Line xian[110];

void getans(double &lans,double &rans,int a,int b)
{
	double t1=-1,t2=-1;
	double tt1[5];
	int cou=0;

	if(inter(xian[a],xian[b]))
	{
		lans=0;
		rans=PI;

		return;
	}

	if(sgn((xian[a].s-xian[a].e)^(xian[b].s-xian[b].e))==0)
	{
		lans=atan2(xian[a].s.x-xian[a].e.x,xian[a].s.y-xian[a].e.y);

		if(sgn(lans)<0)
			lans+=PI;
		rans=lans;

		return;
	}

	if(sgn((xian[b].s-xian[a].s)^(xian[b].e-xian[a].s))*sgn((xian[b].s-xian[a].s)^(xian[a].e-xian[a].s))<=0)
	{
		t1=atan2(xian[b].s.y-xian[a].s.y,xian[b].s.x-xian[a].s.x);

		if(sgn(t1)<0)
			t1+=PI;

		tt1[cou++]=t1;
	}
	
	if(sgn((xian[b].e-xian[a].s)^(xian[b].s-xian[a].s))*sgn((xian[b].e-xian[a].s)^(xian[a].e-xian[a].s))<=0)
	{
		t1=atan2(xian[b].e.y-xian[a].s.y,xian[b].e.x-xian[a].s.x);

		if(sgn(t1)<0)
			t1+=PI;

		tt1[cou++]=t1;
	}
	
	if(sgn((xian[b].s-xian[a].e)^(xian[b].e-xian[a].e))*sgn((xian[b].s-xian[a].e)^(xian[a].s-xian[a].e))<=0)
	{
		t2=atan2(xian[b].s.y-xian[a].e.y,xian[b].s.x-xian[a].e.x);

		if(sgn(t2)<0)
			t2+=PI;

		tt1[cou++]=t2;
	}
	
	if(sgn((xian[b].e-xian[a].e)^(xian[b].s-xian[a].e))*sgn((xian[b].e-xian[a].e)^(xian[a].s-xian[a].e))<=0)
	{
		t2=atan2(xian[b].e.y-xian[a].e.y,xian[b].e.x-xian[a].e.x);

		if(sgn(t2)<0)
			t2+=PI;

		tt1[cou++]=t2;
	}

	lans=tt1[0];
	rans=tt1[0];

	for(int i=1;i<cou;++i)
	{
		lans=min(lans,tt1[i]);
		rans=max(rans,tt1[i]);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	double a,b,c,d;
	double lans=0,rans=PI,lt,rt;
	bool ok;

	scanf("%d",&T);

	while(T--)
	{
		ok=1;
		scanf("%d",&n);

		for(int i=1;i<=n;++i)
		{
			scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

			xian[i].s=Point(a,b);
			xian[i].e=Point(c,d);
		}

		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
			{
				getans(lt,rt,i,j);

				lans=max(lans,lt);
				rans=min(rans,rt);

				if(sgn(rans-lans)<0)
				{
					ok=0;
					break;
				}
			}

		if(sgn(rans-lans)<0)
			ok=0;

		if(n==1 || n==2)
			ok=1;

		if(ok)
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	
	return 0;
}
