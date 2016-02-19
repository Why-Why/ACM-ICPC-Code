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
// Created Time  : 2015年12月21日 星期一 20时41分28秒
// File Name     : 2976_2.cpp

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
const double eps=1e-6;				// !!!

int N,K;
double A[MaxN],B[MaxN];

typedef pair <double,int> pii;
pii rem[MaxN];

double getans() {
	double L=100,ans;
	double a,b;

	do {
		ans=L;
		for(int i=1;i<=N;++i) rem[i].first=A[i]-L*B[i],rem[i].second=i;
		sort(rem+1,rem+N+1);

		a=b=0;
		for(int i=N-K+1;i<=N;++i) a+=A[rem[i].second],b+=B[rem[i].second];
		L=a/b;
	}while(L-ans>eps || ans-L>eps); // !!!

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&K) && N+K) {
		for(int i=1;i<=N;++i) scanf("%lf",A+i);
		for(int i=1;i<=N;++i) scanf("%lf",B+i);
		K=N-K;
		printf("%.0f\n",100*getans());
	}
	
	return 0;
}
