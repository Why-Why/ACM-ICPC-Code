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
// Created Time  : 2015年07月18日 星期六 12时12分42秒
// File Name     : 1191.cpp

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

int map1[10][10];
int dp[10][10][10][10][20];

int sum(int i1,int j1,int i2,int j2)
{
	int ret=map1[i2][j2]-map1[i1-1][j2]-map1[i2][j1-1]+map1[i1-1][j1-1];

	ret*=ret;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int minn;

	scanf("%d",&N);

	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j)
			scanf("%d",&map1[i][j]);

	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j)
			map1[i][j]+=map1[i][j-1];

	for(int j=1;j<=8;++j)
		for(int i=1;i<=8;++i)
			map1[i][j]+=map1[i-1][j];

	for(int i1=1;i1<=8;++i1)
		for(int j1=1;j1<=8;++j1)
			for(int i2=i1;i2<=8;++i2)
				for(int j2=j1;j2<=8;++j2)
					dp[i1][j1][i2][j2][0]=sum(i1,j1,i2,j2);

	for(int k=1;k<N;++k)
		for(int i1=1;i1<=8;++i1)
			for(int j1=1;j1<=8;++j1)
				for(int i2=i1;i2<=8;++i2)
					for(int j2=j1;j2<=8;++j2)
					{
						minn=0x3f3f3f3f;

						for(int q=i1;q<i2;++q)
							minn=min(minn,min(dp[i1][j1][q][j2][k-1]+sum(q+1,j1,i2,j2),dp[q+1][j1][i2][j2][k-1]+sum(i1,j1,q,j2)));

						for(int q=j1;q<j2;++q)
							minn=min(minn,min(dp[i1][j1][i2][q][k-1]+sum(i1,q+1,i2,j2),dp[i1][q+1][i2][j2][k-1]+sum(i1,j1,i2,q)));

						dp[i1][j1][i2][j2][k]=minn;
					}

	long double ans=(long double)(dp[1][1][8][8][N-1]);

	printf("%.3f\n",sqrt(ans/N-(long double)map1[8][8]*map1[8][8]*1.0/((long double)(N)*N)));

	return 0;
}
