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
// Created Time  : 2016年08月18日 星期四 14时38分25秒
// File Name     : 1011.cpp

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

int num[1005]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6,9,9,11,10,10,9,11,11,10,6,9,9,11,10,10,9,11,11,10,5,8,8,10,9,9,8,10,10,9,5,8,8,10,9,9,8,10,10,9,5,8,8,10,9,9,8,10,10,9,7,10,10,12,11,11,10,12,12,11,6,9,9,11,10,10,9,11,11,10,6,9,9,11,10,10,9,11,11,10};

void init() {
	for(int i=100;i<1000;++i)
		if(i%100) {
			num[i]=num[i/100]+10+num[i%100];
		}
		else {
			num[i]=num[i/100]+7;
		}
	num[1000]=11;

	for(int i=2;i<=1000;++i) num[i]+=num[i-1];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,x;
	init();

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&x);
		printf("%d\n",num[x]);
	}

	return 0;
}
