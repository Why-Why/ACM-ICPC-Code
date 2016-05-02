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
// Created Time  : 2016年04月30日 星期六 14时07分11秒
// File Name     : D.cpp

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

const int MaxN=10004;

long long dp[MaxN][MaxN];
int N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	N=20;

	for(int i=0;i<=N;++i) dp[i][0]=1;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) {
			for(int k=0;k<=i && j>=k*i;++k)
				dp[i][j]+=dp[i-1][j-k*i];
		}

	for(int i=1;i<=N;++i,cout<<endl)
		for(int j=1;j<=N;++j)
			printf("%5lld",dp[i][j]);
	
	return 0;
}
