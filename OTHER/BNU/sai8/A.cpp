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
// Created Time  : 2016年10月07日 星期五 15时21分56秒
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

const int HASH=100003;
const int MaxN=3000000;
const int mod=100000007;

struct HashMap {
	int head[HASH],next[MaxN],Hcou;
	unsigned long long key[MaxN];
	int val[MaxN];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(unsigned long long k,int v) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(k==key[i])
				return;

		val[Hcou]=v;
		key[Hcou]=k;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	int find(unsigned long long k) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(k==key[i])
				return val[i];

		return -1;
	}
}rem;

inline void add(long long & a,long long b) {
	a+=b;
	if(a>=mod) a-=mod;
}

long long getans(long long X,long long Y,long long x,long long y) {
	if(x==0) return 1;

	unsigned long long key=(X<<36LL)+(Y<<24LL)+(x<<12LL)+y;
	long long ret=rem.find(key);

	if(ret!=-1) return ret;
	ret=0;

	for(int k=y;k<=Y;++k)
		add(ret,getans(k,X-1,k-y,x-1));

	rem.insert(key,ret);
	return ret;
}

long long getans1(long long X,long long Y,long long x,long long y) {
	if(x==y) {
		return 1+(Y-max(x,y))*(1LL+(x*y+1LL)*(X-max(x,y)));
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	rem.init();

	int N,a,b,c,d;
	scanf("%d",&N);

	for(int i=1;i<=N;++i) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("%d\n",(int)getans(a,b,c,d));
	}

	return 0;
}
