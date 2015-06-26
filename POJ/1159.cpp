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
// Created Time  : 2015年05月13日 星期三 10时30分19秒
// File Name     : 1159.cpp

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

int N;
char s1[5010],s2[5010];
short dp[5010][5010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans;

	scanf("%d %s",&N,s1+1);
	{
		for(int i=1;i<=N;++i)
		{
			s2[N+1-i]=s1[i];
			dp[0][i]=dp[i][0]=0;
		}

		dp[0][0]=0;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(s1[i]==s2[j])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

		ans=0;

		for(int i=1;i<=N;++i)
		{
			ans=max(ans,2*int(dp[i][N+1-i])-1);
			ans=max(ans,2*int(dp[i][N-i]));
		}

		printf("%d\n",N-ans);
	}
	
	return 0;
}
