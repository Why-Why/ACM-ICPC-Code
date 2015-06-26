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
// Created Time  : 2015年05月11日 星期一 22时28分01秒
// File Name     : 2411.cpp

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

long long dp[200][3000];
int n,m;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cou;

	while(~scanf("%d %d",&n,&m) && n+m)
	{
		memset(dp,0,sizeof(dp));
		dp[0][(1<<m)-1]=1;
		cou=1;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				for(int k=0;k<(1<<m);++k)
				{
					if(k & (1<<(j-1)))
						dp[cou][k ^ (1<<(j-1))]+=dp[cou-1][k];
					
					if((k & (1<<(j-1)))==0 && i!=1)
						dp[cou][k ^ (1<<(j-1))]+=dp[cou-1][k];

					if(j!=1 && (k & (1<<(j-2)))==0 && (k & (1<<(j-1))))
						dp[cou][k ^ (1<<(j-2))]+=dp[cou-1][k];
				}

				++cou;
			}

		printf("%lld\n",dp[cou-1][(1<<m)-1]);
	}
	
	return 0;
}
