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
// Created Time  : 2016年08月02日 星期二 14时39分43秒
// File Name     : 1011.cpp

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

const int MaxN=1003;
const int mod=1000000007;

int N,M;
int A[MaxN],B[MaxN];
long long ans[MaxN][MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&M)) {
		ans[0][0]=0;
		for(int i=1;i<=N;++i) scanf("%d",A+i),ans[i][0]=0;
		for(int i=1;i<=M;++i) scanf("%d",B+i),ans[0][i]=0;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				if(A[i]==B[j]) ans[i][j]=(ans[i-1][j]+ans[i][j-1]+1)%mod;
				else ans[i][j]=((ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1])%mod+mod)%mod;

		printf("%d\n",(int)ans[N][M]);
	}

	return 0;
}
