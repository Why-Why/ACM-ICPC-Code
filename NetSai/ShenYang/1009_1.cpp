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
// Created Time  : 2015年09月19日 星期六 22时40分12秒
// File Name     : 1009_1.cpp

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

const int MaxN=30004;
const int MaxM=100005;
const int MaxQ=100005;

struct Edge
{
	int to,next,cost;
};

struct Query
{
	int op;
	int a,b;

}q[MaxQ];

struct REME
{
	int u,v;

	bool operator < (const REME & b) const
	{
		return u==b.u ? v<b.v : u<b.u;
	}
};

Edge E[MaxM<<1];
int head[MaxN],Ecou;

int fa[MaxN],dep[MaxN],son[MaxN],siz[MaxN],top[MaxN],w[MaxN],fw[MaxN];
int Tcou;

bool Evis[MaxM<<1];

int N,M,Q;
multiset <REME> remE;
int zans[MaxQ],anscou;

void init()
{
	Ecou=Tcou=0;			// 不同于点权。
	w[1]=0;
	top[1]=1;
	memset(head,-1,sizeof(head));
	memset(dep,-1,sizeof(dep));
}

void addEdge(int u,int v,int c)
{
	Evis[Ecou]=0;
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs1(int u,int pre,int d)
{
	int v;

	dep[u]=d;
	fa[u]=pre;
	siz[u]=1;
	son[u]=-1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre && dep[E[i].to]==-1)
		{
			Evis[i]=Evis[i^1]=1;
			v=E[i].to;
			dfs1(v,u,d+1);
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
		if(Evis[i] && E[i].to!=son[u] && E[i].to!=fa[u])
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

inline void pushUP(int po)
{
	BIT[po]=BIT[lc]+BIT[rc];
}

inline void pushDown(int po)
{
	if(COL[po])
	{
		COL[po]=0;
		COL[lc]=COL[rc]=1;
		BIT[lc]=BIT[rc]=0;
	}
}

int query_BIT(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return BIT[po];

	pushDown(po);
	int M=(L+R)/2;

	if(ql>M) return query_BIT(ql,qr,rson);
	if(qr<=M) return query_BIT(ql,qr,lson);

	return query_BIT(ql,qr,lson)+query_BIT(ql,qr,rson);
}

void update_BIT(int ul,int ur,int L,int R,int po)
{
	if(ul<=L && ur>=R)
	{
		BIT[po]=0;
		COL[po]=1;
		return;
	}

	pushDown(po);
	int M=(L+R)>>1;

	if(ul<=M) update_BIT(ul,ur,lson);
	if(ur>M) update_BIT(ul,ur,rson);

	pushUP(po);
}

void Build(int L,int R,int po)
{
	BIT[po]=R-L+1;
	COL[po]=0;

	if(L==R) return;

	int M=(L+R)>>1;
	Build(lson);
	Build(rson);
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

	if(u==v) return;
	if(dep[u]>dep[v]) swap(u,v);
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
		ret+=query_BIT(w[f1],w[u],1,N-1,1);		// N-1。

		u=fa[f1];
		f1=top[u];
	}

	if(u==v) return ret;
	if(dep[u]>dep[v]) swap(u,v);
	ret+=query_BIT(w[son[u]],w[v],1,N-1,1);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);
	REME te;
	multiset <REME> ::iterator iter;
	
	while(T--)
	{
		remE.clear();
		scanf("%d %d %d",&N,&M,&Q);
		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&te.u,&te.v);
			if(te.u>te.v) swap(te.u,te.v);
			if(te.u==te.v) continue;
			remE.insert(te);
		}

		printf("Case #%d:\n",cas++);

		for(int i=1;i<=Q;++i)
		{
			scanf("%d %d %d",&q[i].op,&q[i].a,&q[i].b);
			if(q[i].a>q[i].b) swap(q[i].a,q[i].b);
			if(q[i].op==1 && q[i].a!=q[i].b)
			{
				te.u=q[i].a; te.v=q[i].b;
				iter=remE.find(te);
				remE.erase(iter);
			}

			if(N==1 && q[i].op==2)
				printf("0\n");
		}

		if(N==1) continue;

		init();
		M=remE.size();
		for(iter=remE.begin();iter!=remE.end();++iter)
		{
			addEdge(iter->u,iter->v,1);
			addEdge(iter->v,iter->u,1);
		}

		dfs1(1,-1,1);
		dfs2(1);
		Build(1,N-1,1);

		for(int i=0;i<Ecou;++i)
			if(Evis[i]==0)
			{
				Evis[i]=Evis[i^1]=1;
				update(E[i].to,E[i^1].to);
			}

		anscou=0;
		for(int i=Q;i>=1;--i)
		{
			if(q[i].op==1 && q[i].a!=q[i].b) update(q[i].a,q[i].b);
			else if(q[i].op==2)  zans[anscou++]=query(q[i].a,q[i].b);
		}

		for(int i=anscou-1;i>=0;--i)
			printf("%d\n",zans[i]);
	}
	
	return 0;
}
