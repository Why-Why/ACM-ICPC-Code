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
const int MaxN=60;

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

double dist(const Point &a,const Point &b)
{
	return sqrt((a-b)*(a-b));
}

bool cmp(const Point &a,const Point &b,const Point &u)
{
	double temp=a^b;

	if(sgn(temp)>0)
		return 1;
	else if(sgn(temp)==0 && sgn(dist(a,u)-dist(b,u))<=0)
		return 1;

	return 0;
}

Point P[MaxN];
int num[MaxN];
int N;
int ans[MaxN];
bool vis[MaxN];

void getans()
{
	int cou=0,u=0,rem=-1;

	while(cou<N)
	{
		for(int i=1;i<=N;++i)
			if(vis[i]==0)
				if(rem==-1 || cmp(P[i]-P[u],P[rem]-P[u],P[u]))
					rem=i;

		vis[rem]=1;
		ans[cou++]=rem;
		u=rem;
		rem=-1;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int rem;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		rem=1;

		for(int i=1;i<=N;++i)
		{
			scanf("%d %lf %lf",&num[i],&P[i].x,&P[i].y);

			if(P[i].y<P[rem].y)
				rem=i;
		}

		P[0].x=0;
		P[0].y=P[rem].y;
		P[N+1].x=-1;
		P[N+1].y=P[0].y;

		memset(vis,0,sizeof(vis));

		getans();

		printf("%d",N);
		
		for(int i=0;i<N;++i)
			printf(" %d",num[ans[i]]);

		printf("\n");
	}
	
	return 0;
}
