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
// Created Time  : 2015年07月24日 星期五 22时49分05秒
// File Name     : 1004_1.cpp

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
const long long INF=1000000000000000LL;

int N,K,L;

int wei[2][MaxN];
int cou;
long long dp[2][MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	long long L1,L2;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&L,&N,&K);
		L1=L2=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&a,&b);

			if((a<<1)>=L)
				while(b--)
					wei[1][++L2]=L-a;
			else
				while(b--)
					wei[0][++L1]=a;
		}

		sort(wei[0]+1,wei[0]+L1+1);
		sort(wei[1]+1,wei[1]+L2+1);

		dp[0][0]=dp[1][0]=0;

		long long ans=INF;

		for(int i=1;i<=L1;++i)
			if(i<=K)
				dp[0][i]=(wei[0][i]<<1);
			else
				dp[0][i]=dp[0][i-K]+(wei[0][i]<<1);

		for(int i=1;i<=L2;++i)
			if(i<=K)
				dp[1][i]=(wei[1][i]<<1);
			else
				dp[1][i]=dp[1][i-K]+(wei[1][i]<<1);

		ans=dp[1][L2]+dp[0][L1];

		for(int i=0;i<=K && i<=L1 && i<=L2;++i)
			ans=min(ans,L+dp[0][L1-i]+dp[1][L2-(K-i)]);

		if(K>(L1+L2))									//!!!!!
			ans=min(ans,(long long)L);

		printf("%I64d\n",ans);
	}
	
	return 0;
}
