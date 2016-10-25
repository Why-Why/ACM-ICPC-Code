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
// Created Time  : 2016年07月14日 星期四 20时56分13秒
// File Name     : E.cpp

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
#include <bitset>

using namespace std;

const int MaxN=505;

int N,K;
int c[MaxN];

bitset <505> dp[MaxN][MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;++i) scanf("%d",c+i);

	dp[0][0].set(0);
	bitset <505> t;

	for(int i=1;i<=N;++i)
		for(int j=0;j<=K;++j) {
			if(dp[i-1][j].count()) dp[i][j]|=dp[i-1][j];
			if(j>=c[i] && dp[i-1][j-c[i]].count()) {
				t.reset();
				t.set(c[i]);
				dp[i][j]|=dp[i-1][j-c[i]]|t|(dp[i-1][j-c[i]]<<c[i]);
			}
		}

	cout<<dp[N][K].count()<<endl;
	for(int i=0;i<=K;++i)
		if(dp[N][K][i]) printf("%d ",i);
	puts("");

	return 0;
}
