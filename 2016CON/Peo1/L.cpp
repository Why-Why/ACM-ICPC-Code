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
// Created Time  : 2016年02月20日 星期六 15时35分47秒
// File Name     : L.cpp

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

const int MaxN=105;

int num[MaxN];
double dp[100005]={0.0};
int N,M;
double di;
int len;

void getans() {
	di=1.0/(M-1.0);
	for(int i=1;i<=M;++i)
		if(num[1]!=i) dp[i]=di;

	double sum;

	for(int i=2;i<=N;++i) {
		sum=0;
		for(int j=max(1,len-M);j<len;++j) sum+=dp[j];
		for(int j=len;j>=1;--j) {
			dp[j]=sum-(j>num[i] ? dp[j-num[i]] : 0);
			dp[j]*=di;
			sum-=dp[j-1];
			if(j-M-1>0) sum+=dp[j-M-1];
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	len=0;
	for(int i=1;i<=N;++i) {
		scanf("%d",num+i);
		len+=num[i];
	}

	if(M==1) {
		printf("%.16f\n",1.0);
		return 0;
	}

	getans();
	double ans=0;
	for(int i=0;i<len;++i) ans+=dp[i];
	printf("%.16f\n",1+ans*(M-1.0));
	
	return 0;
}
