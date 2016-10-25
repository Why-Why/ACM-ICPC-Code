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
// Created Time  : 2016年05月06日 星期五 20时56分26秒
// File Name     : H.cpp

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

int N;
int A[MaxN];
long long B[MaxN];
long long dp[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",A+i);
		B[N+1]=0;
		for(int i=N;i>=1;--i) B[i]=B[i+1]+A[i];

		int t;

		dp[1]=0;
		for(int i=2;i<=N;++i) {
			dp[i]=100000000000000000LL;
			for(int j=i-1,k=i-1;k>0;k-=2,--j) {
				if(dp[i]>dp[j]+B[k]) {
					t=j;
					dp[i]=dp[j]+B[k];
				}
				cout<<dp[j]+B[k]<<' ';
			}
			cout<<endl;
			cout<<t<<endl;
		}

		for(int i=1;i<=N;++i) cout<<dp[i]<<' ';
		cout<<endl;
	}
	
	return 0;
}
