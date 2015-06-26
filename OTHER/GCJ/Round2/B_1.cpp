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
// Created Time  : 2015年05月30日 星期六 22时53分46秒
// File Name     : B_1.cpp

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

const double eps=1e-6;
int n;
double V,X;
double r[110],c[110];

inline int sgn(double x)
{
	return x<-eps ? -1 : x>eps;
}

double getans()
{
	if(n==1)
	{
		if(sgn(c[1]-X)==0)
			return -1;

		return V/r[1];
	}

	if(n==2)
	{
		double d,d1,d2;

		d=r[1]*r[2]*c[2]-r[2]*r[1]*c[1];
		d1=-r[2]*V*X+V*r[2]*c[2];
		d2=r[1]*V*X-V*r[1]*c[1];

		if(d==0)
			return -1;

		if(d<0)
		{
			d=-d;
			d1=-d1;
			d2=-d2;
		}

		if(d1<0)
			d1=0;

		if(d2<0)
			d2=0;

		if(sgn(d1*r[1]+d2*r[2]-V*d))
			return -1;

		if(sgn(d1*r[1]*c[1]+d2*r[2]*c[2]-V*X*d))
			return -1;

		return max(d1/d,d2/d);
	}

	return 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas=1;
	double ans;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %lf %lf",&n,&V,&X);

		for(int i=1;i<=n;++i)
			scanf("%lf %lf",&r[i],&c[i]);

		printf("Case #%d: ",cas++);

		ans=getans();

		if(ans>-1)
			printf("%.10f\n",ans);
		else
			puts("IMPOSSIBLE");
	}
	
	return 0;
}
