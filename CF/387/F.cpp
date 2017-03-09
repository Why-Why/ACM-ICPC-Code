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
// Created Time  : 2017年01月16日 星期一 16时20分50秒
// File Name     : F.cpp

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

typedef unsigned long long ULL;

const int HASH=100003;
const int MaxN=1000000;

struct HASHMAP {
	int head[HASH],next[MaxN],Hcou;
	ULL key[MaxN];
	long long val[MaxN];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(ULL k,long long v) {
		int h=k%HASH;
		val[Hcou]=v;
		key[Hcou]=k;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	long long get(ULL k) {
		int h=k%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) return val[i];
		return -1;
	}
}rem[10];

long long K,T;

long long dfs(int p,ULL use) {
	if(p<1) return use ? 1 : 0;

	long long ret=0,t;

	t=rem[p].get(use);
	if(t!=-1) return t;

	for(int i=0;i<16;++i)
		if(((use>>(4*i)) & 15)<T) {
			if(use==0 && i==0) t=dfs(p-1,0);
			else t=dfs(p-1,use+(1LL<<(4LL*i)));

			ret+=t;
		}

	rem[p].insert(use,ret);

	return ret;
}

int ans[15];

void getans() {
	long long t;
	ULL use=0;
	bool ok=0;

	for(int i=9;i>=1;--i)
		for(int j=0;j<16;++j)
			if(((use>>(4*j)) & 15)<T) {
				if(ok || j) t=dfs(i-1,use+(1LL<<(4LL*j)));
				else t=dfs(i-1,0);

				if(K>t) K-=t;
				else {
					if(j) ok=1;
					if(ok) use+=(1LL<<(4LL*j));
					ans[i]=j;
					break;
				}
			}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<=9;++i) rem[i].init();

	cin>>K>>T;
	getans();

	bool ok=0;
	for(int i=9;i>=1;--i) {
		if(ans[i]) ok=1;
		if(ok) putchar(ans[i]<10 ? '0'+ans[i] : 'a'+ans[i]-10);
	}
	puts("");

	return 0;
}
