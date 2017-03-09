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

int n,m;
double x1,x2,Y1,y2;
double U1[5010],L1[5010];
int cou[5010];
Point a,b,c;

int find()
{
	int L=0,R=n,mid;

	while(R>L)
	{
		mid=(L+R)/2+1;

		b.x=L1[mid];
		b.y=y2;
		c.x=U1[mid];
		c.y=Y1;

		if(sgn((c-b)^(a-b))>0)
			R=mid-1;
		else
			L=mid;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double x,y;
	int cas=0;

	while(~scanf("%d",&n) && n)
	{
		scanf("%d %lf %lf %lf %lf",&m,&x1,&Y1,&x2,&y2);
		for(int i=1;i<=n;++i)
			scanf("%lf %lf",&U1[i],&L1[i]);
		U1[0]=x1;
		L1[0]=x2;

		memset(cou,0,sizeof(cou));

		while(m--)
		{
			scanf("%lf %lf",&x,&y);

			a.x=x;
			a.y=y;

			++cou[find()];
		}

		if(cas++)
			printf("\n");

		for(int i=0;i<=n;++i)
			printf("%d: %d\n",i,cou[i]);
	}
	
	return 0;
}
