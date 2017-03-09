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
// Created Time  : 2017年02月22日 星期三 21时43分03秒
// File Name     : B.cpp

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

typedef pair<long long,int> pii;

priority_queue <pii> que;

inline void getans(int L,int N,int w[],long long ans[]) {
	while(!que.empty()) que.pop();

	for(int i=1;i<=N;++i) que.push(pii(-w[i],w[i]));
	for(int i=1;i<=L;++i) {
		pii tmp=que.top();
		que.pop();

		ans[i]=-tmp.first;
		tmp.first-=tmp.second;
		que.push(tmp);
	}
}

const int MaxN=1000005;

long long ans1[MaxN],ans2[MaxN];
int L,N,M;
int W[MaxN],D[MaxN];

inline int read() {
	char c=0;
	while(c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	T=read();
	while(T--) {
		L=read(); N=read(); M=read();
		for(int i=1;i<=N;++i) W[i]=read();
		for(int i=1;i<=M;++i) D[i]=read();

		getans(L,N,W,ans1);
		getans(L,M,D,ans2);
		sort(ans1+1,ans1+L+1);
		sort(ans2+1,ans2+L+1,greater<long long>());

		long long ans=0;
		for(int i=1;i<=L;++i) ans=max(ans,ans1[i]+ans2[i]);
		printf("Case #%d: %I64d\n",cas++,ans);
	}

	return 0;
}
