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

struct state
{
	double U1,L1;

	bool operator < (const state & a) const
	{
		return sgn(U1-a.U1)<0;
	}
};

int n,m;
double x1,x2,Y1,y2;
state sta[5010];
int cou[5010];
Point a,b,c;

bool judge()
{
	return 
		sgn(a.x-x1)>=0 &&
		sgn(a.x-x2)<=0 &&
		sgn(a.y-Y1)<=0 &&
		sgn(a.y-y2)>=0 ;
}

int find()
{
	int L=0,R=n,mid;

	while(R>L)
	{
		mid=(L+R)/2+1;

		b.x=sta[mid].L1;
		b.y=y2;
		c.x=sta[mid].U1;
		c.y=Y1;

		if(sgn((c-b)^(a-b))>0)
			R=mid-1;
		else
			L=mid;
	}

	return L;
}

int ans[5010];

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
			scanf("%lf %lf",&sta[i].U1,&sta[i].L1);
		sta[0].U1=x1;
		sta[0].L1=x1;

		sort(sta,sta+n+1);

		memset(cou,0,sizeof(cou));
		memset(ans,0,sizeof(ans));

		while(m--)
		{
			scanf("%lf %lf",&x,&y);

			a.x=x;
			a.y=y;

			if(judge())
				++cou[find()];
		}

		for(int i=0;i<=n;++i)
			++ans[cou[i]];

		printf("Box\n");
		
		for(int i=1;i<=n;++i)
			if(ans[i])
				printf("%d: %d\n",i,ans[i]);
	}
	
	return 0;
}
