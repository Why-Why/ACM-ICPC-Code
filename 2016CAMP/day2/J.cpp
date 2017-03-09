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
// Created Time  : 2017年02月13日 星期一 11时58分23秒
// File Name     : J.cpp

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

inline void gou(int sta,int N) {
	for(int i=1;i<=N;++i)
		for(int j=i+1;j<N;++j)
			printf("%d %d\n",sta+i,sta+j);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,K;
	int a,b;

	while(~scanf("%d %d",&N,&K)) {
		if(K==1) {
			puts("-1");
			continue;
		}

		a=(N-K)>>1;
		b=N-K-a;

		printf("%d\n",(a*(a-1)/2)+(b*(b-1)/2)+(K*(K-1)/2)+a*K+b*K);
		gou(0,a);
		gou(a,b);
		gou(a+b,K);

		for(int i=1;i<=a;++i)
			for(int j=1;j<=K;++j)
				printf("%d %d\n",i,a+b+j);
		for(int i=1;i<=b;++i)
			for(int j=1;j<=K;++j)
				printf("%d %d\n",a+i,a+b+j);

		printf("%d %d %d",1,a+b+1,a+1);
		for(int i=2;i<=b;++i)
			printf(" %d",a+i);
		for(int i=2;i<=K;++i)
			printf(" %d",a+b+i);
		for(int i=2;i<=a;++i)
			printf(" %d",i);
		puts("");
	}

	return 0;
}
