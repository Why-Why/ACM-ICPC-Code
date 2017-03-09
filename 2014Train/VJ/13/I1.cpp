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
};

inline bool inter(const Line &L1,const Line &L2)
{
	return
		max(L1.s.x , L1.e.x) >= min(L2.s.x , L2.e.x) &&
		max(L2.s.x , L2.e.x) >= min(L1.s.x , L1.e.x) &&
		max(L1.s.y , L1.e.y) >= min(L2.s.y , L2.e.y) &&
		max(L2.s.y , L2.e.y) >= min(L1.s.y , L1.e.y) &&
		sgn((L2.s-L1.e)^(L1.s-L1.e)) * sgn((L2.e-L1.e)^(L1.s-L1.e)) <=0 &&
		sgn((L1.s-L2.e)^(L2.s-L2.e)) * sgn((L1.e-L2.e)^(L2.s-L2.e)) <=0;
}

Point P[60];
int num[60];
Line L[60];
int top,N;
int son[60];
bool vis[60];

inline bool judge(const Line &a)
{
	for(int i=0;i<top;++i)
		if(inter(L[i],a))
			return 0;

	return 1;
}

int dfs(int u,int lastu)
{
//	cout<<u<<' '<<lastu<<endl;
	int maxn=0,temp,rem=-1;

	for(int i=1;i<=N;++i)
		if(!vis[i] && sgn((P[u]-P[lastu])^(P[i]-P[u]))>=0 && judge(Line(P[u],P[i])))
		{
			vis[i]=1;
			L[top++]=Line(P[lastu],P[u]);

			temp=dfs(i,u);

			if(temp>maxn)
			{
				maxn=temp;
				rem=i;
			}

			vis[i]=0;
			--top;
		}

	son[u]=rem;

//	cout<<rem<<' ';

	return maxn+1;
}

inline void printans()
{
	int u=0;

	while(son[u]!=-1)
	{
		printf(" %d",son[u]);
		u=son[u];
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int rem;
	int ans;

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

		memset(son,-1,sizeof(son));
		memset(vis,0,sizeof(vis));
		top=0;

		ans=dfs(0,N+1);

		printf("%d",ans-1);
		printans();
		printf("\n");
	}
	
	return 0;
}
