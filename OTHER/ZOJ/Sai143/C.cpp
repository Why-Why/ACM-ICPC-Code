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
// Created Time  : 2015年10月14日 星期三 22时15分29秒
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

const int MaxN=810;
const long long INF=10000000000000000LL;

long long DP1[MaxN],DP2[MaxN],*dp1,*dp2;
int N;

struct State
{
	int a,b;

	bool operator < (const State &y) const
	{
		return b<y.b;
	}
};

State sta[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;++i)
			scanf("%d %d",&sta[i].a,&sta[i].b);
		sort(sta+1,sta+N+1);

		dp1=DP1;
		dp2=DP2;
		for(int i=0;i<=N;++i) dp1[i]=-INF;
		dp1[0]=0;

		for(int i=1;i<=N;++i)
		{
			dp2[0]=dp1[1];
			dp2[N]=dp2[N-1]+sta[i].a;
			for(int j=1;j<N;++j) dp2[j]=max(dp1[j+1],dp1[j-1]+sta[i].a);
			swap(dp1,dp2);
		}

		printf("%lld\n",dp1[0]);
	}
	
	return 0;
}
