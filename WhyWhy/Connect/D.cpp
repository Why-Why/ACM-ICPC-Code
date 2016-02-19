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
// Created Time  : 2016年01月23日 星期六 16时11分03秒
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

const int MaxN=10005;
const int MaxM=50005;

struct Edge {
	int to,next;
	int u;
}E1[MaxM],E2[MaxM];

int E1cou,E2cou;
int head1[MaxN],head2[MaxN];
int N,M;
int Index;
int chu[MaxN];
int Belong[MaxN],bcou;
int sortRem[MaxN],sortCou;

void init() {
	E1cou=E2cou=0;
	Index=bcou=0;
	memset(Belong,0,sizeof(Belong));
	memset(chu,0,sizeof(chu));
	memset(head1,-1,sizeof(head1));
	memset(head2,-1,sizeof(head2));
}

void addEdge(int u,int v) {
	E1[E1cou].to=v;
	E1[E1cou].next=head1[u];
	E1[E1cou].u=u;
	head1[u]=E1cou++;

	E2[E2cou].to=u;
	E2[E2cou].next=head2[v];
	head2[v]=E2cou++;
}

bool vis[MaxN];

void dfs1(int u) {
	vis[u]=1;
	for(int i=head1[u];i!=-1;i=E1[i].next)
		if(!vis[E1[i].to])
			dfs1(E1[i].to);
	sortRem[++sortCou]=u;
}

void dfs2(int u,int b) {
	Belong[u]=b;
	for(int i=head2[u];i!=-1;i=E2[i].next)
		if(!Belong[E2[i].to])
			dfs2(E2[i].to,b);
}

void Kosaraju() {
	sortCou=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=N;++i) if(vis[i]==0) dfs1(i);
	for(int i=N;i>=1;--i) if(Belong[sortRem[i]]==0) dfs2(sortRem[i],++bcou);
}

int getans() {
	Kosaraju();
	for(int i=0;i<E1cou;++i)
		if(Belong[E1[i].u]!=Belong[E1[i].to])
			++chu[Belong[E1[i].u]];
	int ret=-1;
	for(int i=1;i<=bcou;++i)
		if(chu[i]==0)
			if(ret!=-1) return 0;
			else ret=i;
	int cou=0;
	for(int i=1;i<=N;++i) if(Belong[i]==ret) ++cou;
	return cou;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&M)) {
		init();
		while(M--) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
		}
		printf("%d\n",getans());
	}
	
	return 0;
}
