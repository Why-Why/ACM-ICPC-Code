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
// Created Time  : 2017年02月14日 星期二 20时38分16秒
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

const int TTT=1594323;
const int mod=3;

int N;
int dp[55][TTT];
int *dp1,*dp2;
bool map1[55][55];

int wei[TTT][13];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=0;i<TTT;++i)
		for(int j=0,t=i;j<13;++j,t/=3)
			wei[i][j]=t%3;

	int a,b,M;
	bool vis[3];

	scanf("%d %d",&N,&M);
	while(M--) {
		scanf("%d %d",&a,&b);
		map1[a][b]=map1[b][a]=1;
	}

	dp[0][0]=1;
	dp1=dp[0];
	dp2=dp[1];

	for(int i=1;i<=N;++i) {
		for(int j=0;j<TTT;++j)
			if(dp1[j]) {
				(dp2[j*3%TTT]+=dp1[j])&=mod;

				vis[0]=vis[1]=vis[2]=0;
				for(int k=1;k<=13 && i-k>=1;++k)
					if(map1[i][i-k])
						vis[wei[j][k-1]]=1;

				if(!vis[2]) (dp2[(j*3+1)%TTT]+=dp1[j])&=mod;
				if(!vis[1]) (dp2[(j*3+2)%TTT]+=dp1[j])&=mod;
			}

		dp1=dp2;
		dp2=dp[i+1];
	}

	int ans=0;
	for(int i=0;i<TTT;++i) (ans+=dp1[i])&=mod;
	printf("%d\n",ans>>1);

	return 0;
}
