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
// Created Time  : 2015年05月31日 星期日 14时42分33秒
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

const int MaxN=400005;

const double eps=1e-17;
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
	int id;
	
	Point() {}
	Point(double _x,double _y,int c=0):x(_x),y(_y) {id=c;}

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

	bool operator < (const Point &b) const
	{
		if(sgn(x-b.x))
			return x<b.x;

		return y<b.y;
	}
};

struct Line
{
	Point s,e;
	
	Line() {}
	Line(Point _s,Point _e):s(_s),e(_e) {}
};

Point list[MaxN];

double dist(const Point &a,const Point &b)
{
	return sqrt((a-b)*(a-b));
}

bool _cmp(const Point &P1,const Point &P2)
{
	double temp=(P1-list[0])^(P2-list[0]);

	if(sgn(temp)>0)
		return 1;
	else if(sgn(temp)==0 && sgn(dist(P1,list[0])-dist(P2,list[0]))<0)
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

int ans[MaxN],ansnum;
int zans[MaxN],cou;
set <Point> sta;

bool equal(Point &a,Point &b)
{
	return sgn(a.x-b.x)==0 && sgn(a.y-b.y)==0;
}

bool OnSeg(Point &P,Line &L)
{
	return
		sgn((L.s-P)^(L.e-P))==0 &&
		sgn((P.x-L.s.x)*(P.x-L.e.x)) <=0 &&
		sgn((P.y-L.s.y)*(P.y-L.e.y)) <=0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	int s,r;
	double minn=100000000.0;
	Line line;

	scanf("%d",&n);

	for(int i=0;i<n;++i)
	{
		scanf("%d %d",&s,&r);

		list[i].x=1.0/s;
		list[i].y=1.0/r;
		list[i].id=i+1;

		minn=min(minn,1.0/s);
	}

	if(n==1)
	{
		printf("1\n");
		return 0;
	}

	Graham(ans,ansnum,n);

	cou=0;

	sta.insert(list[ans[0]]);

	line.s=list[ans[0]];

	if(sgn(list[ans[0]].x-minn))
		for(int i=ansnum-1;i>=0;--i)
		{
			sta.insert(list[ans[i]]);

			if(sgn(list[ans[i]].x-minn)==0)
			{
				line.e=list[ans[i]];
				break;
			}
		}

	for(int i=0;i<n;++i)
		if(OnSeg(list[i],line))
			sta.insert(list[i]);

	for(int i=0;i<n;++i)
		if(sta.count(list[i]))
			zans[cou++]=list[i].id;

	sort(zans,zans+cou);

	for(int i=0;i<cou;++i)
		printf("%d ",zans[i]);
	puts("");
	
	return 0;
}
