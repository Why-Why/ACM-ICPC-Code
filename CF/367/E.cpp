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
// Created Time  : 2016年09月08日 星期四 18时40分50秒
// File Name     : E.cpp

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

const int MaxN=1005;

struct State {
	int r,d;
	int v;
};

int N,M,Q;
State num[MaxN*MaxN];

inline int getP(int x,int y) {
	int ret=0;
	for(int i=1;i<=x;++i) ret=num[ret].d;
	for(int i=1;i<=y;++i) ret=num[ret].r;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d,e,f;
	int x,y,tx,ty;

	scanf("%d %d %d",&N,&M,&Q);
	for(int i=0;i<=N;++i)
		for(int j=0;j<=M;++j) {
			a=i*(M+1)+j;
			if(i && j) scanf("%d",&num[a].v);

			if(j<M) num[a].r=a+1; else num[a].r=-1;
			if(i<N) num[a].d=a+M+1; else num[a].d=-1;
		}

	while(Q--) {
		scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
		tx=x=getP(a-1,b-1);
		ty=y=getP(c-1,d-1);

		for(int i=1;i<=e;++i) {
			tx=num[tx].d;
			ty=num[ty].d;
			swap(num[tx].r,num[ty].r);
		}
		for(int i=1;i<=f;++i) {
			tx=num[tx].r;
			ty=num[ty].r;
			swap(num[tx].d,num[ty].d);
		}

		tx=x;
		ty=y;
		for(int i=1;i<=f;++i) {
			tx=num[tx].r;
			ty=num[ty].r;
			swap(num[tx].d,num[ty].d);
		}
		for(int i=1;i<=e;++i) {
			tx=num[tx].d;
			ty=num[ty].d;
			swap(num[tx].r,num[ty].r);
		}
	}

	x=getP(0,0);
	for(int i=1;i<=N;++i) {
		x=num[x].d;
		y=x;
		for(int j=1;j<=M;++j) {
			y=num[y].r;
			printf("%d ",num[y].v);
		}
		puts("");
	}

	return 0;
}
