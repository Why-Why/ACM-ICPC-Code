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
// Created Time  : 2015年07月03日 星期五 22时46分05秒
// File Name     : A_1.cpp

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
int num[100];
int rem1[100],rem2[100],cou1,cou2;

bool dfs(int d)
{
	if(d==N+1)
		return 1;

	if(cou1+cou1<N)
	{
		rem1[cou1++]=num[d];
		
		if(dfs(d+1))
			return 1;

		--cou1;
	}

	if(cou2<cou1 && num[d]==rem1[cou2])
	{
		rem2[cou2++]=num[d];

		if(dfs(d+1))
			return 1;

		--cou2;
	}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		cou1=cou2=0;

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		if(dfs(1))
			puts("Good job!!");
		else
			puts("What a pity!");
	}
	
	return 0;
}
