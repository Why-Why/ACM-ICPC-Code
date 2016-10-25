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
// Created Time  : 2016年07月19日 星期二 15时06分15秒
// File Name     : 1002.cpp

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

int sg[(1<<20)+10];

int vis[100],flag=1;
int next1[100];

inline int getSG(int s) {
	++flag;
	if(s&1) next1[0]=-1;
	else next1[0]=0;

	for(int i=1;i<20;++i)
		if(s&(1<<i)) {
			next1[i]=next1[i-1];
			if(next1[i]!=-1) vis[sg[(s^(1<<i))|(1<<(next1[i]))]]=flag;
		}
		else next1[i]=i;

	for(int i=0;i<100;++i)
		if(vis[i]!=flag) return i;
	cerr<<"NO\n";
}

void init() {
	sg[0]=0;

	for(int i=1;i<(1<<20);++i)
		sg[i]=getSG(i);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();
	int T,N,M,a,b,ans;

	scanf("%d",&T);
	while(T--) {
		ans=0;
		scanf("%d",&N);
		while(N--) {
			scanf("%d",&M);
			a=0;
			while(M--) {
				scanf("%d",&b);
				a|=(1<<(20-b));
			}
			ans^=sg[a];
		}
		if(ans) puts("YES");
		else puts("NO");
	}

	return 0;
}
