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
// Created Time  : 2016年01月17日 星期日 09时30分48秒
// File Name     : A.cpp

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

int N;
int num[MaxN];
int dp[MaxN];

inline bool judge(int num[],int len) {
	for(int i=1;i<len;++i) if(num[i]<=num[i-1]) {
		cerr<<"NONONO";
		exit(1);
	}
	if(len==2)
		return num[1]-num[0]<31;
	else if(len==3) {
		if(num[1]-num[0]>=21 || num[2]-num[1]>=21) return 0;
		if(num[1]-num[0]>10 && num[2]-num[1]>10) return 0;
		return 1;
	}
	else if(len==4) {
		for(int i=1;i<len;++i)
			if(num[i]-num[i-1]>10) return 0;
		return 1;
	}
	else {
		cerr<<"NO";
		exit(1);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) {
			scanf("%d",num+i);
			dp[i]=0;
		}
		num[0]=111;
		dp[0]=0;

		for(int i=1;i<=N;++i) {
			dp[i]=dp[i-1]+3;
			for(int j=1;j<4;++j) {
				if(num[i-j]>=num[i-j+1]) break;
				if(judge(num+i-j,j+1)) dp[i]=min(dp[i-j-1]+3-j,dp[i]);
			}
		}
		printf("Case #%d: %d\n",cas++,dp[N]);
	}
	
	return 0;
}
