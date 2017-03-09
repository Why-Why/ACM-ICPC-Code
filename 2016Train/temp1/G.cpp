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
// Created Time  : 2016年04月22日 星期五 23时36分16秒
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

const int MaxN=200005;
const double pi=atan2(1.0,1.0)*4;

double D[MaxN];
double jie[MaxN];

inline double _pow(double x,int b) {
	double base=x;
	double ret=1;

	while(b) {
		if(b&1) ret*=base;
		base*=base;
		b>>=1;
	}
	return ret;
}

inline double getC(int x) {
	if(x&1) return _pow(2,x)*jie[x/2]*_pow(pi,x/2)/jie[x];
	else return _pow(pi,x/2)/jie[x/2];
}

void init() {
	jie[0]=1;
	for(int i=1;i<MaxN;++i) jie[i]=jie[i-1]*i;
	for(int i=2;i<MaxN;++i)
		D[i]=getC(i-1)*pow((i-1.0)/i,(i+1.0)/2)/(i+1.0);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	double R;

	init();

	cout<<D[2]<<endl;

	while(~scanf("%d %lf",&N,&R)) {
		if(N==1) printf("%.10f\n",R/2.0);
		else printf("%.10f\n",_pow(R,N+1)/((N*(double)N-1.0)*pow(N,(N+1.0)/2.0))+D[N]);
	}
	
	return 0;
}
