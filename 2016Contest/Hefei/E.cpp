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
// Created Time  : 2016年11月16日 星期三 22时16分40秒
// File Name     : E.cpp

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

const int mod=100000007;

long long dp[10005][3][3];
char s[10005];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,N,t;
	scanf("%d",&T);

	while(T--) {
		scanf("%s",s+1);
		N=strlen(s+1);
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=dp[0][0][1]=dp[0][0][2]=1;

		for(int i=1;i<=N;++i) {
			t=s[i]-'0';

			for(int a=0;a<3;++a)
				for(int b=0;b<3;++b)
					if(t-a-b>=0 && t-a-b<3)
						(dp[i][a][b]+=((a==1 ? 2 : 1)*dp[i-1][t-a-b][a]))%=mod;
		}

		long long ans=0;
		for(int i=0;i<3;++i) (ans+=dp[N][i][0])%=mod;
		printf("%I64d\n",ans);
	}

	return 0;
}
