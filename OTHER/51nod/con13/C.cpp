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
// Created Time  : 2016年04月30日 星期六 13时08分08秒
// File Name     : C.cpp

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

struct MAT {
	int num[2][2];

	MAT(int p=0) {
		num[0][1]=num[1][0]=0;
		num[0][0]=num[1][1]=p;
	}

	MAT operator * (const MAT &b) const {
		MAT ret;
		int t;

		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j) {
				t=0;
				for(int k=0;k<2;++k) (t+=num[i][k]*b.num[k][j])%=4;
				ret.num[i][j]=t;
			}
		return ret;
	}
};

long long A0,a,b,N;

int _pow(long long N) {
	MAT ret=1,base;
	base.num[0][0]=int(a%4);
	base.num[0][1]=int(b%4);
	base.num[1][1]=1;

	while(N) {
		if(N&1) ret=ret*base;
		base=base*base;
		N>>=1;
	}
	return (ret.num[0][0]*A0+ret.num[0][1])%4;				// !!!
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%lld %lld %lld %lld",&A0,&a,&b,&N);
		if(N==0) {
			if(A0==0) {
				puts("=");
				continue;
			}
		}
		else if(b==0) {
			if(A0==0 || a==0) {
				puts("=");
				continue;
			}
		}

		A0%=4;
		int t=_pow(N);

		if(t==1) puts("=");
		else if(t==3) puts(">");
		else puts("<");
	}

	return 0;
}
