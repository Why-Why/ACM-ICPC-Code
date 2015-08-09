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
// Created Time  : 2015年07月20日 星期一 18时54分22秒
// File Name     : 1925.cpp

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

const int MaxN=2000006;
const int INF=0x3f3f3f3f-1;

int dp[MaxN];
int N;
int remX[5010],remY[5010];

inline bool judge(long long d,int id)
{
	long long dy=remY[id]-remY[1],y=remY[id];

	return d*d<=y*y-dy*dy;
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int ans;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%d %d",&remX[i],&remY[i]);

		for(int i=0;i<MaxN;++i)
			dp[i]=INF;

		dp[remX[1]]=0;
		ans=INF;

		for(int i=2;i<N;++i)
			for(int d=1;;++d)
			{
				if(remX[i]-d<remX[1] || !judge(d,i))
					break;

				if(remX[i]+d>=remX[N])
					dp[remX[N]]=min(dp[remX[N]],dp[remX[i]-d]+1);			// !!!
				else
					dp[remX[i]+d]=min(dp[remX[i]+d],dp[remX[i]-d]+1);
			}

		for(int d=1;remX[N]-d>=remX[1] && judge(d,N);++d)
			ans=min(ans,dp[remX[N]-d]+1);

		ans=min(ans,dp[remX[N]]);

		if(ans>=INF)
			ans=-1;

		printf("%d\n",ans);
	}
	
	return 0;
}
