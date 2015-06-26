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
// Created Time  : 2015年06月05日 星期五 16时00分51秒
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

double p,a,b,c,d;
int N;

inline double F(int x)
{
	return p*(sin(a*x+b)+cos(c*x+d)+2.0);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%lf %lf %lf %lf %lf %d",&p,&a,&b,&c,&d,&N);

	double ans=0.0;
	double maxn=F(1);
	double temp;

	for(int i=2;i<=N;++i)
	{
		temp=F(i);
		ans=max(ans,maxn-temp);
		maxn=max(maxn,temp);
	}

	printf("%.10f\n",ans);
	
	return 0;
}
