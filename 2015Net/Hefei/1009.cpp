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
// Created Time  : 2015年09月27日 星期日 12时22分09秒
// File Name     : 1009.cpp

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

const int MaxN=40;
const int INF=0x3f3f3f3f;

int dp[MaxN][MaxN][2000];
int N,M;

int num[MaxN][MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int sum;
	scanf("%d",&T);

	while(T--)
	{
		sum=1805;
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				scanf("%d",&num[i][j]);

		for(int i=0;i<=N;++i)
			for(int j=0;j<=M;++j)
				for(int k=0;k<=sum;++k)
					dp[i][j][k]=INF;
		/*for(int j=0;j<=M;++j)
			for(int k=0;k<=sum;++k)
				dp[0][j][k]=0;
		for(int i=0;i<=N;++i)
			for(int k=0;k<=sum;++k)
				dp[i][0][k]=0;*/

		int minn;

		dp[1][1][num[1][1]]=num[1][1]*num[1][1];
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				for(int k=num[i][j];k<=sum;++k)
				{
					minn=min(dp[i][j-1][k-num[i][j]],dp[i-1][j][k-num[i][j]]);
					if(minn!=INF)
						dp[i][j][k]=minn+num[i][j]*num[i][j];
				}

		int ans=INF;

		for(int i=0;i<=sum;++i)
			if(dp[N][M][i]!=INF)
				ans=min(ans,(N+M-1)*dp[N][M][i]-i*i);

		printf("Case #%d: %d\n",cas++,ans);
	}
	
	return 0;
}
