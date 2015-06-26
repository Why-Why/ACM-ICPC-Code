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
	Line(Point &_s,Point &_e):s(_s),e(_e) {}
};

bool SetInLine(Line &a,Line &b)		// a is a segmant.
{
	return sgn((a.s-b.s)^(b.e-b.s))*sgn((a.e-b.s)^(b.e-b.s))<=0;
}

double dist(Point &a,Point &b)
{
	return sqrt((a-b)*(a-b));
}

Point P[300];
Line L[130];
int n;

bool judge(int a,int b)
{
	Line Lt;
	Lt.s=P[a];
	Lt.e=P[b];

	for(int i=1;i<=n;++i)
		if(SetInLine(L[i],Lt)==0)
			return 0;
	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	bool ok;

	scanf("%d",&T);

	while(T--)
	{
		ok=0;
		scanf("%d",&n);

		for(int i=1;i<=n;++i)
		{
			scanf("%lf %lf",&P[i*2-1].x,&P[i*2-1].y);
			scanf("%lf %lf",&P[i*2].x,&P[i*2].y);

			L[i].s=P[i*2-1];
			L[i].e=P[i*2];
		}

		if(n==1 || n==2)
		{
			printf("Yes!\n");
			continue;
		}

		for(int i=1;i<=2*n;++i)
			for(int j=i+1;j<=2*n;++j)
				if(sgn(dist(P[i],P[j])))
					if(judge(i,j))
					{
						ok=1;
						break;
					}

		if(ok)
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	
	return 0;
}
