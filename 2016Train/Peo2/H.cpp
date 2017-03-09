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
// Created Time  : 2016年02月27日 星期六 15时32分50秒
// File Name     : H.cpp

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

int N,M,K;
int t[MaxN];
int rem[MaxN];
int remL;
const int LOGN=20;

bool judge(int Mid) {
	long long MM=M;
	int cou=0;
	for(int i=1;i<=N;++i) rem[i]=(Mid-t[i])/K;
	sort(rem+1,rem+N+1);
	for(int i=1;i<=N;++i) {
		if(rem[i]==cou) --MM;
		else {
			if(rem[i]-cou>=LOGN) return 1;
			MM*=(1<<(rem[i]-cou));
			cou=rem[i];
			--MM;
		}
		if(MM>=N) return 1;
		if(MM<0) return 0;
	}
	if(MM<0) return 0;
	return 1;
}

int getans() {
	int L=remL,R=2000000,Mid;

	while(R>L) {
		Mid=(L+R)>>1;
		if(judge(Mid)) R=Mid;
		else L=Mid+1;
	}
	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		remL=1;
		scanf("%d %d %d",&N,&M,&K);
		for(int i=1;i<=N;++i) {
			scanf("%d",t+i);
			remL=max(remL,t[i]);
		}

		printf("%d\n",getans());
	}
	
	return 0;
}
