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
// Created Time  : 2015年08月09日 星期日 18时52分15秒
// File Name     : 101.cpp

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

struct Edge
{
	int id;
	int to,next;
	bool zheng;
};

Edge E[300];
int head[MaxN],Ecou;

int du[MaxN];
int ans1[300],ans2[300];
int anscou;

bool Evis[300];
bool vis[10];

void init()
{
	memset(head,-1,sizeof(head));
	memset(Evis,0,sizeof(Evis));
	Ecou=0;
}

void addEdge(int u,int v,int id,bool zheng)
{
	E[Ecou].to=v;
	E[Ecou].zheng=zheng;
	E[Ecou].id=id;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre)
{
	vis[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(Evis[i]==0)
		{
			Evis[i]=Evis[i^1]=1;
			dfs(E[i].to,i);
		}

	if(pre!=-1)
	{
		ans1[anscou]=E[pre].id;
		ans2[anscou++]=E[pre].zheng;
	}
}

bool getans()
{
	int cou=0;
	int rem;

	for(int i=1;i<=7;++i)
		if(du[i]&1 && du[i])
		{
			rem=i;
			++cou;
		}

	if(cou==0)
		for(int i=1;i<=7;++i)
			if(du[i])
				rem=i;

	if(cou>2) return 0;

	anscou=0;
	dfs(rem,-1);

	for(int i=1;i<=7;++i)
		if(du[i] && vis[i]==0)
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,a,b;

	while(~scanf("%d",&N))
	{
		init();
		memset(du,0,sizeof(du));
		memset(vis,0,sizeof(vis));

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a+1,b+1,i,1);
			addEdge(b+1,a+1,i,0);
			++du[a+1];
			++du[b+1];
		}

		if(getans())
			for(int i=N-1;i>=0;--i)
				printf("%d %c\n",ans1[i],ans2[i] ? '+' : '-');
		else
			puts("No solution");
	}
	
	return 0;
}
