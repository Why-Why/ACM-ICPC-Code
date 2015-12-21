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
// Created Time  : 2015年10月01日 星期四 12时22分47秒
// File Name     : D_2.cpp

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

const int MaxN=510;
const int MaxM=250010;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int du[MaxN];
int N,M;
int ans;
bool vis[MaxN];

void init()
{
	Ecou=0;
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int d)
{
	if(u>30)
	{
		for(int i=1;i<=N;++i)
			if(vis[i]==0) return;
		ans=min(ans,d);
		return ;
	}

	if(du[u]==0) dfs(u+1,d);
	else
	{
		int cou=0;
		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].to>30 && vis[E[i].to]==0)
			{
				vis[E[i].to]=1;
				++cou;
				for(int j=head[E[i].to];j!=-1;j=E[j].to)
					if(vis[E[j].to]==0)
						--du[E[j].to];
			}
		dfs(u+1,d+cou);
		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].to>30 && vis[E[i].to]==0)
			{
				vis[E[i].to]=1;
				++cou;
				for(int j=head[E[i].to];j!=-1;j=E[j].to)
					if(vis[E[j].to]==0)
						--du[E[j].to];
			}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&M))
	{
		init();
		memset(du,0,sizeof(du));
		while(M--)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
			++du[a];
			++du[b];
		}

		ans=INF;
		dfs(1,0);
		printf("%d\n",ans);
	}
	
	return 0;
}
