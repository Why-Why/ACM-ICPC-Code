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
// Created Time  : 2015年05月12日 星期二 21时32分40秒
// File Name     : 3267.cpp

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

int dp[400];
char base[400];
char dic[700][30];
int N,M;

int getans(char *s1,char *s2)
{
	int p=0;

	for(int i=0;s1[i];++i)
	{
		if(s1[i]==s2[p])
			++p;

		if(s2[p]==0)
			return i+1;
	}

	return -1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int p;

	while(~scanf("%d %d",&N,&M))
	{
		scanf("%s",base+1);

		for(int i=1;i<=N;++i)
			scanf("%s",dic[i]);

		dp[M+1]=0;

		for(int i=M;i>=1;--i)
		{
			dp[i]=dp[i+1]+1;

			for(int j=1;j<=N;++j)
			{
				p=getans(base+i,dic[j]);

				if(p!=-1)
					dp[i]=min(dp[i],dp[i+p]+p-int(strlen(dic[j])));
			}
		}

		printf("%d\n",dp[1]);
	}
	
	return 0;
}
