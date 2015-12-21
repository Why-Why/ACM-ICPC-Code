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
// Created Time  : 2015年09月10日 星期四 16时07分57秒
// File Name     : C.cpp

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

int N,M;
int belong[MaxN][2];
int ans[MaxN];
int cou=0;
int vis[MaxN];

inline int sgn(int x)
{
	return x<0 ? -1 : x>0;
}

struct Edge
{
	int to,next;
	int id;
};

Edge E[MaxN<<2];
int head[MaxN],Ecou;

bool Evis[MaxN<<2];

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v,int id)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].id=id;
	head[u]=Ecou++;
}

bool dfs(int x)
{
	if(vis[x]) return 1;
	vis[x]=1;

	int t;

	for(int i=head[x];i!=-1;i=E[i].next)
		if(Evis[i]==0)
		{
			if(E[i].to==x || sgn(E[i].id)!=sgn(E[i^1].id))
				Evis[i]=Evis[i^1]=1;
			else Evis[i]=1;
			t=abs(E[i].id);
			if(sgn(E[i].id)>=0) ans[t]=1;
			else ans[t]=0;
			if(dfs(E[i].to))
				return 1;
			ans[t]=-1;
			if(E[i].to==x || sgn(E[i].id)!=sgn(E[i^1].id))
				Evis[i]=Evis[i^1]=0;
			else Evis[i]=0;
		}

	vis[x]=0;

	return 0;
}

bool getans()
{
	for(int i=1;i<=N;++i)
		if(vis[i]==0 && dfs(i)==0)
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	memset(ans,-1,sizeof(ans));
	int k,a,t;

	scanf("%d %d",&N,&M);

	for(int i=1;i<=N;++i)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&a);
			if(a>0) t=1;
			else t=-1;
			a=abs(a);
			if(belong[a][0]) belong[a][1]=t*i;
			else belong[a][0]=t*i;
		}
	}

	init();
	int b;
	int x,y;

	for(int i=1;i<=M;++i)
	{
		if(belong[i][0]==0) continue;
		a=abs(belong[i][0]);
		b=abs(belong[i][1]);
		x=sgn(belong[i][0]);
		y=sgn(belong[i][1]);

		if(belong[i][1]==0) addEdge(a,a,x*i),addEdge(a,a,x*i);
		else
		{
			addEdge(a,b,x*i);
			addEdge(b,a,y*i);
		}
	}

	if(getans())
	{
		puts("YES");
		for(int i=1;i<=M;++i)
			if(ans[i]) printf("1");
			else printf("0");
		puts("");
	}
	else puts("NO");
	
	return 0;
}
