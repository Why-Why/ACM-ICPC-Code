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
// Created Time  : 2016年08月29日 星期一 12时15分13秒
// File Name     : 1004.cpp

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

struct State {
	int c,d,n;

	bool operator < (const State & b) const {
		if(c!=b.c) return c<b.c;
		return d<b.d;
	}
};

int N,K,Q;
State num[3000005];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,t;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&N,&K,&Q);

		for(int i=1;i<=N;++i) {
			num[i].n=i;
			if((i-1)%K==0) {
				num[i].c=1;
				num[i].d=(i-1)/K+1;
			}
			else {
				t=(i-1)-((i-1)/K);
				num[i].c=num[t].c+1;
				num[i].d=num[t].d;
			}
		}

		sort(num+1,num+N+1);

		while(Q--) {
			scanf("%d",&a);
			printf("%d\n",num[a].n);
		}
	}

	return 0;
}
