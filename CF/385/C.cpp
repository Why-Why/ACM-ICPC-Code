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
// Created Time  : 2017年01月16日 星期一 22时51分28秒
// File Name     : C.cpp

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

int N;
int C[18],R[18],B[18];

const int TTT=130;

int dp[(1<<16)+5][TTT+3];

inline void solve(int sta) {
	int couR=0,couB=0;
	for(int i=0;i<N;++i)
		if(sta & (1<<i))
			if(C[i]) ++couR;
			else ++couB;

	int t,tt;

	for(int d=0;d<=TTT;++d) {
		if(dp[sta][d]==-1) continue;

		for(int i=0;i<N;++i)
			if(!(sta & (1<<i))) {
				t=min(R[i],couR)+d;
				tt=min(B[i],couB);

				if(t<=TTT) dp[sta | (1<<i)][t]=max(dp[sta | (1<<i)][t],dp[sta][d]+tt);
			}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[10];
	int sumR=0,sumB=0;

	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;

	scanf("%d",&N);
	for(int i=0;i<N;++i) {
		scanf("%s %d %d",s,R+i,B+i);
		sumR+=R[i];
		sumB+=B[i];
		if(s[0]=='R') C[i]=1;
		else C[i]=0;
	}

	for(int i=0;i<(1<<N);++i) solve(i);

	int ans=0x3f3f3f3f;
	for(int i=0;i<=TTT;++i)
		if(dp[(1<<N)-1][i]!=-1)
			ans=min(ans,max(sumR-i,sumB-dp[(1<<N)-1][i]));

	printf("%d\n",ans+N);

	return 0;
}
