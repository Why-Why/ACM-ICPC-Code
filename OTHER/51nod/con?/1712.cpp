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
// Created Time  : 2016年12月06日 星期二 01时17分43秒
// File Name     : 1712.cpp

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

const int MaxN=1000006;

int N,A[MaxN];

long long num[MaxN],sum[MaxN],first[MaxN],last[MaxN];
long long ans[MaxN];

inline int read() {
	char c=0;
	while(c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

long long CCC(int L,int R) {
	long long ret=0;
	for(int i=L;i<=R;++i)
		for(int j=i+1;j<=R;++j)
			ret+=A[j]-A[i];
	return ret;
}

long long TTT() {
	long long ret=0;
	for(int i=1;i<=N;++i)
		for(int j=i+1;j<=N;++j)
			if(A[i]==A[j]) ret+=CCC(i,j);
	return ret;
}

int cou1[MaxN],cou2[MaxN];
long long tjian1[MaxN],tjian2[MaxN];
long long tsj1[MaxN],tsj2[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	N=read();
	for(int i=1;i<=N;++i) {
		A[i]=read();

		if(first[A[i]]==0) first[A[i]]=i;
		last[A[i]]=i;
		++num[A[i]];
		sum[A[i]]+=i;
	}

	long long tsum,tnum;

	tsum=tnum=0;
	for(int i=1;i<=N;++i) {
		ans[i]+=i*tnum-tsum;

		++cou1[A[i]];

		if(i!=last[A[i]]) {
			tsum+=i*(num[A[i]]-cou1[A[i]]);
			tnum+=num[A[i]]-cou1[A[i]];
			
			tsj1[A[i]]+=i*(num[A[i]]-cou1[A[i]]);
			tjian1[A[i]]+=num[A[i]]-cou1[A[i]];
		}
		else {
			tsum-=tsj1[A[i]];
			tnum-=tjian1[A[i]];
		}
	}

	for(int i=1;i<=N;++i) cout<<ans[i]<<' ';
	cout<<endl;

	tsum=tnum=0;
	for(int i=N;i>=1;--i) {
		ans[i]-=tsum-i*tnum;

		++cou2[A[i]];

		if(i!=first[A[i]]) {
			tsum+=i*(num[A[i]]-cou2[A[i]]);
			tnum+=num[A[i]]-cou2[A[i]];
			
			tsj2[A[i]]+=i*(num[A[i]]-cou2[A[i]]);
			tjian2[A[i]]+=num[A[i]]-cou2[A[i]];
		}
		else {
			tsum-=tsj2[A[i]];
			tnum-=tjian2[A[i]];
		}
	}

	int zans=0;
	for(int i=1;i<=N;++i) zans+=A[i]*(int)ans[i];
	printf("%u\n",zans);

	cout<<TTT()<<endl;

	return 0;
}
