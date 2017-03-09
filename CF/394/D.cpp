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
// Created Time  : 2017年02月03日 星期五 19时41分08秒
// File Name     : D.cpp

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

const int MaxN=100005;

int N,L,R;
int A[MaxN],C[MaxN];
long long rC[MaxN],B[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&L,&R);
	for(int i=1;i<=N;++i) scanf("%d",A+i);
	for(int i=1;i<=N;++i) scanf("%d",C+i),rC[C[i]]=i;

	long long base=-1000000000000000LL;

	for(int i=1;i<=N;++i) {
		B[rC[i]]=max((long long)L,base+A[rC[i]]+1);
		if(B[rC[i]]>R) {
			puts("-1");
			return 0;
		}
		base=B[rC[i]]-A[rC[i]];
	}

	for(int i=1;i<=N;++i) printf("%d ",(int)B[i]);
	puts("");

	return 0;
}
