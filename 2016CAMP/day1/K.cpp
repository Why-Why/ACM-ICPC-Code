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
// Created Time  : 2017年02月12日 星期日 21时32分10秒
// File Name     : K.cpp

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

const int N=2e5+11;
const int mod=1e9+7;

long long dp[N];

int num[N],first[N];

int n,m;

long long poww[N];
int K;

long long C[N];

inline void init(){
	for(int i=0;i<=m;++i) {
		first[i]=-1;
		num[i]=dp[i]=C[i]=0;
	}
}

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int x,long long d) {
	for(;x<=K;x+=lowbit(x)) {
		C[x]+=d;
		if(C[x]>=mod) C[x]-=mod;
	}
}

inline long long sum(int x) {
	long long ret=0;
	for(;x;x-=lowbit(x)) {
		ret+=C[x];
		if(ret>=mod) ret-=mod;
	}
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	poww[0]=1;
	for(int i=1;i<N;++i) poww[i]=poww[i-1]*2%mod;

	while (scanf("%d %d",&n,&m)!=EOF){
		init();

		K=0;

		for (int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			K=max(k,K);

			for (int j=1;j<=k;j++){
				int r;
				scanf("%d",&r);
				if (first[r]==-1){
					first[r]=j;
					num[j]++;
				}
				else if (first[r]>j){
					num[first[r]]--;
					num[j]++;
					first[r]=j;
				}
			}
		}

		/*
		dp[0]=1;
		for(int i=1;i<=K;++i) dp[i]=(dp[i-1]+poww[num[i]]+mod-1)%mod;

		for(int i=1;i<=20;++i) cout<<dp[i]<<' ';
		cout<<endl;
		for(int i=1;i<=20;++i) cout<<first[i]<<' ';
		cout<<endl;
		*/

		for(int i=1;i<=K;++i) {
			int t=poww[num[i]]-1;
			if(t<0) t+=mod;

			add(i,t);
		}

		long long ans=sum(K)+1;
		if(ans>=mod) ans-=mod;

		for (int i=1;i<=m;i++) {
			int r;
			scanf("%d",&r);

			if(first[r]!=-1) {
				--num[first[r]];
				int t=mod-poww[num[first[r]]];
				if(t==mod) t=0;

				add(first[r],t);
			}

			if(first[r]!=-1) {
				ans+=sum(first[r]-1);
				if(ans>=mod) ans-=mod;
			}
			else {
				ans+=sum(K)+1;
				while(ans>=mod) ans-=mod;
			}
		}

		printf("%lld\n",ans);
	}

	return 0;
}
