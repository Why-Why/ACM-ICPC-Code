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
// Created Time  : 2017年03月03日 星期五 12时13分23秒
// File Name     : H.cpp

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

const int mod=10007;

int N,M;
int map1[69][9];
int dp[9][129];

inline void solve(int map1[]) {
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	int cou;

	for(int i=1;i<=M;++i)
		for(int s=0;s<(1<<(M+1));++s)
			if(dp[i-1][s]) {
				cou=0;
				if(s & (1<<(i-1))) ++cou;
				if(s & (1<<i)) ++cou;

				if(cou>map1[i]) continue;

				if(cou+2<=map1[i]) (dp[i][s | (1<<(i-1)) | (1<<i)]+=dp[i-1][s])%=mod;
				if(cou+1<=map1[i]) (dp[i][s | (1<<(i-1)) & (~(1<<i))]

				else if(cou==map1[i]) {
					(dp[i][s & (~(1<<(i-1))) & (~(1<<i))]+=dp[i-1][s])%=mod;
				}
				else if(cou==map1[i]-1)
			}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				scanf("%d",&map1[i][j]);

		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;++i) {
			solve(map1[i]);
			change();
		}
	}

	return 0;
}
