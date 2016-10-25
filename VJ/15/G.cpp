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
// Created Time  : 2016年09月21日 星期三 00时52分05秒
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

const int MaxN=11;

int dp[MaxN][10][13];
int num[MaxN];

int dfs(int pos,int pre,int mod,bool lim) {
	if(pos<0) return mod==0;
	if(!lim && dp[pos][pre][mod]!=-1) return dp[pos][pre][mod];

	long long ret=0;
	int u=lim ? num[pos] : 9;

	for(int i=0;i<=u;++i)
		if(pre!=1 || i!=3)
			ret+=dfs(pos-1,i,(mod*10+i)%13,lim && i==num[pos]);

	if(!lim) dp[pos][pre][mod]=ret;
	return ret;
}

int getans(int x) {
	int tx=x;
	int dep=0;
	for(;x;x/=10) num[dep++]=x%10;

	return tx/13+1-dfs(dep-1,0,0,1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	memset(dp,-1,sizeof(dp));

	int a;
	while(~scanf("%d",&a)) printf("%d\n",getans(a));

	return 0;
}
