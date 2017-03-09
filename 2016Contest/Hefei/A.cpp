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
// Created Time  : 2016年11月16日 星期三 22时02分52秒
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
#include <bitset>

using namespace std;

bitset <2021> map1[2021],map2[2021];
int N;
char s[2021];

inline bool judge() {
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(i!=j) {
				if(map1[i][j] && ((map1[i] & map1[j])!=map1[j])) return 0;
				if(map2[i][j] && ((map2[i] & map2[j])!=map2[j])) return 0;
			}

	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) {
			map1[i].reset();
			map2[i].reset();
			scanf("%s",s+1);

			for(int j=1;j<=N;++j)
				if(s[j]=='P') map1[i].set(j);
				else if(s[j]=='Q') map2[i].set(j);
		}

		puts(judge() ? "T" : "N");
	}

	return 0;
}
