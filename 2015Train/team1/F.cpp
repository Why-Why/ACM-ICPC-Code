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
// Created Time  : 2015年10月20日 星期二 09时28分54秒
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

const int mod=1000000007;

int N,M;
long long dp[60][10];
long long guan[60];

long long getans(int a,int b,int c)
{
	int temp;

	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=M;++i)
	{
		temp=0;
		if(guan[i] & (1LL<<a)) temp |= 1;
		if(guan[i] & (1LL<<b)) temp |= 2;
		if(guan[i] & (1LL<<c)) temp |= 4;

		for(int k=0;k<8;++k)
			(dp[i][k^temp]+=dp[i-1][k]+dp[i-1][k^temp])%=mod;
	}

	if(a==b && b==c) temp=1;
	else if(a==b || b==c) temp=3;
	else temp=6;

	return (dp[M][7]*temp)%mod;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int t,c;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		for(int i=1;i<=M;++i)
		{
			scanf("%d",&c);
			guan[i]=0;
			while(c--)
			{
				scanf("%d",&t);
				guan[i]|=(1LL<<t);
			}
		}

		long long ans=0;
		for(int i=1;i<=N;++i)
			for(int j=i;j<=N;++j)
				for(int k=j;k<=N;++k)
					(ans+=getans(i,j,k))%=mod;

		printf("Case #%d: %I64d\n",cas++,ans);
	}
	
	return 0;
}
