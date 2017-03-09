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
// Created Time  : 2017年02月12日 星期日 13时43分28秒
// File Name     : E.cpp

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

const long long MaxN=200005;

struct Edge {
	long long to,next;
};

Edge E[MaxN<<1];
long long head[MaxN],Ecou;

long long dep[MaxN],son[MaxN],siz[MaxN],top[MaxN],w[MaxN],fw[MaxN];
long long Tcou;

long long val[MaxN],fa[MaxN],tval[MaxN];

void init() {
	Tcou=1;
	Ecou=0;
	w[1]=1;
	fw[1]=1;
	top[1]=1;
	memset(head,-1,sizeof(head));
}

void addEdge(long long u,long long v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs1(long long u,long long pre,long long d) {
	long long v;

	dep[u]=d;
	fa[u]=pre;
	siz[u]=1;
	son[u]=-1;

	for(long long i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			v=E[i].to;
			dfs1(v,u,d+1);
			siz[u]+=siz[v];

			if(son[u]==-1 || siz[son[u]]<siz[v])
				son[u]=v;
		}
}

void dfs2(long long u) {
	if(son[u]==-1)
		return;

	top[son[u]]=top[u];
	w[son[u]]=++Tcou;
	fw[w[son[u]]]=son[u];

	dfs2(son[u]);

	long long v;

	for(long long i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=son[u] && E[i].to!=fa[u]) {
			v=E[i].to;
			top[v]=v;
			w[v]=++Tcou;
			fw[w[v]]=v;				// !!!
			
			dfs2(v);
		}
}

long long base[MaxN<<2],sum[MaxN<<2];
long long col[MaxN<<2];
long long N;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

inline void build(long long L,long long R,long long po) {
	sum[po]=col[po]=0;

	if(L==R) {
		base[po]=val[fw[L]];
		return;
	}

	long long M=(L+R)>>1;
	build(lson);
	build(rson);

	base[po]=base[lc]+base[rc];
}

inline void pushDown(long long po) {
	if(col[po]) {
		col[lc]+=col[po];
		col[rc]+=col[po];
		sum[lc]+=base[lc]*col[po];
		sum[rc]+=base[rc]*col[po];
		col[po]=0;
	}
}

inline void pushUP(long long po) {
	sum[po]=sum[lc]+sum[rc];
}

long long query(long long ul,long long ur,long long L,long long R,long long po) {
	if(ul<=L && ur>=R)
		return sum[po];

	pushDown(po);

	long long M=(L+R)>>1;
	long long ret=0;
	if(ul<=M) ret+=query(ul,ur,lson);
	if(ur>M) ret+=query(ul,ur,rson);

	return ret;
}

void update(int ul,int ur,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		++col[po];
		sum[po]+=base[po];
		return;
	}

	pushDown(po);
	long long M=(L+R)>>1;
	if(ul<=M) update(ul,ur,lson);
	if(ur>M) update(ul,ur,rson);

	pushUP(po);
}

void change(long long u,long long v) {
	long long f1=top[u],f2=top[v];

	while(f1!=f2) {
		if(dep[f1]<dep[f2]) {
			swap(f1,f2);
			swap(u,v);
		}

		update(w[f1],w[u],1,N,1);

		u=fa[f1];
		f1=top[u];
	}

	if(dep[u]>dep[v]) swap(u,v);

	update(w[u],w[v],1,N,1);
}

long long getans(long long u,long long v) {
	long long f1=top[u],f2=top[v];
	long long ret=0;

	while(f1!=f2) {
		if(dep[f1]<dep[f2]) {
			swap(f1,f2);
			swap(u,v);
		}

		ret+=query(w[f1],w[u],1,N,1);

		u=fa[f1];
		f1=top[u];
	}

	if(dep[u]>dep[v]) swap(u,v);

	ret+=query(w[u],w[v],1,N,1);

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long a;

	while(~scanf("%lld",&N)) {
		init();
		for(long long i=1;i<=N;++i) scanf("%lld",tval+i);
		for(long long i=2;i<=N;++i) {
			scanf("%lld",&a);
			addEdge(a,i);
			addEdge(i,a);
		}
		dfs1(1,-1,1);
		dfs2(1);
		val[1]=tval[1];
		for(long long i=2;i<=N;++i) val[i]=tval[i]-tval[fa[i]];
		build(1,N,1);

		change(1,1);
		for(long long i=2;i<=N;++i) {
			printf("%lld\n",getans(1,i));
			change(1,i);
		}
	}

	return 0;
}
