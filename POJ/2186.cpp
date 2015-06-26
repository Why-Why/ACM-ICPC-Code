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
// Created Time  : 2015年06月23日 星期二 22时35分12秒
// File Name     : 2186.cpp

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
const int MaxM=50005;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int Stack[MaxN],top;
int Belong[MaxN],lfcou;
int Index;
int DFN[MaxN],LOW[MaxN];
bool inStack[MaxN];

void Tarjan(int u)
{
	int v;

	DFN[u]=LOW[u]=++Index;
	Stack[top++]=u;
	inStack[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(!DFN[v])
		{
			Tarjan(v);
			LOW[u]=min(LOW[u],LOW[v]);
		}
		else if(inStack[v] && LOW[u]>LOW[v])
			LOW[u]=LOW[v];
	}

	if(LOW[u]==DFN[u])
	{
		++lfcou;

		do
		{
			v=Stack[--top];
			inStack[v]=0;
			Belong[v]=lfcou;

		}while(v!=u);
	}
}

void getSCC(int N)
{
	for(int i=1;i<=N;++i)
		if(!DFN[i])
			Tarjan(i);
}

void init(int N)
{
	Ecou=0;
	Index=0;
	lfcou=0;
	top=0;

	for(int i=1;i<=N;++i)
	{
		inStack[i]=0;
		Belong[i]=0;
		head[i]=-1;
		DFN[i]=0;
	}
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool chu[MaxN];

int getans(int N)
{
	int rem=-1,v;

	memset(chu,0,sizeof(chu));

	for(int u=1;u<=N;++u)
		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(Belong[v]!=Belong[u])
				++chu[Belong[u]];
		}

	for(int i=1;i<=lfcou;++i)
		if(chu[i]==0)
			if(rem!=-1)
				return 0;
			else
				rem=i;

	int cou=0;

	for(int i=1;i<=N;++i)
		if(Belong[i]==rem)
			++cou;

	return cou;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M,a,b;

	while(~scanf("%d %d",&N,&M))
	{
		init(N);

		while(M--)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
		}

		getSCC(N);
		printf("%d\n",getans(N));
	}
	
	return 0;
}
