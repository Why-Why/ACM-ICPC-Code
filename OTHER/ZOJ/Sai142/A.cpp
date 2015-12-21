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
// Created Time  : 2015年09月12日 星期六 13时03分04秒
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

const int MaxN=100005;
const int mod=1000000000+7;

long long dp[110][110][2];
int rem[MaxN],cou;
char s[MaxN];
int N;

int judge(int op,int L,int R)
{
	if(op==2)
	{
		if(L==1 && R==0)
			return 0;
		if(L==0 && R==1)
			return 0;
		if(L==1 && R==1)
			return 1;
		return -1;
	}
	else if(op==3)
	{
		if(L==0 && R==0)
			return 1;
		return -1;
	}
	else if(op==4)
	{
		if(L==0 && R==0)
			return 0;
		return -1;
	}
	else
	{
		if(L==0 && R==0)
			return 1;
		return 0;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int t,tt;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%s",s);
		cou=0;
		N=0;

		for(int i=0;s[i];++i)
		{
			if(s[i]>='0' && s[i]<='9') t=1;
			else if(s[i]>='a' && s[i]<='z') t=0;
			else
			{
				++N;
				rem[cou++]=t;

				if(s[i]=='*') t=2;
				else if(s[i]=='.') t=3;
				else if(s[i]=='^') t=4;
				else if(s[i]=='!') t=5;

				rem[cou++]=t;
			}
		}
		rem[cou++]=t;

		for(int i=1;i<=N;++i)
		{
			t=judge(rem[2*i-1],rem[2*i-2],rem[2*i]);
			dp[i][i][0]=dp[i][i][1]=0;
			if(t!=-1) dp[i][i][t]+=1;
		}

		for(int L=2;L<=N;++L)
			for(int i=1;i+L-1<=N;++i)
			{
				t=judge(rem[2*i-1],rem[2*i-2],0);
				dp[i][i+L-1][0]=dp[i][i+L-1][1]=0;
				if(t!=-1) (dp[i][i+L-1][t]+=dp[i+1][i+L-1][0])%=mod;

				t=judge(rem[2*i-1],rem[2*i-2],1);
				if(t!=-1) (dp[i][i+L-1][t]+=dp[i+1][i+L-1][1])%=mod;

				tt=i+L-1;
				t=judge(rem[2*tt-1],0,rem[2*tt]);
				if(t!=-1) (dp[i][tt][t]+=dp[i][i+L-2][0])%=mod;

				t=judge(rem[2*tt-1],1,rem[2*tt]);
				if(t!=-1) (dp[i][tt][t]+=dp[i][i+L-2][1])%=mod;

				for(int j=i+1;j<=i+L-2;++j)
				{
					t=judge(rem[2*j-1],0,0);
					if(t!=-1) (dp[i][tt][t]+=(dp[i][j-1][0]*dp[j+1][tt][0])%mod)%=mod;

					t=judge(rem[2*j-1],0,1);
					if(t!=-1) (dp[i][tt][t]+=(dp[i][j-1][0]*dp[j+1][tt][1])%mod)%=mod;

					t=judge(rem[2*j-1],1,0);
					if(t!=-1) (dp[i][tt][t]+=(dp[i][j-1][1]*dp[j+1][tt][0])%mod)%=mod;

					t=judge(rem[2*j-1],1,1);
					if(t!=-1) (dp[i][tt][t]+=(dp[i][j-1][1]*dp[j+1][tt][1])%mod)%=mod;
				}
			}

		printf("%lld\n",(dp[1][N][1]+dp[1][N][0])%mod);
	}
	
	return 0;
}
