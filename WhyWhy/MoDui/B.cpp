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
// Created Time  : 2016年03月29日 星期二 23时14分18秒
// File Name     : B.cpp

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
const int INF=0x3f3f3f3f;

struct Edge {
	int u,v,c;

	Edge() {}
	Edge(int a,int b,int c):u(a),v(b),c(c) {}

	bool operator < (const Edge &b) const {
		return c<b.c;
	}
};

struct Point {
	int x,y;
	int id;

	bool operator < (const Point &b) const {
		if(x==b.x) return y<b.y;
		return x<b.x;
	}
};

Edge E[MaxN<<2];
Point P[MaxN];
int Ecou;
int N,K;

int fa[MaxN];
int find(int x) {
	if(fa[x]==-1) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int C[2005],RC[2005];			// !!!
inline int lowbit(int x) { return x&(-x); }
inline int query(int x,int &p) {
	int ret=INF,rc=-1;
	for(;x;x-=lowbit(x))
		if(C[x]<ret) {
			ret=C[x];
			rc=RC[x];
		}
	p=rc;
	return ret;
}
inline void update(int x,int t,int v) {
	for(;x<=2001;x+=lowbit(x))
		if(t<C[x]) {
			C[x]=t;
			RC[x]=v;
		}
}

void getans() {
	sort(P+1,P+N+1);
	for(int i=1;i<=2001;++i) C[i]=INF;

	int t,v,x,y;

	for(int i=N;i>=1;--i) {
		x=P[i].x;
		y=P[i].y;
		t=query(x-y+1001,v);
		update(x-y+1001,x+y,P[i].id);

		if(t==-1) continue;
		else E[Ecou++]=Edge(P[i].id,v,t-x-y);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&K)) {
		for(int i=1;i<=N;++i) scanf("%d %d",&P[i].x,&P[i].y),fa[i]=-1,P[i].id=i;
		Ecou=0;
		getans();
		for(int i=1;i<=N;++i) swap(P[i].x,P[i].y);
		getans();
		for(int i=1;i<=N;++i) P[i].x=-P[i].x;
		getans();
		for(int i=1;i<=N;++i) swap(P[i].x,P[i].y);
		getans();

		K=N-K;
		int ans=0;
		sort(E,E+Ecou);
		for(int i=0;i<Ecou;++i) {
			if(find(E[i].u)==find(E[i].v)) continue;
			--K;
			fa[find(E[i].u)]=find(E[i].v);
			if(K==0) { ans=E[i].c; break; }
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
