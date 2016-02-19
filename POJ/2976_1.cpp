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
// Created Time  : 2015年12月21日 星期一 20时13分43秒
// File Name     : 2976_1.cpp

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

const int MaxN=1011;
const double eps=1e-4;
const double INF=105.0;

int N,K;
int A[MaxN],B[MaxN];
double rem[MaxN];

bool judge(double M) {
	for(int i=1;i<=N;++i) rem[i]=A[i]-M*B[i];
	sort(rem+1,rem+N+1);
	double ans=0;
	for(int i=N-K+1;i<=N;++i) ans+=rem[i];
	return ans>=-eps;
}

double getans() {
	double L,R,M;
	L=0;
	R=INF;

	while(R-L>eps) {
		M=(L+R)/2.0;
		if(judge(M)) L=M;
		else R=M;
	}
	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&K) && N+K) {
		for(int i=1;i<=N;++i) scanf("%d",A+i);
		for(int i=1;i<=N;++i) scanf("%d",B+i);
		K=N-K;
		printf("%.0f\n",100*getans());
	}
	
	return 0;
}
