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
// Created Time  : 2016年12月03日 星期六 14时26分31秒
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

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long N,num[10];

	cin>>N>>num[1]>>num[2]>>num[3];
	long long dp[10];
	for(int i=0;i<10;++i) dp[i]=1000000000000000LL;

	for(int i=0;i<=4;++i)
		for(int j=0;j<=4;++j)
			for(int k=0;k<=4;++k) {
				long long t=(i+j*2+k*3)%4;
				dp[t]=min(dp[t],num[1]*i+num[2]*j+num[3]*k);
			}

	dp[4]=0;
	cout<<(dp[4-N%4])<<endl;

	return 0;
}
