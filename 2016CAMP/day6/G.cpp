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
// Created Time  : 2017年02月18日 星期六 11时07分03秒
// File Name     : G.cpp

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

long long a,b;
long long g;
long long acou=0;
long long rinv;

char rem[105];

long long gcd(long long a,long long b) {
	if(!a) return b;
	return gcd(b%a,a);
}

long long extend_gcd(long long a,long long b,long long &x,long long &y) {
	if(a==0&&b==0) return -1;//无最大公约数
	if(b==0){x=1;y=0;return a;}
	long long d=extend_gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

long long inv(long long a,long long n) {
	long long x,y;
	long long d=extend_gcd(a,n,x,y);
	if(d==1) return (x%n+n)%n;
	else return -1;
}

set <long long> sta[55];
long long maxn[55];

long long getans(long long N,long long r) {
	cerr<<N<<' '<<r<<endl;
	if(acou>=100) return 100;

	if(N==0) {
		if(!r) {
			puts(rem+1);
			++acou;
			return 1;
		}
		return 0;
	}

	if(sta[N].count(r)) return 0;

	long long ret=0;

	for(long long i=1;i<=26;++i) {
		rem[N]='a'+i-1;
		ret+=getans(N-1,((r-i)%b+b)%b*rinv%b);

		if(acou>=100) return 100;
	}

	if(!ret) sta[N].insert(r);

	return ret;
}

inline void getans(long long N) {
	if(g==1) getans(N,0);
	else {
		rem[N]='a';
		getans(N-1,0);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%lld %lld",&a,&b);
	g=gcd(a,b);
	long long len=2;

	if(g!=1) b/=g;
	rinv=inv(a,b);

	while(acou<100 && len<=50) {
		getans(len);
		++len;
	}

	return 0;
}
