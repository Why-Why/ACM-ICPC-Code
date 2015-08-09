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
// Created Time  : 2015年07月22日 星期三 13时55分13秒
// File Name     : 1006.cpp

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

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int MaxN=100005;

struct Edge
{
	int to,next;
};

struct Lian 
{
	int u,v;
	int cost;
	int next;
};

int N,M;

Edge E[MaxN<<1];
int head[MaxN],Ecou;

Lian L[MaxN];
int Lhead[MaxN],Lcou;

int fa[MaxN],dep[MaxN],son[MaxN],siz[MaxN],top[MaxN],w[MaxN];
int Tcou;

int C_max[MaxN],C_wu[MaxN];

void init()
{
	Ecou=0;
	Lcou=0;
	Tcou=1;
	w[1]=1;
	top[1]=1;
	memset(Lhead,-1,sizeof(Lhead));
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
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

void addLian(int u,int v,int c)
{
	int h=lca(u,v);

	L[Lcou].u=u;
	L[Lcou].v=v;
	L[Lcou].cost=c;
	L[Lcou].next=Lhead[h];
	Lhead[h]=Lcou++;
}

void dfs1(int u,int pre,int d)
{
	int v;

	dep[u]=d;
	fa[u]=pre;
	siz[u]=1;
	son[u]=-1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
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

	dfs2(son[u]);

	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=son[u] && E[i].to!=fa[u])
		{
			v=E[i].to;
			top[v]=v;
			w[v]=++Tcou;
			dfs2(v);
		}
}

void TL_init()
{
	dfs1(1,-1,1);
	dfs2(1);
	memset(C_max,0,sizeof(C_max));
	memset(C_wu,0,sizeof(C_wu));
}

inline int lowbit(int x)
{
	return x&(-x);
}

int sum(int x,int C[])
{
	int ret=0;
	
	while(x>0)
	{
		ret+=C[x];
		x-=lowbit(x);
	}

	return ret;
}

void add(int x,int d,int C[])
{
	while(x<=N)
	{
		C[x]+=d;
		x+=lowbit(x);
	}
}

int query(int u,int v,int C[])
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

		ret+=sum(w[u],C)-sum(w[f1]-1,C);
		u=fa[f1];
		f1=top[u];
	}

	if(dep[u]>dep[v])
		swap(u,v);

	ret+=sum(w[v],C)-sum(w[u]-1,C);

	return ret;
}

void update(int u,int ut,int C[])
{
	add(w[u],ut,C);
}

int dp[MaxN][2];

void dfs(int u)
{
	int v;
	int ans=0;
	int maxn=0,tsum1,tsum2;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=fa[u])
		{
			dfs(E[i].to);
			ans+=dp[E[i].to][1];
		}

	for(int h=Lhead[u];h!=-1;h=L[h].next)
	{
		tsum1=query(L[h].u,L[h].v,C_wu);
		tsum2=query(L[h].u,L[h].v,C_max);
		maxn=max(maxn,tsum1-tsum2+ans+L[h].cost);
	}

	maxn=max(maxn,ans);
	dp[u][0]=ans;
	dp[u][1]=maxn;

	update(u,ans,C_wu);
	update(u,maxn,C_max);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b,c;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init();

		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		TL_init();

		while(M--)
		{
			scanf("%d %d %d",&a,&b,&c);
			addLian(a,b,c);
		}

		memset(dp,0,sizeof(dp));
		dfs(1);

		printf("%d\n",dp[1][1]);
	}
	
	return 0;
}
