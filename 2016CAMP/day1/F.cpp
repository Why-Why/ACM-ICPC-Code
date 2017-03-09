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
// Created Time  : 2017年02月15日 星期三 12时52分13秒
// File Name     : F.cpp

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
const long long base=108669496;
const long long TTT=100;
long long fbase;

long long inv1(long long a,long long m) {
	if(a==1) return 1;
	return inv1(m%a,m)*(m-m/a)%m;
}

int rrr[77];

int N,M,T;
char map1[77][77];

int tt[10004],v[10004];
long long dp[TTT+1][77][77];

long long num[77],tnum[77],XX=1,fXX=1;

inline int getans(int v,int len) {
	int ret=0,tmp;
	long long t;

	(num[v]+=XX)%=mod;

	while(len) {
		ret^=num[N]*fXX%mod;
		tmp=min(len,(int)TTT);

		for(int i=1;i<tmp;++i) {
			t=0;
			for(int j=1;j<=N;++j) t+=dp[i][j][N]*num[j]%mod;
			t%=mod;

			(XX*=base)%=mod;
			(fXX*=fbase)%=mod;

			ret^=t*fXX%mod;
		}
		len-=tmp;

		(XX*=base)%=mod;
		(fXX*=fbase)%=mod;

		for(int i=1;i<=N;++i) tnum[i]=0;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				(tnum[j]+=dp[tmp][i][j]*num[i]%mod)%=mod;
		for(int i=1;i<=N;++i) num[i]=tnum[i];
	}

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=0;

	for(int i=1;i<77;++i) rrr[i]=inv1(i,mod)*base%mod;
	fbase=inv1(base,mod);

	scanf("%d %d %d",&N,&M,&T);
	for(int i=1;i<=N;++i) scanf("%s",map1[i]+1);
	for(int i=1;i<=M;++i) scanf("%d %d",tt+i,v+i);

	for(int i=1;i<=N;++i) {
		dp[0][i][i]=1;

		int du=0;
		for(int j=1;j<=N;++j) if(map1[i][j]=='1') ++du;

		for(int j=1;j<=N;++j)
			if(map1[i][j]=='1')
				dp[1][i][j]=rrr[du];
	}

	for(int t=2;t<=TTT;++t)
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j) {
				for(int k=1;k<=N;++k)
					dp[t][i][j]+=dp[t-1][i][k]*dp[1][k][j]%mod;
				dp[t][i][j]%=mod;
			}

	for(int i=1;i<M;++i)
		ans^=getans(v[i],tt[i+1]-tt[i]);
	ans^=getans(v[M],T-tt[M]+1);

	printf("%d\n",ans);

	return 0;
}
