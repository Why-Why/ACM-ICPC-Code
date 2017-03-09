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
// Created Time  : 2016年01月25日 星期一 10时55分12秒
// File Name     : H.cpp

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
const int MaxM=6005;

struct Edge {
	int to,next;
	int u;
}E[MaxM],E1[MaxM];

int head[MaxN],head1[MaxN],Ecou,E1cou;
int N;
int belong[MaxN],bcou,sortrem[MaxN],sortcou;
bool vis[MaxN];

void init() {
	Ecou=E1cou=bcou=sortcou=0;
	for(int i=1;i<=N;++i) head[i]=head1[i]=-1,belong[i]=vis[i]=0;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].u=u;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E1[E1cou].to=u;
	E1[E1cou].next=head1[v];
	head1[v]=E1cou++;
}

void dfs1(int u) {
	vis[u]=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) dfs1(E[i].to);
	sortrem[++sortcou]=u;
}

void dfs2(int u) {
	belong[u]=bcou;
	for(int i=head1[u];i!=-1;i=E1[i].next)
		if(!belong[E1[i].to]) dfs2(E1[i].to);
}

void getSCC() {
	for(int i=1;i<=N;++i) if(!vis[i]) dfs1(i);
	for(int i=N;i>=1;--i) if(!belong[sortrem[i]]) { ++bcou; dfs2(sortrem[i]); }
}

int ru[MaxN],chu[MaxN];

inline bool judge() {
	if(bcou==1) return 1;
	bool rem1=0,rem2=0;

	for(int i=1;i<=bcou;++i)
		if(ru[i]==0 && chu[i]==1) {
			if(rem1) return 0;
			rem1=1;
		}
		else if(ru[i]==1 && chu[i]==0) {
			if(rem2) return 0;
			rem2=1;
		}
		else if(ru[i]==1 && chu[i]==1) {}
		else return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a,b,M;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		init();
		while(M--) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
		}
		getSCC();

		for(int i=1;i<=bcou;++i) ru[i]=chu[i]=0;
		for(int i=0;i<Ecou;++i)
			if(belong[E[i].u] != belong[E[i].to]) ++chu[belong[E[i].u]],++ru[belong[E[i].to]];
		if(judge()) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
