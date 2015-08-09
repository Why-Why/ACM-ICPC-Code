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
// Created Time  : 2015年07月23日 星期四 22时13分53秒
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

using namespace std;

const int MaxN=10;
const int MaxM=400;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int cou[MaxN];
int N,M;
int bai[MaxN],hei[MaxN];

bool Evis[MaxM];
bool vis[MaxN];

int rem[MaxN*10];
int rcou;

void init()
{
	Ecou=0;
	rcou=0;
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	memset(Evis,0,sizeof(Evis));
	memset(cou,0,sizeof(cou));
	memset(bai,0,sizeof(bai));
	memset(hei,0,sizeof(hei));
	memset(rem,0,sizeof(rem));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	++cou[v];
}

int dfs1(int d)
{
	int u=rem[d],v=rem[d+1];
	int k=cou[u]>>1;
	int ret=0;

	if(hei[u]>k || bai[u]>k)
		return 0;

	if(d==rcou)
		return 1;

	if(hei[u]<k)
	{
		++hei[u];
		++hei[v];
		ret+=dfs1(d+1);
		--hei[u];
		--hei[v];
	}

	if(bai[u]<k)
	{
		++bai[u];
		++bai[v];
		ret+=dfs1(d+1);
		--bai[u];
		--bai[v];
	}

	return ret;
}

void dfs(int u)
{
	bool ok=0;

	vis[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(Evis[i]==0)
		{
			Evis[i]=Evis[i^1]=1;
			ok=1;
			dfs(E[i].to);
		}

	rem[++rcou]=u;
}

int getans()
{
	for(int i=1;i<=N;++i)
		if(cou[i]&1)
			return 0;

	int ret=1;

	for(int i=1;i<=N;++i)
		if(!vis[i])
		{
			rcou=0;
			dfs(i);
			ret*=dfs1(1);
		}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init();

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		printf("%d\n",getans());
	}
	
	return 0;
}
