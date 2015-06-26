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
// Created Time  : 2015年05月10日 星期日 21时21分45秒
// File Name     : 1276.cpp

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

int dp[100005];
int N;
int num[12],D[12];
int cash;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&cash,&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%d %d",&num[i],&D[i]);

		memset(dp,-1,sizeof(dp));
		dp[0]=0;

		for(int i=1;i<=N;++i)
			for(int j=D[i];j<=cash;++j)
				if(dp[j]==-1)
				{
					if(dp[j-D[i]]!=-1 && dp[j-D[i]]<num[i])
						dp[j]=dp[j-D[i]]+1;
					else
						dp[j]=-1;
				}
				else
					dp[j]=0;

		for(int i=cash;i>=0;--i)
			if(dp[i]!=-1)
			{
				printf("%d\n",i);
				break;
			}
	}
	
	return 0;
}
