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
// Created Time  : 2015年12月24日 星期四 00时38分37秒
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
typedef pair<int,int> pii;
pii sta[MaxN];

int dp[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d %d",&sta[i].first,&sta[i].second);
	sort(sta+1,sta+N+1);

	int t1,t2;
	int ans=0x3f3f3f3f;
	dp[0]=0;
	for(int i=1;i<=N;++i) {
		t1=lower_bound(sta+1,sta+N+1,pii(sta[i].first-sta[i].second,0))-sta;
		--t1;
		dp[i]=dp[t1]+i-1-t1;
		ans=min(ans,dp[i]+N-i);
	}
	printf("%d\n",ans);
	
	return 0;
}
