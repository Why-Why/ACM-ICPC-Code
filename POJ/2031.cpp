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
// Created Time  : 2015年05月27日 星期三 22时25分08秒
// File Name     : 2031.cpp

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

struct Point
{
	double x,y,z,r;

	double dis(Point &b)
	{
		return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y)+(z-b.z)*(z-b.z));
	}
};

Point sta[110];
int N;

const double INF=10e8;
const int MaxN=110;

bool vis[MaxN];
double lowc[MaxN];

double Prim(double cost[][MaxN],int n)
{
	double ans=0;
	int k;
	double minn;

	memset(vis,0,sizeof(vis));
	vis[1]=1;

	for(int i=1;i<=n;++i)
		lowc[i]=cost[1][i];

	for(int i=1;i<=n-1;++i)				// 循环n-1次。
	{
		minn=INF;
		k=-1;

		for(int j=1;j<=n;++j)
			if(!vis[j] && minn>lowc[j])
			{
				minn=lowc[j];
				k=j;
			}

		if(minn==INF)
			return -1;

		ans+=minn;
		vis[k]=1;

		for(int j=1;j<=n;++j)
			if(!vis[j] && lowc[j]>cost[k][j])
				lowc[j]=cost[k][j];
	}

	return ans;
}

double cost[MaxN][MaxN];

void chuli(int a,int b)
{
	double d=sta[a].dis(sta[b]);

	cost[a][b]=max(0.0,d-sta[a].r-sta[b].r);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N) && N)
	{
		for(int i=1;i<=N;++i)
			scanf("%lf %lf %lf %lf",&sta[i].x,&sta[i].y,&sta[i].z,&sta[i].r);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				chuli(i,j);

		printf("%.3f\n",Prim(cost,N));
	}
	
	return 0;
}
