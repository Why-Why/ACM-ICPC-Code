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
// Created Time  : 2015年05月17日 星期日 13时08分24秒
// File Name     : 5033.cpp

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

const int MaxN=100005;

struct point
{
	double x,y;
	
	bool operator < (const point & b) const
	{
		return x<b.x;
	}

	point operator - (const point & b) const
	{
		point ret;

		ret.x=x-b.x;
		ret.y=y-b.y;

		return ret;
	}

	point(double _x=0,double _y=0)
	{
		x=_x;
		y=_y;
	}

	double operator ^ (const point & b) const
	{
		return x*b.y-y*b.x;
	}
};

struct query
{
	double x;
	int id;

	bool operator < (const query & b) const
	{
		return x<b.x;
	}
};

const double eps=1e-8;
const double PI=atan2(1.0,1.0)*4.0;

point wall[MaxN];
query man[MaxN];
int N,M;

double ans[MaxN];

inline int sgn(double x)
{
	return x<=-eps ? -1 : x>=eps;
}

int Stack[MaxN];
int top;

void push(int n)
{
	while(top>0 && wall[Stack[top-1]].y<=wall[n].y)
		--top;

	while(top>1 && sgn((wall[Stack[top-1]]-wall[Stack[top-2]])^(wall[n]-wall[Stack[top-2]]))>=0)
		--top;

	Stack[top++]=n;
}

double pop(double qx)
{
	while(top>1 && sgn((wall[Stack[top-1]]-wall[Stack[top-2]])^(point(qx,0)-wall[Stack[top-2]]))>0)
		--top;

	return atan2(qx-wall[Stack[top-1]].x,wall[Stack[top-1]].y);
}

void getans()
{
	int p=1;

	top=0;

	for(int i=1;i<=M;++i)
	{
		while(wall[p].x<man[i].x)
		{
			push(p);
			++p;
		}

		ans[man[i].id]+=pop(man[i].x);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%lf %lf",&wall[i].x,&wall[i].y);

		scanf("%d",&M);

		for(int i=1;i<=M;++i)
		{
			ans[i]=0;
			scanf("%lf",&man[i].x);
			man[i].id=i;
		}

		sort(wall+1,wall+N+1);
		sort(man+1,man+M+1);

		getans();

		reverse(wall+1,wall+N+1);
		reverse(man+1,man+M+1);

		for(int i=1;i<=N;++i)
			wall[i].x=-wall[i].x;

		for(int i=1;i<=M;++i)
			man[i].x=-man[i].x;

		getans();

		printf("Case #%d:\n",cas++);

		for(int i=1;i<=M;++i)
			printf("%.10lf\n",ans[i]*180.0/PI);
	}
	
	return 0;
}
