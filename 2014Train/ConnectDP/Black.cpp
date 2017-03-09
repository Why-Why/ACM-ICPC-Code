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
// Created Time  : 2015年12月14日 星期一 11时53分03秒
// File Name     : Black.cpp

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

struct HASHMAP {
	static const int HASH=30007;
	static const int MaxS=1000000;

	int head[HASH],Hcou,next[MaxS];
	unsigned int key[MaxS];
	long long val[MaxS];
	unsigned long long route[MaxS];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(unsigned int k,LL v,ULL r) {
		int h=k%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) {
				val+=v;
				return;
			}
		val[Hcou]=v;
		route[Hcou]=r;
		key[Hcou]=k;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	LL find(unsigned int k,ULL &r) {
		int h=k%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) {
				r=route[i];
				return val[i];
			}
		return 0;
	}
}dp[2];

int N,M;
char map1[11][11];

void solve() {
	int flag=0;
	dp[0].init();
	dp[0].insert()
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i) scanf("%s",map1[i]+1);
		solve();
		puts("");
	}
	
	return 0;
}
