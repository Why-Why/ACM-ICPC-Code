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
// Created Time  : 2015年12月05日 星期六 19时42分06秒
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

const int MaxN=500005;

struct Edge {
	int to,next;
}E[MaxN<<1];

int head[MaxN],Ecou;

int T;
int N,K,A,B;
int ans;

inline void init() {
	Ecou=0;
	for(int i=0;i<=N;++i) head[i]=-1;
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int dp[MaxN][13];
int fa[MaxN];

void dfs(int u,int pre) {
	fa[u]=pre;
	for(int i=0;i<=K;++i) dp[u][i]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u);
			for(int j=1;j<=K;++j) dp[u][j]+=dp[E[i].to][j-1];
		}
}

void dfs1(int u) {
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=fa[u])
			dfs1(E[i].to);

	int tans=dp[u][K];
	int t=u;
	for(int i=1;i<=K && fa[t]!=-1;++i) {
		if(i==K) ++tans;
		else tans+=dp[fa[t]][K-i]-dp[t][K-i-1];
		t=fa[t];
	}
	ans^=tans;
}

void getans() {
	dfs(1,-1);
	dfs1(1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&T);
	int t;

	while(T--) {
		scanf("%d %d %d %d",&N,&K,&A,&B);
		ans=0;
		init();
		fa[1]=-1;
		for(long long i=2;i<=N;++i) {
			t=(A*i+B)%(i-1)+1;
			addEdge(t,i);
			addEdge(i,t);
		}

		getans();
		printf("%d\n",ans);
	}
	
	return 0;
}
