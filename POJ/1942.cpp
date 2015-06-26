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
// Created Time  : 2015年05月14日 星期四 22时50分43秒
// File Name     : 1942.cpp

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

long long dp[1010][1010];

void init()
{
	dp[0][0]=0;
	for(int i=1;i<=1000;++i)
		dp[i][0]=dp[0][i]=1;

	for(int i=1;i<=1000;++i)
		for(int j=1;j<=1000;++j)
			dp[i][j]=dp[i][j-1]+dp[i-1][j];
}

long long getans(long long a,long long b)
{
	if(a<=1000 && b<=1000)
		return dp[a][b];

	if(a==0 || b==0)
		return 1;

	if(a==1 || b==1)
		return max(a,b)+1;

	return getans(a-1,b)+getans(a,b-1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	long long a,b;

	while(~scanf("%lld %lld",&a,&b) && a+b)
	{
		printf("%lld\n",getans(a,b));
	}
	
	return 0;
}
