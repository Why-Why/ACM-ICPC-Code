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
// Created Time  : 2015年05月10日 星期日 22时12分19秒
// File Name     : 1014.cpp

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

int dp[70000];
int xian;
int num[10];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;

	while(1)
	{
		xian=0;

		for(int i=1;i<=6;++i)
		{
			scanf("%d",&num[i]);
			xian+=num[i]*i;
		}

		if(!xian)
			break;

		printf("Collection #%d:\n",cas++);

		if(xian&1)
		{
			puts("Can't be divided.\n");
			continue;
		}

		xian>>=1;

		memset(dp,-1,sizeof(dp));

		dp[0]=0;

		for(int i=1;i<=6;++i)
			for(int j=1;j<=xian;++j)
			{
				if(dp[j]==-1)
				{
					if(j<i)
						continue;

					if(dp[j-i]!=-1 && dp[j-i]<num[i])
						dp[j]=dp[j-i]+1;
					else
						dp[j]=-1;
				}
				else
					dp[j]=0;
			}


		if(dp[xian]==-1)
			puts("Can't be divided.\n");
		else
			puts("Can be divided.\n");
	}
	
	return 0;
}
