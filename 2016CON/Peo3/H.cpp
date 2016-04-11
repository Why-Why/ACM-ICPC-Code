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
// Created Time  : 2016年03月05日 星期六 14时10分49秒
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

int ans[10001];

int run(int x) {
	if(x%4) return 0;
	if((x%400)==0) return 1;
	if(x%100) return 1;
	return 0;
}

void init() {
	int base=7;
	ans[1928]=1;

	for(int i=1929;i<=9999;++i) {
		base=((base+365+run(i))-1)%7+1;
		if(base==6) ans[i]=4;
		if(base==5 || base==7) ans[i]=1;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	int T,a;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&a);
		printf("%d\n",ans[a]+5);
	}
	
	return 0;
}
