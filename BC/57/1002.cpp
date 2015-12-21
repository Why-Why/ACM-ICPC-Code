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
// Created Time  : 2015年09月26日 星期六 19时38分38秒
// File Name     : 1002.cpp

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

const int MaxN=200005;
const int mod=1000000007;

int HASH[MaxN],Hcou;

int hash(int x)
{
	return lower_bound(HASH,HASH+Hcou,x)-HASH;
}

int N;

struct State
{
	int l,r;
	
	bool operator < (const State & b) const
	{
		if(l==b.l) return r<b.r;
		return l<b.l;
	}
}sta[MaxN];

int rem[MaxN];

long long CHANG;

long long _pow(long long a,long long n)
{
	long long base=a;
	long long ret=1;

	while(n)
	{
		if(n&1) (ret*=base)%=mod;
		(base*=base)%=mod;
		n>>=1;
	}
	return ret;
}

long long getans(long long k,long long L)
{
	return (L*((CHANG-_pow(2,N-k)+mod)%mod))%mod;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		CHANG=_pow(2,N);
		Hcou=0;
		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&sta[i].l,&sta[i].r);
			HASH[Hcou++]=sta[i].l;
			HASH[Hcou++]=sta[i].r;
		}
		sort(HASH,HASH+Hcou);
		Hcou=unique(HASH,HASH+Hcou)-HASH;

		for(int i=0;i<=Hcou;++i) rem[i]=0;
		for(int i=1;i<=N;++i)
		{
			++rem[hash(sta[i].l)];
			--rem[hash(sta[i].r)];
		}

		long long ans=0;
		long long sum=0;
		sum=rem[0];
		for(int i=1;i<Hcou;++i)
		{
			(ans+=getans(sum,HASH[i]-HASH[i-1]))%=mod;
			sum+=rem[i];
		}

		printf("%d\n",(int)ans);
	}
	
	return 0;
}
