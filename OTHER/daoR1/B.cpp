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
// Created Time  : 2015年07月18日 星期六 13时47分45秒
// File Name     : B.cpp

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

const int MaxN=33;
const int INF=0x3f3f3f3f;

int U[MaxN][MaxN];
int W[MaxN][MaxN];
int n,m,k;

int dp[MaxN][70][70];
int C;
int dp1[MaxN][70];
int num1[MaxN][70];
int num[MaxN][70][70];

int getnum(int x,int y,int num)
{
	return W[x][y]*(abs(num+x+y)^U[x][y]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int minn;

	scanf("%d %d %d",&n,&m,&k);

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&U[i][j]);

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&W[i][j]);

	if(n==2)
	{
		C=2*k+1;

		for(int i=1;i<=m;++i)
			for(int j=-k;j<=k;++j)
				for(int q=-k;q<=k;++q)
					num[i][j+k][q+k]=abs(j+q)+getnum(1,i,j)+getnum(2,i,q);

		for(int j=-k;j<=k;++j)
			for(int q=-k;q<=k;++q)
				dp[1][j+k][q+k]=num[1][j+k][q+k];

		for(int i=2;i<=m;++i)
			for(int j=-k;j<=k;++j)
				for(int q=-k;q<=k;++q)
				{
					minn=INF;

					for(int x=-k;x<=k;++x)
						for(int y=-k;y<=k;++y)
							minn=min(minn,dp[i-1][x+k][y+k]+abs(x+j)+abs(y+q));

					dp[i][j+k][q+k]=minn+num[i][j+k][q+k];
				}

		minn=INF;
    
		for(int j=-k;j<=k;++j)
			for(int q=-k;q<=k;++q)
				minn=min(minn,dp[m][j+k][q+k]);
    
		printf("%d\n",minn);
	}
	else if(n==1)
	{
		for(int i=1;i<=m;++i)
			for(int j=-k;j<=k;++j)
				num1[i][j+k]=getnum(1,i,j);

		for(int j=-k;j<=k;++j)
			dp1[1][j+k]=num1[1][j+k];

		for(int i=2;i<=m;++i)
			for(int j=-k;j<=k;++j)
			{
				minn=INF;

				for(int x=-k;x<=k;++x)
					minn=min(minn,dp1[i-1][x+k]+abs(x+j));

				dp1[i][j+k]=minn+num1[i][j+k];
			}

		minn=INF;

		for(int j=-k;j<=k;++j)
			minn=min(minn,dp1[m][j+k]);

		printf("%d\n",minn);
	}
	
	return 0;
}
