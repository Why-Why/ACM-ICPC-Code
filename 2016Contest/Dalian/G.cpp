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
// Created Time  : 2016年11月12日 星期六 17时12分34秒
// File Name     : G.cpp

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

const int MaxN=50005;
const int INF=0x3f3f3f3f;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N;
bool vis[MaxN];

int K,kind[MaxN];
int BASE;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

///////////////////////

int sumnode;
int cen,minnC;
int maxson[MaxN],couson[MaxN];

void dfsC1(int u,int pre) {
	couson[u]=1;
	maxson[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre) {
			dfsC1(E[i].to,u);
			couson[u]+=couson[E[i].to];
			maxson[u]=max(maxson[u],couson[E[i].to]);
		}
}

void dfsC2(int u,int pre) {
	int maxn=max(maxson[u],sumnode-couson[u]);
	if(maxn<minnC) { minnC=maxn; cen=u; }

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsC2(E[i].to,u);
}

int getCenter(int u) {
	dfsC1(u,-1);
	sumnode=couson[u];
	minnC=INF;
	cen=u;
	dfsC2(u,-1);
	return cen;
}

///////////////////////

long long ans;

int rem[MaxN],rcou;

long long map1[32][32];
int yan[32][32],ycou[32];
int suo[32][32],scou[32];

inline void add(int k,int v) {
	int a=k&31,b=k>>5;

	for(int i=0;i<scou[a];++i)
		map1[suo[a][i]][b]+=v;
}

inline long long cal(int k) {
	long long ret=0;
	int a=k&31,b=k>>5;

	for(int i=0;i<ycou[b];++i)
		ret+=map1[a][yan[b][i]];

	return ret;
}

void dfsc(int u,int pre,int k) {
	k|=(1<<kind[u]);
	rem[++rcou]=k;

	ans+=cal(BASE&(~k));

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsc(E[i].to,u,k);
}

void calc(int u) {
	int last=1;
	rcou=0;

	add(1<<kind[u],1);

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {
			dfsc(E[i].to,u,1<<kind[u]);
			for(int i=last;i<=rcou;++i) add(rem[i],1);
			last=rcou+1;
		}

	add(1<<kind[u],-1);
	for(int i=1;i<=rcou;++i) add(rem[i],-1);
} 

///////////////////////

void getans(int u) {
	int c=getCenter(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c];i!=-1;i=E[i].next)			// !!! c is not u.
		if(!vis[E[i].to])
			getans(E[i].to);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=0;i<32;++i)
		for(int j=0;j<32;++j) {
			if((j&i)==i) yan[i][ycou[i]++]=j;
			if((j&i)==j) suo[i][scou[i]++]=j;
		}

	int a,b;

	while(~scanf("%d %d",&N,&K)) {
		BASE=(1<<K)-1;

		for(int i=1;i<=N;++i) {
			scanf("%d",kind+i);
			--kind[i];
		}

		init();
		ans=0;
		memset(map1,0,sizeof(map1));

		for(int i=1;i<N;++i) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		getans(1);

		ans<<=1;
		if(K==1) ans+=N;			// !!!

		printf("%I64d\n",ans);
	}

	return 0;
}
