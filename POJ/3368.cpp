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
// Created Time  : 2015年07月17日 星期五 17时11分45秒
// File Name     : 3368.cpp

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

int dp[MaxN][20];
int logN[MaxN];			//!!!

void init(int N,int num[])
{
	logN[0]=-1;

	for(int i=1;i<=N;++i)
	{
		logN[i]=logN[i-1]+((i&(i-1))==0);
		dp[i][0]=num[i];
	}

	for(int j=1;j<=logN[N];++j)
		for(int i=1;i+(1<<j)-1<=N;++i)
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int RMQ(int a,int b)
{
	if(a>b)
		return 0;

	int k=logN[b-a+1];

	return max(dp[a][k],dp[b-(1<<k)+1][k]);
}

int num[MaxN];
int rem[MaxN],wei[MaxN];
int N,Q;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int a,b;

	while(~scanf("%d",&N) && N)
	{
		scanf("%d",&Q);

		rem[1]=1;

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		for(int i=2;i<=N;++i)
			if(num[i]==num[i-1])
				rem[i]=rem[i-1]+1;
			else
				rem[i]=1;

		wei[N]=N;

		for(int i=N-1;i>=1;--i)
			if(num[i]==num[i+1])
				wei[i]=wei[i+1];
			else
				wei[i]=i;

		init(N,rem);

		while(Q--)
		{
			scanf("%d %d",&a,&b);
			printf("%d\n",max(RMQ(wei[a]+1,b),min(wei[a],b)-a+1));
		}
	}
	
	return 0;
}
