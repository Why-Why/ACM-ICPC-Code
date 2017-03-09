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
// Created Time  : 2017年01月08日 星期日 15时13分39秒
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
#include <bitset>

using namespace std;

const int MaxN=805;

int N,M,R,C;

struct bitmap {
	bitset <MaxN> num[MaxN];

	bitmap() {
		for(int i=0;i<MaxN;++i) num[i].reset();
	}

	void set(int x,int y) {
		num[x].set(y);
	}

	/*
	bitmap move(int a,int b) {
		bitmap ret=*this;
		for(int i=0;i<MaxN;++i) {
			if(i+a<MaxN) ret.num[i]=ret.num[i+a]>>b;
			else ret.num[i].reset();
		}
		return ret;
	}

	bitmap operator & (const bitmap & b) const {
		bitmap ret;
		for(int i=0;i<MaxN;++i) ret.num[i]=num[i] & b.num[i];
		return ret;
	}
	*/

	void solve(const bitmap & a,int x,int y) {
		for(int i=0;i<N;++i)
			if(i+x<MaxN) num[i]&=a.num[i+x]>>y;
			else num[i].reset();
	}

	void show(int N,int M) const {
		for(int i=0;i<N;++i,puts(""))
			for(int j=0;j<M;++j)
				putchar('0'+num[i][j]);
	}
}rem[26],ans;

char map1[MaxN][MaxN];
char flag[MaxN][MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	for(int i=0;i<N;++i) scanf("%s",map1[i]);

	scanf("%d %d",&R,&C);

	for(int i=0;i<N+R;++i)
		for(int j=0;j<M+C;++j)
			rem[map1[i%N][j%M]-'a'].set(i,j);

	for(int i=0;i<N;++i) ans.num[i].set();
	for(int i=0;i<R;++i) {
		scanf("%s",flag[i]);
		for(int j=0;j<C;++j)
			if(flag[i][j]!='?')
				ans.solve(rem[flag[i][j]-'a'],i,j);
	}
	ans.show(N,M);

	return 0;
}
