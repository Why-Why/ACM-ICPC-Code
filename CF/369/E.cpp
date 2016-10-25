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
// Created Time  : 2016年08月30日 星期二 00时18分11秒
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

const int mod=1000003;

long long n,k;

long long get2(long long x) {
	if(x<=1) return 0;
	return get2(x/2)+x/2LL;
}

inline int wei(long long x) {
	int ret=0;
	for(;x;x>>=1) ++ret;
	return ret;
}

inline long long del(long long a,long long b) {
	a%=mod;
	b%=mod;
	return ((a-b)%mod+mod)%mod;
	a-=b;
	if(a<0) a+=mod;
	return a;
}

inline long long add(long long a,long long b) {
	a%=mod;
	b%=mod;
	return (a+b)%mod;
	a+=b;
	if(a>=mod) a-=mod;
	return a;
}

long long inv(long long a,long long m) {
	if(a == 1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

inline long long mul(long long a,long long b) {
	a%=mod;
	b%=mod;

	long long ret=0;

	for(;b;b>>=1,(a<<=1)%=mod)
		if(b&1)
			ret=add(ret,a);

	return ret;
}

inline long long _pow(long long a,long long n) {
	a%=mod;

	long long ret=1;

	for(;n;n>>=1,a=mul(a,a))
		if(n&1) ret=mul(ret,a);

	return ret;
}

long long gcd(long long a,long long b) {
	if(!a) return b;
	return gcd(b%a,a);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>n>>k;

	int t=wei(k)-1;
	if(t>n || (t==n && (1LL<<t)<k)) {
		puts("1 1");
		return 0;
	}

	--k;

	long long n2=get2(k);
	long long a=_pow(_pow(2,k),n),b=inv(_pow(2,n2),mod),c;

	if(k>=mod) c=0;
	else {
		long long d=_pow(2,n);
		c=1;
		for(long long i=1;i<=k;++i) c=mul(c,del(d,i));
	}

	c=mul(c,b);

	long long A,B,ttt;

	B=mul(a,b);
	A=del(B,c);

	cout<<A<<' '<<B<<endl;

	return 0;
}
