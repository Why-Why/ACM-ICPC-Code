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
// Created Time  : 2016年05月06日 星期五 20时28分06秒
// File Name     : G.cpp

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

const int INF=1000000007;

priority_queue <int,vector<int>,greater<int> > que;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,a,b;
	int maxn=-INF;
	scanf("%d",&N);
	while(N--) {
		scanf("%d",&a);
		if(a==1) { scanf("%d",&b); que.push(b); maxn=max(maxn,b); }
		else if(a==2) { if(!que.empty()) que.pop(); if(que.empty()) maxn=-INF; }
		else printf("%d\n",maxn==-INF ? 0 : maxn);
	}
	
	return 0;
}
