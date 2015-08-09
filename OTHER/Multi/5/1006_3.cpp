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
// Created Time  : 2015年08月05日 星期三 09时14分40秒
// File Name     : 1006_3.cpp

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

const int MaxN=100005;
const int MaxM=300005;

struct Edge
{
	int to,next,pre;
	int id;
	bool zheng;
};

Edge E[MaxM<<1];
int head[MaxN],Ecou;

int ans[MaxM];
bool nvis[MaxN];
int N,M;

bool Evis[MaxM<<1];

void init(int N)
{
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		nvis[i]=0;
		head[i]=-1;
	}
}

void addEdge(int u,int v,int id,bool zheng)
{
	Evis[Ecou]=0;
	E[Ecou].pre=-1;
	
	if(head[u]!=-1)
		E[head[u]].pre=Ecou;

	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].zheng=zheng;
	E[Ecou].id=id;
	head[u]=Ecou++;
}

void xiaobian(int x,int u)
{
	Evis[x]=1;

	if(E[x].pre==-1)
		head[u]=E[x].next;
	else
		E[E[x].pre].next=E[x].next;
	E[E[x].next].pre=E[x].pre;
}

void dfs(int u,int type)
{
	int t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(Evis[i]==0)
		{
			t=head[u];
			ans[E[t].id]=E[t].zheng ? type : 1-type;
			xiaobian(t,u);
			xiaobian(t^1,E[t].to);
			dfs(E[t].to,type);

			break;
		}
}

void getans()
{
	int t;

	for(int u=1;u<=N;++u)
	{
		t=1;
		for(int i=head[u];i!=-1;i=E[i].next)
			if(Evis[i]==0)
			{
				ans[E[i].id]=E[i].zheng ? t : 1-t;
				xiaobian(i,u);
				xiaobian(i^1,E[i].to);
				dfs(E[i].to,t);
				t=1-t;
			}
	}
}

int main()
{
	//freopen("out.txt","w",stdout);

	int T,a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init(N);

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			if(a==b)
			{
				ans[i]=1;
				continue;
			}
			ans[i]=-1;
			addEdge(a,b,i,1);
			addEdge(b,a,i,0);
		}

		getans();

		for(int i=1;i<=M;++i)
			printf("%d\n",ans[i]);
	}
	
	return 0;
}
