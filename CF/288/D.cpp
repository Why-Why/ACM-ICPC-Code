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
// Created Time  : 2015年05月19日 星期二 11时27分12秒
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

struct Edge
{
	int to,next;
	int id;
};

Edge E[300005];
int head[67000],Ecou;
int vis[300005];
int rem[67000];
int frem[67000];
int N;
int ans[300005];
int anscou=0;

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v,int d)
{
	E[Ecou].id=d;
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int cha[67000];

void dfs(int u)
{
	for(int i=head[u];i!=-1;i=E[i].next)
	{
		if(vis[E[i].id]==0)
		{
			vis[E[i].id]=1;
			dfs(E[i].to);
		}

		while(vis[E[E[i].next].id])
			E[i].next=E[E[i].next].next;
	}

	ans[anscou++]=u;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	N=0;
	char s[10];
	int t;
	int a,b;

	scanf("%d",&n);

	init();

	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);

		t=s[0]*256+s[1];

		if(rem[t]==0)
			rem[t]=++N;
		a=rem[t];

		t=s[1]*256+s[2];

		if(rem[t]==0)
			rem[t]=++N;
		b=rem[t];

		addEdge(a,b,i);
		--cha[a];
		++cha[b];
	}

	for(int i=0;i<65536;++i)
		if(rem[i])
			frem[rem[i]]=i;

	int start=-1,end=-1;
	bool ok=1,ok2=1;

	for(int i=1;i<=N;++i)
	{
		if(cha[i])
			ok2=0;

		if(cha[i]==-1)
		{
			if(start==-1)
				start=i;
			else
				ok=0;
		}
		else if(cha[i]==1)
		{
			if(end==-1)
				end=i;
			else
				ok=0;
		}
	}

	if(start==-1 || end==-1)
		if(!ok2)
			ok=0;

	if(!ok)
	{
		puts("NO");
		return 0;
	}

	if(start==-1)
		start=1;

	dfs(start);

	if(anscou-1==n)
	{
		puts("YES");
		printf("%c%c",frem[ans[anscou-1]]/256,frem[ans[anscou-1]]%256);

		for(int i=anscou-2;i>=0;--i)
			printf("%c",frem[ans[i]]%256);

		puts("");
	}
	else
		puts("NO");
	
	return 0;
}
