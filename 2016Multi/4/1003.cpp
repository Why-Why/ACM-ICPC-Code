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
// Created Time  : 2016年07月28日 星期四 15时25分16秒
// File Name     : 1003.cpp

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

const int MaxN=23;

int N,M;
int ans[MaxN*MaxN];
int U[MaxN*MaxN],V[MaxN*MaxN];
int map1[MaxN*MaxN];

bool lian[(1<<20)+5];

void getans() {
	int s2;

	for(int s1=1;s1<(1<<(N-1));++s1) {
		s2=(~s1)&((1<<N)-1);

		if(lian[s1] && lian[s2]) {
			for(int i=0;i<(N-1);++i)
				if(s1&(1<<i))
					for(int j=0;j<N;++j)
						if(s2&(1<<j)) ++ans[map1[i*N+j]];
			/*
			for(int i=1;i<=M;++i)
				if(((s1&(1<<U[i])) && (s2&(1<<V[i]))) || ((s1&(1<<V[i]) && s2&(1<<U[i]))))
					++ans[i];
			*/
		}
	}
}

int bian[MaxN];

inline bool judge(int p,int s) {
	if(!s) return 1;
	if(bian[p]&s) return 1;
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		memset(bian,0,sizeof(bian));
		scanf("%d %d",&N,&M);

		for(int i=0;i<N*N;++i) map1[i]=0;
		for(int i=1;i<=M;++i) {
			scanf("%d %d",U+i,V+i);
			//map1[U[i]][V[i]]=map1[V[i]][U[i]]=i;
			bian[U[i]]|=(1<<V[i]);
			bian[V[i]]|=(1<<U[i]);
			map1[U[i]*N+V[i]]=map1[V[i]*N+U[i]]=i;
			ans[i]=0;
		}

		printf("Case #%d:",cas++);
		if(N*(N-1)/2==M) {
			for(int i=1;i<=M;++i) printf(" %d",(1<<(N-2)));
			puts("");
			continue;
		}

		lian[0]=1;
		for(int i=1;i<(1<<N);++i) {
			lian[i]=0;
			for(int j=0;j<N;++j)
				if((i&(1<<j)) && lian[i^(1<<j)] && judge(j,i^(1<<j))) {
					lian[i]=1;
					break;
				}
		}

		getans();

		for(int i=1;i<=M;++i)
			printf(" %d",ans[i]);
		puts("");
	}

	return 0;
}
