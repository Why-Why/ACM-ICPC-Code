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
// Created Time  : 2016年09月12日 星期一 23时45分12秒
// File Name     : 1004.cpp

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
const int mod=1000000007;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N,M;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool vis[MaxN];
int bridge[MaxN<<1],bcou,remb[MaxN<<1];

//////////////////////////////////

void dfsC(int u,int pre) {
	vis[u]=1;
	for(int i=head[u];i!=-1;i=E[i],next)
		if(E[i].to!=pre) {
			if(vis[E[i].to]) {

			}
		}
}

void getCut() {
	memset(vis,0,sizeof(vis));
	dfsC(1);
}

///////////////////////////////////

long long ansa[MaxN],ansr[MaxN];

void dfs(int u) {
	vis[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {

		}

	vis[u]=0;
}

long long getans() {
	dfs(1);
	return ansa[1];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&M)) {
		init();
		for(int i=1;i<=M;++i) {
			scanf("%d %d",&a,&b);

			if(a==b) continue;
			addEdge(a,b);
			addEdge(b,a);
		}
		getCut();
		printf("%d\n",(int)getans());
	}

	return 0;
}
