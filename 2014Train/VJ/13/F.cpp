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

	Point() {};
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
	return
		max(L1.s.x , L1.e.x) >= min(L2.s.x , L2.e.x) &&
		max(L2.s.x , L2.e.x) >= min(L1.s.x , L1.e.x) &&
		max(L1.s.y , L1.e.y) >= min(L2.s.y , L2.e.y) &&
		max(L2.s.y , L2.e.y) >= min(L1.s.y , L1.e.y) &&
		sgn((L2.s-L1.e)^(L1.s-L1.e)) * sgn((L2.e-L1.e)^(L1.s-L1.e)) <0 &&
		sgn((L1.s-L2.e)^(L2.s-L2.e)) * sgn((L1.e-L2.e)^(L2.s-L2.e)) <0;
}

int top1;
int Stack[201000];
Line L[200006];
int n;

bool judge(int a)
{
	for(int i=a+1;i<=n;++i)
		if(inter(L[i],L[a]))
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&n) && n)
	{
		top1=0;

		for(int i=1;i<=n;++i)
			scanf("%lf %lf %lf %lf",&L[i].s.x,&L[i].s.y,&L[i].e.x,&L[i].e.y);

		for(int i=n;i>=1;--i)
		{
			if(judge(i))
				Stack[top1++]=i;

		//	if(top>1000)
		//		break;
		}

		printf("Top sticks:");
		
		for(int i=top1-1;i>=1;--i)
			printf(" %d,",Stack[i]);
		printf(" %d.\n",Stack[0]);
	}
	
	return 0;
}
