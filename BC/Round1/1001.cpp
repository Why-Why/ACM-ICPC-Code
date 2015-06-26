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
// Created Time  : 2015年05月30日 星期六 14时06分31秒
// File Name     : 1001.cpp

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

const long long INF=10000000000000000LL;

int n;
long long m,k;
long long num[10004];

bool getans()
{
	int p=1;

	num[n+1]=INF;

	while(p<=n)
	{
		if(num[p]>m)
			return 0;

		while(num[p]<=m)
			++p;

		m=num[p-1]+k;
		--k;
	}

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int p;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %I64d %I64d",&n,&m,&k);

		for(int i=1;i<=n;++i)
			scanf("%I64d",&num[i]);

		sort(num+1,num+n+1);

		printf("Case #%d:\n",cas++);

		if(getans())
			puts("why am I so diao?");
		else
			puts("madan!");
	}
	
	return 0;
}
