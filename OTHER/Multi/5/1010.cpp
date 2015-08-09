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
// Created Time  : 2015年08月05日 星期三 18时25分38秒
// File Name     : 1010.cpp

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

const int MaxN=750;
const int INF=0x3f3f3f3f;
const int MaxM=200000;

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM<<1];
int Ecou,head[MaxN];

int S,T;
int pre[MaxN];

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=0;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

int zans[210];
int nvis[MaxN],flag1=0;

bool dfs(int u)
{
	nvis[u]=flag1;
	if(u==T)
		return 1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].cap>E[i].flow && nvis[E[i].to]!=flag1)
		{
			pre[E[i].to]=i;
			if(dfs(E[i].to))
				return 1;
		}

	return 0;
}

int chuli()
{
	int minn=INF;
	int u=T;
	int i;

	while(u!=S)
	{
		i=pre[u];
		minn=min(minn,E[i].cap-E[i].flow);
		u=E[i^1].to;
	}

	u=T;

	while(u!=S)
	{
		i=pre[u];
		E[i].flow+=minn;
		E[i^1].flow-=minn;
		u=E[i^1].to;
	}

	return minn;
}

void getans(int N,int cou)
{
	int ans=0;

	pre[S]=-1;
	++flag1;
	while(dfs(S))
		ans+=chuli(),++flag1;

	printf("%d\n",ans);
	for(int i=head[S];i!=-1;i=E[i].next)
		if(E[i].to>N+2)
			zans[E[i].to-N-2]=E[i].flow;

	printf("%d",zans[1]);
	for(int i=2;i<=cou;++i)
		printf(" %d",zans[i]);
	puts("");
}

bool map1[210][210];
int que[300],first,last;
int vis[300],flag=0;

void jiejue(int N,int u,int cou)
{
	int t;

	first=last=0;
	++flag;
	vis[u]=flag;
	que[last++]=u;

	while(last-first)
	{
		t=que[first++];
		addEdge(cou,t,1);

		for(int i=1;i<=N;++i)
			if(vis[i]!=flag && map1[t][i])
				que[last++]=i,vis[i]=flag;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Tcase,a,b,c,d;
	int N,M,K,cou;

	scanf("%d",&Tcase);

	while(Tcase--)
	{
		scanf("%d %d %d",&N,&M,&K);
		init();
		cou=N+3;
		S=N+1;
		T=N+2;
		memset(map1,0,sizeof(map1));

		for(int i=1;i<=N;++i)
		{
			map1[i][i]=1;
			addEdge(i,T,1);
		}

		for(int i=1;i<=M;++i)
		{
			scanf("%d",&a);
			if(a==1)
			{
				addEdge(S,cou,K);
				scanf("%d",&b);
				jiejue(N,b,cou);
				++cou;
			}
			else if(a==2)
			{
				scanf("%d %d",&a,&b);
				map1[a][b]=map1[b][a]=1;
			}
			else
			{
				scanf("%d",&b);
				while(b--)
				{
					scanf("%d %d",&c,&d);
					map1[d][c]=map1[c][d]=0;
				}
			}
		}

		getans(N,cou-N-3);
	}
	
	return 0;
}
