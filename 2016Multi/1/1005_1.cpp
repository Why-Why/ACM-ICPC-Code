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
// Created Time  : 2016年07月25日 星期一 13时00分05秒
// File Name     : 1005_1.cpp

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

const int MaxN=11;

bool vis[MaxN];
int linker[MaxN];
int line[MaxN][MaxN];

int N,M;
int rem[MaxN][MaxN];
int use[MaxN];
int rnk[MaxN];

int ans;

inline bool find(int u) {
	for(int v=1;v<=N;++v)
		if(line[u][v] && !vis[v]) {
			vis[v]=1;
			if(linker[v]==-1 || find(linker[v])) {
				linker[v]=u;
				return 1;
			}
		}

	return 0;
}

inline int Hungary() {
	int ret=0;

	for(int u=1;u<=N;++u) {
		memset(vis,0,sizeof(vis));
		if(find(u)) ++ret;
	}

	return ret;
}

inline int getans() {
	memset(linker,-1,sizeof(linker));
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) line[i][j]=0;

	for(int j=1;j<=N;++j)
		if(!rem[rnk[N]][j] && !rem[rnk[1]][j]) line[1][j]=1;
	for(int i=2;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(!rem[rnk[i-1]][j] && !rem[rnk[i]][j]) line[i][j]=1;

	return N-Hungary();
}

void dfs(int d) {
	if(d>=N) {
		rnk[N]=N;
		ans=min(ans,getans());
		return;
	}

	for(int i=1;i<N;++i) {
		if(use[i]==0) {
			use[i]=1;
			rnk[d]=i;
			dfs(d+1);
			use[i]=0;
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&M)) {
		memset(rem,0,sizeof(rem));
		memset(use,0,sizeof(use));

		for(int i=1;i<=M;++i) {
			scanf("%d %d",&a,&b);
			rem[b][a]=1;
		}

		ans=1000;
		dfs(1);

		printf("%d\n",ans);
	}

	return 0;
}
