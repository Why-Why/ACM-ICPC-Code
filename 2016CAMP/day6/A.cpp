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
// Created Time  : 2017年02月18日 星期六 10时41分35秒
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

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,K;
	scanf("%d %d",&N,&K);

	if(K>N/2) {
		puts("-1");
		return 0;
	}

	if(N&1) {
		--N;
		for(int i=1;i<=K;++i) {
			printf("%d %d\n",i,((N>>1)+i-1)%N+1);
			for(int j=1;j<(N>>1);++j) printf("%d %d\n%d %d\n",i,(i+j-1)%N+1,((N>>1)+i-1)%N+1,((N>>1)+i+j-1)%N+1);
			printf("%d %d\n",i,N+1);
			puts("");
		}
	}
	else {
		for(int i=1;i<=K;++i) {
			printf("%d %d\n",i,((N>>1)+i-1)%N+1);
			for(int j=1;j<(N>>1);++j) printf("%d %d\n%d %d\n",i,(i+j-1)%N+1,((N>>1)+i-1)%N+1,((N>>1)+i+j-1)%N+1);
			puts("");
		}
	}

	return 0;
}
