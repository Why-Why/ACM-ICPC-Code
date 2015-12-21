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
// Created Time  : 2015年10月02日 星期五 14时09分46秒
// File Name     : D.cpp

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

const int MaxN=200005;
const int LOG=20;

struct Edge
{
	int next,to;
};

Edge E[MaxN*2];
int head[MaxN],Ecou;

int dep[MaxN];
int par[MaxN][LOG];

struct State
{
	int shang,xia,zhong,sum;
};

State sta[MaxN][LOG];

void merge(const State &a,const State &b,State &z)
{
	z.zhong=max(max(a.zhong,b.zhong),a.shang+b.xia);
	z.shang=max(b.shang,b.sum+a.shang);
	z.xia=max(a.xia,a.sum+b.xia);
	z.sum=a.sum+b.sum;
}

void Edge_init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].next=head[u];
	E[Ecou].to=v;
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

	sta[root][0].sum=sta[root][0].shang=sta[root][0].xia=sta[root][0].zhong=val[root];

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
