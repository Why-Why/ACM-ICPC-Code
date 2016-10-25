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
// Created Time  : 2016年07月21日 星期四 23时48分24秒
// File Name     : 1002.cpp

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

const int MaxN=(1<<16)+5;
const int mod=1000000007;

struct OPT {
	char s[5];

	int operator () (int a,int b) {
		if(s[0]=='A') return a&b;
		if(s[0]=='O') return a|b;
		return a^b;
	}
}opt;

struct Edge {
	int to,next;
};

int N;
Edge E[MaxN<<1];
int head[MaxN],Ecou;

int fa[MaxN];

int w[MaxN];
long long ans[MaxN],f[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u) {
	long long maxn=0;

	for(int t=fa[u];t!=-1;t=fa[t]) {
		maxn=max(maxn,f[t]+opt(w[t],w[u]));
		if(maxn-f[t]>=65535) break;
	}

	f[u]=maxn;
	ans[u]=f[u]+w[u];

	for(int i=head[u];i!=-1;i=E[i].next)
		dfs(E[i].to);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %s",&N,opt.s);
		init();
		for(int i=1;i<=N;++i) scanf("%d",w+i);
		fa[1]=-1;
		for(int i=2;i<=N;++i) {
			scanf("%d",&a);
			fa[i]=a;
			addEdge(a,i);
		}

		dfs(1);

		long long sum=0;
		for(int i=1;i<=N;++i)
			(sum+=i*ans[i]%mod)%=mod;
		printf("%I64d\n",sum);
	}

	return 0;
}
