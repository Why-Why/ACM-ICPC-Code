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
// Created Time  : 2015年05月10日 星期日 19时06分48秒
// File Name     : 1129.cpp

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
	int next,to;
};

Edge E[1000];
int head[30],Ecou;
int vis[30];
int N;
int xian;

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

bool neng(int c,int u)
{
	for(int i=head[u];i!=-1;i=E[i].next)
		if(vis[E[i].to]==c)
			return 0;

	return 1;
}

bool dfs(int u)
{
	int v;
	bool ok;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(vis[v])
			continue;

		for(int k=1;k<=xian;++k)
			if(neng(k,v))
			{
				vis[v]=k;
				if(dfs(v))
					return 1;
				vis[v]=0;
			}

		return 0;
	}

	return 1;
}

bool judge(int M)
{
	memset(vis,0,sizeof(vis));
	xian=M;

	for(int i=1;i<=N;++i)
		if(vis[i]==0)
		{
			vis[i]=1;
			if(dfs(i)==0)
				return 0;
		}

	return 1;
}

int getans()
{
	int L=1,R=N,M;

	while(R>L)
	{
		M=(L+R)>>1;

		if(judge(M))
			R=M;
		else
			L=M+1;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[50];
	int ans;

	while(~scanf("%d",&N) && N)
	{
		init();
		
		for(int i=1;i<=N;++i)
		{
			scanf("%s",s);
			for(int j=2;s[j];++j)
				addEdge(i,s[j]-'A'+1);
		}

		ans=getans();

		printf("%d",ans);

		if(ans==1)
			puts(" channel needed.");
		else
			puts(" channels needed.");
	}
	
	return 0;
}
