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
// Created Time  : 2016年09月07日 星期三 23时42分32秒
// File Name     : C.cpp

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

const int MaxN=100005;
const long long INF=10000000000000000LL;

int N;
char s1[MaxN],s2[MaxN];
char i1[MaxN],i2[MaxN];
int c[MaxN];
long long dp[MaxN][2];

inline void inv(char *s1,char *s2) {
	int len=strlen(s2);
	for(int i=0;i<len;++i) s1[i]=s2[len-1-i];
	s1[len]=0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",c+i);
	dp[0][0]=dp[0][1]=0;

	s1[0]=i1[0]=0;
	for(int i=1;i<=N;++i) {
		scanf("%s",s2);
		inv(i2,s2);
		dp[i][0]=dp[i][1]=INF;

		if(strcmp(s2,s1)>=0) dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if(strcmp(s2,i1)>=0) dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if(strcmp(i2,s1)>=0) dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
		if(strcmp(i2,i1)>=0) dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);

		strcpy(s1,s2);
		strcpy(i1,i2);
	}

	long long ans=min(dp[N][0],dp[N][1]);
	if(ans>=INF) ans=-1;
	cout<<ans<<endl;

	return 0;
}
