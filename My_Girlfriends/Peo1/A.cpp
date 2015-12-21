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
// Created Time  : 2015年09月16日 星期三 18时08分51秒
// File Name     : A.cpp

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

const int MaxN=1010;
const int MaxM=MaxN*MaxN;

const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next,c;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int LOW[MaxN],DFN[MaxN];
int couBridge;
bool bridge[MaxM];
bool chongE[MaxM];
int Index;

int map1[MaxN][MaxN];

int N,M;

void init()
{
	Ecou=0;
	couBridge=0;
	Index=0;
	memset(head,-1,sizeof(head));
	memset(DFN,0,sizeof(DFN));
}

void addEdge(int u,int v,int c,bool b)
{
	chongE[Ecou]=b;
	bridge[Ecou]=0;
	E[Ecou].to=v;
	E[Ecou].c=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void Tarjan(int u,int pre)
{
	int v;
	int couSon=0;
	LOW[u]=DFN[u]=++Index;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;
		if(v==pre) continue;
		if(!DFN[v])
		{
			++couSon;
			Tarjan(v,u);
			if(LOW[v]<LOW[u]) LOW[u]=LOW[v];
			if(DFN[u]<LOW[v] && !chongE[i])
			{
				bridge[i]=1;
				bridge[i^1]=1;
				++couBridge;
			}
		}
		else if(DFN[v]<LOW[u]) LOW[u]=DFN[v];
	}
}

int getans()
{
	int cou=0;

	for(int i=1;i<=N;++i)
		if(!DFN[i])
		{
			if(cou) return 0;
			++cou;
			Tarjan(i,i);
		}

	int ret=INF;
	for(int i=0;i<Ecou;++i)
		if(chongE[i]==0 && bridge[i])
			ret=min(ret,E[i].c);
	if(ret==INF) ret=-1;
	if(ret==0) ret=1;				// !!!
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		init();
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				map1[i][j]=INF;

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(map1[a][b]!=INF)
				map1[a][b]=-c-1;
			else map1[a][b]=c;
			map1[b][a]=map1[a][b];
		}

		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				if(map1[i][j]!=INF)
				{
					addEdge(i,j,map1[i][j],map1[i][j]<0);
					addEdge(j,i,map1[i][j],map1[i][j]<0);
				}

		printf("%d\n",getans());
	}
	
	return 0;
}
