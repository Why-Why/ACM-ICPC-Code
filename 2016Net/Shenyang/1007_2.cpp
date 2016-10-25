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
// Created Time  : 2016年09月19日 星期一 19时46分42秒
// File Name     : 1007_2.cpp

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

long long dp[MaxN][5];
int num[MaxN];

inline int zhuan(int sta,int n) {
	if((n&1)==(sta>>1)) return sta^1;
	if(sta==1 || sta==2) return ((n&1)<<1)|1;
	return -1;
}

long long dfs(int pos,int pre,bool lim,bool first) {
	if(pos<0) {
		if(first) return 0;
		if(pre==2 || pre==1) return 1;
		return 0;
	}
	if(!lim && !first && dp[pos][pre]!=-1) return dp[pos][pre];

	int maxn=lim ? num[pos] : 9,t;
	long long ret=0;

	for(int i=0;i<=maxn;++i) {
		if(!first) t=zhuan(pre,i);
		else t=((i&1)<<1)|1;

		if(t!=-1) ret+=dfs(pos-1,t,lim && i==num[pos],first && !i);
	}

	if(!lim && !first) dp[pos][pre]=ret;
	return ret;
}

inline long long getans(long long x) {
	int dep=0;
	for(;x;x/=10) num[dep++]=x%10;
	memset(dp,-1,sizeof(dp));

	return dfs(dep-1,0,1,1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	long long a,b;

	scanf("%d",&T);
	while(T--) {
		scanf("%I64d %I64d",&a,&b);
		--a;
		printf("Case #%d: %I64d\n",cas++,getans(b)-getans(a));
	}

	return 0;
}
