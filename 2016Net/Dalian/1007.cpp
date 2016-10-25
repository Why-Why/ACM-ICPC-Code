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
// Created Time  : 2016年09月10日 星期六 14时19分30秒
// File Name     : 107.cpp

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

int n;
long long a[1000000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	a[0]=0;
	for(n=1;a[n-1]<=(1LL<<31);++n) a[n]=a[n-1]+n/2;

	long long M,N;
	while(~scanf("%I64d %I64d",&M,&N)) {
	//while(cin>>M>>N) {
		if(M<n && N>=a[M]) puts("T");
		else puts("F");
		//if(N>=M || (M<=3 && N>=(M-1))) puts("T");
		//else puts("F");
	}

	return 0;
}
