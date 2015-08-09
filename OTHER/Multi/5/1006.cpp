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
// Created Time  : 2015年08月04日 星期二 13时37分15秒
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
int N,M;

bool Evis[MaxM<<1];
int ans[MaxM];

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v,int id,bool zheng)
{
	Evis[Ecou]=0;
	E[Ecou].to=v;
	E[Ecou].zheng=zheng;
	E[Ecou].id=id;
	E[Ecou].next=head[u];

	if(head[u]!=-1)
		E[head[u]].pre=Ecou;

	E[Ecou].pre=-1;
	head[u]=Ecou++;
}

int vis[MaxN],flag=0;
int nvis[MaxN];
int cou=1;
int fa[MaxN],remfa[MaxN];

void xiaoqu(int u,int v)
{
	while(u!=v)
	{
		Evis[remfa[u]]=Evis[remfa[u]^1]=1;
		ans[E[remfa[u]].id]=E[remfa[u]].zheng ? 1 : 0;
		u=fa[u];
	}

	cout<<v<<endl;
}

void dfs1(int u,int pre,int pid)
{
	int v;

	fa[u]=pre;
	remfa[u]=pid;
	nvis[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(Evis[i]==0 && i!=pid && (i^1)!=pid)
		{
			v=E[i].to;
			if(nvis[v])
			{
				xiaoqu(u,v);
				ans[E[i].id]=E[i].zheng ? 1 : 0;
				Evis[i]=Evis[i^1]=1;
			}

			if(nvis[v]==0)
				dfs1(v,u,i);
		}
}

void xiaoquan()
{
	int a,b,c;
	memset(nvis,0,sizeof(nvis));
	cou=1;

	for(int i=1;i<=N;++i)
		if(nvis[i]==0)
		{
			dfs1(i,i,-1);
		}
}

void dfs(int u,int t,int pre)
{
	cout<<u<<' '<<pre<<endl;

	vis[u]=flag;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(Evis[i]==0 && E[i].to!=pre)
		{
			ans[E[i].id]=E[i].zheng ? t : 1-t;
			dfs(E[i].to,1-t,u);
			t=1-t;
		}
}

void getans()
{
	++flag;
	for(int i=1;i<=N;++i)
		if(vis[i]!=flag)
			dfs(i,1,-1);
}

int main()
{
//	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init();
		memset(ans,-1,sizeof(ans));

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			if(a==b)
			{
				ans[i]=1;
				continue;
			}
			addEdge(a,b,i,1);
			addEdge(b,a,i,0);
		}

		xiaoquan();
		getans();

//		for(int i=1;i<=M;++i)
//			printf("%d\n",ans[i]);
	}
	
	return 0;
}
