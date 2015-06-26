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
// Created Time  : 2015年05月27日 星期三 22时02分27秒
// File Name     : 2151.cpp

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

double zero[1010],daN[1010];
int M,T,N;
double p[1010][35];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double ans;

	while(~scanf("%d %d %d",&M,&T,&N))
	{
		for(int i=1;i<=T;++i)
			for(int j=1;j<=M;++j)
				scanf("%lf",&p[i][j]);

		for(int i=1;i<=T;++i)
		{
			zero[i]=1;

			for(int j=1;j<=M;++j)
				zero[i]*=(1.0-p[i][j]);
		}
	}
	
	return 0;
}
