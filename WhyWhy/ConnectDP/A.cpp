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
// Created Time  : 2015年12月04日 星期五 16时27分18秒
// File Name     : A.cpp

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

const int MaxN=13;
typedef long long LL;

int N,M;
int map1[MaxN][MaxN];
LL dp[MaxN][MaxN][1<<MaxN];

void getans() {
	memset(dp[0],0,sizeof(dp[0]));
	dp[0][M][0]=1;

	int x,y;

	for(int i=1;i<=N;++i) {
		for(int k=0;k<(1<<M);++k) dp[i][0][k<<1]=dp[i-1][M][k];
		for(int j=1;j<=M;++j) {
			x=(1<<j); y=(1<<(j-1));

			for(int k=0;k<(1<<(M+1));++k)
				if(map1[i][j]) {
					if((k&x) && (k&y)) dp[i][j][k]=dp[i][j-1][k-x-y];
					else if(!(k&x) && !(k&y)) dp[i][j][k]=dp[i][j-1][k+x+y];
					else dp[i][j][k]=dp[i][j-1][k]+dp[i][j-1][k^x^y];
				}
				else {
					if(!(k&x) && !(k&y)) dp[i][j][k]=dp[i][j-1][k];
					else dp[i][j][k]=0;
				}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				scanf("%d",&map1[i][j]);
		printf("Case %d: ",cas++);
		getans();
		printf("There are %I64d ways to eat the trees.\n",dp[N][M][0]);
	}
	
	return 0;
}
