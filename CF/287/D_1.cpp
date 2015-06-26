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
// Created Time  : 2015年05月19日 星期二 21时48分52秒
// File Name     : D_1.cpp

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

int n,m,k;
long long dp[1010][110];
long long pre[1010];
long long dui[1010][110];

void init()
{
	pre[1]=9%m;

	for(int i=2;i<=1000;++i)
		pre[i]=(pre[i-1]*10)%m;
}

bool judge(long long x,int mod)
{
	int base=10;

	while(base/10<=x)
	{
		if((x%base)>0 && (x%base)%k==mod)
			return 1;

		base*=10;
	}

	return 0;
}

void getdui()
{
	long long base=1;
	int cou=0;

	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<k;++j)
		{
			cou=0;
			for(long long c=base;c<base*10;++c,++cou)
				if(judge(c,j))
					++dui[i][j];
			dui[i][j]%=m;
		}
		base*=10;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&n,&k,&m);

	init();
//	getdui();

	long long cou[20];

	for(int i=1;i<10;++i)
		dp[1][i%k]=(dp[1][i%k]+1)%m;

	for(int i=1;i<n;++i)
	{
		for(int r=1;r<10;++r)
		{
			cou[r]=0;
			dp[i+1][r%k]=(dp[i+1][r%k]+pre[i])%m;
		}

		for(int r=0;r<10;++r)
		{
			for(int j=0;j<k;++j)
			{
				if(r && (10*j+r)%k==r%k)
					continue;

				dp[i+1][(10*j+r)%k]=(dp[i+1][(10*j+r)%k]+dp[i][j])%m;
			}
		}
	}

	for(int i=1;i<=n;++i,cout<<endl)
		for(int j=0;j<k;++j)
			cout<<dp[i][j]-dui[i][j]<<' ';

	printf("%lld\n",dp[n][0]);
	
	return 0;
}
