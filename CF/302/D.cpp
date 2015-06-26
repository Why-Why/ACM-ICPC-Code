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
// Created Time  : 2015年06月01日 星期一 10时27分17秒
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

const int MaxN=3010;
const int MaxM=6010;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int N,M;
int cost[MaxN][MaxN];
int s1,t1,l1,s2,t2,l2;

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

int que[MaxN];
int first,last;

void bfs(int start)
{
	int u,v;
	int (&vis)[MaxN]=cost[start];

	que[last++]=start;
	vis[start]=0;

	while(last-first)
	{
		u=que[first++];

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(vis[v]==-1)
			{
				vis[v]=vis[u]+1;
				que[last++]=v;
			}
		}
	}
}

int getans()
{
	int ret=0x3f3f3f3f;

	int d1,d2;

	if(cost[s1][t1]<=l1 && cost[s2][t2]<=l2)
		ret=cost[s1][t1]+cost[s2][t2];

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			d1=cost[s1][i]+cost[i][j]+cost[t1][j];
			d2=cost[s2][i]+cost[i][j]+cost[t2][j];

			if(d1<=l1 && d2<=l2)
				ret=min(ret,d1+d2-cost[i][j]);

			d1=cost[s1][j]+cost[i][j]+cost[t1][i];

			if(d1<=l1 && d2<=l2)
				ret=min(ret,d1+d2-cost[i][j]);
		}

	if(ret>M)
		return -1;

	return M-ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);

	init();
	memset(cost,-1,sizeof(cost));

	int a,b;

	for(int i=0;i<M;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	scanf("%d %d %d %d %d %d",&s1,&t1,&l1,&s2,&t2,&l2);

	for(int i=1;i<=N;++i)
		bfs(i);

	printf("%d\n",getans());
	
	return 0;
}
