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
// Created Time  : 2015年12月24日 星期四 01时00分53秒
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

const int MaxN=505;

int dp[MaxN][MaxN];
int C[MaxN];
int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",C+i),dp[i][i]=1;

	for(int L=2;L<=N;++L)
		for(int i=1,j=1+L-1;j<=N;++i,++j) {
			dp[i][j]=dp[i+1][j]+1;
			for(int k=i+1;k<=j;++k)
				if(C[i]==C[k]) {
					dp[i][j]=min(dp[i][j],max(1,dp[i+1][k-1])+dp[k+1][j]);
				}
		}
	printf("%d\n",dp[1][N]);

	return 0;
}
