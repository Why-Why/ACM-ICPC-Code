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
// Created Time  : 2016年03月31日 星期四 23时11分32秒
// File Name     : G.cpp

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

const int MaxN=1000006;
const int mod=1000000007;

long long dp[MaxN][2];
int num[MaxN];
int N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",num+i);

	dp[1][0]=num[1]-1;
	dp[1][1]=num[2]-1;
	long long ans=dp[1][0];

	for(int i=2;i<=N;++i) {
		dp[i][0]=num[i]-1;
		dp[i][1]=num[i+1]-1;

		if(num[i]>=num[i-1]) {
			(dp[i][0]+=(dp[i-1][0]*(num[i-1]-1LL))%mod)%=mod;
			(dp[i][1]+=(dp[i-1][0]*(min(num[i-1],num[i+1])-1LL))%mod)%=mod;
		}
		else {
			(dp[i][0]+=(dp[i-1][1]*(num[i]-1LL))%mod)%=mod;
			(dp[i][1]+=(dp[i-1][1]*(num[i+1]-1LL))%mod)%=mod;
		}
		(ans+=dp[i][0])%=mod;
	}
	cout<<ans<<endl;
	
	return 0;
}
