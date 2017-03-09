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
// Created Time  : 2016年10月26日 星期三 22时32分36秒
// File Name     : J.cpp

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

const int INF=0x3f3f3f3f;

typedef pair<int,int> pii;

int N;
pii num[103];

pii dp[103][10003];

pii operator + (const pii & a,const pii & b) {
	return pii(a.first+b.first,a.second+b.second);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int sum=0;

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",&num[i].second),sum+=num[i].second;
	for(int i=1;i<=N;++i) scanf("%d",&num[i].first);

	for(int i=0;i<=N;++i)
		for(int j=0;j<=10000;++j)
			dp[i][j].first=INF;
	dp[0][0]=pii(0,0);

	for(int i=1;i<=N;++i) {
		for(int j=num[i].first;j<=10000;++j)
			dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i-1][j-num[i].first]+pii(1,-num[i].second)));
		for(int j=0;j<num[i].first;++j) dp[i][j]=min(dp[i][j],dp[i-1][j]);
	}

	pii ans(INF,INF);
	for(int i=sum;i<=10000;++i) ans=min(ans,dp[N][i]);

	printf("%d %d\n",ans.first,sum+ans.second);

	return 0;
}
