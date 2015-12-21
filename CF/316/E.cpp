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
// Created Time  : 2015年09月12日 星期六 10时27分02秒
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

const int MaxN=505;
const int mod=1000000000+7;

int N,M;
char map1[MaxN][MaxN];
long long dp[MaxN][MaxN][2];
long long **pre,**now;
int len;

void getdp()
{

}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);

	for(int i=1;i<=N;++i)
		scanf("%s",map1[i]+1);
	len=(N+M)>>1;

	long long ans=0;
	getdp();

	int x,y,x1,y1;1
	if(N>=M) { x=1; y=len; x1=1; y1=m+n-x1+1-len; }
	else { y=N; x=len+1-N; y1=N; x1=m+n-y1+1-len; }
	for(int i=1;x<=M && y>=1;++i,++x,--y)
		for(int j=1;x1<=M && y1>=1;++x1,--y1)
			if(abs(x-x1)+abs(y-y1)<=1 && map1[y][x]==map1[y1][x1])
				(ans+=now[i][j])%=mod;

	cout<<ans<<endl;
	
	return 0;
}
