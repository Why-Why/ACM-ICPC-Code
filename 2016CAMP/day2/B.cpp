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
// Created Time  : 2017年02月13日 星期一 14时29分00秒
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

const int MaxN=200005;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int vis[MaxN];

void init(int N) {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1,vis[i]=-1;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int N;

bool dfs(int u,int col) {
	vis[u]=col;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(vis[E[i].to]==-1) {
			if(dfs(E[i].to,!col)==0) return 0;
		}
		else if(vis[E[i].to]==col) return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b;

	while(~scanf("%d %d",&N,&M)) {
		init(N);
		while(M--) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		printf("%d\n",dfs(1,0));
	}

	return 0;
}
