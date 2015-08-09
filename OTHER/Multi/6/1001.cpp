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
// Created Time  : 2015年08月06日 星期四 13时48分43秒
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

const int MaxN=100005;

int N;
int A[MaxN];
long long sum;
int temp[MaxN];

struct state
{
	int a,b;
};

state sta[MaxN];
int cou;

bool judge(int L,int R)
{
	for(int i=L;i<=R;++i)
	{
		if(A[i-1]==sum)
			continue;
		else if(A[i-1]==sum-1)
		{
			sta[cou].a=i;
			sta[cou].b=i-1;
			++cou;

			--A[i];
			++A[i-1];

			if(A[i]<0)
				return 0;
		}
		else if(A[i-1]==sum+1)
		{
			sta[cou].a=i-1;
			sta[cou].b=i;
			++cou;

			--A[i-1];
			++A[i];

			if(A[i-1]<0)
				return 0;
		}
		else
			return 0;
	}

	return A[R]==sum;
}

bool getans()
{
	if(sum%N)
		return 0;
	sum/=N;

	if(N==2)
	{
		A[1]=temp[1];
		A[2]=temp[2];

		if(A[2]-A[1]==0)
		{
			cou=0;
			return 1;
		}
		if(A[2]-A[1]==2)
		{
			sta[0].a=2;
			sta[0].b=1;
			cou=1;
			return 1;
		}
		if(A[2]-A[1]==-2)
		{
			sta[0].a=1;
			sta[0].b=2;
			cou=1;
			return 1;
		}

		return 0;
	}

	for(int i=1;i<=N;++i)
		A[i]=temp[i];
	cou=0;
	if(judge(2,N))
		return 1;

	for(int i=1;i<=N;++i)
		A[i]=temp[i];
	cou=1;
	sta[0].a=1;
	sta[0].b=N;
	++A[N];
	--A[1];
	if(A[1]>=0 && judge(2,N))
		return 1;

	for(int i=1;i<=N;++i)
		A[i]=temp[i];
	cou=1;
	sta[0].a=N;
	sta[0].b=1;
	--A[N];
	++A[1];
	if(A[N]>=0 && judge(2,N))
		return 1;

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
		sum=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&temp[i]);
			sum+=temp[i];
		}

		if(getans())
		{
			puts("YES");
			printf("%d\n",cou);
			for(int i=0;i<cou;++i)
				printf("%d %d\n",sta[i].a,sta[i].b);
		}
		else
			puts("NO");
	}

	return 0;
}
