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
// Created Time  : 2015年05月30日 星期六 14时18分33秒
// File Name     : 1003.cpp

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

int N;
long long num[100005];

inline bool judge(long long x)
{
	long long last=num[1]-x;

	for(int i=2;i<=N;++i)
	{
		if(num[i]+x<=last)
			return 0;

		last=max(num[i]-x,last+1);
	}

	return 1;
}

long long getans()
{
	long long L=0,R=10000000,M;

	while(R>L)
	{
		M=(L+R)>>1;

		if(judge(M))
			R=M;
		else
			L=M+1;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%I64d",&num[i]);

		printf("Case #%d:\n",cas++);
		printf("%I64d\n",getans());
	}
	
	return 0;
}
