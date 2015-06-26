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
// Created Time  : 2015年05月19日 星期二 10时57分02秒
// File Name     : C.cpp

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

int m,t,r;
int w[1010];
int have[1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&m,&t,&r);

	for(int i=1;i<=m;++i)
	{
		scanf("%d",&w[i]);
		w[i]+=310;
	}

	if(t<r)
	{
		puts("-1");
		return 0;
	}

	int cou=0;

	for(int i=1;i<=m;++i)
	{
		cou=0;
		for(int j=1;j<=t;++j)
			if(have[w[i]-j])
				++cou;

		for(int j=1;cou<r;++j)
			if(have[w[i]-j]==0)
			{
				++cou;
				have[w[i]-j]=1;
			}
	}

	cou=0;

	for(int i=0;i<=1000;++i)
		if(have[i])
			++cou;

	printf("%d\n",cou);
	
	return 0;
}
