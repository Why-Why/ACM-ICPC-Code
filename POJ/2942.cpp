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
// Created Time  : 2015年06月20日 星期六 23时59分15秒
// File Name     : 2942.cpp

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

const int MaxM=1000006;
const int MaxN=1010;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int LOW[MaxN],DFN[MaxN];
int Index;

int Stack[MaxN],top;
bool InStack[MaxN];
int Belong[MaxN],Bcou;

int vis[MaxN];
int N,M;
bool ok[MaxN];
int Ncou;

int TStack[MaxN],Ttop;

bool dfs(int u,int type)
{
	int v;
	bool ok=0;

	TStack[Ttop++]=u;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(Belong[v]!=Ncou)
			continue;

		if(vis[v]==type)
			ok=1;

		if(!vis[v])
		{
			vis[v]=-type;
			
			if(dfs(v,-type))
				ok=1;
		}
	}

	return ok;
}

void Tarjan(int u,int pre)
{
	int v,tv;

	LOW[u]=DFN[u]=++Index;
	Stack[top++]=u;
	InStack[u]=1;
	
	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)
			continue;

		if(!DFN[v])
		{
			Tarjan(v,u);

			if(LOW[v]<LOW[u])
				LOW[u]=LOW[v];

			if(DFN[u]<=LOW[v])
			{
				Bcou++;

				do
				{
					tv=Stack[--top];
					Belong[tv]=Bcou;
					InStack[tv]=0;

				}while(tv!=v);

				Ncou=Bcou;
				Ttop=0;
				memset(vis,0,sizeof(vis));
				vis[u]=1;
				
				if(dfs(u,1))
				{
					ok[u]=1;
					
					while(Ttop)
						ok[TStack[--Ttop]]=1;
				}
			}
		}
		else if(DFN[v]<LOW[u])
			LOW[u]=DFN[v];
	}
}

void getCUTP(int n)
{
	for(int i=1;i<=n;++i)
		if(!DFN[i])
			Tarjan(i,i);
}

void init(int n)
{
	Index=0;
	Ecou=0;
	Bcou=0;
	top=0;
	
	for(int i=1;i<=n;++i)
	{
		head[i]=-1;
		Belong[i]=0;
		InStack[i]=0;
		DFN[i]=0;
		ok[i]=0;
	}
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}


int map1[1010][1010];
int flag;

void display()
{
	for(int i=1;i<=N;++i)
		cout<<Belong[i]<<' ' ;
}

void getans()
{
	getCUTP(N);

	int ans=0;

	for(int i=1;i<=N;++i)
		if(!ok[i])
			++ans;

	printf("%d\n",ans);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		init(N);
		++flag;

		while(M--)
		{
			scanf("%d %d",&a,&b);

			if(a!=b)
				map1[a][b]=map1[b][a]=flag;
		}

		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				if(map1[i][j]!=flag)
				{
					addEdge(i,j);
					addEdge(j,i);
				}

		getans();
	}
	
	return 0;
}
