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
// Created Time  : 2016年12月01日 星期四 16时46分00秒
// File Name     : D.cpp

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

const int S = 8;

long long mult_mod(long long a,long long b,long long c) {
	a %= c;
	b %= c;
	long long ret = 0;
	long long tmp = a;
	while(b) {
		if(b & 1) {
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<= 1;
		if(tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret;
}

long long pow_mod(long long a,long long n,long long mod) {
	long long ret = 1;
	long long temp = a%mod;
	while(n) {
		if(n & 1) ret = mult_mod(ret,temp,mod);
		temp = mult_mod(temp,temp,mod);
		n >>= 1;
	}
	return ret;
}

bool check(long long a,long long n,long long x,long long t) {
	long long ret = pow_mod(a,x,n);
	long long last = ret;
	for(int i = 1;i <= t;i++) {
		ret = mult_mod(ret,ret,n);
		if(ret == 1 && last != 1 && last != n-1)return true;//合数
		last = ret;
	}
	if(ret != 1)return true;
	else return false;
}

bool Miller_Rabin(long long n) {
	if( n < 2) return false;
	if( n == 2) return true;
	if( (n&1) == 0) return false;//偶数
	long long x = n - 1;
	long long t = 0;
	while( (x&1)==0 ) { x >>= 1; t++; }
	srand(time(NULL));/* *************** */
	for(int i = 0;i < S;i++) {
		long long a = rand()%(n-1) + 1;
		if( check(a,n,x,t) )
			return false;
	}
	return true;
}

inline bool isP(long long x) {
	return Miller_Rabin(x);
}

int getans(long long N) {
	if(isP(N)) return 1;
	if(N%2==0) return 2;
	if(isP(N-2)) return 2;
	return 3;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long N;
	cin>>N;
	cout<<getans(N)<<endl;

	return 0;
}
