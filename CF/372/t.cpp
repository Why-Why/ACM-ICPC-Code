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
// Created Time  : 2017年01月17日 星期二 19时29分41秒
// File Name     : t.cpp

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

long long dp[55][55];
int n,m;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	n=m=31;

	dp[1][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(i!=1 || j!=1)
				dp[i][j]=dp[i-1][j]+dp[i][j-1];

	for(int i=1;i<=n;++i,cout<<endl)
		for(int j=1;j<=m;++j) cout<<dp[i][j]<<' ';

	return 0;
}
