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
// Created Time  : 2015年07月25日 星期六 19时02分54秒
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

long long X1,X2,Y1,Y2,Z1,Z2;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	long long dx1,dx2,dy1,dy2,dz1,dz2;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%lld %lld %lld %lld %lld %lld",&X1,&X2,&Y1,&Y2,&Z1,&Z2);

		dx1=max(0LL,X2)-max(0LL,X1);
		dx2=min(0LL,X2)-min(0LL,X1);
		dy1=max(0LL,Y2)-max(0LL,Y1);
		dy2=min(0LL,Y2)-min(0LL,Y1);
		dz1=max(0LL,Z2)-max(0LL,Z1);
		dz2=min(0LL,Z2)-min(0LL,Z1);

		printf("%lld ",dx1*dy1*dz1);
		printf("%lld ",dx2*dy1*dz1);
		printf("%lld ",dx2*dy2*dz1);
		printf("%lld ",dx1*dy2*dz1);
		printf("%lld ",dx1*dy1*dz2);
		printf("%lld ",dx2*dy1*dz2);
		printf("%lld ",dx2*dy2*dz2);
		printf("%lld\n",dx1*dy2*dz2);
	}
	
	return 0;
}
