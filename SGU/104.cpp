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
// Created Time  : 2015年08月10日 星期一 16时54分38秒
// File Name     : 104.cpp

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

const int MaxN=110;
const int INF=0x3f3f3f3f;

int F,V;
int map1[MaxN][MaxN];
int dp[MaxN][MaxN];
int ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&F,&V))
	{
		for(int i=1;i<=F;++i)
			for(int j=1;j<=V;++j)
			{
				scanf("%d",&map1[i][j]);
				dp[i][j]=0;
			}

		for(int i=0;i<=V;++i)
			dp[0][i]=0;

		for(int i=1;i<=F;++i)
			for(int j=0;j<i;++j)
				dp[i][j]=-INF;

		for(int i=1;i<=F;++i)
			for(int j=i;j<=V;++j)
				dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+map1[i][j]);

		for(int i=0,ph=F,pl=V;i<F;)
		{
			if(dp[ph][pl-1]==dp[ph][pl])
				--pl;
			else
			{
				ans[i++]=pl;
				--pl;
				--ph;
			}
		}
		
		printf("%d\n",dp[F][V]);
		for(int i=F-1;i>=1;--i)
			printf("%d ",ans[i]);
		printf("%d\n",ans[0]);
	}
	
	return 0;
}
