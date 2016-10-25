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
// Created Time  : 2016年09月09日 星期五 16时26分52秒
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

using namespace std;

const int MaxN=5005;
const long long INF=1000000000000000LL;

int N,s,e;
long long dp[MaxN][MaxN];
long long x[MaxN],a[MaxN],b[MaxN],c[MaxN],d[MaxN];

inline void change1(long long ans[],long long base,int sta,int p) {
	if(base>=INF) return;
	if(sta==0) return;
	if(sta==1 && p<N) return;
	if(p==s && e>s) return;
	if(p==e && s>e) return;

	ans[sta-1]=min(ans[sta-1],base+x[p]+x[p]+c[p]+a[p]);
}

inline void change2(long long ans[],long long base,int sta,int p) {
	if(base>=INF) return;
	if(p==s && e<s) return;
	if(p==e && s<e) return;
	if(p!=1 && sta==0) return;			// !!!

	ans[sta+1]=min(ans[sta+1],base-x[p]-x[p]+d[p]+b[p]);
}

inline void change3(long long ans[],long long base,int sta,int p) {
	if(base>=INF) return;
	if(sta==0) return;
	if(p==s && e<s) return;
	if(p==e && e<s) return;
	if(sta==1 && p>s && p<e) return;	// !!!

	ans[sta]=min(ans[sta],base+c[p]+b[p]);
}

inline void change4(long long ans[],long long base,int sta,int p) {
	if(base>=INF) return;
	if(sta==0) return;
	if(p==s && s<e) return;
	if(p==e && s<e) return;
	if(sta==1 && p>e && p<s) return;	// !!!

	ans[sta]=min(ans[sta],base+d[p]+a[p]);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&s,&e);
	for(int i=1;i<=N;++i) scanf("%I64d",x+i);
	for(int i=1;i<=N;++i) scanf("%I64d",a+i);
	for(int i=1;i<=N;++i) scanf("%I64d",b+i);
	for(int i=1;i<=N;++i) scanf("%I64d",c+i);
	for(int i=1;i<=N;++i) scanf("%I64d",d+i);

	dp[0][0]=0;
	for(int i=1;i<=N;++i) {
		for(int j=0;j<=i;++j) dp[i][j]=INF;
		for(int j=0;j<i;++j) {
			change1(dp[i],dp[i-1][j],j,i);
			change2(dp[i],dp[i-1][j],j,i);
			change3(dp[i],dp[i-1][j],j,i);
			change4(dp[i],dp[i-1][j],j,i);
		}
	}

	long long t=0;
	if(s>e) t=x[s]-x[e]+d[e]+a[s];
	else t=x[e]-x[s]+c[e]+b[s];

	printf("%I64d\n",dp[N][0]-t);

	return 0;
}
