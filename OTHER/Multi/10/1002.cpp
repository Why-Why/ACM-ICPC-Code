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
// Created Time  : 2015年08月20日 星期四 15时14分53秒
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

const int mod=1000000007;

long long jie[1000006];

void init()
{
	jie[0]=1;
	for(int i=1;i<=1000002;++i)
	{
		jie[i]=jie[i-1]*i;
		jie[i]%=mod;
	}
}

int getans(long long S,long long X)
{
	int n=mod-2;
	long long base=X;
	long long ret=1;

	while(n)
	{
		if(n&1)
			(ret*=base)%=mod;
		(base*=base)%=mod;
		n>>=1;
	}

	return (ret*S)%mod;
}

int gcd(int a,int b)
{
	if(!a)
		return b;
	return gcd(b%a,a);
}

int getgcd(int N)
{
	int ret=jie[N];
	for(int i=0;i<=N;++i)
		ret=gcd(ret,jie[i]*jie[N-i]);

	return ret;
}

int get1(int N)
{
	int ret=jie[N];

	for(int i=N;i>((N+1)/2);--i)
		ret=gcd(ret,jie[i]);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N;
	int pre,now;

	init();

	for(int i=2;i<=20;++i)
	{
		now=getans(jie[i],(getgcd(i))%mod);
		cout<<i<<' '<<pre*i/now<<endl;
		pre=now;
	}

	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d",&N);
		
//		printf("%d\n",getans(jie[N],(getgcd(N))%mod));
	}
	
	return 0;
}
