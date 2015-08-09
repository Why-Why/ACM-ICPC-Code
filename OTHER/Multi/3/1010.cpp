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
// Created Time  : 2015年07月28日 星期二 16时17分39秒
// File Name     : 1010.cpp

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

struct node
{
	int id;
	int val;

	node() {}
	node(int a,int b)
	{
		id=a;
		val=b;
	}

	bool operator < (const node &b) const
	{
		return val>b.val;
	}
};

struct Edge
{
	int to,next;
};

node dian[MaxN];
Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N,a,b;

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

int vis[MaxN],flag=1;
priority_queue <node> que;
int rem[MaxN];
int inque[MaxN],flag1=1;

int bfs(int u)
{
	++flag1;

	while(!que.empty())
		que.pop();

	int t;
	int ret=0;
	node temp;
	
	que.push(dian[u]);

	while(!que.empty())
	{
		temp=que.top();
		que.pop();
		u=temp.id;

		if(inque[u]==flag1)
			continue;
		
		++ret;
		vis[u]=flag;
		inque[u]=flag1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(inque[dian[rem[E[i].to]].id]!=flag1 && dian[rem[E[i].to]].val>temp.val)
				que.push(dian[rem[E[i].to]]);
	}

	return ret;
}

int getans()
{
	int ret=0;

	++flag;

	for(int i=N;i>=1;--i)
		if(vis[i]!=flag)
		{
			ret=max(ret,bfs(i));

			if(ret>=i)
				break;
		}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	srand(time(0));

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
		{
			scanf("%d",&dian[i].val);
			dian[i].id=i;
		}

		init();

		sort(dian+1,dian+N+1);

		for(int i=1;i<=N;++i)
			rem[dian[i].id]=i;

		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		printf("%d\n",getans());
	}
	
	return 0;
}
