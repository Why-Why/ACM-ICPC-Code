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
// Created Time  : 2015年08月01日 星期六 21时39分35秒
// File Name     : 1185.cpp

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

int dp[110][4000];
int N,M;
int map1[110];

int rem[3600],bian[3000000],cou;

inline int calc(int sta)
{
	int ret=0;

	while(sta)
	{
		if(sta&1)
			++ret;
		sta>>=1;
	}

	return ret;
}

int getmax(int hang,int sta)
{
	int x=sta>>10,y=sta-(x<<10);
	int ret=0;

	if(x&map1[hang-1] || y&map1[hang])
		return 0;

	for(int i=0;i<(1<<M);++i)
		if(!(i&(i<<1)) && !(i&(i<<2)) && !(i&map1[hang-2]) && !(i&x) && !(i&y))
			ret=max(ret,dp[hang-1][bian[(i<<10)+x]]);

	return ret+calc(y);
}

int getans()
{
	for(int i=0;i<cou;++i)
		if(!(rem[i]>>10) && !((rem[i]-((rem[i]>>10)<<10))&map1[1]))
			dp[1][i]=calc(rem[i]-(rem[i]>>10)<<10);
	
	for(int i=2;i<=N;++i)
		for(int j=0;j<cou;++j)
			dp[i][j]=getmax(i,rem[j]);

	int ret=0;

	for(int i=0;i<cou;++i)
		ret=max(ret,dp[N][i]);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char ts[100];

	while(~scanf("%d %d",&N,&M))
	{
		memset(dp,0,sizeof(dp));
		cou=0;

		for(int i=0;i<(1<<M);++i)
			if(!(i&(i<<1)) && !(i&(i<<2)))
				for(int j=0;j<(1<<M);++j)
					if(!(i&j) && !(j&(j<<1)) && !(j&(j<<2)))
					{
						rem[cou++]=(i<<10)+j;
						bian[(i<<10)+j]=cou-1;
					}

		for(int i=1;i<=N;++i)
		{
			map1[i]=0;
			scanf("%s",ts);
			for(int j=0;j<M;++j)
				if(ts[j]=='H')
					map1[i]|=(1<<j);
		}

		printf("%d\n",getans());
	}

	return 0;
}
