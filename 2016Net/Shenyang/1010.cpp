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
// Created Time  : 2016年09月19日 星期一 01时20分05秒
// File Name     : 1010.cpp

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

const int MAXN=10000000;

bool isP[MAXN];
int prime[700000],pcou;
int pi[MAXN];

inline long long getPI(long long);

void init() {
	pi[1]=0;
	for(long long i=2;i<MAXN;++i)
		if(!isP[i]) {
			for(long long j=i*i;j<MAXN;j+=i) isP[j]=1;
			prime[++pcou]=i;
			pi[i]=pi[i-1]+1;
		}
		else pi[i]=pi[i-1];
}

inline long long getPhi(long long m,long long n) {
	if(m==0) return 0;
	if(n==0) return m;
	if(prime[n]*(long long)prime[n]>=m) return getPI(m)-n+1;			// !!!
	return getPhi(m,n-1)-getPhi(m/prime[n],n-1);
}

inline long long getP2(long long y,long long m,long long n) {
	long long ret=0;
	for(long long p=y+1;p*p<=m;++p)
		ret+=getPI(m/p)-getPI(p)+1;
	return ret;
}

inline long long getPI(long long m) {
	if(m<MAXN) return pi[m];

	long long y=sqrt((double)m);
	long long n=getPI(y);

	return getPhi(m,n)+n-1-getP2(y,m,n);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	long long N;
	while(cin>>N)
		cout<<getPI(N)<<endl;

	return 0;
}
