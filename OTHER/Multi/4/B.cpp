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
// Created Time  : 2015年07月30日 星期四 12时10分00秒
// File Name     : B.cpp

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

const int MaxN=1000006;

int N;
long long num[1000006];
long long D[MaxN];
long long S[MaxN],X[MaxN];

long long gcd(long long a,long long b)
{
	if(!a)
		return b;

	return gcd(b%a,a);
}

int getans1()
{
	int ret=0;
	int cou=1;

	for(int i=2;i<N;++i)
		if(D[i]==D[i-1])
			++cou;
		else
		{
			ret=max(ret,cou);
			cou=1;
		}

	return ret;
}

int getans2()
{
	int ret=0;
	int cou=1;

	for(int i=2;i<N;++i)
		if(S[i]==S[i-1] && X[i]==X[i-1])
			++cou;
		else
		{
			ret=max(ret,cou);
			cou=1;
		}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	long long t;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		if(N==0)
		{
			puts("0");
			continue;
		}

		for(int i=1;i<=N;++i)
			scanf("%I64d",&num[i]);

		for(int i=1;i<N;++i)
		{
			D[i]=num[i+1]-num[i];
			t=gcd(num[i+1],num[i]);
			S[i]=num[i+1]/t;
			X[i]=num[i]/t;
		}

		printf("%d\n",max(getans1(),getans2())+1);
	}

	return 0;
}
