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
// Created Time  : 2015年05月26日 星期二 23时42分17秒
// File Name     : 3122.cpp

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

const double eps=1e-7;
const double PI=atan2(1.0,1.0)*4.0;

int N,F;
double num[10004];

inline bool judge(double x)
{
	int cou=0;

	for(int i=1;i<=N;++i)
		cou+=(int)(PI*num[i]*num[i]/x);

	return cou>=F;
}

double getans()
{
	double L=0,R=10000000000.0,M;

	while(R-L>eps)
	{
		M=(L+R)/2.0;

		if(judge(M))
			L=M;
		else
			R=M;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&F);
		++F;

		for(int i=1;i<=N;++i)
			scanf("%lf",&num[i]);

		printf("%.5f\n",getans());
	}
	
	return 0;
}
