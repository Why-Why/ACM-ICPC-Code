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
// Created Time  : 2016年03月19日 星期六 01时15分10秒
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

const int MaxN=100005;

int N,K;
char s[MaxN];
int sum[MaxN];

bool judge(int M) {
	int a,b;
	for(int i=1;i<=N;++i)
		if(s[i]=='0') {
			a=sum[i]-sum[max(i-M-1,0)]-1;
			b=sum[min(i+M,N)]-sum[i];
			if(a+b>=K) return 1;
		}
	return 0;
}

int getans() {
	int L=0,R=N,M;

	while(R>L) {
		M=(L+R)>>1;
		if(judge(M)) R=M;
		else L=M+1;
	}

	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&K);
	scanf("%s",s+1);
	sum[0]=0;
	for(int i=1;i<=N;++i) sum[i]=sum[i-1]+('1'-s[i]);

	//judge(1);
	printf("%d\n",getans());
	
	return 0;
}
