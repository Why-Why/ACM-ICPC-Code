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
// Created Time  : 2016年09月18日 星期日 23时49分19秒
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

const int MaxN=40010;

struct Edge {
	int to,next,cost;
};

Edge E[MaxN*2];
int head[MaxN],Ecou;

int fa[MaxN],dep[MaxN],son[MaxN],siz[MaxN],top[MaxN],w[MaxN],fw[MaxN];
int Tcou;

int N;

void init() {
	Ecou=Tcou=0;			// 不同于点权。
	w[1]=0;
	top[1]=1;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c) {
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs1(int u,int pre,int d) {
	int v;

	dep[u]=d;
	fa[u]=pre;
	siz[u]=1;
	son[u]=-1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			v=E[i].to;
			dfs1(v,u,d+1);
			siz[u]+=siz[v];

			if(son[u]==-1 || siz[son[u]]<siz[v])
				son[u]=v;
		}
}

void dfs2(int u) {
	if(son[u]==-1) return;

	top[son[u]]=top[u];
	w[son[u]]=++Tcou;
	fw[w[son[u]]]=son[u];

	dfs2(son[u]);

	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=son[u] && E[i].to!=fa[u]) {
			v=E[i].to;
			top[v]=v;
			w[v]=++Tcou;
			fw[w[v]]=v;

			dfs2(v);
		}
}

////////////////////////////////////////////////

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct NUM {
	int n,s,x;
};

NUM BIT[MaxN<<2];
int COL[MaxN<<2];

inline void pushUP(NUM & ret,const NUM & a,const NUM & b) {
	ret.n=a.n+b.n;
	if(a.x==b.s) --ret.n;
	ret.s=a.s;
	ret.x=b.x;
}

inline void pushUP(int po) {
	pushUP(BIT[po],BIT[lc],BIT[rc]);
}

inline void pushDown(int po) {
	if(COL[po]==-1) return;

	COL[lc]=COL[rc]=COL[po];
	BIT[lc].n=1;
	BIT[lc].s=BIT[lc].x=COL[po];

	BIT[rc]=BIT[lc];

	COL[po]=-1;
}

NUM query_BIT(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];

	pushDown(po);

	int M=(L+R)>>1;

	if(ql>M) return query_BIT(ql,qr,rson);
	if(qr<=M) return query_BIT(ql,qr,lson);

	NUM ret;
	pushUP(ret,query_BIT(ql,qr,lson),query_BIT(ql,qr,rson));
	return ret;
}

void update_BIT(int ul,int ur,int uc,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		BIT[po].n=1;
		BIT[po].s=BIT[po].x=uc;
		COL[po]=uc;
		return;
	}

	pushDown(po);

	int M=(L+R)>>1;

	if(ul<=M) update_BIT(ul,ur,uc,lson);
	if(ur>M) update_BIT(ul,ur,uc,rson);

	pushUP(po);
}

void update(int u,int v,int c) {
	int f1=top[u],f2=top[v];

	while(f1!=f2) {
		update_BIT(w[f1],w[u],c,1,N-1,1);		// N-1。

		u=fa[f1];
		f1=top[u];
	}

	if(u==v) return;

	if(dep[u]>dep[v]) swap(u,v);

	update_BIT(w[son[u]],w[v],c,1,N-1,1);
}

void query(NUM & ans,int u,int v) {
	int f1=top[u],f2=top[v];
	NUM now,last,ttt;

	last.n=0;
	last.s=last.x=-1;

	while(f1!=f2) {
		now=query_BIT(w[f1],w[u],1,N-1,1);		// N-1。
		pushUP(ttt,now,last);
		last=ttt;

		u=fa[f1];
		f1=top[u];
	}

	if(u==v) {
		ans=last;
		return;
	}

	if(dep[u]>dep[v]) swap(u,v);

	now=query_BIT(w[son[u]],w[v],1,N-1,1);
	pushUP(ans,now,last);
}

void build_BIT(int N) {
	int v;
	memset(COL,-1,sizeof(COL));

	for(int u=1;u<=N;++u)
		for(int i=head[u];i!=-1;i=E[i].next) {
			v=E[i].to;

			if(fa[v]==u) update_BIT(w[v],w[v],E[i].cost,1,N-1,1);
		}
}

int lca(int a,int b) {
	while(1) {
		if(top[a]==top[b]) return dep[a]<dep[b] ? a : b;
		else if(dep[top[a]]>dep[top[b]]) a=fa[top[a]];
		else b=fa[top[b]];
	}
}

////////////////////////////////////////////////

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b,c,tt;
	char s[20];
	NUM ans1,ans2;
	int ans;

	while(~scanf("%d %d",&N,&M)) {
		init();
		for(int i=1;i<N;++i) {
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		dfs1(1,-1,1);
		dfs2(1);

		build_BIT(N);

		while(M--) {
			scanf("%s %d %d",s,&a,&b);
			tt=lca(a,b);

			if(s[0]=='Q')
				if(a==b) puts("0");
				else {
					query(ans1,a,tt);
					query(ans2,b,tt);
					ans=ans1.n+ans2.n;
					if(ans1.s==ans2.s) --ans;

					printf("%d\n",ans);
				}
			else {
				scanf("%d",&c);
				update(a,tt,c);
				update(b,tt,c);
			}
		}
	}

	return 0;
}
