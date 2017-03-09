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
// Created Time  : 2015年09月19日 星期六 13时09分41秒
// File Name     : 1003_1.cpp

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

const int MaxN=20010;

struct Edge
{
	int to,next,cost;
};

Edge E[MaxN*2];
int head[MaxN],Ecou;

int fa[MaxN],dep[MaxN],son[MaxN],siz[MaxN],top[MaxN],w[MaxN],fw[MaxN];
int Tcou;

void init()
{
	Ecou=Tcou=0;			// 不同于点权。
	w[1]=0;
	top[1]=1;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c)
{
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
	fw[w[son[u]]]=son[u];

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

inline int lowbit(int x)
{
	return x&(-x);
}

int C[MaxN];
int CN;

int sum(int x)
{
	int ret=0;

	while(x>0)
	{
		ret+=C[x];
		x-=lowbit(x);
	}
	return ret;
}

void add(int x,int d)
{
	while(x<=CN)
	{
		C[x]+=d;
		x+=lowbit(x);
	}
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

		add(w[f1],1);
		add(w[u]+1,-1);

		u=fa[f1];
		f1=top[u];
	}

	if(u==v) return;
	if(dep[u]>dep[v]) swap(u,v);
	add(w[son[u]],1);
	add(w[v]+1,-1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int N,M,a,b,c;

	scanf("%d",&T);

	while(T--)
	{
		init();
		scanf("%d %d",&N,&M);
		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b,1);
			addEdge(b,a,1);
		}

		dfs1(1,-1,1);
		dfs2(1);

		CN=N-1;
		memset(C,0,sizeof(C));

		for(int i=N;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			update(a,b);
		}

		int ans=0;
		for(int i=1;i<N;++i)
			ans=max(ans,sum(i));
		printf("Case #%d: %d\n",cas++,ans+1);
	}
	
	return 0;
}
