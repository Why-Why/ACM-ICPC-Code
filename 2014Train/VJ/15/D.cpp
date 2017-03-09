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
// Created Time  : 2016年09月21日 星期三 00时16分22秒
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

const int MaxN=21;

long long dp[MaxN][11];
int num[MaxN];

long long dfs(int pos,int pre,bool lim) {
	if(pos<0) return 1;
	if(!lim && dp[pos][pre]!=-1) return dp[pos][pre];

	int u=lim ? num[pos] : 9;
	long long ret=0;

	for(int i=0;i<=u;++i)
		if(pre!=4 || i!=9)
			ret+=dfs(pos-1,i,lim && i==num[pos]);

	if(!lim) dp[pos][pre]=ret;
	return ret;
}

long long getans(long long x) {
	int dep=0;
	for(;x;x/=10) num[dep++]=x%10;

	return dfs(dep-1,0,1)-1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	long long x;

	memset(dp,-1,sizeof(dp));

	scanf("%d",&T);
	while(T--) {
		scanf("%I64d",&x);
		printf("%I64d\n",x-getans(x));
	}

	return 0;
}
