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
// Created Time  : 2016年09月23日 星期五 11时18分24秒
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

const int MaxN=1003;

int N,M;
int map1[MaxN][MaxN];
int dp[MaxN][MaxN][11][11];

int logN[MaxN];

void init() {
	logN[0]=-1;
	for(int i=1;i<MaxN;++i) logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
	for(int ii=0;ii<=logN[N];++ii)
		for(int jj=0;jj<=logN[M];++jj)
			if(ii+jj)
				for(int i=1;i+(1<<ii)-1<=N;++i)
					for(int j=1;j+(1<<jj)-1<=M;++j)
						if(ii) dp[i][j][ii][jj]=max(dp[i][j][ii-1][jj],dp[i+(1<<(ii-1))][j][ii-1][jj]);
						else dp[i][j][ii][jj]=max(dp[i][j][ii][jj-1],dp[i][j+(1<<(jj-1))][ii][jj-1]);
}

inline int RMQ(int x1,int y1,int x2,int y2) {
	if(x1>x2 || y1>y2) return 0;

	int k1=logN[x2-x1+1],k2=logN[y2-y1+1];
	x2=x2-(1<<k1)+1;
	y2=y2-(1<<k2)+1;

	return max(max(dp[x1][y1][k1][k2],dp[x1][y2][k1][k2]),max(dp[x2][y1][k1][k2],dp[x2][y2][k1][k2]));
}

inline int sum(int x1,int y1,int x2,int y2) {
	return map1[x2][y2]-map1[x1-1][y2]-map1[x2][y1-1]+map1[x1-1][y1-1];
}

inline int getsq(int x,int y) {
	int L=1,R=N,Mid;

	while(R>L) {
		Mid=(L+R+1)>>1;
		if(x-Mid+1>=1 && y-Mid+1>=1 && sum(x-Mid+1,y-Mid+1,x,y)==Mid*Mid) L=Mid;
		else R=Mid-1;
	}

	return L;
}

inline int getans(int x1,int y1,int x2,int y2) {
	if(sum(x1,y1,x2,y2)==0) return 0;		 		// !!!

	int L=1,R=min(x2-x1+1,y2-y1+1),Mid;				// !!!

	while(R>L) {
		Mid=(L+R+1)>>1;
		if(RMQ(x1+Mid-1,y1+Mid-1,x2,y2)>=Mid) L=Mid;
		else R=Mid-1;
	}

	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j) {
			scanf("%d",&map1[i][j]);
			map1[i][j]+=map1[i][j-1]+map1[i-1][j]-map1[i-1][j-1];
		}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			dp[i][j][0][0]=getsq(i,j);
	init();

	int Q,a,b,c,d;
	scanf("%d",&Q);

	while(Q--) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("%d\n",getans(a,b,c,d));
	}

	return 0;
}
