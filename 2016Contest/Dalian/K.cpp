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
// Created Time  : 2016年11月12日 星期六 11时58分32秒
// File Name     : K.cpp

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

const int MaxN=6000005;
const int mod=100000073;

int dp[MaxN];
long long rem[MaxN];

//int dp1[MaxN],rem1[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;

	dp[0]=0;
	rem[0]=1;

/*
	dp1[0]=0;
	rem1[0]=1;
	for(int i=1;i<1000;++i) {
		dp1[i]=0x3f3f3f3f;
		for(int j=1;j<=i;++j) {
			t=max(j-1,dp1[i-j])+1;

			if(t<dp1[i]) dp1[i]=t,rem1[i]=rem1[i-j];
			else if(t==dp1[i]) (rem1[i]+=rem1[i-j])%=mod;
		}
	}
*/

	int cou;

	t=1;
	cou=0;
	for(int i=1;i<MaxN;++i) {
		dp[i]=t;
		++cou;
		if(cou>=t) {
			rem[i]=1;
			for(int j=1;j<t;++j)
				rem[i-j]=(rem[i-j+1]+rem[i-t-j])%mod;

			++t;
			cou=0;
		}
	}

	int a,b;
	while(~scanf("%d %d",&a,&b))
		printf("%d %d\n",dp[b-a+1],(int)rem[b-a+1]);

	return 0;
}
