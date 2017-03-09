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
// Created Time  : 2017年02月03日 星期五 20时49分40秒
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

int N,L;
int A[55],D[155],B[55],DD[55];

bool judge(int A[],int B[]) {
	for(int i=0;i<N;++i) if(A[i]!=B[i]) return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&L);
	for(int i=0;i<N;++i) scanf("%d",A+i);
	for(int i=0;i<N;++i) scanf("%d",B+i);
	for(int i=0;i<N;++i) D[i]=(A[(i+1)%N]-A[i]+L)%L,D[i+N]=D[i],DD[i]=(B[(i+1)%N]-B[i]+L)%L;

	for(int i=0;i<N;++i)
		if(judge(D+i,DD)) {
			puts("YES");
			return 0;
		}
	puts("NO");

	return 0;
}
