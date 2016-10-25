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
// Created Time  : 2016年08月16日 星期二 12时20分58秒
// File Name     : 1013.cpp

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

const int mod=1000000009;

int dp[103][1003][103];
int N;
int num[103];

inline void add(int & a,int b) {
	a+=b;
	while(a>=mod) a-=mod;
}

int gcd(int a,int b) {
	if(!a) return b;
	return gcd(b%a,a);
}

long long inv(long long a,long long m) {
	if(a == 1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

long long _pow(int a,int x) {
	long long ret=1,base=a;

	while(x) {
		if(x&1) (ret*=base)%=mod;
		x>>=1;
		(base*=base)%=mod;
	}

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,t;
	int *dp1,*dp2;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",num+i);

		memset(dp[0],-1,sizeof(dp[0]));
		dp[0][0][0]=0;

		for(int i=1;i<=N;++i) {
			memset(dp[i],-1,sizeof(dp[i]));

			for(int j=0;j<=1000;++j) {
				t=gcd(j,num[i]);
				dp1=dp[i-1][j];
				dp2=dp[i][j];

				for(int k=0;k<=i;++k) {
					if(dp1[k]==-1) continue;
					//if(dp[i-1][k][j]==-1) continue;

					if(dp2[k]==-1) dp2[k]=0;
					add(dp2[k],dp1[k]);
					//dp2[k]+=dp1[k];
					if(dp[i][t][k+1]==-1) dp[i][t][k+1]=0;
					if(k) add(dp[i][t][k+1],((dp1[k]+0LL)*(long long)num[i]*num[i])%mod);
					else add(dp[i][t][k+1],num[i]*num[i]);
				}
			}
		}

		int ans=0;
		for(int i=1;i<=1000;++i) {
			if(dp[N][i][1]!=-1)
				add(ans,(dp[N][i][1]*(long long)i)%mod);
			for(int j=2;j<=N;++j)
				if(dp[N][i][j]!=-1)
					add(ans,((long long)dp[N][i][j]*inv(_pow(i,2*j-3),mod))%mod);
		}

		printf("%d\n",ans);
	}

	return 0;
}
