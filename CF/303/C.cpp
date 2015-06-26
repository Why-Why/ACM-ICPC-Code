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
// Created Time  : 2015年05月21日 星期四 18时37分32秒
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

int dp[100005][3];
int n;
int x[100005],h[100005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&n);

	for(int i=1;i<=n;++i)
		scanf("%d %d",&x[i],&h[i]);

	x[n+1]=x[n]+h[n]+10;

	dp[1][0]=1;
	dp[1][1]=0;
	dp[1][2]=(x[2]-x[1]>h[1]);

	for(int i=2;i<=n;++i)
	{
		if(x[i]-x[i-1]>h[i-1]+h[i])
			dp[i][0]=dp[i-1][2]+1;
		else if(x[i]-x[i-1]>h[i])
			dp[i][0]=max(dp[i-1][0],dp[i-1][1])+1;
		
	   dp[i][1]=max(dp[i-1][1],max(dp[i-1][0],dp[i-1][2]));
	   
	   if(x[i+1]-x[i]>h[i])
		   dp[i][2]=dp[i][1]+1;
	}

	printf("%d\n",max(dp[n][0],max(dp[n][1],dp[n][2])));
	
	return 0;
}
