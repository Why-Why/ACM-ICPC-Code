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
// Created Time  : 2015年11月07日 星期六 00时21分24秒
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

const int MaxN=30004;
const int INF=0x3f3f3f3f;

int N,K;

namespace TU
{

struct Edge
{
	int to,c;

	Edge(int a=0,int b=0):to(a),c(b) {}

	bool operator < (const Edge & E) const
	{
		return to<E.to;
	}
};
vector <Edge> E[MaxN];

struct Node
{
	int id,val;

	Node(int a=0,int b=0):id(a),val(b) {}

	bool operator < (const Node & b) const
	{
		return val>b.val;
	}
};

void init()
{
	for(int i=1;i<=N;++i) E[i].clear();
}

void addEdge(int u,int v,int c)
{
	E[u].push_back(Edge(v,c));
}

bool vis[MaxN];

void Dijkstra(int lowcost[])
{
	priority_queue <Node> que;
	Node temp;
	int u,len;

	for(int i=1;i<=N;++i) lowcost[i]=INF,vis[i]=0;
	que.push(Node(1,0));
	lowcost[1]=0;

	while(!que.empty())
	{
		temp=que.top();
		que.pop();
		u=temp.id;

		if(vis[u]) continue;
		vis[u]=1;
		len=E[u].size();

		for(int i=0;i<len;++i)
			if(lowcost[E[u][i].to]>lowcost[u]+E[u][i].c)
			{
				lowcost[E[u][i].to]=lowcost[u]+E[u][i].c;
				que.push(Node(E[u][i].to,lowcost[E[u][i].to]));
			}
	}
}

void process()
{
	for(int i=1;i<=N;++i)
		sort(E[i].begin(),E[i].end());
}

}

int lowcost[MaxN];
bool vis1[MaxN];

struct Edge
{
	int to,next,c;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int sumnode,rsize[MaxN];
bool vis[MaxN];

int ans;
long long anscou;

void init()
{
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		vis[i]=vis1[i]=0;
	}
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].c=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u)
{
	vis1[u]=1;
	int len=TU::E[u].size();
	for(int i=0;i<len;++i)
		if(!vis1[TU::E[u][i].to] && lowcost[TU::E[u][i].to]==lowcost[u]+TU::E[u][i].c)
		{
			addEdge(u,TU::E[u][i].to,TU::E[u][i].c);
			addEdge(TU::E[u][i].to,u,TU::E[u][i].c);
			dfs(TU::E[u][i].to);
		}
}

/////////////////

int cen,minn;

int dfsC(int u,int pre)
{
	int sum=1,t;
	int maxn=0;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
		{
			t=dfsC(E[i].to,u);
			maxn=max(maxn,t);
			sum+=t;
		}
	maxn=max(maxn,sumnode-sum);
	if(maxn<minn) { minn=maxn; cen=u; }

	return sum;
}

int getCenter(int u)
{
	minn=0x3f3f3f3f;
	dfsC(u,-1);
	return cen;
}

/////////////////////

int cvis[MaxN],flag=1;
int maxn[MaxN],cou[MaxN];

int num[MaxN],dep[MaxN],len;

int dfsc(int u,int pre,int dis,int dep1)
{
	num[len]=dis;
	dep[len++]=dep1;

	int sum=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			sum+=dfsc(E[i].to,u,dis+E[i].c,dep1+1);
	return sum;
}

void getnum()
{
	for(int i=0;i<len;++i)
		if(dep[i]<=K && cvis[K-dep[i]]==flag)
		{
			if(num[i]+maxn[K-dep[i]]>ans)
			{
				ans=num[i]+maxn[K-dep[i]];
				anscou=cou[K-dep[i]];
			}
			else if(num[i]+maxn[K-dep[i]]==ans)
				anscou+=cou[K-dep[i]];
		}
}

void merge()
{
	for(int i=0;i<len;++i)
		if(cvis[dep[i]]!=flag)
			cvis[dep[i]]=flag,maxn[dep[i]]=num[i],cou[dep[i]]=1;
		else
		{
			if(num[i]>maxn[dep[i]]) maxn[dep[i]]=num[i],cou[dep[i]]=1;
			else if(num[i]==maxn[dep[i]]) ++cou[dep[i]];
		}
}

void calc(int u)
{
	++flag;
	cvis[0]=flag;
	maxn[0]=0;
	cou[0]=1;
	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			len=0;
			rsize[j++]=dfsc(E[i].to,u,E[i].c,1);
			getnum();
			merge();
		}
}

void getans(int u)
{
	int c=getCenter(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			sumnode=rsize[j++];
			getans(E[i].to);
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int M,a,b,c;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&N,&M,&K);
		--K;
		TU::init();
		while(M--)
		{
			scanf("%d %d %d",&a,&b,&c);
			TU::addEdge(a,b,c);
			TU::addEdge(b,a,c);
		}
		TU::process();
		TU::Dijkstra(lowcost);
		init();
		dfs(1);

		sumnode=N;
		ans=0;
		getans(1);

		printf("%d %I64d\n",ans,anscou);
	}
	
	return 0;
}
