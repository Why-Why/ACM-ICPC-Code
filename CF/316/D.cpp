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
// Created Time  : 2015年09月10日 星期四 23时22分39秒
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

const int MaxN=500005;
const int LOG=20;

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N,M;
int dep[MaxN];
int num[MaxN];
int cdep[MaxN];
int rank[MaxN];
int par[MaxN][LOG];
char ns[MaxN];
int depcou=0;
int dian[MaxN];

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

int que[MaxN<<1];
int first,last;

void BFS(int root)
{
	int t,v,u;
	int cou=0;

	first=last=0;
	dep[root]=1;
	par[root][0]=root;
	que[last++]=root;

	while(last-first)
	{
		u=que[first++];
		for(int i=1;i<LOG;++i)
			par[u][i]=par[par[u][i-1]][i-1];

		if(dep[u]>depcou)
		{
			++depcou;
			cdep[depcou]=cou;
			t=0;
		}
		else t=num[cou-1];

		rank[u]=cou;
		dian[cou]=u;
		num[cou]=t^(1<<(ns[u]-'a'));
		++cou;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].to!=par[u][0])
			{
				v=E[i].to;
				dep[v]=dep[u]+1;
				par[v][0]=u;
				que[last++]=v;
			}
	}
	cdep[++depcou]=cou;
}

void show(int x)
{
	int num[30];
	int cou=0;

	for(int i=0;i<27;++i)
	{
		num[cou++]=x&1;
		x>>=1;
	}

	for(int i=cou-1;i>=0;--i)
		cout<<num[i];
	cout<<endl;
}

int getrank(int u,int dis)
{
	int t=0;

	while(dis)
	{
		if(dis&1)
			u=par[u][t];
		++t;
		dis>>=1;
	}

	return rank[u];
}

bool getans(int u,int d)
{
	if(dep[u]>=d) return 1;
	if(d>=depcou) return 1;

	int L=cdep[d],R=cdep[d+1]-1,M;
	int dis=d-dep[u];
	int rem1,rem2;

	while(R>L)
	{
		M=(L+R+1)>>1;

		if(getrank(dian[M],dis)<=rank[u])
			L=M;
		else R=M-1;
	}

	rem1=num[L];

	int t=rank[u]-1;
	L=cdep[d],R=cdep[d+1]-1;

	if(getrank(dian[L],dis)==rank[u])
		rem2=0;
	else
	{
		while(R>L)
		{
			M=(L+R+1)>>1;

			if(getrank(dian[M],dis)<=t)
				L=M;
			else R=M-1;
		}
		rem2=num[L];
	}

	t=rem1^rem2;
	int tcou=0;

	while(t)
	{
		if(t&1)
			++tcou;
		t>>=1;
	}

	return tcou<=1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&N,&M);

	init();
	for(int i=2;i<=N;++i)
	{
		scanf("%d",&a);
		addEdge(a,i);
		addEdge(i,a);
	}

	scanf("%s",ns+1);
	BFS(1);

	while(M--)
	{
		scanf("%d %d",&a,&b);
		if(getans(a,b)) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
