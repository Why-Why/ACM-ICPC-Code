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
// Created Time  : 2015年06月13日 星期六 21时14分17秒
// File Name     : 2187.cpp

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
const int MaxN=50010;

inline int sgn(double x)
{
	return x<-eps ? -1 : x>eps;
}

struct Point
{
	double x,y;

	Point(double a=0,double b=0):x(a),y(b) {}

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

	Line() {}
	Line(const Point &a,const Point &b):s(a),e(b) {}
};

inline double dist(const Point &P1,const Point &P2)
{
	return ((P1-P2)*(P1-P2));
}

Point list[MaxN];

bool _cmp(const Point &p1,const Point &p2)
{
	double temp=(p1-list[0])^(p2-list[0]);

	if(sgn(temp)>0)
		return 1;
	else if(sgn(temp)==0 && sgn(dist(p1,list[0])-dist(p2,list[0]))<=0)
		return 1;
	else
		return 0;
}

int Graham(int Stack[],int n)
{
	int top=0;
	Point p0=list[0];
	int k=0;

	for(int i=1;i<n;++i)
		if(sgn(p0.y-list[i].y)>0 || (sgn(p0.y-list[i].y)==0 && sgn(p0.x-list[i].x)>0))
		{
			p0=list[i];
			k=i;
		}

	swap(list[k],list[0]);
	sort(list+1,list+n,_cmp);

	if(n==1)
	{
		top=1;
		Stack[0]=0;
		
		return top;
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

	return top;
}

double distLine(const Point &P,const Line &L)
{
	Point ret;
	double t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));

	ret.x=L.s.x+(L.e.x-L.s.x)*t;
	ret.y=L.s.y+(L.e.y-L.s.y)*t;

	return dist(ret,P);
}

int rP[MaxN];
Point tP[MaxN];

double getans(int N)
{
	double maxn=0,temp,ret=0;
	int p,q=-1;

	ret=dist(tP[0],tP[1]);

	p=1;

	for(int i=2;i<N;++i)
	{
		temp=distLine(tP[i],Line(tP[0],tP[1]));

		if(temp>maxn)
		{
			maxn=temp;
			q=i;
		}
	}

	if(q==-1)
		return ret;

	ret=max(dist(tP[1],tP[q]),dist(tP[0],tP[q]));

	do
	{
		if(sgn((tP[p]-tP[(p+1)%N])^(tP[(q+1)%N]-tP[q]))>=0)
			(++p)%=N;
		else
		{
			swap(p,q);
			(++p)%=N;
		}

		ret=max(ret,max(dist(tP[q],tP[p]),dist(tP[q],tP[(p-1+N)%N])));

	}while(p!=1);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;

	while(~scanf("%d",&N))
	{
		for(int i=0;i<N;++i)
			scanf("%lf %lf",&list[i].x,&list[i].y);

		int tN=Graham(rP,N);

		for(int i=0;i<tN;++i)
			tP[i]=list[rP[i]];

		double ans=getans(tN);

		printf("%.0f\n",ans);
	}
	
	return 0;
}
