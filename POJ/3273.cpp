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
// Created Time  : 2015年05月26日 星期二 22时35分43秒
// File Name     : 3273.cpp

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

int n,m;
int num[100005];

inline bool judge(int lim)
{
	int sum=0;
	int cou=1;

	for(int i=1;i<=n;++i)
	{
		if(num[i]>lim)
			return 0;

		if(num[i]+sum<=lim)
			sum+=num[i];
		else
		{
			sum=num[i];
			++cou;
		}
	}

	return cou<=m;
}

int getans()
{
	int L=0,R=1000000000+9,M;

	while(R>L)
	{
		M=(R+L)>>1;

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

	while(~scanf("%d %d",&n,&m))
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&num[i]);

		printf("%d\n",getans());
	}
	
	return 0;
}
