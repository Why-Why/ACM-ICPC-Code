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
// Created Time  : 2016年07月19日 星期二 13时57分01秒
// File Name     : 1001.cpp

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

struct EEE {
	int u,v,w;

	bool operator < (const EEE & b) const {
		return w<b.w;
	}
};

struct Edge {
	int to,next,w;
};

EEE EE[1000006];
Edge E[MaxN<<1];
int N,M;

int head[MaxN],Ecou;
int fa[MaxN];

long long ans1;
double ans2;

inline int read() {
char c; int sgn;
int ret=0;
if(c=getchar(),c==EOF) return 0;
while(c!='-'&&(c<'0'||c>'9')) c=getchar();
sgn=(c=='-')?-1:1;
ret=(c=='-')?0:(c-'0');
while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
ret*=sgn;
return ret;
}

void init() {
	for(int i=1;i<=N;++i) fa[i]=head[i]=-1;
	Ecou=0;
}

void addEdge(int u,int v,int w) {
	E[Ecou].to=v;
	E[Ecou].w=w;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int find(int u) {
	if(fa[u]==-1) return u;
	fa[u]=find(fa[u]);
	return fa[u];
}

int sum[MaxN];

void dfs(int u,int pre,int w) {
	sum[u]=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u,E[i].w);
			sum[u]+=sum[E[i].to];
		}

	if(u!=1) ans2+=(double)sum[u]*(0.0+N-sum[u])*(w+0.0);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a,b;
	T=read();

	while(T--) {
		ans1=ans2=0;
		N=read();
		M=read();
		init();
		for(int i=0;i<M;++i) {
			EE[i].u=read();
			EE[i].v=read();
			EE[i].w=read();
		}
		sort(EE,EE+M);
		
		int j=0;
		for(int i=0;j<N-1 && i<M;++i) {
			a=find(EE[i].u);
			b=find(EE[i].v);
			if(a==b) continue;
			fa[a]=b;
			++j;
			addEdge(EE[i].u,EE[i].v,EE[i].w);
			addEdge(EE[i].v,EE[i].u,EE[i].w);
			ans1+=EE[i].w;
		}

		if(j<N-1) {
			puts("0 0.00");
			continue;
		}

		dfs(1,-1,0);
		printf("%I64d %.2f\n",ans1,2.0*ans2/N/(N-1.0));
	}

	return 0;
}
