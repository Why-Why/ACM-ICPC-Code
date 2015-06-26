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
// Created Time  : 2015年06月25日 星期四 00时41分42秒
// File Name     : A.cpp

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

long long jie[3000];

void init()
{
	jie[0]=1;

	for(int i=1;i<=2010;++i)
		jie[i]=(jie[i-1]*i)%mod;
}

int C[1010];
int s[1010];

long long pow(long long a,long long n)
{
	long long ret=1;
	long long base=a;

	while(n)
	{
		if(n&1)
			(ret*=base)%=mod;

		(base*=base)%=mod;
		n>>=1;
	}

	return ret;
}

long long getans(int d)
{
	if(d==0)
		return 1;

	long long temp;

	if(C[d]==1)
		temp=1;
	else
		temp=(jie[s[d-1]+C[d]-1]*pow((jie[s[d-1]]*jie[C[d]-1])%mod,mod-2))%mod;
		
	return (getans(d-1)*temp)%mod;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int k;

	scanf("%d",&k);

	for(int i=1;i<=k;++i)
		scanf("%d",&C[i]);

	s[0]=0;

	for(int i=1;i<=k;++i)
		s[i]=s[i-1]+C[i];

	cout<<getans(k)<<endl;
	
	return 0;
}
