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
// Created Time  : 2016年10月07日 星期五 11时42分33秒
// File Name     : LCS2.cpp

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

typedef unsigned long long ULL;

const ULL seed=131313;

char s[13][MaxN];
int len[13];
int N;

inline bool judge(int M) {
	int p[13]={};
	ULL v[13]={};
	ULL base=1;

	for(int i=0;i<M;++i) base*=seed;

	for(int i=1;i<=N;++i) {
		if(len[i]<M) return 0;
		for(int j=0;j<M;++j) v[i]=v[i]*seed+s[i][j];
	}

	int cou;
	ULL maxn;

	while(1) {
		maxn=v[1];
		cou=1;
		for(int i=2;i<=N;++i)
			if(maxn<v[i]) {
				maxn=v[i];
				cou=1;
			}
			else if(maxn==v[i])
				++cou;

		if(cou==N) return 1;

		for(int i=1;i<=N;++i) {
			while(p[i]+M-1<len[i] && v[i]<maxn) 
		}
	}
}

int getans() {
	int L=0,R=len[1],M;

	while(R>L) {
		M=(L+R+1)>>1;
		if(judge(M)) L=M;
		else R=M-1;
	}

	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s[++N])) len[N]=strlen(s[N]);
	--N;
	printf("%d\n",getans());

	return 0;
}
