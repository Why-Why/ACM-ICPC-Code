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
// Created Time  : 2016年09月04日 星期日 17时08分21秒
// File Name     : 2_B.cpp

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

const int MaxN=100005;

int N;
int x[MaxN],a;

int getans(int x[],int N) {
	if(x[1]>=a) return x[N]-a;
	if(x[N]<=a) return a-x[1];

	return x[N]-x[1]+min(x[N]-a,a-x[1]);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&a);
	for(int i=1;i<=N;++i) scanf("%d",x+i);
	if(N==1) {
		puts("0");
		return 0;
	}
	sort(x+1,x+N+1);
	printf("%d\n",min(getans(x,N-1),getans(x+1,N-1)));

	return 0;
}
