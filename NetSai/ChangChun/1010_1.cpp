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
// Created TimI64 : 2015年09月16日 星期三 00时23分05秒
// File Name     : 1010_1.cpp

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

const int MaxN=20;

long long a[MaxN];
long long t[MaxN];
long long M[MaxN];
long long n,m;
int p[MaxN];
int k;

long long F[100010];

long long inv(long long a,long long m)
{
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

void init(long long p)
{
	F[0]=1;
	for(int i=1;i<=p;++i)
		F[i]=F[i-1]*i%p;
}

long long Lucas(long long n,long long m,long long p)
{
	init(p);

	long long ans=1;
	while(n && m)
	{
		long long a=n%p;
		long long b=m%p;
		if(a<b) return 0;
		ans=ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
		n/=p;
		m/=p;
	}

	return ans;
}

long long mul(long long a,long long b,long long m)
{
	long long ret=0;
	
	while(b)
	{
		if(b&1) (ret+=a)%=m;
		b>>=1;
		(a<<=1)%=m;
	}

	return ret;
}

long long getans()
{
	long long ZM=1;
	for(int i=1;i<=k;++i)
		ZM*=p[i];
	for(int i=1;i<=k;++i)
		M[i]=ZM/p[i];
	for(int i=1;i<=k;++i)
		t[i]=inv(M[i]%p[i],p[i]);

	long long ret=0;
	
	for(int i=1;i<=k;++i)
		(ret+=mul(M[i],mul(a[i],t[i],ZM),ZM))%=ZM;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%I64d %I64d %d",&n,&m,&k);
		for(int i=1;i<=k;++i)
			scanf("%d",&p[i]);

		for(int i=1;i<=k;++i)
			a[i]=Lucas(n,m,p[i]);

		printf("%I64d\n",getans());
	}
	
	return 0;
}
