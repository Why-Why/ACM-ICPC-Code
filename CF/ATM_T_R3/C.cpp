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
// Created Time  : 2016年09月03日 星期六 18时44分27秒
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

const int MaxN=400005;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int jianx[MaxN],jians[MaxN];
int jianx2[MaxN],rem[MaxN];
int son[MaxN];

int ans[MaxN];

int dfs(int u,int pre) {
	int ret=1,t;
	jianx[u]=jianx2[u]=0;
	rem[u]=-1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			t=dfs(E[i].to,u);
			ret+=t;
			if(t<=N/2) t=max(t,jianx[E[i].to]);
			else t=jianx[E[i].to];

			//jianx[u]=max(jianx[u],t);
			if(jianx[u]<t) {
				jianx2[u]=jianx[u];
				rem[u]=E[i].to;
				jianx[u]=t;
			}
			else if(jianx2[u]<t)
				jianx2[u]=t;
		}

	son[u]=ret;
	return ret;
}

void dfs1(int u,int pre) {
	int t=0;

	if(pre!=-1) {
		if(N-son[pre]<=N/2) t=N-son[pre];
		t=max(t,jians[pre]);
		if(rem[pre]==u) t=max(t,jianx2[pre]);
		else t=max(t,jianx[pre]);
	}
	else t=0;

	jians[u]=t;

	t=0;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs1(E[i].to,u);
			if(son[E[i].to]>N/2) {
				if(son[E[i].to]-jianx[E[i].to]<=N/2) ++t;
				else t+=2;
			}
		}
	if(N-son[u]>N/2) {
		if(N-son[u]-jians[u]<=N/2) ++t;
		else t+=2;
	}

	if(t<2) ans[u]=1;
	else ans[u]=0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	init();

	int a,b;
	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	dfs(1,-1);
	dfs1(1,-1);

	for(int i=1;i<=N;++i) printf("%d ",ans[i]);
	puts("");

	return 0;
}
