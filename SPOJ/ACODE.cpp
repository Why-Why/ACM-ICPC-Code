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
// Created Time  : 2016年04月01日 星期五 15时41分27秒
// File Name     : ACODE.cpp

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

const int MaxN=5005;

char s[MaxN];
long long dp[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s+1) && s[1]!='0') {
		dp[0]=1;
		int len=0;
		for(int i=1;s[i];++i,++len) {
			dp[i]=0;
			if(s[i]!='0') dp[i]+=dp[i-1];
			if(i>1 && s[i-1]!='0' && (s[i-1]-'0')*10+s[i]-'0'<=26) dp[i]+=dp[i-2];
		}
		printf("%lld\n",dp[len]);
	}
	
	return 0;
}
