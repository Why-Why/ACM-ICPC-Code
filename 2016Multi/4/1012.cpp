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
// Created Time  : 2016年07月28日 星期四 12时38分43秒
// File Name     : 1012.cpp

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

int C[MaxN];
int N,num[MaxN];
int pos[MaxN];

inline int lowbit(int x) {
	return x&(-x);
}

void add(int p,int d) {
	for(;p<=N;p+=lowbit(p)) C[p]+=d;
}

int sum(int p) {
	int ret=0;
	for(;p;p-=lowbit(p)) ret+=C[p];
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) {
			C[i]=0;
			scanf("%d",num+i);
			pos[num[i]]=i;
		}

		printf("Case #%d:",cas++);
		for(int i=1;i<=N;++i) {
			a=min(pos[i],i);
			b=max(i,pos[i]+i-1-sum(pos[i]));
			printf(" %d",b-a);

			add(pos[i],1);
		}
		puts("");
	}

	return 0;
}
