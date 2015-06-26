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
// Created Time  : 2015年06月13日 星期六 22时51分45秒
// File Name     : 1113.cpp

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

double dist(const Point &a,const Point &b)
{
	return sqrt((a-b)*(a-b));
}

const int MaxN=1010;

Point list[MaxN];

bool _cmp(const Point &P1,const Point &P2)
{
	double temp=(P1-list[0])^(P2-list[0]);

	if(sgn(temp)>0)
		return 1;
	else if(sgn(temp)==0 && sgn(dist(P1,list[0])-dist(P2,list[0]))<0)		// <= 会RE！！！
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

int rN,rP[MaxN];

double getans()
{
	double ret=0;

	for(int i=0;i<rN;++i)
		ret+=dist(list[rP[i]],list[rP[(i+1)%rN]]);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long R,N;
	double ans;

	while(~scanf("%lld %lld",&N,&R))
	{
		for(int i=0;i<N;++i)
			scanf("%lf %lf",&list[i].x,&list[i].y);

		Graham(rP,rN,N);

		ans=2.0*PI*R;
		ans+=getans();

		printf("%.0f\n",ans);
	}
	
	return 0;
}
