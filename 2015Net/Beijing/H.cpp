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
// Created Time  : 2015年09月20日 星期日 12时49分33秒
// File Name     : H.cpp

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

double num[10000];
double len[10000];
int cou=0;
double k;

void init()
{
	num[0]=0.0;
	len[0]=0.5;

	for(int i=1;i<=500;++i)
	{
		len[i]=len[i-1]/2.0;
		num[i]=num[i-1]+len[i];
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%lf",&k);
		int t=lower_bound(num,num+501,k)-num;
		if(num[t]==k) printf("-1\n");
		else printf("%d\n",4*t);
	}
	
	return 0;
}
