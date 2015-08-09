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
// Created Time  : 2015年07月21日 星期二 09时43分34秒
// File Name     : 3254.cpp

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

const int mod=100000000;

int N,M;
int map1[15][15];
int rem[15];
long long dp[15][5000];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long ans;

	while(~scanf("%d %d",&N,&M))
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				scanf("%d",&map1[i][j]);

		for(int i=1;i<=M;++i)
		{
			rem[i]=0;

			for(int j=1;j<=N;++j)
				if(!map1[j][i])
					rem[i]|=(1<<(j-1));
		}

		memset(dp,0,sizeof(dp));

		for(int j=0;j<(1<<N);++j)
			if(!(j&rem[1] || j&(j<<1)))
				++dp[1][j];

		for(int i=2;i<=M;++i)
			for(int j=0;j<(1<<N);++j)
			{
				if(j&(j<<1)  || j&rem[i])
					continue;
				
				for(int k=0;k<(1<<N);++k)
				{
					if(j&k)
						continue;

					(dp[i][j]+=dp[i-1][k])%=mod;
				}
			}

		ans=0;

		for(int j=0;j<(1<<N);++j)
			(ans+=dp[M][j])%=mod;

		printf("%lld\n",ans);
	}
	
	return 0;
}
