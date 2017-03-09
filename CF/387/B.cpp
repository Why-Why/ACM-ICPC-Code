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
// Created Time  : 2017年01月16日 星期一 21时41分27秒
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
char s[300];

const char flag[]="ACGT";

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %s",&N,s);
	if(N%4) {
		puts("===");
		return 0;
	}

	int cou[256]={};
	int f=N/4;

	for(int i=0;s[i];++i) ++cou[s[i]];
	for(int i=0;i<4;++i)
		if(cou[flag[i]]>f) {
			puts("===");
			return 0;
		}
		else {
			int t=f-cou[flag[i]];
			for(int j=0;s[j] && t;++j)
				if(s[j]=='?') {
					s[j]=flag[i];
					--t;
				}
		}

	puts(s);

	return 0;
}
