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
// Created Time  : 2016年09月17日 星期六 12时14分56秒
// File Name     : 1006.cpp

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

struct Edge {
	int u,v;
};

Edge E[500005];
int N,M;
int A[MaxN];
int du[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		memset(du,0,sizeof(du));
		for(int i=1;i<=N;++i) scanf("%d",A+i);
		for(int i=1;i<=M;++i) scanf("%d %d",&E[i].u,&E[i].v),++du[E[i].u],++du[E[i].v];

		int cou=0,rem[10];
		bool ok=1;

		for(int i=1;i<=N;++i) {
			if(du[i]&1) rem[++cou]=i;
			if(cou>2) { ok=0; break; }
		}

		if(cou>2 || !ok) {
			puts("Impossible");
			continue;
		}

		int ans=0;
		for(int i=1;i<=N;++i)
			if((du[i]/2)&1) ans^=A[i];

		if(cou==0) {
			int zans=0;
			for(int i=1;i<=N;++i) zans=max(zans,ans^A[i]);
			printf("%d\n",zans);
			continue;
		}

		ans^=A[rem[1]];
		ans^=A[rem[2]];
		printf("%d\n",ans);
	}

	return 0;
}
