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
// Created Time  : 2016年01月28日 星期四 12时01分20秒
// File Name     : I.cpp

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

const int MaxN=30005;
const int MaxM=150005;

struct Edge {
	int u,to,next;
}E[MaxM],E1[MaxM];

int N;
int head[MaxN],head1[MaxN],Ecou,E1cou;
int Index,sortrem[MaxN],belong[MaxN],bcou;
bool vis[MaxN];
int val[MaxN];
int rem[MaxN];

void init() {
	Ecou=E1cou=Index=bcou=0;
	for(int i=1;i<=N;++i) head[i]=head1[i]=-1,belong[i]=vis[i]=0;
}

void addEdge(int u,int v) {
	++u; ++v;
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
		if(!vis[E[i].to])
			dfs1(E[i].to);
	sortrem[++Index]=u;
}

int dfs2(int u) {
	belong[u]=bcou;
	int ret=max(0,val[u]);
	for(int i=head1[u];i!=-1;i=E1[i].next)
		if(!belong[E1[i].to]) ret+=dfs2(E1[i].to);
	return ret;
}

void getSCC() {
	for(int i=1;i<=N;++i) if(!vis[i]) dfs1(i);
	for(int i=N;i>=1;--i) if(!belong[sortrem[i]]) rem[++bcou]=dfs2(sortrem[i]);
}

namespace AAA {
	Edge E[MaxM];
	int head[MaxN],Ecou;
	int du[MaxN];
	int r[MaxN];

	void init() {
		Ecou=0;
		memset(head,-1,sizeof(head));
		memset(du,0,sizeof(du));
		memset(r,-1,sizeof(r));
	}

	void addEdge(int u,int v) {
		++du[v];
		E[Ecou].to=v;
		E[Ecou].next=head[u];
		head[u]=Ecou++;
	}

	int dfs(int u) {
		if(r[u]!=-1) return r[u];
		r[u]=0;
		for(int i=head[u];i!=-1;i=E[i].next)
			r[u]=max(r[u],dfs(E[i].to));
		r[u]+=rem[u];
		return r[u];
	}

	int getans() {
		int ret=-1;
		for(int i=1;i<=bcou;++i)
			if(!du[i])
				ret=max(ret,dfs(i));
		return ret;
	}
};

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b;
	while(~scanf("%d %d",&N,&M)) {
		init();
		for(int i=1;i<=N;++i) scanf("%d",val+i);
		for(int i=1;i<=M;++i) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
		}
		getSCC();
		AAA::init();
		for(int i=0;i<Ecou;++i)
			if(belong[E[i].u]!=belong[E[i].to])
				AAA::addEdge(belong[E[i].u],belong[E[i].to]);
		printf("%d\n",AAA::getans());
	}
	
	return 0;
}
