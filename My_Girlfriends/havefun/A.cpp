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
// Created Time  : 2016年01月26日 星期二 18时20分10秒
// File Name     : A.cpp

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
const long long INF=10000000000000000LL;

int N,M;
long long num[MaxN];
long long ans[MaxN],tans[MaxN];

struct OPE {
	int a,b,c,d;
	
	OPE(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d) {}
}ope[MaxN];

inline bool judge() {
	for(int i=1;i<=N;++i) {
		tans[i]=ans[i];
		if(ans[i]!=INF && abs(ans[i])>1000000000) return 0;
	}
	long long maxn;

	for(int i=1;i<=M;++i)
		if(ope[i].a==1) for(int j=ope[i].b;j<=ope[i].c;++j) ans[j]+=ope[i].d;
		else {
			maxn=-INF;
			for(int j=ope[i].b;j<=ope[i].c;++j) maxn=max(maxn,ans[j]);
			if(maxn!=ope[i].d) return 0;
		}
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i) ans[i]=INF;

	for(int i=1;i<=M;++i) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		ope[i]=OPE(a,b,c,d);
		if(a==1) for(int i=b;i<=c;++i) num[i]+=d;
		else for(int i=b;i<=c;++i) ans[i]=min(ans[i],d-num[i]);
	}

	if(judge()) {
		puts("YES");
		for(int i=1;i<=N;++i) if(tans[i]!=INF) printf("%I64d ",tans[i]); else printf("0 ");
		puts("");
	}
	else puts("NO");
	
	return 0;
}
