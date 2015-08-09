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
// Created Time  : 2015年07月25日 星期六 20时41分50秒
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

const int MaxN=100005;
const int LOG=20;

struct Edge
{
	int next,to,cost;
};

Edge E[MaxN*2];
int head[MaxN],Ecou;

int dep[MaxN];
int par[MaxN][LOG];

void Edge_init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v,int c)
{
	E[Ecou].next=head[u];
	E[Ecou].to=v;
	E[Ecou].cost=c;
	head[u]=Ecou++;
}

int que[MaxN];
int first,last;

void BFS(int root)
{
	int t,v;

	first=last=0;
	dep[root]=1;
	par[root][0]=root;
	que[last++]=root;

	while(last-first)
	{
		t=que[first++];

		for(int i=1;i<LOG;++i)
			par[t][i]=par[par[t][i-1]][i-1];

		for(int i=head[t];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(v==par[t][0])
				continue;

			dep[v]=dep[t]+1;
			par[v][0]=t;
			que[last++]=v;
		}
	}
}

int query(int u,int v)
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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	return 0;
}
