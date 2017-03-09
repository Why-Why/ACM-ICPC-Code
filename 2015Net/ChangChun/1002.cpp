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
// Created Time  : 2015年09月13日 星期日 09时37分20秒
// File Name     : 1002.cpp

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

const int MaxM=100005;
const int MaxN=100004;

struct Edge
{
	int to,next;
};

Edge E[MaxM<<1];
int head[MaxN],Ecou;
long long sum;
int du[MaxN];

void init()
{
	Ecou=0;
	memset(du,0,sizeof(du));
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	++du[v];
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int N,M;
long long remV[MaxN];
bool vis[MaxN];

void remove(int u)
{
	vis[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(vis[E[i].to]==0)
		{
			--du[E[i].to];
			if(du[E[i].to]<=1)
				remove(E[i].to);
		}
}

queue <int> que;

long long bfs(int u)
{
	int v;
	while(!que.empty())
		que.pop();

	que.push(u);
	vis[u]=1;
	int cou=1;
	long long ret=remV[u];

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		for(int i=head[u];i!=-1;i=E[i].next)
			if(vis[E[i].to]==0)
			{
				vis[E[i].to]=1;
				++cou;
				ret+=remV[E[i].to];
				que.push(E[i].to);
			}
	}

	if(cou&1)
		return ret;
	else return 0;
}

long long getans()
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=N;++i)
	{
		if(vis[i]==0 && du[i]<=1)
			remove(i);
	}

	long long ret=0;

	for(int i=1;i<=N;++i)
		if(vis[i]==0)
			ret+=bfs(i);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		sum=0;
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
		{
			scanf("%I64d",&remV[i]);
			sum+=remV[i];
		}
		init();

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		printf("%I64d\n",getans());
	}
	
	return 0;
}
