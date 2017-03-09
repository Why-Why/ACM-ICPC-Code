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
// Created Time  : 2016年11月17日 星期四 22时26分58秒
// File Name     : J.cpp

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

int N,M,P;
int K;
long long JJ[677][677],CC[677][677],FF[677][677];

inline void f(int x,int y) {
	long long c=0,t;
	int tx=x,ty=y;

	while(y>0) {
		++c;
		t=x%y;
		x=y;
		y=t;
	}

	JJ[tx][ty]=ty/x;
	CC[tx][ty]=c;
	FF[tx][ty]=c*x*x;

}

void init() {
	for(int j=1;j<=666;++j)
		for(int i=0;i<j;++i)
			f(i,j);
}

/*
inline long long calFF(int r,int j,int rk,long long J,long long C,long long F) {
	if(K<rk) return 0;

	long long KK=(K-rk)/C;
	long long B=(r*(long long)j+rk*(long long)j*j)/F;

	long long ret=((KK+1)*(B%P)%P+(((KK*(KK+1)/2)%P)*J%P*J%P)%P)%P;

	//cerr<<"C "<<r<<' '<<j<<' '<<rk<<' '<<J<<' '<<C<<' '<<F<<' '<<ret<<endl;

	return ret;
}

inline long long calFL(int r,int j) {
	if(N<r) return 0;

	long long ret=0;
	long long C=CC[r][j],J=JJ[r][j],F=FF[r][j];

	K=(N-r)/j;
	for(int i=0;i<C;++i) (ret+=calFF(r,j,i,J,C,F))%=P;

	//cerr<<"B "<<r<<' '<<j<<' '<<ret<<endl;
	return ret;
}

inline long long calL(int j) {
	long long ret=0;
	for(int i=0;i<j;++i) (ret+=calFL(i,j))%=P;

	//cerr<<"A "<<ret<<endl;
	return ret;
}

*/

/////////////////////////////////////////

inline long long add(long long a,long long b) {
	a+=b;
	if(a>=P) a-=P;
	return a;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T;
	long long J,C,F,B,K,KK,t;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&N,&M,&P);

		long long ans=0;

		for(int j=1;j<=M;++j)
			for(int r=0;r<j && r<=N;++r) {
				J=JJ[r][j]; C=CC[r][j]; F=FF[r][j];
				K=(N-r)/j;

				for(int rk=0;rk<C && rk<=K;++rk) {
					KK=(K-rk)/C;
					B=(r*j+rk*j*j)/F;
					//t=((KK+1)*(B%P)%P+(((KK*(KK+1)/2)%P)*J%P*J%P)%P)%P;

					t=(KK+1)*B+((KK+1)*KK/2)%P*J*J;

					ans=add(ans,t%P);
				}
			}

		printf("%d\n",(int)ans);
	}

	return 0;
}
