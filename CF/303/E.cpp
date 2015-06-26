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
// Created Time  : 2015年05月21日 星期四 18时55分17秒
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

struct Edge
{
	int to,next,cost,id;
};

struct node
{
	long long val;
	int id;

	node()
	{}

	node(long long a,int b)
	{
		val=a;
		id=b;
	}

	bool operator < (const node & b) const
	{
		return val>b.val;
	}
};

Edge E[700005];
int head[400005],Ecou;
const long long INF=10000000000000000LL;

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c,int d)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].id=d;
	E[Ecou].cost=c;
	head[u]=Ecou++;
}

priority_queue <node> que;
bool vis[400005];

void Dijkstra(long long lowcost[],int N,int start)
{
	int t,v;
	node temp;
	
	for(int i=1;i<=N;++i)
		lowcost[i]=INF;
	lowcost[start]=0;

	que.push(node(0,start));

	while(!que.empty())
	{
		temp=que.top();
		que.pop();

		t=temp.id;

		if(vis[t])
			continue;

		vis[t]=1;

		for(int i=head[t];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(vis[v]==0 && lowcost[t]+E[i].to<lowcost[v])
			{
				lowcost[v]=lowcost[t]+E[i].cost;
				que.push(node(lowcost[v],v));
			}
		}
	}
}

long long lowcost[400005];
long long ans[400005];
int n,m;
int que1[800005];
int Erem[800005];

void bfs(int start)
{
	int u,v;
	int first=0,last=0;
	
	for(int i=1;i<=n;++i)
	{
		ans[i]=-1;
		vis[i]=0;
	}

	que1[last++]=start;
	vis[start]=1;

	while(last-first)
	{
		u=que1[first++];

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(lowcost[u]+E[i].cost==lowcost[v])
			{
				if(ans[v]==-1 || Erem[ans[v]]>E[i].cost)
					ans[v]=E[i].id;

				if(vis[v]==0)
				{
					vis[v]=1;
					que1[last++]=v;
				}
			}
		}
	}
}

int ansnum[400005];
int cou=0;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	scanf("%d %d",&n,&m);
	init();

	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&a,&b,&c);
		addEdge(a,b,c,i);
		addEdge(b,a,c,i);
		Erem[i]=c;
	}

	scanf("%d",&a);

	Dijkstra(lowcost,n,a);
	bfs(a);

	long long sum=0;

	for(int i=1;i<=n;++i)
		if(i!=a)
		{
			sum+=Erem[ans[i]];
			ansnum[cou++]=ans[i];
		}

	cout<<sum<<endl;

	for(int i=0;i<cou;++i)
		printf("%d ",ansnum[i]);
	puts("");
	
	return 0;

	}
