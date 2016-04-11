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
// Created Time  : 2016年04月09日 星期六 21时48分13秒
// File Name     : C1.cpp

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

const int S=8;
const int wei=32;

__int128 fac[20];

__int128 getnum(__int128 x,__int128 p) {
	__int128 ret=0,base=1;
	for(int i=0;i<wei;++i) {			// !!!
		if(x&(1LL<<i)) ret+=base;
		base*=p;
	}
	return ret;
}

__int128 mult_mod(__int128 a,__int128 b,__int128 c) {\
	a%=c;
	b%=c;
	__int128 ret=0,tmp=a;

	while(b) {
		if(b&1) {
			ret+=tmp;
			if(ret>c) ret-=c;
		}
		tmp<<=1;
		if(tmp>c) tmp-=c;
		b>>=1;
	}
	return ret;
}

__int128 pow_mod(__int128 a,__int128 n,__int128 mod) {
	__int128 ret=1;
	__int128 temp=a%mod;
	while(n) {
		if(n&1) ret=mult_mod(ret,temp,mod);
		temp=mult_mod(temp,temp,mod);
		n>>=1;
	}
	return ret;
}

bool check(__int128 a,__int128 n,__int128 x,__int128 t) {
	__int128 ret=pow_mod(a,x,n);
	__int128 last=ret;
	for(int i=1;i<=t;++i) {
		ret=mult_mod(ret,ret,n);
		if(ret==1 && last!=1 && last!=n-1) return true;
		last=ret;
	}
	if(ret!=1) return 1;
	return 0;
}

bool Miller_Rabin(__int128 n) {
	if(n<2) return 0;
	if(n==2) return 1;
	if((n&1)==0) return 0;
	__int128 x=n-1;
	__int128 t=0;
	while((x&1)==0) { x>>=1;++t; }
	srand(time(NULL));
	for(int i=0;i<S;++i) {
		__int128 a=rand()%(n-1)+1;
		if(check(a,n,x,t)) return 0;
	}
	return 1;
}

__int128 gcd(__int128 a,__int128 b) {
	__int128 t;
	while(b) {
		t=a; a=b; b=t%b;
	}
	if(a>=0) return a;
	else return -a;
}

__int128 pollard_rho(__int128 x,__int128 c) {
	__int128 i=1,k=2;
	srand(time(NULL));
	__int128 x0=rand()%(x-1)+1;
	__int128 y=x0;

	while(1) {
		++i;
		x0=(mult_mod(x0,x0,x)+c)%x;
		__int128 d=gcd(y-x0,x);

		if(d!=1 && d!=x) return d;
		if(y==x0) return x;
		if(i==k) { y=x0; k+=k; }
	}
	return x;
}

__int128 findfac(__int128 n,int k) {
	if(n==1) return -1;
	if(Miller_Rabin(n)) return -1;

	__int128 p=n;
	int c=k;
	while(p==n) p=pollard_rho(n,c--);
	return p;
}

bool judge(__int128 x,int p) {
	__int128 t=findfac(x,107);
	if(t!=-1) { fac[p]=t; return 1; }
	return 0;
}

void show(__int128 x) {
	for(int i=wei-1;i>=0;--i) {
		if(x&(1<<i)) putchar('1');
		else putchar('0');
	}
	for(int i=2;i<=10;++i) printf(" %lld",(long long)fac[i]);
	puts("");
}

inline bool judge(__int128 x) {
	for(int i=2;i<=10;++i)
		if(!judge(getnum(x,i),i)) return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int zu=500;
	__int128 t;

	puts("Case #1:");
	for(__int128 i=(1<<(wei-2));i<(1LL<<(wei-1)) && zu;++i) {
		t=(i<<1)|1;
		if(judge(t)) show(t),--zu;
	}
	
	return 0;
}
