// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年09月20日 星期日 12时06分03秒
// File Name     : A.cpp

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

const int INF=0x3f3f3f3f;
const double eps=1e-10;

int M,N;

struct Point
{
	double x,y;
};

Point P[110];
double rem[110];
int cou=0;

double dist(Point &a,Point &b)
{
	double dx=a.x-b.x;
	double dy=a.y-b.y;

	return sqrt(dx*dx+dy*dy);
}

int getmax(int u)
{
	cou=0;
	for(int i=1;i<=M;++i)
		if(u!=i)
			rem[++cou]=dist(P[i],P[u]);

	sort(rem+1,rem+cou+1);
	rem[0]=0;
	if(N>=M) return rem[cou]+1;
	int t=rem[N-1]+1;
	if(t==0) t=1;

	if(rem[N]>t+eps)
		return t;
	else return INF;
}

int getans()
{
	int ret=INF;
	
	for(int i=1;i<=M;++i)
		ret=min(ret,getmax(i));

	if(ret==INF) ret=-1;
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&M,&N);
		for(int i=1;i<=M;++i)
			scanf("%lf %lf",&P[i].x,&P[i].y);

		if(N>M)
		{
			printf("-1\n");
			continue;
		}

		printf("%d\n",getans());
	}
	
	return 0;
}
