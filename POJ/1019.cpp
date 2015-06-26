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
// Created Time  : 2015年05月14日 星期四 22时29分47秒
// File Name     : 1019.cpp

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

long long A[100000];

void init()
{
	int base=0;
	int cheng=1;

	A[0]=0;

	for(int i=1;i<=99999;++i)
	{
		if(i==cheng)
		{
			++base;
			cheng*=10;
		}

		A[i]=A[i-1]+base;
	}

	for(int i=1;i<=99999;++i)
		A[i]=A[i-1]+A[i];
}

int find(long long x)
{
	int L=0,R=99999,M;

	while(R>L)
	{
		M=(L+R)>>1;

		if(A[M]<x)
			L=M+1;
		else
			R=M;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T;
	int num;
	long long cou;
	long long a;
	int base=0;
	int cheng=1;

	scanf("%d",&T);

	while(T--)
	{
		base=0;
		cheng=1;
		scanf("%lld",&a);

		num=find(a);
		a-=A[num-1];
		
		for(int i=1;i<=num;++i)
		{
			if(i==cheng)
			{
				++base;
				cheng*=10;
			}

			if(a<=base)
			{
				a=base-a;

				for(int k=0;k<a;++k)
					i/=10;

				printf("%d\n",i%10);
				break;
			}

			a-=base;
		}
	}
	
	return 0;
}
