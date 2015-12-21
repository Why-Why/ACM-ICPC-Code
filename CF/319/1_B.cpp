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
// Created Time  : 2015年09月29日 星期二 23时16分45秒
// File Name     : 1_B.cpp

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

int num[MaxN];
int vis[MaxN];
int rem[MaxN],cou=0;
int N;

int dfs(int u,int id)
{
	int ret=1;
	vis[u]=id;
	for(int i=num[u];i!=u;i=num[i])
	{
		vis[i]=id;
		++ret;
	}
	return ret;
}

void show(int u,int p1,int p2)
{
	int t=1;
	vis[u]=0;
	printf("%d %d\n",p1,u);
	for(int i=num[u];i!=u;i=num[i])
	{
		vis[i]=0;
		t=!t;
		printf("%d %d\n",t ? p1 : p2,i);
	}
}

void getans()
{
	int cou1=0,cou2=0,couo=0;
	int r1,r2,ro;

	for(int i=1;i<=cou;++i)
		if(rem[i]==1)
		{
			++cou1;
			r1=i;
		}
		else if(rem[i]==2)
		{
			++cou2;
			r2=i;
		}
		else if(rem[i]%2==0)
		{
			ro=i;
			++couo;
		}

	if(cou1)
	{
		puts("YES");
		int p;
		for(p=1;p<=N;++p)
			if(vis[p]==r1)
				break;

		for(int i=1;i<=N;++i)
			if(i!=p)
				printf("%d %d\n",i,p);
		return;
	}

	if(cou2==0)
	{
		puts("NO");
		return;
	}

	if(cou-cou1-cou2-couo>0)
	{
		puts("NO");
		return;
	}

	int p1=-1,p2;
	for(int i=1;i<=N;++i)
		if(vis[i]==r2)
			p1=i;
	p2=num[p1];

	puts("YES");
	printf("%d %d\n",p1,p2);
	for(int i=1;i<=N;++i)
		if(vis[i] && i!=p1 && i!=p2)
			show(i,p1,p2);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",num+i);

	for(int i=1;i<=N;++i)
		if(vis[i]==0)
		{
			++cou;
			rem[cou]=dfs(i,cou);
		}

	getans();
	
	return 0;
}
