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
		max(L1.s.x,L1.e.x)>=min(L2.s.x,L2.e.x) &&
		max(L2.s.x,L2.e.x)>=min(L1.s.x,L1.e.x) &&
		max(L1.s.y,L1.e.y)>=min(L2.s.y,L2.e.y) &&
		max(L2.s.y,L2.e.y)>=min(L1.s.y,L1.e.y) &&
		sgn((L2.s-L1.e)^(L1.s-L1.e))*sgn((L2.e-L1.e)^(L1.s-L1.e))<=0 &&
		sgn((L1.s-L2.e)^(L2.s-L2.e))*sgn((L1.e-L2.e)^(L2.s-L2.e))<=0;
}

//int dp[60][60];
int N;
bool vis[60];
Point z[60];
Line Stack[60];
int top;
int fa[60];

bool judge(const Line &L)
{
	for(int i=0;i<top;++i)
		if(inter(L,Stack[i]))
			return 0;

	return 1;
}

int dfs(int u,int fang)
{
//cout<<u<<' '<<fang<<'%';
//	if(dp[u][fang])
//		return dp[u][fang];

	int maxn=0,rem,temp;

	for(int i=1;i<=N;++i)
		if(i!=u && vis[i]==0 && sgn((z[i]-z[u])^(z[u]-z[fang]))<=0 && judge(Line(z[u],z[i])))
		{
			vis[i]=1;

			temp=dfs(i,u);

			Stack[top++]=Line(z[u],z[i]);

			if(maxn<temp)
			{
				maxn=temp;
				rem=i;
			}

			--top;
			vis[i]=0;
		}

//	cout<<u<<' '<<fang<<' '<<maxn+1<<endl;

	fa[u]=rem;

//	cout<<rem<<endl;

	return maxn+1;
}

void printfans()
{
	int u=0;

	while(fa[u]!=-1)
	{
		printf(" %d",fa[u]);
		u=fa[u];
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int t,rem;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		rem=1;

		for(int i=1;i<=N;++i)
		{
			scanf("%*d %lf %lf",&z[i].x,&z[i].y);

			if(z[rem].y>z[i].y)
				rem=i;
		}

		z[0].x=0;
		z[0].y=z[rem].y;
		z[N+1].x=-1;
		z[N+1].y=z[0].y;

//		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		memset(fa,-1,sizeof(fa));
		top=0;

		int ans=dfs(0,N+1);

		printf("%d",ans-1);
		printfans();
	}
	
	return 0;
}
