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
// Created Time  : 2016年07月15日 星期五 19时02分07秒
// File Name     : D.cpp

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

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N;

double ans[MaxN];
int sum[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs1(int u) {
	sum[u]=1;
	for(int i=head[u];i!=-1;i=E[i].next) {
		dfs1(E[i].to);
		sum[u]+=sum[E[i].to];
	}
}

void dfs2(int u) {
	for(int i=head[u];i!=-1;i=E[i].next) {
		ans[E[i].to]=ans[u]+(sum[u]-1-sum[E[i].to])/2.0+1;
		dfs2(E[i].to);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	scanf("%d",&N);
	init();
	for(int i=2;i<=N;++i) {
		scanf("%d",&a);
		addEdge(a,i);
	}

	ans[1]=1.0;
	dfs1(1);
	dfs2(1);

	for(int i=1;i<=N;++i)
		printf("%.8f ",ans[i]);
	puts("");

	return 0;
}
