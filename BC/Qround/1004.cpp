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
// Created Time  : 2015年05月23日 星期六 22时23分21秒
// File Name     : 1004.cpp

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

const double PI=atan2(1.0,1.0)*4.0;
const double eps=1e-8;

inline int sgn(double x)
{
	return x<-eps ? -1 : x>eps;
}

int n;
double a,r;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	double t;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %lf %lf",&n,&a,&r);

		t=a/(2.0*tan(PI/n));

		printf("Case #%d:\n",cas++);

		if(sgn(t-r)>0)
			puts("Give me a kiss!");
		else
			puts("I want to kiss you!");
	}
	
	return 0;
}
