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
// Created Time  : 2015年05月26日 星期二 22时46分04秒
// File Name     : 3258.cpp

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

int L,N,M;
int num[50004];

bool judge(int x)
{
	int last=0,cou=0;

	for(int i=1;i<=N;++i)
		if(num[i]-last<x)
			++cou;
		else
			last=num[i];

	return cou<=M;
}

int getans()
{
	int L=0,R=1000000000+9,Mid;

	while(R>L)
	{
		Mid=(L+R+1)>>1;

		if(judge(Mid))
			L=Mid;
		else
			R=Mid-1;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d",&L,&N,&M))
	{
		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		sort(num+1,num+N+1);
		num[++N]=L;

		printf("%d\n",getans());
	}
	
	return 0;
}
