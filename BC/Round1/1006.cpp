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
// Created Time  : 2015年05月30日 星期六 14时56分14秒
// File Name     : 1006.cpp

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

const int MaxN=10010;
const double eps=1e-8;
const double PI=acos(-1.0);

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

double dist(const Point &a,const Point &b)
{
	return sqrt((a-b)*(a-b));
}

Point list[MaxN];

bool _cmp(const Point &P1,const Point &P2)
{
	double temp=(P1-list[0])^(P2-list[0]);

	if(sgn(temp)>0)
		return 1;
	else if(sgn(temp)==0 && sgn(dist(P1,list[0])-dist(P2,list[0]))<=0)
		return 1;
	else
		return 0;
}

void Graham(int Stack[],int &top,int n)
{
	Point P0=list[0];
	int k=0;

	for(int i=1;i<n;++i)
		if(sgn(P0.y-list[i].y)>0 || (sgn(P0.y-list[i].y)==0 && sgn(P0.x-list[i].x)>0))
		{
			P0=list[i];
			k=i;
		}

	swap(list[k],list[0]);
	sort(list+1,list+n,_cmp);

	if(n==1)
	{
		top=1;
		Stack[0]=0;

		return;
	}

	if(n==2)
	{
		top=2;
		Stack[0]=0;
		Stack[1]=1;
	}

	Stack[0]=0;
	Stack[1]=1;
	top=2;

	for(int i=2;i<n;++i)
	{
		while(top>1 && sgn((list[Stack[top-1]]-list[Stack[top-2]])^(list[i]-list[Stack[top-2]]))<=0)
			--top;

		Stack[top++]=i;
	}
}

Point PointTOLine(Point &P,Line &L)
{
	Point ret;
	double t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));

	ret.x=L.s.x+(L.e.x-L.s.x)*t;
	ret.y=L.s.y+(L.e.y-L.s.y)*t;

	return ret;
}

int N;
int ans[MaxN],ansnum;
double ansarea;

double getdis(Line &L,Point &P)
{
	Point temp=PointTOLine(P,L);

	return dist(temp,P);
}

double getans(Point &a,Point &b)
{
	double h=0,w1=-1e8,w2=1e8;
	int rem1,rem2;
	Point t1;
	double d;
	Line L(a,b);

	for(int i=0;i<ansnum;++i)
	{
		h=max(h,getdis(L,list[ans[i]]));

		t1=PointTOLine(list[ans[i]],L);
		
		if(sgn(a.x-b.x))
			d=t1.x-a.x;
		else
			d=t1.y-a.y;

		if(d>w1)
		{
			w1=d;
			rem1=i;
		}

		if(d<w2)
		{
			w2=d;
			rem2=i;
		}
	}

	double www=dist(PointTOLine(list[ans[rem1]],L),PointTOLine(list[ans[rem2]],L));
	return h*www;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	double x,y;
	int cou;

	scanf("%d",&T);

	while(T--)
	{
		cou=0;
		scanf("%d",&N);

		ansarea=1e10;

		for(int i=0;i<N;++i)
		{
			for(int j=1;j<=4;++j)
			{
				scanf("%lf %lf",&x,&y);
				list[cou].x=x;
				list[cou++].y=y;
			}
		}

		N=cou;

		Graham(ans,ansnum,N);

		for(int i=0;i<ansnum;++i)
			ansarea=min(ansarea,getans(list[ans[i]],list[ans[(i+1)%ansnum]]));

		printf("Case #%d:\n",cas++);
		printf("%.0f\n",ansarea+eps);
	}
	
	return 0;
}
