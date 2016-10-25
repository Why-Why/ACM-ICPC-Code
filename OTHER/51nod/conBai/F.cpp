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
// Created Time  : 2016年05月20日 星期五 20时45分55秒
// File Name     : F.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int mod=1000000007;

struct HASHMAP {
	static const int HASH=100003;
	static const int MaxS=50000000;

	int head[HASH],Hcou,next[MaxS];
	long long key[MaxS];
	long long value[MaxS];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(long long k,long long v) {
		int h=k%HASH;
		v%=mod;

		for(int i=head[h];i!=-1;i=next[i])
			if(k==key[i]) {
				(value[i]+=v)%=mod;
				return;
			}
		key[Hcou]=k;
		value[Hcou]=v;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	long long find(long long k) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) return value[i];
		return 0;
	}
}dp[2];

int N,M;

void show(long long x) {
	for(int i=0;i<33;++i,x>>=1)
		if(x&1) putchar('1');
		else putchar('0');
	puts("");
}

inline int pos(long long sta,long long p) {
	return (sta&(3LL<<(p<<1LL)))>>(p<<1LL);
}

inline long long set(long long sta,long long p,long long v) {
	return (sta & (~(3LL<<(p<<1LL)))) | (v<<(p<<1LL));
}

inline long long set(long long sta,long long p1,long long v1,long long p2,long long v2) {
	sta=set(sta,p1,v1);
	return set(sta,p2,v2);
}

void getans_1(int h,int flag) {
	long long sta,v;
	int a;

	for(int i=0;i<dp[flag].Hcou;++i) {
		sta=dp[flag].key[i];
		v=dp[flag].value[i];

		a=pos(sta,0);

		if(a==0) dp[flag^1].insert(set(sta,0,2,16,h!=1 ? 1 : 0),v);
		else if(a==2) dp[flag^1].insert(set(sta,0,0),v);
	}
}

void getans(int h,int l,int flag) {
	long long sta,v;
	int a,b;

	for(int i=0;i<dp[flag].Hcou;++i) {
		sta=dp[flag].key[i];
		v=dp[flag].value[i];

		a=pos(sta,l-2);
		b=pos(sta,l-1);

		if(a<2 && b<2) dp[flag^1].insert(set(sta,l-1,b+2),v);
		else if(b>1) dp[flag^1].insert(set(sta,l-1,b-2,16,0),v);
		else {
			dp[flag^1].insert(set(sta,l-2,a-2,l-1,1),v);
			dp[flag^1].insert(set(sta,l-1,b+2),v);
		}
	}
}

inline long long getans() {
	int flag=0;
	long long sta=0;
	dp[0].init();
	dp[0].insert(0,1);

	for(int i=1;i<=N;++i) {
		dp[flag^1].init();
		for(int j=0;j<dp[flag].Hcou;++j)
			if(!(dp[flag].key[j]&(1LL<<32LL)))
				dp[flag^1].insert(dp[flag].key[j],dp[flag].value[j]);
		flag^=1;

		dp[flag^1].init();
		getans_1(i,flag);
		flag^=1;

		for(int j=2;j<=M;++j) {
			cerr<<i<<' '<<j<<' '<<dp[flag].Hcou<<endl;
			dp[flag^1].init();
			getans(i,j,flag);
			flag^=1;
		}
	}

	long long end=0;
	for(int i=1;i<M;++i) {
		end<<=2;
		end|=1;
	}
	end<<=2;
	return dp[flag].find(end);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long ans;

	N=M=16;
	cerr<<16<<','<<16<<','<<getans()<<endl;
	
	return 0;
}
