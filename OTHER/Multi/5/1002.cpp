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
// Created Time  : 2015年08月04日 星期二 12时25分28秒
// File Name     : 1002.cpp

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

const int MaxN=500005;

int N,M,Z,L;

int getans()
{
	long long A=0;
	long long ret=0;

	for(int i=1;i<=N;++i)
	{
		ret=ret^A;
		A=(A*M+(long long)Z)%L;
	}

	int cou=0;
	int ans=0;

	while(ret)
	{
		if(ret&1)
			ans+=(1<<(cou+1));
		ret>>=1;
		++cou;
	}

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	long long a,b;
	long long fu;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d %d",&N,&M,&Z,&L);

		printf("%d\n",getans());
	}
	
	return 0;
}
