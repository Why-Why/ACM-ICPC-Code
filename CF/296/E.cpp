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
// Created Time  : 2015年05月31日 星期日 22时15分31秒
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

const int MaxN=100005;
const int MaxM=400005;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int N,M;
int zong[MaxN],ru[MaxN],chu[MaxN];
int cou,ansa[600000],ansb[600000];

void init()
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

int que[MaxN];
int first,last;
int vis[MaxN];

void chuli(int u,int type)
{
	int v;

	if((type==1 && (ru[u] & 1)))


	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(vis[v])
			continue;

		if((type==1 && (ru[u] & 1)==0) || (type==-1 && (chu[u] & 1)==0))
		{
			ansa[cou]=u;
			ansb[cou++]=v;
			++chu[u];
			++ru[v];
		}
		else
		{
			ansa[cou]=v;
			ansb[cou++]=u;
			++ru[u];
			++chu[v];
		}

		vis[v]=-type;
		que[last++]=v;
	}
}

void bfs(int start)
{
	int u;
	first=last=0;

	vis[start]=1;
	que[last++]=start;
	
	while(last-first)
	{
		u=que[first++];
		chuli(u,vis[u]);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int rem=-1;

	scanf("%d %d",&N,&M);

	init();

	while(M--)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);

		++zong[a];
		++zong[b];
	}

	for(int i=1;i<=N;++i)
		if(zong[i] & 1)
		{
			if(rem==-1)
				rem=i;
			else
			{
				addEdge(rem,i);
				addEdge(i,rem);
				rem=-1;
			}
		}

	bfs(1);

	printf("%d\n",cou);

	for(int i=0;i<cou;++i)
		printf("%d %d\n",ansa[i],ansb[i]);
	
	return 0;
}
