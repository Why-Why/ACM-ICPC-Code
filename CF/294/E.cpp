// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月12日 星期二 15时29分41秒
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

const int LOG=20;
const int MaxN=100100;

struct Edge
{
	int to,next;
};

Edge E[MaxN*2];
int head[MaxN],Ecou;

int dep[MaxN];
int par[MaxN][LOG];
int son[MaxN];

void Edge_init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int dfs(int u)
{
	int ret=0;
	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(dep[v])
			continue;

		par[v][0]=u;
		dep[v]=dep[u]+1;
		ret+=dfs(v);
	}

	son[u]=ret+1;
	return son[u];
}

void LCA_init(int root,int N)
{
	dep[root]=1;
	par[root][0]=root;
	dfs(root);

	for(int i=1;i<LOG;++i)
		for(int j=1;j<=N;++j)
			par[j][i]=par[par[j][i-1]][i-1];
}

int query_zu(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);

	for(int det=dep[u]-dep[v],i=0;det;det>>=1,++i)
		if(det&1)
			u=par[u][i];

	if(u==v)
		return u;

	for(int i=LOG-1;i>=0;--i)
		if(par[u][i]!=par[v][i])
		{
			u=par[u][i];
			v=par[v][i];
		}

	return par[u][0];
}

int query(int u,int v,int N)
{
	int ret;
	int zu=query_zu(u,v);
	int len=dep[u]-dep[zu]+dep[v]-dep[zu];

	if(len&1)
		return 0;

	if(len==0)
		return N;

	if(dep[u]<dep[v])
		swap(u,v);

	len>>=1;
	--len;
	bool ok=(dep[u]==dep[v]);
	int cou=0;

	while(len)
	{
		if(len&1)
		{
			u=par[u][cou];
			v=par[v][cou];
		}

		++cou;
		len>>=1;
	}

	if(par[u][0]!=zu)
		return son[par[u][0]]-son[u];

	return N-son[u]-son[v];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M;
	int a,b;

	scanf("%d",&N);

	Edge_init();

	for(int i=1;i<N;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	LCA_init(1,N);

	scanf("%d",&M);

	while(M--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",query(a,b,N));
	}
	
	return 0;
}
