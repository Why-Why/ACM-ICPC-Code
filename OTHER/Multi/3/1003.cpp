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
// Created Time  : 2015年07月29日 星期三 13时47分16秒
// File Name     : 1003.cpp

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

const int MaxN=52;
const int Mod=1000000007;

long long map1[MaxN][MaxN];
long long ans[MaxN][MaxN];
long long base[MaxN][MaxN];
long long temp[MaxN][MaxN];

int N,M;
char s[MaxN][100];

void cheng(long long A[][MaxN],long long B[][MaxN])
{
	long long t;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			t=0;

			for(int x=1;x<=N;++x)
				(t+=A[i][x]*B[x][j])%=Mod;

			temp[i][j]=t;
		}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			A[i][j]=temp[i][j];
}

int getans()
{
	long long zans=0;

	while(M)
	{
		if(M&1)
			cheng(ans,base);

		cheng(base,base);
		M>>=1;
	}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			(zans+=ans[i][j])%=Mod;

	return (int)zans;
}

bool can(char s1[],char s2[],int L)
{
	for(int i=0;i<L;++i)
		if(s1[i]!=s2[i])
			return 0;

	return 1;
}

bool judge(char s1[],char s2[])
{
	int L1=strlen(s1),L2=strlen(s2);
	int L=min(L1,L2);

	for(int i=2;i<=L;++i)
		if(can(s1+L1-i,s2,i))
			return 1;

	return 0;
}

int num[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		--M;

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		sort(num+1,num+N+1);
		N=unique(num+1,num+N+1)-num-1;

		for(int i=1;i<=N;++i)
			sprintf(s[i],"%d",num[i]);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
			{
				if(i==j)
					ans[i][j]=1;
				else
					ans[i][j]=0;

				if(judge(s[i],s[j]))
					map1[i][j]=1;
				else
					map1[i][j]=0;

				base[i][j]=map1[i][j];
			}

		printf("%d\n",getans());
	}
	
	return 0;
}
