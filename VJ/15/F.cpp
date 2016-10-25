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
// Created Time  : 2016年09月21日 星期三 00时35分29秒
// File Name     : F.cpp

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

long long dp[MaxN][MaxN][1700];
int num[MaxN];
int mid;

long long dfs(int pos,int pre,bool lim) {
	if(pos<0) return pre==0;
	if(!lim && dp[pos][mid][pre]!=-1) return dp[pos][mid][pre];

	int u=lim ? num[pos] : 9,t;
	long long ret=0;

	for(int i=0;i<=u;++i) {
		t=pre+(pos-mid)*i;
		if(t>=0) ret+=dfs(pos-1,t,lim && i==num[pos]);
	}

	if(!lim) dp[pos][mid][pre]=ret;
	return ret;
}

inline long long getans(long long x) {
	if(x<0) return 0;

	int dep=0;
	for(;x;x/=10) num[dep++]=x%10;
	if(!dep) num[dep++]=0;

	long long ret=0;
	for(int i=0;i<dep;++i) {
		mid=i;
		ret+=dfs(dep-1,0,1)-1;
	}
	++ret;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	long long L,R;
	scanf("%d",&T);

	memset(dp,-1,sizeof(dp));

	while(T--) {
		scanf("%I64d %I64d",&L,&R);
		printf("%I64d\n",getans(R)-getans(L-1));
	}

	return 0;
}
