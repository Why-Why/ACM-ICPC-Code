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
// Created Time  : 2015年07月22日 星期三 22时34分21秒
// File Name     : B.cpp

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
#include <climits>

using namespace std;

const int MaxN=200005;

char s1[MaxN],s2[MaxN];
int N;

unsigned long long tn1[MaxN];
int tcou1,tcou2;

const unsigned long long mod=1000000007;

unsigned long long hash(char s[],int L)
{
	unsigned long long seed=13131313,ret=0;

	for(int i=0;i<L;++i)
	{
		ret=ret*seed+s[i];
		ret%=mod;
	}

	return ret;
}

unsigned long long chuli(char s[],int B,int cou)
{
	int L;
	int K;
	unsigned long long ret,seed=131313;

	tcou1=0;
	L=B;
	K=N/B;

	for(int i=0,j=0;j<K;++j,i+=L)
		tn1[tcou1++]=hash(s+i,L);

	for(int i=0;i<cou;++i)
	{
		K/=2;
		tcou1=0;

		for(int t=0,j=0;t<K;++t,j+=2)
		{
			tn1[tcou1++]=min(tn1[j],tn1[j+1])*seed+max(tn1[j],tn1[j+1]);
			tn1[tcou1-1]%=mod;
		}

		(seed*=seed)%=mod;
	}

	return tn1[0];
}

bool getans()
{
	int cou=0;
	int B=N;

	while(!(B&1))
	{
		++cou;
		B>>=1;
	}

	return chuli(s1,B,cou)==chuli(s2,B,cou);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s %s",s1,s2);
	N=strlen(s1);

	if(getans())
		puts("YES");
	else
		puts("NO");
	
	return 0;
}
