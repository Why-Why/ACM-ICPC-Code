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
// Created Time  : 2016年07月19日 星期二 16时18分43秒
// File Name     : 1005.cpp

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

int map1[11][11];
int rem1[11][11];
int rcou1[11];
int rem2[11][11];
int rcou2[11];
int N,M;

inline int count(int x) {
	int ret=0;
	while(x) {
		++ret;
		x>>=1;
	}
	return ret;
}

int map2[11][11];

bool dfs(int u,int X,int Y,int t) {
	if(X==(1<<N)-1 && t==1 && map2[t][1]) return 1;

	if(!t) {
		for(int i=1;i<=N;++i)
			if(!(Y&(1<<(i-1))) && map2[u][i]) {
				if(dfs(i,X,Y|(1<<(i-1)),1)) return 1;
			}
	}
	else {
		for(int i=1;i<=N;++i)
			if(!(X&(1<<(i-1))) && map2[i][u]) {
				if(dfs(i,X|(1<<(i-1)),Y,0)) return 1;
			}
	}

	return 0;
}

int d1[11],d2[11];

inline bool judge1() {
	for(int i=1;i<=N;++i) d1[i]=d2[i]=0;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(map2[i][j]) ++d1[i],++d2[j];
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) {
			if(map2[i][j]==0) {
				if(d1[i]+d2[j]<2*N) return 0;
			}
			if(d1[i]+d1[j]<2*N) return 0;
			if(d2[i]+d2[j]<2*N) return 0;
		}

	return 1;
}

inline bool judge(int s) {
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) map2[i][j]=map1[i][j];
	for(int i=0;i<N;++i)
		if(s&(1<<i)) {
			for(int j=0;j<rcou1[i+1];++j)
				map2[i+1][rem1[i+1][j]]=map2[rem1[i+1][j]][i+1]=1;
		}

	if(N>1 && judge1()) return 1;

	if(dfs(1,1,0,0)) return 1;
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&M)) {
		for(int i=1;i<=N;++i) {
			rcou1[i]=rcou2[i]=0;
			for(int j=1;j<=N;++j) map1[i][j]=1;
		}

		for(int i=1;i<=M;++i) {
			scanf("%d %d",&a,&b);
			map1[a][b]=map1[b][a]=0;
			rem1[a][rcou1[a]++]=b;
			rem2[b][rcou2[b]++]=a;
		}

		if(N==0) {
			puts("0");
			continue;
		}

		if(N==1) {
			if(M) puts("1");
			else puts("0");
			continue;
		}

		int ans=100000;
		for(int i=0;i<(1<<N);++i)
			if(judge(i)) ans=min(ans,count(i));
		printf("%d\n",ans);
	}

	return 0;
}
