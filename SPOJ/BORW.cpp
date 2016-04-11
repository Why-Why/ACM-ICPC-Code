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
// Created Time  : 2016年04月01日 星期五 15时57分11秒
// File Name     : BORW.cpp

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

const int MaxN=205;
const int INF=0x3f3f3f3f;

int dp[MaxN][MaxN][MaxN];
int N,cou;
int rem[MaxN];
int hash[1000006];
int num[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N) && N!=-1) {
		for(int i=1;i<=N;++i) scanf("%d",num+i),rem[i]=num[i];
		sort(rem+1,rem+N+1);
		cou=unique(rem+1,rem+N+1)-rem-1;
		for(int i=1;i<=cou;++i) hash[rem[i]]=i;
		for(int i=1;i<=N;++i) num[i]=hash[num[i]];

		for(int i=0;i<=cou;++i)
			for(int j=0;j<=cou;++j)
				dp[0][i][j]=INF;
		dp[0][0][0]=0;

		for(int i=1;i<=N;++i) {
			for(int j=0;j<=cou;++j)
				for(int k=0;k<=cou;++k)
					dp[i][j][k]=INF;

			for(int j=0;j<=cou;++j)
				for(int k=0;k<=cou;++k) {
					dp[i][j][k]=min(dp[i-1][j][k]+1,dp[i][j][k]);
					if(j==0 || j<num[i]) dp[i][num[i]][k]=min(dp[i][num[i]][k],dp[i-1][j][k]);
					if(k==0 || k>num[i]) dp[i][j][num[i]]=min(dp[i][j][num[i]],dp[i-1][j][k]);
				}
		}
		int ans=INF;
		for(int i=0;i<=cou;++i)
			for(int j=0;j<=cou;++j)
				ans=min(ans,dp[N][i][j]);
		printf("%d\n",ans);
	}
	
	return 0;
}
