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
// Created Time  : 2015年09月20日 星期日 15时44分52秒
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

bool OnSeg(Point &P,Line &L)
{
	return
		sgn((L.s-P)^(L.e-P))==0 &&
		sgn((P.x-L.s.x)*(P.x-L.e.x)) <=0 &&
		sgn((P.y-L.s.y)*(P.y-L.e.y)) <=0;
}

double R;
Point cen;
Point P[1010];
double ans;
int N;
bool in;
bool have;
double rrrrr;
double remJ[100000];
int cou;

double dist(Point &a,Point &b)
{
	double dx=a.x-b.x;
	double dy=a.y-b.y;

	return sqrt(dx*dx+dy*dy);
}

bool judgein(Point & p)
{
	double dx=p.x-cen.x;
	double dy=p.y-cen.y;

	if(dx*dx+dy*dy<=R*R)
	{
		if(have==0) in=1;
		return 1;
	}
	else
		return 0;
}

Point intersection(Point u1,Point u2,Point v1,Point v2)
{
Point ret=u1;
double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
ret.x+=(u2.x-u1.x)*t;
ret.y+=(u2.y-u1.y)*t;
return ret;
}

void haha(Point c,double r,Point l1,Point l2,Point &p1,Point &p2)
{
Point p=c;
double t;
p.x+=l1.y-l2.y;
p.y+=l2.x-l1.x;
p=intersection(p,c,l1,l2);
t=sqrt(r*r-dist(p,c)*dist(p,c))/dist(l1,l2);
p1.x=p.x+(l2.x-l1.x)*t;
p1.y=p.y+(l2.y-l1.y)*t;
p2.x=p.x-(l2.x-l1.x)*t;
p2.y=p.y-(l2.y-l1.y)*t;
}

double angle(Point &p)
{
	double dx=p.x-cen.x;
	double dy=p.y-cen.y;

	return atan2(dy,dx);
}

double linedian(Point &p1,Point &p2)
{
	double ts=p1.x*p2.y-p1.y*p2.x;
	double dx=p1.x-p2.x;
	double dy=p1.y-p2.y;
	double tdis=ts*ts/(dx*dx+dy*dy);
	
	if(sgn(tdis-R)>=0) return 0;

	double ret=2.0*sqrt(R*R-tdis);
	
	Point a1,a2;
	haha(cen,R,p1,p2,a1,a2);

	remJ[cou++]=angle(a1);
	remJ[cou++]=angle(a2);

	return ret;
}

bool judgein(Point &p,Point &a,Point &b)
{
/*	double minn=min(a.x,b.y),maxn=max(a.x,b.x);

	if(minn!=maxn) return sgn(maxn-p.x)>=0 && sgn(p.x-minn)>=0;

	minn=min(a.y,b.y);
	maxn=max(a.y,b.y);
	return sgn(maxn-p.y)>=0 && sgn(p.y-minn)>=0;
*/

	Line t(a,b);
	return OnSeg(p,t);
}

Point getjiao(Point &a,Point &b)
{
	Point a1,a2;
	haha(cen,R,a,b,a1,a2);

	if(judgein(a1,a,b))
		return a1;
	else return a2;
}

double getnum(Point &p1,Point &p2)
{
	double ret=0;
	bool t1,t2;

	t1=judgein(p1);
	t2=judgein(p2);

	if(t1 && t2)
		return dist(p1,p2);
	else if(!t1 && !t2)
		ret+=linedian(p1,p2);
	else
	{
		Point p=getjiao(p1,p2);
		if(t1) ret+=dist(p1,p);
		else ret+=dist(p2,p);

		remJ[cou++]=angle(p);
		if(have==0 && in)
		{
			rrrrr=remJ[cou-1];
			have=1;
		}
	}

	return ret;
}

double getyuan(double sum)
{
	return sum*R;
}

const double PI=atan2(1,1)*4.0;

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

int inxing(Point &a,Point P[],int n)
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

		if(OnSeg(a,side))
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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N) && N)
	{
		for(int i=1;i<=N;++i)
			scanf("%lf %lf",&P[i].x,&P[i].y);
		scanf("%lf %lf %lf",&cen.x,&cen.y,&R);

		if(judgein(P[1])) in=1;
		else in=0;
		have=0;

		cou=0;
		double ans=0;
		P[N+1]=P[1];
		for(int i=1;i<=N;++i)
			ans+=getnum(P[i],P[i+1]);

		cout<<ans<<endl;

		sort(remJ,remJ+cou);
		for(int i=cou;i<2*cou;++i)
			remJ[i]=remJ[i-cou];
		int p=0;
		for(int i=0;i<cou;++i)
			if(sgn(remJ[i]-rrrrr)==0) p=i;

		double sum=0;
		for(int i=0;i<cou;i+=2,p+=2)
			sum+=remJ[p+1]-remJ[p];
		ans+=getyuan(sum);

		if(sgn(ans)==0 && inxing(cen,P+1,N)==1)
			ans=2*PI*R;

		printf("%.0f\n",ans);
	}
	
	return 0;
}
