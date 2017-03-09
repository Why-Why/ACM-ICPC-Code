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
// Created Time  : 2017年02月07日 星期二 23时57分04秒
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

int N,K;
long long A[300005];

int last[300005];

inline bool judge(int M) {
	if(!M) return 1;
	if(M*K>N) return 0;

	memset(last,0,sizeof(last));
	int p=1;

	for(int i=1;i<=K;++i) {
		for(int j=1;j<=M;++j) {
			while(p<=N && A[p]<(A[last[j]]<<1)) ++p;
			if(p>N) return 0;
			last[j]=p;
			++p;
		}
	}

	return 1;
}

int getans() {
	int L=0,R=N,M;

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

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&K);
		for(int i=1;i<=N;++i) scanf("%I64d",A+i);
		sort(A+1,A+N+1);

		printf("Case #%d: %d\n",cas++,getans());
	}

	return 0;
}
