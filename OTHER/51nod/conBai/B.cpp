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
// Created Time  : 2016年05月20日 星期五 18时54分36秒
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

const int MaxN=2005;
const int mod=1000000007;

long long dp[MaxN][MaxN];
int N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	dp[0][0]=1;
	dp[1][1]=1;
	for(int i=2;i<=N;++i)
		for(int j=0;j<i;++j)
			for(int k=0;k<=j;++k)
				if(dp[j][k]) {
					for(int d=-1;d<=1;++d)
						if(k+d>=0 && k+d<=N)
							(dp[i][max(k,k+d)+1]+=(dp[j][k]*dp[i-1-j][k+d])%mod)%=mod;
				}

	for(int i=1;i<=N;++i) {
		long long ans=0;
		for(int j=0;j<=N;++j)
			(ans+=dp[i][j])%=mod;
		cout<<ans<<',';
	}
	
	return 0;
}
