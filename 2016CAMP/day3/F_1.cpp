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
// Created Time  : 2017年02月14日 星期二 20时12分53秒
// File Name     : F_1.cpp

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

const int N=2e5+7;

int ans[N],dp[N],po[N],w[N];

inline void update(int p){
	if (p==0) return;

	if (dp[p]>0) update(p>>1);
	dp[p]--;
}

inline int query(int p){
	if (p==1) return 0;
	int fa=(p>>1);
	int mx;
	if (dp[p]<=0) mx=dp[fa];
	else mx=dp[fa]-dp[p];
	return mx+max(0,query(fa));
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	while (scanf("%d",&n)!=EOF) {
		for (int i=1;i<=n;i++) {
			scanf("%d",&w[i]);
			po[w[i]]=i;
		}

		for (int i=1;i<=n;i++) dp[i]=0;
		for (int i=1;i<=n;i++) {
			int k=i;
			while (k){
				dp[k]++;
				k>>=1;
			}
		}

		for (int i=1;i<=n;i++){
			update(po[i]);
			update(po[i-1]);

			ans[i]=max(0,query(po[i]))+dp[po[i]];
		}

		int now=n;
		printf("%d",n);
		for (int i=1;i<n;i++) {
			while (ans[now]<i) now--;
			printf(" %d",now);
		}
		puts("");
	}

	return 0;
}
