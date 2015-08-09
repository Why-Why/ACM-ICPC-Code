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
// Created Time  : 2015年07月28日 星期二 21时42分31秒
// File Name     : 1010_1.cpp

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

const int MaxN=500005;

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N;
int size[MaxN];
int shang[MaxN];
int w[MaxN];

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int dfs(int u,int pre)
{
	int v;
	int t;

	size[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			v=E[i].to;
			t=dfs(v,u);

			if(w[v]>w[u])
				size[u]+=t;
		}

	return size[u];
}

void dfs1(int u,int pre)
{
	if(pre!=-1 && w[pre]>w[u])
		shang[u]=shang[pre]+size[pre];
	else
		shang[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs1(E[i].to,u);
}

int getans()
{
	int ret=0;

	for(int i=1;i<=N;++i)
		ret=max(ret,shang[i]+size[i]);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	
	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%d",&w[i]);

		init();

		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		dfs(1,-1);
		dfs1(1,-1);

		printf("%d\n",getans());
	}
	
	return 0;
}
