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
// Created Time  : 2015年08月11日 星期二 12时55分46秒
// File Name     : 1007.cpp

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

const int MaxN=200005;
const int INF=0x3f3f3f3f;

int dp[MaxN][2];
int a[MaxN];
int N;
char s[MaxN];

int getans()
{
	if(s[1]=='1')
		dp[1][0]=-INF;
	else
		dp[1][0]=0;
	if(s[1]=='0')
		dp[1][1]=-INF;
	else
		dp[1][1]=a[1];

	for(int i=2;i<=N;++i)
	{
		if(s[i]=='0')
			dp[i][1]=-INF;
		else
			dp[i][1]=max(dp[i-1][0]+a[i],dp[i-1][1]);
		if(s[i]=='1')
			dp[i][0]=-INF;
		else
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i]);
	}

	return max(dp[N][0],dp[N][1]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1,T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%s",s+1);
		N=strlen(s+1);
		for(int i=1;i<=N;++i)
			scanf("%d",&a[i]);

		printf("Case #%d: %d\n",cas++,getans());
	}
	
	return 0;
}
