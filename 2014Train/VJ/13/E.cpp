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
const double PI=acos(-1.0);

typedef double typeM;

const int MaxN=100;
const double INF=10e7;					// 注意不要太大，防止溢出。

bool vis[MaxN];
int fa[MaxN];

void Dijkstra(typeM cost[][MaxN],typeM lowcost[],int n,int start)
{
	for(int i=1;i<=n;++i)
	{
		lowcost[i]=INF;
		fa[i]=-1;
		vis[i]=0;
	}
	lowcost[start]=0;

	for(int j=1;j<=n;++j)
	{
		int k=-1;
		double minn=INF;

		for(int i=1;i<=n;++i)
			if(!vis[i] && lowcost[i]<minn)
			{
				minn=lowcost[i];
				k=i;
			}

		if(k==-1)
			break;
		vis[k]=1;

		for(int i=1;i<=n;++i)
			if(!vis[i] && cost[k][i]>=0 && lowcost[k]+cost[k][i]<lowcost[i])
			{
				lowcost[i]=lowcost[k]+cost[k][i];
				fa[i]=k;
			}
	}
}

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

double dist(Point &a,Point &b)
{
	return sqrt((a-b)*(a-b));
}

bool inter(Line &a,Line &b)
{
	return sgn((a.s-b.s)^(b.e-b.s))*sgn((a.e-b.s)^(b.e-b.s))<=0;
}

Point P[100];
Line L[50];
int N;

double map1[100][100];
double lowcost[100];

bool judge(int a,int b)
{
	double maxx=max(P[a].x,P[b].x),minx=min(P[a].x,P[b].x);
	Line TL=Line(P[a],P[b]);

	for(int i=1;i<=N;++i)
		if(sgn(L[i*2].s.x-maxx)<0 && sgn(L[i*2].s.x-minx)>0)
			if(inter(L[i*2-1],TL)==0 && inter(L[i*2],TL)==0)
				return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double a,b,c,e,d;

	while(~scanf("%d",&N) && N!=-1)
	{
		for(int i=1;i<=N;++i)
		{
			scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);

			P[i*4-3].x=P[i*4-2].x=P[i*4-1].x=P[i*4].x=a;

			P[i*4-3].y=b;
			P[i*4-2].y=c;
			P[i*4-1].y=d;
			P[i*4].y=e;

			L[i*2-1].s=P[i*4-3];
			L[i*2-1].e=P[i*4-2];
			L[i*2].s=P[i*4-1];
			L[i*2].e=P[i*4];
		}

		P[4*N+1]=Point(0,5);
		P[4*N+2]=Point(10,5);

		memset(map1,-1,sizeof(map1));

		for(int i=1;i<=4*N+2;++i)
			for(int j=1;j<=4*N+2;++j)
				if(i!=j && sgn(P[i].x-P[j].x))
					if(judge(i,j))
						map1[i][j]=dist(P[i],P[j]);

		Dijkstra(map1,lowcost,4*N+2,4*N+1);

		printf("%.2f\n",lowcost[4*N+2]+eps);
	}
	
	return 0;
}
