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
// Created Time  : 2016年09月21日 星期三 00时22分15秒
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

using namespace std;

const int MaxN=33;

long long dp[MaxN][33][33];
int num[MaxN];

long long dfs(int pos,int cou1,int cou0,bool lim,bool first) {
	if(pos<0) {
		if(cou1<=cou0) return 1;
		return 0;
	}
	if(!lim && !first && dp[pos][cou1][cou0]!=-1) return dp[pos][cou1][cou0];

	long long ret=0;
	int u=lim ? num[pos] : 1;

	for(int i=0;i<=u;++i)
		ret+=dfs(pos-1,cou1+i,cou0+((!first && !i) ? 1 : 0),lim && i==num[pos],first && !i);

	if(!lim && !first) dp[pos][cou1][cou0]=ret;
	return ret;
}

long long getans(long long x) {
	int dep=0;
	for(dep=0;x;x>>=1) num[dep++]=x&1;
	return dfs(dep-1,0,0,1,1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long L,R;
	memset(dp,-1,sizeof(dp));

	while(~scanf("%lld %lld",&L,&R)) printf("%lld\n",getans(R)-getans(L-1));

	return 0;
}
