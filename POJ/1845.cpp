// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月26日 星期二 12时24分25秒
// File Name     : 1845.cpp

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

const int mod=9901;

bool vis[20005];
long long prime[20000],pcou=0;
int cou;
long long rem[100];
long long remk[100];

void init()
{
	for(int i=2;i<=20000;++i)
		if(!vis[i])
		{
			prime[pcou++]=i;

			for(int j=i*i;j<=20000;j+=i)
				vis[j]=1;
		}
}

void chuli(long long a,long long b)
{
	int tot=0;
	cou=0;

	for(int i=0;i<pcou;++i)
	{
		while(a % prime[i] ==0)
		{
			++tot;
			a/=prime[i];
		}

		if(tot)
		{
			rem[cou]=prime[i];
			remk[cou++]=tot*b;
			tot=0;
		}

		if(a==1)
			break;
	}

	if(a!=1)
	{
		rem[cou]=a;
		remk[cou++]=b;
	}
}

long long getpow(long long a,long long b)
{
	long long base=a;
	long long ret=1;

	while(b)
	{
		if(b&1)
			(ret*=base)%=mod;

		(base*=base)%=mod;
		b>>=1;
	}

	return ret;
}

long long getsum(long long p,long long k)
{
	long long ret=0;

	if(k==1)
		return p%mod;

	if(k==0)
		return 0;

	if(k & 1)
	{
		(ret+=getpow(p,k))%=mod;
		--k;
	}

	k>>=1;

	(ret+=(1+getpow(p,k))*(getsum(p,k)))%=mod;

	return ret;
}

long long getans()
{
	long long ret=1;
	long long temp;

	for(int i=0;i<cou;++i)
	{
		temp=getsum(rem[i],remk[i])+1;
		(ret*=temp)%=mod;
	}

	return ret;;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	long long A,B;

	while(~scanf("%lld %lld",&A,&B))
	{
		if(A==0)
		{
			printf("%d\n",0);
			continue;
		}

		chuli(A,B);
		printf("%lld\n",getans());
	}
	
	return 0;
}
