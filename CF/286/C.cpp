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
// Created Time  : 2015年05月22日 星期五 10时54分11秒
// File Name     : C.cpp

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

int n,d;
int dp[30004][800];
int rem[30004];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&n,&d);

	int ans=0;
	int t;

	for(int i=1;i<=n;++i)
	{
		scanf("%d",&t);
		++rem[t];
	}

	memset(dp,-1,sizeof(dp));
	dp[d][400]=rem[d];

	for(int i=d;i<=30000;++i)
		for(int j=-300;j<=300;++j)
		{
			if(dp[i][j+400]==-1)
				continue;

			ans=max(ans,dp[i][j+400]);

			if(i+d+j<=30000 && d+j>0)
				dp[i+d+j][j+400]=max(dp[i+d+j][j+400],dp[i][j+400]+rem[i+d+j]);

			if(i+d+j+1<=30000 && d+j+1>0)
				dp[i+d+j+1][j+401]=max(dp[i+d+j+1][j+401],dp[i][j+400]+rem[i+d+j+1]);

			if(i+d+j-1<=30000 && d+j-1>0)
				dp[i+d+j-1][j+399]=max(dp[i+d+j-1][j+399],dp[i][j+400]+rem[i+d+j-1]);
		}

	printf("%d\n",ans);
	
	return 0;
}
