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
// Created Time  : 2016年09月20日 星期二 00时02分50秒
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

const int MaxN=21;

int num[MaxN];
long long dp[MaxN][13][(1<<10)+1];
int K;

inline int count(int x) {
	int ret=0;
	for(;x;x-=(x&(-x))) ++ret;
	return ret;
}

inline int getfirst(int sta,int p) {
	sta=sta & (~((1<<p)-1));
	if(sta==0) return -1;
	sta=sta&(-sta);

	int ret=0;
	for(;sta;sta>>=1) ++ret;
	return ret-1;
}

long long dfs(int pos,int pre,bool lim,bool first) {
	if(pos<0) {
		if(first) return 0;
		if(count(pre)==K) return 1;
		return 0;
	}
	if(!lim && !first && dp[pos][K][pre]!=-1) return dp[pos][K][pre];

	int u=lim ? num[pos] : 9,t,tt;
	long long ret=0;

	for(int i=0;i<=u;++i) {
		if(first && !i) tt=0;
		else {
			t=getfirst(pre,i);
			if(t==-1) tt=pre | (1<<i);
			else tt=(pre^(1<<t)) | (1<<i);
		}

		ret+=dfs(pos-1,tt,lim && i==num[pos],first && !i);
	}

	if(!lim && !first) dp[pos][K][pre]=ret;
	return ret;
}

inline long long getans(long long x) {
	if(!x) return 0;
	int dep=0;
	for(;x;x/=10) num[dep++]=x%10;

	return dfs(dep-1,0,1,1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	long long L,R;
	scanf("%d",&T);

	memset(dp,-1,sizeof(dp));

	while(T--) {
		scanf("%I64d %I64d %d",&L,&R,&K);
		--L;
		printf("Case #%d: %I64d\n",cas++,getans(R)-getans(L));
	}

	return 0;
}
