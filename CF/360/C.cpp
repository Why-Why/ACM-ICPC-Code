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
// Created Time  : 2016年07月14日 星期四 20时04分30秒
// File Name     : C.cpp

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
}E[MaxN<<1];

int N,M;
int head[MaxN],Ecou;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int ans1[MaxN],ans2[MaxN],cou1,cou2;
int rem[MaxN];

bool dfs(int u,int pre,int t) {
	if(t==0) ans1[++cou1]=u;
	else ans2[++cou2]=u;
	rem[u]=t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			if(rem[E[i].to]==t) return 0;
			if(rem[E[i].to]==-1) {
				if(dfs(E[i].to,u,!t)==0) return 0;
			}
		}

	return 1;
}

bool getans() {
	for(int i=1;i<=N;++i)
		if(rem[i]==-1) {
			if(dfs(i,-1,0)==0) return 0;
		}
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&N,&M);
	init();
	memset(rem,-1,sizeof(rem));
	while(M--) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	if(getans()) {
		printf("%d\n",cou1);
		for(int i=1;i<=cou1;++i) printf("%d ",ans1[i]);
		puts("");
		printf("%d\n",cou2);
		for(int i=1;i<=cou2;++i) printf("%d ",ans2[i]);
		puts("");
	}
	else puts("-1");

	return 0;
}
