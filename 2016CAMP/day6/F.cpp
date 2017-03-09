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
// Created Time  : 2017年02月18日 星期六 14时26分52秒
// File Name     : F.cpp

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

int N;
int a[103],b[103],s;

typedef pair<long long,long long> pii;
pii rm[103];
long long rb[103];

inline long long getans(int r) {
	long long need=r;

	for(int i=1;i<=N;++i) {
		rm[i]=pii(-a[i]*r%s,i);

		rb[i]=b[i];
		rb[i]-=r*a[i]/s;
		need-=r*a[i]/s;
	}
	sort(rm+1,rm+N+1);

	int t=need%N,tt=need/N;
	for(int i=1;i<=t;++i) rb[rm[i].second]-=1+tt;
	for(int i=t+1;i<=N;++i) rb[rm[i].second]-=tt;

	long long maxk=0;
	for(int i=1;i<=N;++i)
		if(rb[i]>=0)
			maxk=max(maxk,(rb[i]+a[i]-1)/a[i]);

	return s*maxk+r;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d %d",a+i,b+i),s+=a[i];

	long long ans=100000000000000000LL;
	for(int r=0;r<s;++r) ans=min(ans,getans(r));
	printf("%lld\n",ans);

	return 0;
}
