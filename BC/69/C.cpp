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
// Created Time  : 2016年01月23日 星期六 19时44分17秒
// File Name     : C.cpp

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

int map1[15][105];
int N,M;

int ans[15][105];
int tans[15][105];

inline bool judge1() {
	for(int i=1;i<=N;++i)
		if(tans[i][M]+tans[i-1][M]+tans[i+1][M]+tans[i-1][M-1]+tans[i][M-1]+tans[i+1][M-1]!=map1[i][M]) return 0;
	return 1;
}

inline void copy() {
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j) ans[i][j]=tans[i][j];
}

inline bool judge(int sta) {
	tans[1][1]=tans[N][1]=tans[N+1][1]=0;
	for(int i=0;i<(N-2);++i)
		tans[i+2][1]=((1<<i)&sta) ? 1 : 0;

	for(int j=2;j<=M;++j) {
		tans[1][j]=0;
		for(int i=2;i<=N+1;++i) {
			tans[i][j]=map1[i-1][j-1]-tans[i-2][j-2]-tans[i-1][j-2]-tans[i][j-2]-tans[i-2][j-1]-tans[i-1][j-1]-tans[i][j-1]-tans[i-2][j]-tans[i-1][j];
			if(tans[i][j]!=0 && tans[i][j]!=1) return 0;
			if(i>=N && tans[i][j]) return 0;
		}
	}

	if(judge1()) return 1;
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
			for(int j=1;j<=M;++j) scanf("%d",&map1[i][j]);
		int have=0;
		for(int i=0;i<(1<<(N-2)) && have!=2;++i)
			if(judge(i)) {
				if(have) have=2;
				else have=1,copy();
			}
		if(have==0) puts("Impossible");
		else if(have==2) puts("Multiple");
		else {
			for(int i=1;i<=N;++i)
				for(int j=1;j<=M;++j) printf("%d%c",ans[i][j],j==M ? '\n' : ' ');
		}
	}
	
	return 0;
}
