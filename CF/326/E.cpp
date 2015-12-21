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
// Created Time  : 2015年10月16日 星期五 19时27分09秒
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

const int MaxN=100005;
const int LOG=20;

struct Edge
{
	int next,to;
};

Edge E[MaxN*2];
int head[MaxN],Ecou;

int dep[MaxN];
int par[MaxN][LOG];

struct State
{
	int num[10];
	int size;
};

State rem[MaxN][LOG];

void Edge_init()
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

void megre(State &a,State &b,State &c)
{
	int len=min(10,b.size+c.size);
	a.size=len;
	
	for(int i=0,p1=0,p2=0;i<len;++i)
		if(p2<c.size && (p1>=b.size || c.num[p2]<b.num[p1]))
			a.num[i]=c.num[p2++];
		else
			a.num[i]=b.num[p1++];
}

void BFS(int root)
{
	int t,v;

	first=last=0;
	dep[root]=1;
	par[root][0]=root;
	que[last++]=root;

	int temp=rem[root][0].size;
	rem[root][0].size=0;

	while(last-first)
	{
		t=que[first++];

		for(int i=1;i<LOG;++i)
		{
			par[t][i]=par[par[t][i-1]][i-1];

			if(t!=root) megre(rem[t][i],rem[t][i-1],rem[par[t][i-1]][i-1]);
			else rem[t][i].size=0;
		}

		for(int i=head[t];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(v==par[t][0])
				continue;

			dep[v]=dep[t]+1;
			par[v][0]=t;
			que[last++]=v;
		}
	}

	rem[root][0].size=temp;
}

int A;

void megre1(State &a,State &b,State c)
{
	int len=min(A,b.size+c.size);
	a.size=len;

	for(int i=0,p1=0,p2=0;i<len;++i)
		if(p2<c.size && (p1>=b.size || c.num[p2]<b.num[p1]))
			a.num[i]=c.num[p2++];
		else
			a.num[i]=b.num[p1++];
}

void show(State &ans)
{
	int len=ans.size;
	len=min(A,len);

	printf("%d",len);
	for(int i=0;i<len;++i)
		printf(" %d",ans.num[i]);
	puts("");
}

void query(int u,int v)
{
	State ans;
	ans.size=0;

	if(dep[u]<dep[v])
		swap(u,v);

	for(int det=dep[u]-dep[v],i=0;det;det>>=1,++i)
		if(det&1)
		{
			megre1(ans,rem[u][i],ans);
			u=par[u][i];
		}

	if(u==v)
	{
		megre1(ans,rem[v][0],ans);
		show(ans);
		return;
	}

	for(int i=LOG-1;i>=0;--i)
		if(par[u][i]!=par[v][i])
		{
			u=par[u][i];
			v=par[v][i];

			megre1(ans,rem[v][i],ans);
			megre1(ans,rem[u][i],ans);
		}

	megre1(ans,rem[u][0],ans);
	megre1(ans,rem[v][0],ans);
	megre1(ans,rem[par[u][0]][0],ans);
	show(ans);
}

vector <int> rrr[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M,Q;
	int a,b,c;

	scanf("%d %d %d",&N,&M,&Q);
	Edge_init();
	for(int i=1;i<N;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}
	for(int i=1;i<=M;++i)
	{
		scanf("%d",&a);
		rrr[a].push_back(i);
	}

	int len;

	for(int i=1;i<=N;++i)
	{
		sort(rrr[i].begin(),rrr[i].end());
		len=min(10,(int)rrr[i].size());
		for(int j=0;j<len;++j) rem[i][0].num[j]=rrr[i][j];
		rem[i][0].size=len;
	}
	BFS(1);

	while(Q--)
	{
		scanf("%d %d %d",&a,&b,&A);
		query(a,b);
	}
	
	return 0;
}
