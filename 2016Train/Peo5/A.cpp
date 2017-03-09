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
// Created Time  : 2016年03月22日 星期二 16时40分03秒
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

const int MaxN=100005;

int N,M;
long long dp[MaxN][4];
char s[MaxN];

long long num[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	scanf("%s",s+1);

	for(int i=3;i<=N;++i)
		if(s[i]==s[i-2]) num[i]=num[i-1]+1;
		else num[i]=0;

	dp[0][1]=1;

	for(int i=1;i<=N;++i) {
		for(int j=0;j<M;++j) {
			if(j+'a'==s[i-1]) dp[i][0]+=dp[i-1][0];
			else dp[i][0]+=1;

			if(j+'a'==s[i+1]) dp[i][1]+=dp[i-1][1];
			else if(j+'a'==s[i]) dp[i][1]+=1;

			if(j+'a'==s[i]) dp[i][3]+=dp[i-1][3];
			else {
				if(j+'a'==s[i-1]) dp[i][3]+=dp[i-1][0]-num[i]-2;
				dp[i][3]+=dp[i-1][1];
				//else dp[i][3]+=1;
			}
		}
	}

	cout<<dp[N][3]<<endl;
	
	return 0;
}
