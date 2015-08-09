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
// Created Time  : 2015年08月01日 星期六 11时10分07秒
// File Name     : 1741.cpp

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

const int MaxN=10004;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next,cost;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N,K;

bool vis[MaxN<<1];

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].cost=c;
	head[u]=Ecou++;
}

struct state
{
	int dep,belong;

	bool operator < (const state &b) const
	{
		return dep<b.dep;
	}
};

state sta[MaxN];
int cou;
int dep[MaxN],size[MaxN],belong[MaxN];
int dp[MaxN],rem[MaxN];

void dfs2(int u,int pre,int d)
{
	dep[u]=d;

	if(pre!=-1 && belong[pre]==-1)
		belong[u]=u;
	else if(pre!=-1)
		belong[u]=belong[pre];
	
	sta[cou].belong=belong[u];
	sta[cou++].dep=dep[u];

	for(int i=head[u];i!=-1;i=E[i].next)
		if(vis[i]==0 && E[i].to!=pre)
			dfs2(E[i].to,u,d+E[i].cost);
}

int BaseN;

void dfs1(int u,int pre)
{
	int maxn=0,minn=INF;
	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(vis[i]==0 && E[i].to!=pre)
		{
			v=E[i].to;
			dfs1(v,u);
			maxn=max(maxn,size[v]);

			if(dp[v]<minn)
			{
				minn=dp[v];
				rem[u]=rem[v];
			}
		}

	maxn=max(maxn,BaseN-size[u]);

	if(maxn<minn)
	{
		minn=maxn;
		rem[u]=u;
	}

	dp[u]=minn;
}

int dfs(int u,int pre)
{
	size[u]=0;
	
	for(int i=head[u];i!=-1;i=E[i].next)
		if(vis[i]==0 && E[i].to!=pre)
			size[u]+=dfs(E[i].to,u);

	return size[u]+1;
}

int findZhong(int u)
{
	dfs(u,-1);
	BaseN=size[u];
	dfs1(u,-1);

	return rem[u];
}

bool cmp(const state &a,const state &b)
{
	if(a.belong==b.belong)
		return a.dep<b.dep;
	return a.belong<b.belong;
}

long long count(state *sta,int N)
{
	long long ret=0;
	int p1=0,p2=N-1;

	for(p2=N-1;p2>=0;--p2)
	{
		while(p1<N && sta[p1].dep+sta[p2].dep<=K)
			++p1;

		if(p1>p2)
			ret+=p2;
		else
			ret+=p1;
	}

	return ret;
}

long long getnum()
{
	long long ret=0;
	int rem=0;

	sort(sta,sta+cou);
	
	ret+=count(sta,cou);

	sort(sta,sta+cou,cmp);
	sta[cou].belong=sta[cou-1].belong+1;

	for(int i=0;i<=cou;++i)
		if(sta[i].belong!=sta[rem].belong)
		{
			ret-=count(sta+rem,i-rem);
			rem=i;
		}

	return ret;
}

long long getans(int u)
{
	long long ret=0;
	cou=0;
	int zhong=findZhong(u);
	
	belong[zhong]=-1;
	dfs2(zhong,-1,0);
	ret+=getnum();

	for(int i=head[zhong];i!=-1;i=E[i].next)
		if(vis[i]==0)
		{
			vis[i]=vis[i^1]=1;
			ret+=getans(E[i].to);
		}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	while(~scanf("%d %d",&N,&K) && N+K)
	{
		init();

		for(int i=1;i<N;++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		printf("%lld\n",getans(1));
	}
	
	return 0;
}
