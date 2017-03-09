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
// Created Time  : 2017年02月12日 星期日 17时26分44秒
// File Name     : G_1.cpp

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

int N,M,mod;

inline void add(int & a,int b) {
	a+=b;
	if(a>=mod) a-=mod;
}

struct Matrix{
	int a[5][5];
	
	void reset(){
		memset(a,0,sizeof(a));
		for (int i=0;i<M;i++) a[i][i]=1;
	}

	Matrix operator * (const Matrix &t) const {
		Matrix ret;
		long long tmp;

		for (int i=0;i<M;++i)
			for (int j=0;j<M;++j) {
				tmp=0;
				for(int x=0;x<M;++x)
					tmp+=a[i][x]*(long long)t.a[x][j];
				ret.a[i][j]=tmp%mod;
			}

		return ret;
	}
}A,B;

inline long long read() {
	char c=0;
	while(c<'0' || c>'9') {
		c=getchar();
		if(c==EOF) return -1;
	}

	long long ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

Matrix rem[1000005];
int c[1000005];

void solve(int L,int M,int R) {
	int p=M+1;
	Matrix base;
	base.reset();

	for(int i=R;i>M;--i) {
		while(p>c[i] && p>L) {
			--p;
			base=rem[p]*base;
		}

		if(p>=c[i]) rem[i]=rem[i]*base;
	}
}

void getans(int L,int R) {
	if(L==R) {
		if(L) rem[L]=rem[L]*B;
		return;
	}
	int M=(L+R)>>1;
	getans(L,M);
	solve(L,M,R);
	getans(M+1,R);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(1) {
		N=read();
		if(N==-1) break;
		M=read();
		mod=read();

		for(int i=0;i<M;++i)
			for(int j=0;j<M;++j)
				A.a[i][j]=read();
		for(int i=0;i<M;++i)
			for(int j=0;j<M;++j)
				B.a[i][j]=read();

		for(int i=1;i<=N;++i) c[i]=read(),rem[i].reset();
		rem[0]=A;
		getans(0,N);

		for(int i=0;i<M;++i,puts(""))
			for(int j=0;j<M;++j) {
				if(j) putchar(' ');
				printf("%d",rem[N].a[i][j]);
			}
	}

	return 0;
}
