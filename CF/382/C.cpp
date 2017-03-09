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
// Created Time  : 2016年12月01日 星期四 16时29分23秒
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

long long rem[1000000];
int rcou;
long long N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>N;

	if(N==2) {
		puts("1");
		return 0;
	}

	if(N==3) {
		puts("2");
		return 0;
	}

	rem[1]=2;
	rem[2]=3;

	for(rcou=3;;++rcou) {
		rem[rcou]=rem[rcou-1]+rem[rcou-2];
		if(rem[rcou]>N || rem[rcou]<=rem[rcou-1]) {
			printf("%d\n",rcou-1);
			return 0;
		}
	}

	return 0;
}
