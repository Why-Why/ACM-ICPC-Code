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
// Created Time  : 2015年07月20日 星期一 20时03分48秒
// File Name     : 3034.cpp

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

const int MaxN=42;

int dp[MaxN][MaxN][15];
int N,D,M;
int map1[MaxN][MaxN][15];

int gcd(int a,int b)
{
	if(!a)
		return b;

	return gcd(b%a,a);
}

int sum(int x1,int y1,int x2,int y2,int t)
{
	int dx=x2-x1,dy=y2-y1;
	int temp=gcd(abs(dx),abs(dy));
	int ret=0;

	if(temp)
	{
		dx/=temp;
		dy/=temp;
	}

	for(int i=0;i<=temp;++i)
		ret+=map1[x1+i*dx+5][y1+i*dy+5][t];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int x,y,t;
	int maxn;

	while(~scanf("%d %d %d",&N,&D,&M) && N+D+M)
	{
		memset(dp,0,sizeof(dp));
		memset(map1,0,sizeof(map1));

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&x,&y,&t);
			++map1[x+5][y+5][t];
		}

		for(int i=1;i<=10;++i)
			for(x=-5;x<N+6;++x)
				for(y=-5;y<N+6;++y)
				{
					maxn=0;

					for(int x1=-5;x1<N+6;++x1)
						for(int y1=-5;y1<N+6;++y1)
							if(D*D>=(x-x1)*(x-x1)+(y-y1)*(y-y1))
								maxn=max(maxn,dp[x1+5][y1+5][i-1]+sum(x,y,x1,y1,i));

					dp[x+5][y+5][i]=maxn;
				}

		maxn=0;

		for(int i=-5;i<N+6;++i)
			for(int j=-5;j<N+6;++j)
				maxn=max(maxn,dp[i+5][j+5][10]);

		printf("%d\n",maxn);
	}
	
	return 0;
}
