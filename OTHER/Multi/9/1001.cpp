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
// Created Time  : 2015年08月18日 星期二 12时47分11秒
// File Name     : 1001.cpp

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

const int MaxN=110;
const int mod=1000000007;

int N;
long long num[MaxN];
char s[MaxN];
long long dp[MaxN][MaxN];
long long jie[MaxN];

void init()
{
	jie[0]=1;
	for(int i=1;i<=101;++i)
	{
		jie[i]=jie[i-1]*i;
		jie[i]%=mod;
	}
}

long long getnum(long long S,long long X)
{
	S=(S%mod+mod)%mod;
	X=(X%mod+mod)%mod;

	long long base=X;
	long long ret=1;
	int n=mod-2;

	while(n)
	{
		if(n&1)
			(ret*=base)%=mod;
		(base*=base)%=mod;
		n>>=1;
	}

	return (ret*S)%mod;
}

long long chuli(long long a,long long b,char c,int L1,int L2)
{
	if(L1==1 || L2==1)
	{
		if(c!='*')
		{
			(a*=jie[L2-1])%=mod;
			(b*=jie[L1-1])%=mod;

			if(c=='+')
				return (a+b)%mod;
			else
				return (a-b)%mod;
		}
		else
			return (a*b)%mod;
	}
	
	long long t=getnum(jie[L1+L2-2],jie[(L1-1)]*jie[(L2-1)]);

	if(c!='*')
	{
		(a*=jie[L2-1])%=mod;
		(b*=jie[L1-1])%=mod;
	}

	if(c=='+') return ((a+b)%mod*t)%mod;
	else if(c=='-') return ((a-b)%mod*t)%mod;
	else return ((a*b)%mod*t)%mod;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%I64d",&num[i]);
		scanf("%s",s+1);

		for(int i=1;i<=N;++i)
			dp[i][i]=num[i];

		for(int L=2;L<=N;++L)
			for(int i=1;i+L-1<=N;++i)
			{
				dp[i][i+L-1]=0;
				for(int k=1;k<L;++k)
					(dp[i][i+L-1]+=chuli(dp[i][i+k-1],dp[i+k][i+L-1],s[i+k-1],k,L-k))%=mod;
			}

		printf("%I64d\n",(dp[1][N]%mod+mod)%mod);
	}

	return 0;
}
