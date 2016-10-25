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
// Created Time  : 2016年09月10日 星期六 15时17分33秒
// File Name     : 1008.cpp

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

int N,A[MaxN];

int dp[MaxN][20];
int logN[MaxN];			// logN[i]表示log(i)的值。

void init_RMQ(int n,int num[]) {
	logN[0]=-1;

	for(int i=1;i<=n;++i) {
		dp[i][0]=num[i];
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];	// !!!
	}

	for(int j=1;j<=logN[n];++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

inline int RMQ(int x,int y) {
	int k=logN[y-x+1];

	return min(dp[x][k],dp[y-(1<<k)+1][k]);
}

inline int find(int L,int R,int x) {
	if(L>R) return -1;
	if(RMQ(L,R)>x) return -1;

	int M;
	while(R>L) {
		M=(L+R)>>1;
		if(RMQ(L,M)>x) L=M+1;
		else R=M;
	}

	return L;
}

inline int getans(int a,int b) {
	int ans=A[a];
	int t=find(a+1,b,ans);

	while(t!=-1) {
		ans%=A[t];
		t=find(t+1,b,ans);
	}

	return ans;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int Q,a,b;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",A+i);
		init_RMQ(N,A);

		scanf("%d",&Q);
		while(Q--) {
			scanf("%d %d",&a,&b);
			printf("%d\n",getans(a,b));
		}
	}

	return 0;
}
