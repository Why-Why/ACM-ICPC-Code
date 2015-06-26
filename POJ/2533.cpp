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
// Created Time  : 2015年05月12日 星期二 22时15分31秒
// File Name     : 2533.cpp

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

int dp[1010];
int N;
int ans;
int num[1010];

int find(int x)
{
	int L=0,R=ans,M;

	while(R>L)
	{
		M=(L+R+1)>>1;

		if(dp[M]>=x)
			R=M-1;
		else
			L=M;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		dp[0]=0;
		ans=0;

		for(int i=1;i<=N;++i)
		{
			t=find(num[i]);
			
			if(t==ans)
				dp[++ans]=num[i];
			else
				dp[t+1]=min(dp[t+1],num[i]);
		}

		printf("%d\n",ans);
	}
	
	return 0;
}
