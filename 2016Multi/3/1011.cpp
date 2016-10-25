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
// Created Time  : 2016年07月26日 星期二 12时50分53秒
// File Name     : 1011.cpp

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

int N,M;

int vis[MaxN<<2];
int flag=0;

int a[MaxN],b[MaxN];

inline int dis(int x,int y) {
	return abs(a[x]-a[y])+abs(b[x]-b[y]);
}

inline bool judge1() {
	int t;
	++flag;
	for(int i=1;i<=N;++i)
		for(int j=1;j<i;++j) {
			t=dis(i,j);
			if(vis[t]==flag) return 1;
			vis[t]=flag;
		}
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
			scanf("%d %d",a+i,b+i);

		if(N<=2) {
			puts("NO");
			continue;
		}
		if(N*(N-1LL)/2LL>2*M+1LL) {
			puts("YES");
			continue;
		}

		if(judge1()) puts("YES");
		else puts("NO");
	}

	return 0;
}
