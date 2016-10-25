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
// Created Time  : 2016年08月11日 星期四 12时55分15秒
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

int N;
double C,V[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int Q,k;
	double t,x;

	scanf("%d",&T);

	while(T--) {
		scanf("%d %lf",&N,&C);
		for(int i=1;i<=N;++i)
			scanf("%lf %lf %lf",V+i,&x,&t);
		sort(V+1,V+N+1);

		scanf("%d",&Q);
		while(Q--) {
			scanf("%lf %d",&t,&k);
			x=-V[k]*V[k]/(2.0*C);
			t=(t-x)*2.0*C;
			printf("%.3f\n",sqrt(t));
		}
	}

	return 0;
}
