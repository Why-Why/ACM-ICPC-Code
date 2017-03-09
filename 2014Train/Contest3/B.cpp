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
// Created Time  : 2015年10月11日 星期日 22时40分22秒
// File Name     : B.cpp

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

const int MaxN=200005;
const int MaxM=MaxN<<1;

//////////////////////////////////////////////////////

namespace TU
{

struct Edge
{
	int u;
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int LOW[MaxN],DFN[MaxN];
int couBridge;
bool bridge[MaxM],cutp[MaxN];
int add_block[MaxN];		// The number of bolcks that is added by deleting a point.(not the number of blocks of this new graph!!!)
int Index;

struct newEdge
{
	int u,v,num;

	newEdge(int _u=0,int _v=0,int _num=0):u(_u),v(_v),num(_num) {};

	bool operator < (const newEdge &a) const
	{
		if(u==a.u)
			return v<a.v;

		return u<a.u;
	}

	bool operator == (const newEdge &a) const
	{
		return u==a.u && v==a.v;
	}
};

bool chongE[MaxM];			// Parallel edge.
newEdge remE[MaxM];

void Tarjan(int u,int pre)
{
	int v;
	int couSon=0;

	LOW[u]=DFN[u]=++Index;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)			// !!!
			continue;

		if(!DFN[v])
		{
			++couSon;
			Tarjan(v,u);

			if(LOW[v]<LOW[u])
				LOW[u]=LOW[v];

			if(DFN[u]<LOW[v] && !chongE[i])
			{
				bridge[i]=1;
				bridge[i^1]=1;		//
				++couBridge;
			}
			if(u!=pre && DFN[u]<=LOW[v])
			{
				cutp[u]=1;
				++add_block[u];
			}
		}
		else if(DFN[v]<LOW[u])
			LOW[u]=DFN[v];
	}

	if(u==pre && couSon>1)
	{
		cutp[u]=1;
		add_block[u]=couSon-1;
	}
}

void getCUTP(int n)
{
	sort(remE,remE+Ecou);

	for(int i=1;i<Ecou;++i)
		if(remE[i]==remE[i-1])
			chongE[remE[i].num]=chongE[remE[i-1].num]=1;

	for(int i=1;i<=n;++i)
		if(!DFN[i])
			Tarjan(i,i);
}

void addEdge(int u,int v)
{
	E[Ecou].u=u;
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	bridge[Ecou]=0;

	chongE[Ecou]=0;
	remE[Ecou]=newEdge(u,v,Ecou);

	head[u]=Ecou++;
}

void init(int n)
{
	Ecou=couBridge=Index=0;

	for(int i=1;i<=n;++i)
	{
		head[i]=-1;
		cutp[i]=DFN[i]=add_block[i]=0;
	}
}

};

//////////////////////////////////

int belong[MaxN];
int vis[MaxN];
int N;
int TN;
int Q;

namespace TREE
{
	
const int LOG=20;

struct Edge
{
	int next,to;
};

Edge E[MaxN*2];
int head[MaxN],Ecou;

int dep[MaxN];
int par[MaxN][LOG];

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].next=head[u];
	E[Ecou].to=v;
	head[u]=Ecou++;
}

int que[MaxN];
int first,last;

void BFS(int root,int VI)
{
	int t,v;

	first=last=0;
	dep[root]=1;
	par[root][0]=root;
	que[last++]=root;

	vis[root]=VI;

	while(last-first)
	{
		t=que[first++];

		for(int i=1;i<LOG;++i)
			par[t][i]=par[par[t][i-1]][i-1];

		for(int i=head[t];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(v==par[t][0])
				continue;

			dep[v]=dep[t]+1;
			par[v][0]=t;
			que[last++]=v;

			vis[v]=VI;
		}
	}
}

int query(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);

	for(int det=dep[u]-dep[v],i=0;det;det>>=1,++i)
		if(det&1)
			u=par[u][i];

	if(u==v)
		return u;

	for(int i=LOG-1;i>=0;--i)
		if(par[u][i]!=par[v][i])
		{
			u=par[u][i];
			v=par[v][i];
		}

	return par[u][0];
}

// -------------

int rem1[MaxN],rem2[MaxN];
int sum1[MaxN],sum2[MaxN];
bool tvis[MaxN];

bool dfs111(int u,int pre)
{
	tvis[u]=1;

	sum1[u]=rem1[u];
	sum2[u]=rem2[u];

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			if(dfs111(E[i].to,u)==0) return 0;
			sum1[u]+=sum1[E[i].to];
			sum2[u]+=sum2[E[i].to];
		}

	if(sum1[u]>0 && sum2[u]>0 && pre!=-1) return 0;
	return 1;
}

bool judge()
{
	int a,b;
	int c;
	int VI=0;

	for(int i=1;i<=N;++i)
		if(!vis[i])
			BFS(i,++VI);

	while(Q--)
	{
		scanf("%d %d",&a,&b);
		a=belong[a];
		b=belong[b];

		if(vis[a]!=vis[b]) return 0;

		if(a!=b)
		{
			c=query(a,b);
			++rem1[a];
			--rem1[c];
			++rem2[b];
			--rem2[c];
		}
	}

	for(int i=1;i<=N;++i)
		if(tvis[i]==0)
			if(!dfs111(i,-1))
				return 0;
	return 1;
}

};

///////////////////////////////////////

int que[MaxN];
int first,last;

void bfs(int u,int be)
{
	first=last=0;
	que[last++]=u;
	belong[u]=be;

	while(last-first)
	{
		u=que[first++];
		for(int i=TU::head[u];i!=-1;i=TU::E[i].next)
			if(TU::bridge[i]==0 && belong[TU::E[i].to]==0)
			{
				belong[TU::E[i].to]=be;
				que[last++]=TU::E[i].to;
			}
	}
}

void getbelong()
{
	N=0;
	for(int i=1;i<=TN;++i)
		if(!belong[i])
			bfs(i,++N);
}

void addEdge()
{
	for(int i=0;i<TU::Ecou;++i)
		if(TU::bridge[i])
			TREE::addEdge(belong[TU::E[i].u],belong[TU::E[i].to]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M;
	int a,b;

	scanf("%d %d %d",&TN,&M,&Q);

	TU::init(TN);
	while(M--)
	{
		scanf("%d %d",&a,&b);
		TU::addEdge(a,b);
		TU::addEdge(b,a);
	}
	TU::getCUTP(TN);

	getbelong();

	TREE::init();
	addEdge();

	if(TREE::judge()) puts("Yes");
	else puts("No");
	
	return 0;
}
