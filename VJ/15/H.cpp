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
// Created Time  : 2016年09月21日 星期三 12时11分37秒
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

const int MaxN=11;
const int maxnum=511*9;

int dp[MaxN][5000];
int num[MaxN];

int dfs(int pos,int pre,bool lim) {
	if(pos<0) return 1;
	if(!lim && dp[pos][pre]!=-1) return dp[pos][pre];

	int u=lim ? num[pos] : 9,ret=0;

	for(int i=0;i<=u;++i)
		if(pre-(i*(1<<pos))>=0)
			ret+=dfs(pos-1,pre-(i*(1<<pos)),lim && i==num[pos]);

	if(!lim) dp[pos][pre]=ret;
	return ret;
}

inline int count(int x) {
	int ret=0,base=1;
	for(;x;x/=10,base<<=1) ret+=(x%10)*base;
	return ret;
}

int getans(int x,int K) {
	if(x<0) return 1;

	int dep=0;
	for(;x;x/=10) num[dep++]=x%10;

	return dfs(dep-1,K,1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b;
	scanf("%d",&T);

	memset(dp,-1,sizeof(dp));

	while(T--) {
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d\n",cas++,getans(b,count(a)));
	}

	return 0;
}
