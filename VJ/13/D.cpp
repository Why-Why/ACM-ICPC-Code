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
};

struct Line
{
	Point s,e;

	Line() {}
	Line(Point &_s,Point &_e):s(_s),e(_e) {}

	pair<int,Point> operator & (const Line &b) const
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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	Line L1,L2;
	pair <int,Point> temp;

	scanf("%d",&n);

	printf("INTERSECTING LINES OUTPUT\n");

	while(n--)
	{
		scanf("%lf %lf %lf %lf",&L1.s.x,&L1.s.y,&L1.e.x,&L1.e.y);
		scanf("%lf %lf %lf %lf",&L2.s.x,&L2.s.y,&L2.e.x,&L2.e.y);

		temp=L1&L2;

		if(temp.first==0)
			printf("LINE\n");
		else if(temp.first==1)
			printf("NONE\n");
		else
			printf("POINT %.2f %.2f\n",temp.second.x,temp.second.y);
	}

	printf("END OF OUTPUT\n");
	
	return 0;
}
