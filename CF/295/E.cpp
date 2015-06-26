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
// Created Time  : 2015年06月03日 星期三 00时50分19秒
// File Name     : E.cpp

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

const long long mod=1000000007;
long long C1[100005],C2[100005];
long long ten[100005];
char s[100005];
int n,k;

long long getpow(long long a,long long n)
{
	long long base=a;
	long long ret=1;

	while(n)
	{
		if(n&1)
			(ret*=base)%=mod;

		(base*=base)%=mod;
		n>>=1;
	}

	return ret;
}

void init()
{
	C1[k-1]=1;

	for(int i=k-1;i<n-2;++i)
		C1[i+1]=(((C1[i]*(i+1))%mod)*getpow(i+2-k,mod-2))%mod;

	C2[k]=1;

	for(int i=k+1;i<=n-1;++i)
		C2[i]=(C2[i-1]+C1[i-1])%mod;

	ten[0]=1;

	for(int i=1;i<=n;++i)
		ten[i]=(ten[i-1]*10)%mod;
}

long long getans()
{
	long long ret=0;
	long long sum=0;

	for(int i=n;i>=1;--i)
	{
		(ret+=(s[i]-'0')*(sum+C2[i-1]*ten[n-i]%mod))%=mod;
		
		if(i>1)
			(sum+=C1[i-2]*ten[n-i])%=mod;
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&n,&k);
	scanf("%s",s+1);

	init();
	cout<<getans()<<endl;
	
	return 0;
}
