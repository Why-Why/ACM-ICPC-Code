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
// Created Time  : 2016年03月05日 星期六 12时32分42秒
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

const int MaxN=1111;

int N;
int rem[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int x;
	scanf("%d",&T);
	while(T--) {
		memset(rem,0,sizeof(rem));
		scanf("%d",&N);
		for(int i=1;i<=N;++i) {
			scanf("%d",&x);
			++rem[x];
		}

		int maxn=-1,r=-1,cou=0;
		for(int i=1;i<=1000;++i)
			maxn=max(maxn,rem[i]);
		for(int i=1;i<=1000;++i)
			if(rem[i]==maxn) {
				if(r==-1) r=i;
				else r=-2;
			}
		if(r==-2) puts("Nobody");
		else printf("%d\n",r);
	}
	
	return 0;
}
