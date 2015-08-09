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
// Created Time  : 2015年08月04日 星期二 16时02分56秒
// File Name     : 1006_1.cpp

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

const int MaxN=100010;
const int MaxM=300005;

struct Edge
{
	int to,next;
	int id;
	bool zheng;
};

Edge E[MaxM*2];
int head[MaxN],Ecou;

int fa[MaxN],dep[MaxN],son[MaxN],siz[MaxN],top[MaxN],w[MaxN],fw[MaxN];
int Tcou;

int remfa[MaxN];

int ans[MaxM];
int N,M;

int Evis[MaxM<<1];
int nvis[MaxN];
int vis[MaxN];

void init(int N)
{
	Ecou=Tcou=0;			// 不同于点权。
	w[1]=0;
	top[1]=1;

	for(int i=1;i<=N;++i)
	{
		nvis[i]=0;
		head[i]=ans[i]=-1;
		vis[i]=0;
	}
}

void addEdge(int u,int v,int c,int zheng)
{
	Evis[Ecou]=0;
	E[Ecou].to=v;
	E[Ecou].id=c;
	E[Ecou].next=head[u];
	E[Ecou].zheng=zheng;
	head[u]=Ecou++;
}

void dfs1(int u,int pre,int d,int pid)
{
	int v;

	dep[u]=d;
	fa[u]=pre;
	siz[u]=1;
	son[u]=-1;

	remfa[u]=pid;
	nvis[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(nvis[u]==0 && E[i].to!=pre)
		{
			Evis[i]=Evis[i^1]=1;

			v=E[i].to;
			dfs1(v,u,d+1,i);
			siz[u]+=siz[v];

			if(son[u]==-1 || siz[son[u]]<siz[v])
				son[u]=v;
		}
}

void dfs2(int u)
{
	if(son[u]==-1)
		return;

	top[son[u]]=top[u];
	w[son[u]]=++Tcou;
	fw[w[son[u]]]=son[u];

	dfs2(son[u]);

	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(Evis[i]==1 && E[i].to!=son[u] && E[i].to!=fa[u])
		{
			v=E[i].to;
			top[v]=v;
			w[v]=++Tcou;

			dfs2(v);
		}
}

///// 线段树部分。
#define lc po*2
#define rc po*2+1
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN*4];
bool COL[MaxN<<2];

void pushUP(int po)
{
	BIT[po]=max(BIT[lc],BIT[rc]);
}

void pushDown(int po)
{
	if(COL[po])
	{
		COL[po]=0;
		COL[lc]=COL[rc]=1;
		BIT[lc]=BIT[rc]=1;
	}
}

int query_BIT(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return BIT[po];

	pushDown(po);

	int M=(L+R)/2;

	if(ql>M)
		return query_BIT(ql,qr,rson);
	if(qr<=M)
		return query_BIT(ql,qr,lson);

	return max(query_BIT(ql,qr,lson),query_BIT(ql,qr,rson));
}

void update_BIT(int ul,int ur,int L,int R,int po)
{
	if(ul<=L && ur>=R)
	{
		BIT[po]=1;
		COL[po]=1;
		return;
	}

	pushDown(po);

	int M=(L+R)/2;

	if(ul<=M)
		update_BIT(ul,ur,lson);
	else if(ur>M)
		update_BIT(ul,ur,rson);

	pushUP(po);
}

void update(int u,int v)
{
	int f1=top[u],f2=top[v];

	while(f1!=f2)
	{
		if(dep[f1]<dep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}

		update_BIT(w[f1],w[u],1,N-1,1);

		u=fa[f1];
		f1=top[u];
	}

	if(u==v)						//!!!
		return;

	if(dep[u]>dep[v])
		swap(u,v);

	update_BIT(w[son[u]],w[v],1,N-1,1);
}

int query(int u,int v)
{
	int f1=top[u],f2=top[v];
	int ret=0;

	while(f1!=f2)
	{
		if(dep[f1]<dep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}

		ret=max(ret,query_BIT(w[f1],w[u],1,N-1,1));		// N-1。

		u=fa[f1];
		f1=top[u];
	}

	if(u==v)						//!!!
		return ret;

	if(dep[u]>dep[v])
		swap(u,v);

	ret=max(ret,query_BIT(w[son[u]],w[v],1,N-1,1));

	return ret;
}

int lca(int a,int b)
{
    while(1)
    {
        if(top[a]==top[b])
            return dep[a]<dep[b] ? a : b;
        else if(dep[top[a]]>dep[top[b]])
            a=fa[top[a]];
        else
            b=fa[top[b]];
    }
}

void build(int L,int R,int po)
{
	BIT[po]=COL[po]=0;

	if(L==R)
		BIT[po]=COL[po]=0;

	int M=(L+R)>>1;

	build(lson);
	build(rson);
}

void dfs111(int u,int t,int pre)
{
	vis[u]=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(Evis[i]!=2 && E[i].to!=pre)
		{
			ans[E[i].id]=E[i].zheng ? t : 1-t;
			dfs111(E[i].to,1-t,u);
			t=1-t;
		}
}

void getans111()
{
	for(int i=1;i<=N;++i)
		if(vis[i]==0)
			dfs111(i,1,-1);
}

void chuli(int u,int v,int id)
{
	int t=lca(u,v);

	if(query(u,v))
		return;

	update(u,v);
	while(u!=t)
	{
		ans[E[remfa[u]].id]=E[remfa[u]].zheng ? 1 : 0;
		Evis[remfa[u]]=Evis[remfa[u]^1]=2;
		u=fa[u];
	}

	while(v!=t)
	{
		ans[E[remfa[u]].id]=E[remfa[u]].zheng ? 0 : 1;
		Evis[remfa[v]]=Evis[remfa[v]^1]=2;
		v=fa[v];
	}

	ans[E[id].id]=E[id].zheng ? 0 : 1;
	Evis[id]=Evis[id^1]=2;
}

void getans()
{
	for(int u=1;u<=N;++u)
		for(int i=head[u];i!=-1;i=E[i].next)
			if(Evis[i]==0)
				chuli(u,E[i].to,i);

//	getans111();
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init(N);

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b,i,1);
			addEdge(b,a,i,0);
		}

		dfs1(1,-1,1,-1);
		dfs2(1);
		build(1,N-1,1);
		getans();
	}
	
	return 0;
}
