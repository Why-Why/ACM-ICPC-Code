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
// Created Time  : 2016年07月21日 星期四 19时36分05秒
// File Name     : 1012_1.cpp

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
#include <bitset>

using namespace std;

const int MaxN=100005;

char s1[MaxN],s2[5005];
int N,M;

bitset <MaxN> zi[26],dp[2][3],ttt;

void getans() {
	int flag=0;

	dp[flag][0].reset();
	dp[flag][2].reset();

	for(int i=0;i<N;++i) dp[flag][1].set(i);

	for(int j=0;j<M;++j) {
		if(j) dp[flag^1][0]=(dp[flag][2]<<1) & zi[s2[j-1]-'a'];
		else dp[flag^1][0].reset();

		if(j) dp[flag^1][1]=((dp[flag][0]<<1) | (dp[flag][1]<<1)) & zi[s2[j]-'a'];
		else dp[flag^1][1]=((dp[flag][0]<<1) | ((dp[flag][1]<<1) | ttt)) & zi[s2[j]-'a'];

		if(j<M-1) {
			if(j) dp[flag^1][2]=((dp[flag][0]<<1) | (dp[flag][1]<<1))  & zi[s2[j+1]-'a'];
			else dp[flag^1][2]=((dp[flag][0]<<1) | ((dp[flag][1]<<1) | ttt))  & zi[s2[j+1]-'a'];
		}
		else dp[flag^1][2].reset();

		flag^=1;
	}

	for(int i=M-1;i<N;++i)
		if(dp[flag][0][i] | dp[flag][1][i]) putchar('1');
		else putchar('0');
	for(int i=0;i<M-1;++i) putchar('0');
	puts("");
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ttt.reset();
	ttt.set(0);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		scanf("%s %s",s1,s2);

		for(int i=0;i<26;++i) zi[i].reset();
		for(int i=0;i<N;++i) zi[s1[i]-'a'].set(i);

		getans();
	}

	return 0;
}
