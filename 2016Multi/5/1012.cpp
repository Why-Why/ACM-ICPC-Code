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
// Created Time  : 2016年08月02日 星期二 14时45分50秒
// File Name     : 1012.cpp

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

const int MaxN=50005;

int N,A[MaxN];
int hnum[MaxN],hcou,tnum[MaxN];

long long shun,ni;
int xiao[MaxN],da[MaxN],houxiao[MaxN];

long long C[MaxN];

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int p,long long d) {
	for(;p<=hcou;p+=lowbit(p)) C[p]+=d;
}

inline long long sum(int p) {
	long long ret=0;
	for(;p;p-=lowbit(p)) ret+=C[p];
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i) scanf("%d",A+i),hnum[i]=A[i],C[i]=0;
		sort(hnum+1,hnum+N+1);
		for(int i=1;i<=N;++i) tnum[i]=lower_bound(hnum+1,hnum+N+1,A[i])-hnum-1;
		hcou=unique(hnum+1,hnum+N+1)-hnum-1;
		for(int i=1;i<=N;++i) A[i]=lower_bound(hnum+1,hnum+hcou+1,A[i])-hnum;

		shun=ni=0;
		for(int i=1;i<=N;++i) {
			xiao[i]=sum(A[i]-1);
			da[i]=i-1-sum(A[i]);
			houxiao[i]=tnum[i]-xiao[i];
			shun+=xiao[i];
			ni+=da[i];

			add(A[i],1);
		}

		memset(C,0,sizeof(C));
		long long ans=shun*ni;
		for(int i=1;i<=N;++i) {
			ans-=xiao[i]*(da[i]+houxiao[i]);
			ans-=sum(A[i]-1);

			add(A[i],houxiao[i]+da[i]);
		}

		printf("%I64d\n",ans);
	}

	return 0;
}
