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
// Created Time  : 2015年09月08日 星期二 19时07分08秒
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

const int MaxN=300005;

int A[MaxN];
long long dp[5010][5010];

int X,Y,L1,L2;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,K;

	scanf("%d %d",&N,&K);

	X=N%K;
	Y=K-X;
	L1=N/K+1;
	L2=L1-1;

	for(int i=1;i<=N;++i)
		scanf("%d",&A[i]);
	sort(A+1,A+N+1);

	dp[0][0]=0;
	for(int i=1;i<=X;++i)
		dp[i][0]=dp[i-1][0]+A[i*L1]-A[(i-1)*L1+1];
	for(int j=1;j<=Y;++j)
		dp[0][j]=dp[0][j-1]+A[j*L2]-A[(j-1)*L2+1];
	for(int i=1;i<=X;++i)
		for(int j=1;j<=Y;++j)
			dp[i][j]=min(dp[i-1][j]+A[i*L1+j*L2]-A[(i-1)*L1+j*L2+1],dp[i][j-1]+A[i*L1+j*L2]-A[i*L1+(j-1)*L2+1]);

	cout<<dp[X][Y]<<endl;
	
	return 0;
}
