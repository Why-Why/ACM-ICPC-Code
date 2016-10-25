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
// Created Time  : 2016年06月02日 星期四 18时40分02秒
// File Name     : 5713.cpp

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

const int MaxN=15;
const int mod=1000000009;

bool map1[MaxN][MaxN];
int N,K;
long long ans;
long long dp[(1<<MaxN)];

void init() {
	int p,cou;

	dp[0]=1;
	for(int i=1;i<(1<<N);++i) {
		cou=0;
		for(int j=0;j<N;++j) if(i&(1<<j)) p=j+1,++cou;
		if(cou==1) { dp[i]=1; continue; }
		cou=0;
		for(int j=0;j<N;++j) if(i&(1<<j) && map1[j+1][p]) ++cou;
		if(map1[p][p]) dp[i]=dp[i^(1<<(p-1))]*2%mod*((1LL<<(cou-1))-1)%mod;
		else dp[i]=dp[i^(1<<(p-1))]*((1LL<<cou)-1)%mod;

		cout<<cou<<endl;
		cout<<i<<' '<<dp[i]<<endl;
	}
}

void getans() {
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b,M;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&N,&M,&K);
		memset(map1,0,sizeof(map1));
		while(M--) {
			scanf("%d %d",&a,&b);
			map1[a][b]=map1[b][a]=1;
		}
		init();
		ans=0;
		getans();
		printf("Case #%d:\n%I64d\n",cas++,ans);
	}
	
	return 0;
}
