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
// Created Time  : 2016年03月30日 星期三 22时57分09秒
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
#include <climits>

using namespace std;

const int MaxN=100005;
const int INF=0x3f3f3f3f;

struct Treap {
	int tot,root;
	int ch[MaxN][2];
	int key[MaxN],pri[MaxN];

	int val[MaxN],rem[MaxN];
	int allval[MaxN],allrem[MaxN];

	void init() {
		tot=1;
		root=0;
		pri[0]=INT_MAX;

		allval[0]=INF;
		allrem[0]=-1;
	}

	void update(int x) {
		int t=allval[ch[x][0]]>allval[ch[x][1]] ? allrem[ch[x][1]] : allrem[ch[x][0]];
		int tv=min(allval[ch[x][0]],allval[ch[x][1]]);
		if(val[x]>tv) allrem[x]=t,allval[x]=tv;
		else allrem[x]=rem[x],allval[x]=val[x];
	}

	void rotate(int &x,int t) {
		int y=ch[x][t];
		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;
		update(x);
		update(y);
		x=y;
	}

	void _insert(int &x,int k,int v,int r) {
		if(x) {
			if(key[x]==k) {
				if(val[x]>v) {
					val[x]=v;
					rem[x]=r;
				}
			}
			else {
				int t=key[x]<k;
				_insert(ch[x][t],k,v,r);
				if(pri[ch[x][t]]<pri[x]) rotate(x,t);
			}
		}
		else {
			x=tot++;
			key[x]=k;
			pri[x]=rand();
			ch[x][0]=ch[x][1]=0;

			val[x]=v;
			rem[x]=r;
		}
		update(x);
	}

	void insert(int k,int v,int r) { _insert(root,k,v,r); }

	void solve(int &v,int &r,int v1,int r1) {
		if(v>v1) v=v1,r=r1;
	}

	int getnum(int k,int &r) {
		int ret=INF,x=root;
		r=-1;

		while(x) {
			if(key[x]<k) x=ch[x][1];
			else {
				solve(ret,r,allval[ch[x][1]],allrem[ch[x][1]]);
				solve(ret,r,val[x],rem[x]);
				if(key[x]==k) return ret;
				x=ch[x][0];
			}
		}
		return ret;
	}
}tree;

struct Edge {
	int u,v;
	long long c;

	Edge() {}
	Edge(int a,int b,long long c):u(a),v(b),c(c) {}

	bool operator < (const Edge &b) const {
		return c<b.c;
	}
}E[MaxN<<2];

struct Point {
	int x,y;
	int id;

	bool operator < (const Point &b) const {
		return x==b.x ? y<b.y : x<b.x;
	}
}P[MaxN];

int N;
int Ecou;

int fa[MaxN];

int find(int x) {
	if(fa[x]==-1) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

void getans() {
	sort(P+1,P+N+1);
	tree.init();

	int id,t;

	for(int i=N;i>=1;--i) {
		t=tree.getnum(P[i].y-P[i].x,id);
		tree.insert(P[i].y-P[i].x,P[i].x+P[i].y,P[i].id);
		if(id==-1) continue;
		E[Ecou++]=Edge(id,P[i].id,t-P[i].x-P[i].y);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;
	while(~scanf("%d",&N) && N) {
		Ecou=0;
		for(int i=1;i<=N;++i) scanf("%d %d",&P[i].x,&P[i].y),fa[i]=-1,P[i].id=i;
		getans();
		for(int i=1;i<=N;++i) swap(P[i].x,P[i].y);
		getans();
		for(int i=1;i<=N;++i) P[i].x=-P[i].x;
		getans();
		for(int i=1;i<=N;++i) swap(P[i].x,P[i].y);
		getans();

		sort(E,E+Ecou);
		long long ans=0;
		for(int i=0;i<Ecou;++i)
			if(find(E[i].u)!=find(E[i].v)) {
				fa[find(E[i].u)]=find(E[i].v);
				ans+=E[i].c;
			}
		printf("Case %d: Total Weight = %lld\n",cas++,ans);
	}
	
	return 0;
}
