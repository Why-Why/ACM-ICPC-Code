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
// Created Time  : 2015年05月14日 星期四 23时27分04秒
// File Name     : 2635.cpp

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

bool vis[1000065];
int cou;
int prime[80000];

char num[110];
long long num1[100];
int len,len1;

bool judge(long long x)
{
	long long t=0;
	long long base=1;

	for(int i=0;i<len1;++i)
	{
		t=(t+num1[i]*base)%x;
		base=(base*1000000000000LL)%x;
	}

	return t==0;
}

void chuli()
{
	long long t=0;
	long long base;

	len1=0;

	for(int i=len-1;i>=0;i-=12)
	{
		t=0;
		base=1;
		for(int j=0;j<12 && i>=j;++j)
		{
			t=(t+base*(num[i-j]-'0'));
			base*=10;
		}

		num1[len1++]=t;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=2;i<=1000050;++i)
		if(vis[i]==0)
		{
			prime[cou++]=i;
			
			for(long long j=i*(long long)i;j<=1000050;j+=i)
				vis[j]=1;
		}

	int L;
	bool ok;

	while(~scanf("%s %d",num,&L) && L+num[0]-'0')
	{
		ok=0;
		len=strlen(num);
		chuli();

		for(int i=0;prime[i]<L;++i)
			if(judge(prime[i]))
			{
				ok=1;
				printf("BAD %d\n",prime[i]);
				break;
			}

		if(!ok)
			puts("GOOD");
	}
	
	return 0;
}
