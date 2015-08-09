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
// Created Time  : 2015年07月17日 星期五 15时35分58秒
// File Name     : 3321.cpp

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

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int fa[MaxN],son[MaxN],siz[MaxN],dep[MaxN],top[MaxN],w[MaxN];
int Tcou;

int C[MaxN];

void init()
{
	Tcou=1;
	Ecou=0;
	w[1]=1;
	top[1]=1;

	memset(head,-1,sizeof(head));
	memset(C,0,sizeof(C));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
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

int N;

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int d)
{
	while(x<=N)
	{
		C[x]+=d;
		x+=lowbit(x);
	}
}

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

void update(int u,int v,int d)
{
	int f1=top[u],f2=top[v];

	while(f1!=f2)
	{
		if(dep[f1]<dep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}

		add(w[f1],d);
		add(w[u]+1,-d);
		u=fa[f1];
		f1=top[u];
	}

	if(dep[u]>dep[v])
		swap(u,v);

	add(w[u],d);
	add(w[v]+1,-d);
}

bool rem[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M;
	int a,b;
	char s[10];

	while(~scanf("%d",&N))
	{
		init();
		memset(rem,0,sizeof(rem));

		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		dfs1(1,-1,1);
		dfs2(1);

		scanf("%d",&M);

		for(int i=1;i<=N;++i)
			update(1,i,1);

		while(M--)
		{
			scanf("%s %d",s,&a);

			if(s[0]=='Q')
				printf("%d\n",sum(w[a]));
			else
			{
				update(1,a,rem[a]?1:-1);
				rem[a]=!rem[a];
			}
		}
	}
	
	return 0;
}
