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
// Created Time  : 2016年07月28日 星期四 12时55分43秒
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

const int MaxN=100005;

int next1[MaxN];
bool pos[MaxN];

void KMP_pre(int m,char s[])
{
	int i=0,j=-1;

	next1[0]=-1;

	while(i<m)
	{
		while(j!=-1 && s[i]!=s[j])
			j=next1[j];

		++i;
		++j;

		next1[i]=j;
	}
}

int KMP(int n,char s1[],int m,char s2[])
{
	memset(pos,0,sizeof(pos));
	int i=0,j=0;
	int ret=0;

	KMP_pre(m,s2);

	while(i<n)
	{
		while(j!=-1 && s1[i]!=s2[j])
			j=next1[j];

		++i;
		++j;

		if(j>=m)
		{
			++ret;
			j=next1[j];
			pos[i-1]=1;
		}
	}

	return ret;
}

const int mod=1000000007;

char A[MaxN],B[MaxN];
long long dp[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);
	while(T--) {
		scanf("%s %s",A,B);
		int N=strlen(A),M=strlen(B);
		KMP(N,A,M,B);

		dp[0]=1;
		for(int i=1;i<=N;++i)
			if(pos[i-1]) dp[i]=(dp[i-1]+dp[i-M])%mod;
			else dp[i]=dp[i-1];

		printf("Case #%d: %d\n",cas++,(int)dp[N]);
	}

	return 0;
}
