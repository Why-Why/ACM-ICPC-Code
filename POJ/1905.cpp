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
// Created Time  : 2015年05月26日 星期二 23时20分58秒
// File Name     : 1905.cpp

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

double L1,L2;
const double eps=1e-6;
const double INF=1000000000000.0;

inline double f(double x)
{
	return 2.0*x*sin(L2/(2.0*x));
}

double getr()
{
	double L=0,R=INF,Mid;

	while(R-L>eps)
	{
		Mid=(L+R)/2.0;

		if(f(Mid)>=L1)
			R=Mid;
		else
			L=Mid;
	}

	return L;
}

double getans()
{
	double r=getr();

	return r-0.5*sqrt(4.0*r*r-L1*L1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double a,b,c;

	while(~scanf("%lf %lf %lf",&a,&b,&c) && a>=0)
	{
		if(a==0 || b==0 || c==0)
		{
			puts("0.000");
			continue;
		}

		L1=a;
		L2=a*(1.0+b*c);

		printf("%.3f\n",getans());
	}
	
	return 0;
}
