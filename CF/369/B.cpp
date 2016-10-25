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
// Created Time  : 2016年09月03日 星期六 15时33分50秒
// File Name     : B.cpp

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

int N;
long long map1[555][555];
int r,c;
long long tsum;

inline bool judge() {
	long long tt;

	for(int i=1;i<=N;++i) {
		tt=0;
		for(int j=1;j<=N;++j) tt+=map1[i][j];
		if(tt!=tsum) return 0;
	}

	for(int i=1;i<=N;++i) {
		tt=0;
		for(int j=1;j<=N;++j) tt+=map1[j][i];
		if(tt!=tsum) return 0;
	}

	tt=0;
	for(int i=1;i<=N;++i) tt+=map1[i][i];
	if(tt!=tsum) return 0;

	tt=0;
	for(int i=1;i<=N;++i) tt+=map1[i][N+1-i];
	if(tt!=tsum) return 0;

	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) {
			cin>>map1[i][j];
			if(map1[i][j]==0) r=i,c=j;
		}

	if(N==1) {
		puts("1");
		return 0;
	}

	long long sum=0;
	for(int i=1;i<=N;++i)
		if(i!=r) {
			for(int j=1;j<=N;++j) sum+=map1[i][j];
			break;
		}
	tsum=sum;

	for(int i=1;i<=N;++i) sum-=map1[r][i];
	if(sum<=0) {
		puts("-1");
		return 0;
	}

	map1[r][c]=sum;
	if(judge()) cout<<sum<<endl;
	else cout<<-1<<endl;

	return 0;
}
