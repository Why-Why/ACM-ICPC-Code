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
// Created Time  : 2017年02月07日 星期二 23时04分48秒
// File Name     : B.cpp

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

const long long INF=1000000000000000000LL;

int N;
long long K;
char ans[100005];

int A[100005],B[100005];
int pA,pB;
bool okA,okB;
int lenA,lenB;

inline long long checkA() {
	bool okA=::okA;
	if(lenA+1-pA<pA && A[lenA+1-pA]!=A[pA]) okA=0;
	if(!okA) return 0;

	int nA=max(0,((lenA+1)>>1)-pA);		// !!!
	nA+=lenB-pB;

	if(nA>=60) return INF;
	return (1LL<<nA);
}

inline long long checkB() {
	bool okB=::okB;
	if(lenB+1-pB<pB && B[lenB+1-pB]!=B[pB]) okB=0;
	if(!okB) return 0;

	int nB=max(0,((lenB+1)>>1)-pB);		// !!!
	nB+=lenA-pA;

	if(nB>=60) return INF;
	return (1LL<<nB);
}

inline long long check() {
	bool okA=::okA,okB=::okB;
	if(lenA+1-pA<pA && A[lenA+1-pA]!=A[pA]) okA=0;
	if(lenB+1-pB<pB && B[lenB+1-pB]!=B[pB]) okB=0;
	if(!okA || !okB) return 0;

	int nA=max(0,((lenA+1)>>1)-pA),nB=max(0,((lenB+1)>>1)-pB);		// !!!
	return (1LL<<nA)*(1LL<<nB);
}

inline long long cal() {
	long long x=checkA(),y=checkB();

	if(x>=INF || y>=INF) return INF;
	return x+y-check();
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	long long t;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %I64d",&N,&K);
		printf("Case #%d: ",cas++);
		pA=pB=0;
		okA=okB=1;
		lenA=(N+1)>>1;
		lenB=N>>1;

		if(cal()<K) {
			puts("NOT FOUND!");
			continue;
		}

		for(int i=1;i<=N;++i) {
			if(i&1) A[++pA]=0;
			else B[++pB]=0;

			t=cal();

			if(t>=K) ans[i]='0';
			else {
				K-=t;
				ans[i]='1';

				if(i&1) A[pA]=1;
				else B[pB]=1;
			}

			if((i&1) && lenA+1-pA<pA && A[lenA+1-pA]!=A[pA]) okA=0;
			if(!(i&1) && lenB+1-pB<pB && B[lenB+1-pB]!=B[pB]) okB=0;
		}

		ans[N+1]=0;
		puts(ans+1);
	}

	return 0;
}
