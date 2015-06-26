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
// Created Time  : 2015年06月04日 星期四 22时42分23秒
// File Name     : D_1.cpp

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
const int MaxM=7000;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int N,M;
int s1,t1,l1,s2,t2,l2;
int cost[MaxN][MaxN];

void init()
{
	memset(cost,-1,sizeof(cost));
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

void bfs(int s)
{
	int u;
	int v;

	first=last=0;

	que[last++]=s;
	cost[s][s]=0;

	while(last-first)
	{
		u=que[first++];

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(cost[s][v]==-1)
			{
				cost[s][v]=cost[s][u]+1;
				que[last++]=v;
			}
		}
	}
}

int getans()
{
	if(cost[s1][t1]>l1 || cost[s2][t2]>l2)
		return -1;

	int ret=cost[s1][t1]+cost[s2][t2];
	int d1,d2;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			d1=cost[s1][i]+cost[i][j]+cost[j][t1];
			d2=cost[s2][i]+cost[i][j]+cost[j][t2];

			if(d1<=l1 && d2<=l2)
				ret=min(ret,d1+d2-cost[i][j]);

			d1=cost[s1][j]+cost[i][j]+cost[i][t1];

			if(d1<=l1 && d2<=l2)
				ret=min(ret,d1+d2-cost[i][j]);
		}

	return M-ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&N,&M);

	init();

	for(int i=1;i<=M;++i)
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
