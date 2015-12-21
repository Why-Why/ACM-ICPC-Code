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
// Created Time  : 2015年11月28日 星期六 10时09分24秒
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

using namespace std;

const int MaxN=1000005;

char s[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s",s);
	int cou1=0,cou2=0;
	int sum=0,len=0;

	for(int i=0;s[i];++i,++len)
		if(s[i]=='1') ++sum;

	for(int i=0;i<=len;++i) {
		if(cou1==sum-cou2) { printf("%d\n",i); return 0; }
		if(s[i]=='0') ++cou1;
		else ++cou2;
	}

	printf("-1\n");
	
	return 0;
}
