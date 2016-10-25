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
// Created Time  : 2016年07月26日 星期二 22时43分59秒
// File Name     : 1001.cpp

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

char s[111];
long long num[]={3,15,255,65535,65536LL*65536LL-1};

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s)) {
		if(strlen(s)>15) {
			puts("TAT");
			continue;
		}

		long long t;
		sscanf(s,"%I64d",&t);

		if(t==0) {
			puts("TAT");
			continue;
		}

		if(t==1) {
			puts("0");
			continue;
		}

		if(t>num[4]) {
			puts("TAT");
			continue;
		}

		for(int i=0;i<5;++i)
			if(num[i]>=t) {
				printf("%d\n",i+1);
				break;
			}
	}

	return 0;
}
