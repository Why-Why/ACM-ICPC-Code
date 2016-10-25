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
// Created Time  : 2016年09月09日 星期五 20时26分59秒
// File Name     : 1002.cpp

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
const int mod=268435456;

int N,X,L;
int A[MaxN];

inline bool judge(int K) {
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int P.Q;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&N,&X,&L);
		scanf("%d %d %d",A+1,&P,&Q);
		for(int i=2;i<=N;++i) A[i]=(A[i-1]*(long long)P+Q)%mod;

		int L=1,R=N/L,M;
		while(R>L) {
			M=(L+R)>>1;
			if(judge(M)) L=M;
			else R=M-1;
		}
		printf("%d\n",L);
	}

	return 0;
}
