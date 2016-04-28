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
// Created Time  : 2016年04月11日 星期一 22时32分45秒
// File Name     : 1086.cpp

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

const int MaxN=1005;

struct Edge {
	int to,next;
}E[MaxN<<1];

int head[MaxN],Ecou;
int N,B;

int bcou,belong[MaxN],mid[MaxN];

int stack[MaxN],top;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void add(int L,int id) {
	++bcou;
	mid[bcou]=id;

	while(top>L) belong[stack[--top]]=bcou;
}

void dfs(int u,int pre) {
	stack[top++]=u;
	int r=top;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u);
			if(top-r>=B) add(r,u);
		}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&N,&B);
	init();
	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	dfs(1,-1);
	while(top) belong[stack[--top]]=bcou;

	printf("%d\n",bcou);
	for(int i=1;i<=N;++i) printf("%d ",belong[i]);
	puts("");
	for(int i=1;i<=bcou;++i) printf("%d ",mid[i]);
	puts("");
	
	return 0;
}
