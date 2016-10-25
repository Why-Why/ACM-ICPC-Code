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
// Created Time  : 2016年09月03日 星期六 22时56分15秒
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

const int MaxN=1505;
const int mod=1000000007;

int N,M;
int a,b,K;

long long T[MaxN],C[100005];
long long P[MaxN][MaxN],D[MaxN];
long long g[MaxN][MaxN];
long long Q;

long long inv(long long a,long long m) {
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

long long gcd(long long a,long long b) {
	if(!a) return b;
	return gcd(b%a,a);
}

long long _pow(long long a,long long n) {
	long long ret=1;
	for(;n;n>>=1,(a*=a)%=mod)
		if(n&1) (ret*=a)%=mod;
	return ret;
}

inline void cal(long long &ans,int h,int x) {
	(ans+=(D[x]*(g[h-1][M]-g[h-1][M-x]+mod))%mod)%=mod;

	if(T[M+1-x]) Q=Q*inv(T[M+1-x],mod)%mod*T[M-x]%mod;
	else {
		Q=0;
		if(T[M-x]) for(int i=1;i<x;++i) (Q+=P[i][x]*g[h-1][i-1]%mod)%=mod;  // !!!
	}
	(Q+=P[x][x]*g[h-1][x-1]%mod)%=mod;

	ans=(ans-Q+mod)%mod;

	//for(int i=1;i<=x;++i)
		//(ans+=P[i][x]*((g[h-1][M]-g[h-1][M-x]-g[h-1][i-1])%mod+mod)%mod)%=mod;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	scanf("%d %d",&a,&b);
	scanf("%d",&K);

	int t=gcd(a,b);
	a/=t;
	b/=t;

	C[0]=1;
	for(int i=1;i<=K;++i) C[i]=C[i-1]*(K-i+1)%mod*inv(i,mod)%mod;
	for(int i=0;i<=M;++i) 
		if(K>=i) T[i]=C[i]*_pow(a,i)%mod*_pow(b-a,K-i)%mod;
		else T[i]=0;
	for(int i=1;i<=M;++i)
		for(int j=i;j<=M;++j)
			P[i][j]=T[i-1]*T[M-j]%mod;

	for(int i=0;i<=M;++i) {
		D[i]=0;
		for(int j=1;j<=i;++j) (D[i]+=P[j][i])%=mod;
	}

	g[1][0]=0;
	for(int i=1;i<=M;++i) {
		g[1][i]=g[1][i-1];
		for(int j=1;j<=i;++j) (g[1][i]+=P[j][i])%=mod;
	}

	for(int i=2;i<=N;++i) {
		g[i][0]=0;
		Q=0;
		for(int j=1;j<=M;++j) {
			g[i][j]=g[i][j-1];
			cal(g[i][j],i,j);
		}
	}

	printf("%d\n",(int)(g[N][M]*inv(_pow(b,2*K*N),mod)%mod));

	return 0;
}
