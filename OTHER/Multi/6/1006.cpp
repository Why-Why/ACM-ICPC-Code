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
// Created Time  : 2015年08月06日 星期四 15时08分44秒
// File Name     : 1006.cpp

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

const int MaxN=100005;

int N;
int num[MaxN];
long long sum[40];

inline long long suan(int L,int R)
{
	return L*(L-1LL)/2LL+(L-1LL)*(long long)R;
}

long long getnum(int wei)
{
	long long base=(1LL<<wei);
	int p=1;
	long long sum=0;
	long long ret=0;

	if(wei==0)
		base=0;

	for(int i=1;i<=N;++i)
	{
		sum+=num[i];

		while(p<=i && sum>=base)
		{
			sum-=num[p];
			++p;
		}

		ret+=suan(p,i);
	}

	return ret;
}

long long getans()
{
	long long ret=0;

	for(int i=0;i<=35;++i)
		sum[i]=getnum(i);

/*	int L=-1;

	num[N+1]=-1;
	for(int i=1;i<=N+1;++i)
		if(num[i]==0)
		{
			if(L==-1)
				L=i;
		}
		else
		{
			if(L!=-1)
				sum[0]+=
			L=-1;
		}*/

	sum[36]=0;
	for(int i=0;i<=35;++i)
		ret+=(sum[i]-sum[i+1])*(i+1LL);

	return ret;
}

long long SUM(int L,int R)
{
	long long ret=0;

	for(int i=L;i<=R;++i)
		ret+=num[i];

	return ret;
}

long long LOG(int x)
{
	long long ret=0;

	if(x==0)
		return 0;

	while(x)
	{
		++ret;
		x>>=1;
	}

	return ret-1;
}

long long judge()
{
	long long ret=0;

	for(int i=1;i<=N;++i)
		for(int j=i;j<=N;++j)
			ret+=((long long)i+j)*(1LL+LOG(SUM(i,j)));

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	LOG(3);
	LOG(4);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		printf("%I64d\n",getans());
	}

	
	return 0;
}
