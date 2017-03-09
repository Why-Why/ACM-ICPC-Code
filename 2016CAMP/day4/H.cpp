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
// Created Time  : 2017年02月16日 星期四 14时06分32秒
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

const int MaxN=200005;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N,s,m;

void init(int N) {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1;
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int sum[MaxN],dis[MaxN],fa[MaxN],maxn[MaxN];

bool dfs(int u,int pre) {
	bool ok=0,t;

	sum[u]=1;
	fa[u]=pre;
	maxn[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dis[E[i].to]=dis[u]+1;

			t=dfs(E[i].to,u);
			if(t) ok=1;

			if(!t) maxn[u]=max(maxn[u],maxn[E[i].to]+1);
			sum[u]+=sum[E[i].to];
		}

	if(u==m) ok=1;

	return ok;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&N,&s,&m);
		init(N);

		for(int i=1;i<N;++i) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}
		dis[s]=1;
		dfs(s,-1);

		int ans=0x3f3f3f3f;
		int anum=-dis[m]+1;
		int rem=maxn[m];

		for(int u=m;u!=-1;u=fa[u]) {
			rem=max(rem,maxn[u]+dis[m]-dis[u]);

			ans=min(ans,rem+anum+2*N-2*sum[u]);
			anum+=2;
		}

		printf("%d\n",ans);
	}

	return 0;
}
