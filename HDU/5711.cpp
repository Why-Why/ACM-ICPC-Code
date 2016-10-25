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
// Created Time  : 2016年07月18日 星期一 20时09分01秒
// File Name     : 5711.cpp

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

const int MaxN=18;

struct Edge {
	int to,next;
	int w;
};

Edge E[MaxN*MaxN];
int head[MaxN],Ecou;
int N,K,L;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int w) {
	E[Ecou].to=v;
	E[Ecou].w=w;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int getans() {
	for(int i=0;i<(1<<(n-1));++i) {
		for(int j=1;j<n;++j)
			if(i&(1<<(j-1))) {
				if((i^(1<<(j-1)))==0) dp[i][j]=map1[0][
			}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);
	while(T--) {
		int M,a,b,c;

		scanf("%d %d %d %d",&N,&M,&K,&L);
		init();
		while(M--) {
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		printf("Case %d: %d\n",cas++,getans());
	}

	return 0;
}
