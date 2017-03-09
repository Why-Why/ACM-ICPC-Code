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
// Created Time  : 2016年10月30日 星期日 22时29分57秒
// File Name     : D.cpp

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
#include <bitset>

using namespace std;

const int MaxN=500005;

int N,M;
long long K;
int A[MaxN],B[MaxN];

bitset <MaxN> ra[3],rb[3];

int gcd(int a,int b) {
	if(!a) return b;
	return gcd(b%a,a);
}

long long f[MaxN],ff[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %lld",&N,&M,&K);
	for(int i=0;i<N;++i) scanf("%d",A+i);
	for(int i=0;i<M;++i) scanf("%d",B+i);

	long long T=N*(long long)M/gcd(N,M);
	int MM=max(N,M),a,b;

	for(int i=0;i<M;++i) {
		ra[A[a]].set(i);
		rb[B[b]].set(i);

		++a;
		++b;
		if(a>=N) a=0;
		if(b>=M) b=0;
	}

	for(int i=0;i<N;++i) {
		f[i]+=(ra[0]&rb[1]).count();
		f[i]+=(ra[1]&rb[2]).count();
		f[i]+=(ra[2]&rb[0]).count();

		ff[i]+=(ra[0]&rb[2]).count();
		ff[i]+=(ra[1]&rb[0]).count();
		ff[i]+=(ra[2]&rb[1]).count();

		ra[0]>>=1;
		ra[1]>>=1;
		ra[2]>>=1;
		ra[A[a]].set(M-1);

		++a;
		if(a>=N) a=0;
	}

	long long X=0,Y=0,r=0,R=M%N;

	for(long long i=0;i<T;i+=M) {
		X+=f[r];
		Y+=ff[r];

		r=(R+r)%N;
	}

	long long ans1=0,ans2=0,tt=K/T,rr=K%T;

	ans1=tt*X;
	ans2=tt*Y;
	r=0;

	for(long long i=0;i<rr;i+=M) {
		if(i+M>rr) {
			for(int j=r,k=0;i<rr;++i,++k) {
				if(A[j]==0 && B[k]==1) ++ans1;
				if(A[j]==1 && B[k]==2) ++ans1;
				if(A[j]==2 && B[k]==0) ++ans1;

				if(A[j]==0 && B[k]==2) ++ans2;
				if(A[j]==1 && B[k]==0) ++ans2;
				if(A[j]==2 && B[k]==1) ++ans2;

				++j;
				if(j>=N) j=0;
			}
		}
		else {
			ans1+=f[r];
			ans2+=ff[r];

		}

		r=(R+r)%N;
	}

	printf("%lld %lld\n",ans1,ans2);

	return 0;
}
