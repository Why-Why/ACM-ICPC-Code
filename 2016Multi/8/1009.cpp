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
// Created Time  : 2016年08月11日 星期四 15时59分41秒
// File Name     : 1009.cpp

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
const int mod=998244353;

int N;
long long num[MaxN],ans[MaxN];

long long jie(int x) {
	int ret=1;
	for(int i=1;i<=x;++i) ret*=i;
	return ret;
}

long long C(int n,int m) {
	if(n<m) return 0;

	return jie(n)/(jie(m)*jie(n-m));
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%I64d",num+i),ans[i]=0;
		sort(num+1,num+N+1);

		for(int i=1;i<=N;++i) {
			long long sum=0,t=(1LL<<(i-1))*num[i];

			for(int j=1;j<=N;++j) {
				sum+=C(N-i,j-1);
				ans[j]+=sum*t;
			}
		}

		for(int i=1;i<=N;++i) printf("%lld ",ans[i]);
		puts("");
	}

	return 0;
}
