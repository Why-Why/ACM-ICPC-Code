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
// Created Time  : 2016年08月02日 星期二 13时54分50秒
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

inline long long read() {
	long long ret=0;
	int c=0,sgn=1;

	if(c=getchar(),c==-1) return -1;

	while(c!='-' && (c<'0' || c>'9')) c=getchar();
	sgn=(c=='-') ? -1 : 1;
	ret=(c=='-') ? 0 : c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';

	return ret*sgn;
}

const int MaxN=1000006;

long long hnum[MaxN],hcou;
int A[MaxN];
long long ans[MaxN];
long long C[MaxN];

inline int lowbit(int x) {
	return x&(-x);
}

inline int hash1(long long x) {
	return lower_bound(hnum+1,hnum+hcou+1,x)-hnum;
}

inline void add(int p,long long x) {
	for(;p<=hcou;p+=lowbit(p)) C[p]=max(C[p],x);
}

inline int query(int p) {
	long long ret=0;
	for(;p;p-=lowbit(p)) ret=max(ret,C[p]);
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	while((N=read())!=-1) {
		hnum[0]=0;
		for(int i=1;i<=N;++i) {
			A[i]=read();
			hnum[i]=hnum[i-1]+A[i];
		}

		sort(hnum+1,hnum+N+1);
		hcou=unique(hnum+1,hnum+N+1)-hnum-1;
		for(int i=0;i<=hcou;++i) C[i]=0;

		ans[0]=0;
		long long s=0,t;

		A[0]=0;
		for(int i=1;i<=N;++i) {
			s+=A[i];
			t=hash1(s);
			if(A[i]>=0) ans[i]=ans[i-1]+1;
			else
				if(A[i-1]>=-A[i]) ans[i]=ans[i-2]+1;
				else ans[i]=ans[query(t)]+1;
			add(t,i);
		}

		printf("%d\n",(int)ans[N]);
	}

	return 0;
}
