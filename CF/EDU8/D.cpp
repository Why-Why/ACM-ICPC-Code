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
// Created Time  : 2016年02月19日 星期五 23时46分10秒
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

const int MaxN=2005;
const int mod=1000000007;

char a[MaxN],b[MaxN];
char *num;
int m,d,len;
long long *dp[MaxN];
long long dp1[MaxN][MaxN],dp2[MaxN][MaxN];

void dfs(int p,int base,bool x) {
	if(
}

long long getans(char a[],long long dp1[MaxN][]) {
	dp=dp1;
	num=a;
	dfs(0,1%m,0);
	return dp[len-1][0];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %s %s",&m,&d,a,b);
	len=strlen(a);

	long long ans1=getans(a,dp1);
	long long ans2=getans(b,dp2);

	printf("%d\n",(int)(((ans2-ans1)%mod+mod)%mod));
	
	return 0;
}
