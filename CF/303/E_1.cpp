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
// Created Time  : 2015年05月21日 星期四 19时26分12秒
// File Name     : E_1.cpp

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

const int MaxN=300005;
const int MaxM=300005;
const long long INF=1000000000000000LL;

struct Node
{
	int id;
	long long val;

	Node(int a=0,long long b=0)
	{
		id=a;
		val=b;
	}

	bool operator < (const Node &b) const
	{
		return val>b.val;
	}
};

struct Edge
{
	int next,to;
	long long cost;
	int id;
};

Edge E[MaxM*2];
int head[MaxN],Ecou;

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v,long long cost,int d)
{
	E[Ecou].cost=cost;
	E[Ecou].id=d;
	E[Ecou].next=head[u];
	E[Ecou].to=v;
	head[u]=Ecou++;
}

bool vis[MaxN];

void Dijkstra(long long lowcost[],int n,int start)
{
	priority_queue <Node> que;
	Node temp;
	int u,v;

	for(int i=1;i<=n;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
	}

	lowcost[start]=0;

	que.push(Node(start,0));

	while(!que.empty())
	{
		temp=que.top();
		que.pop();

		u=temp.id;

		if(vis[u])
			continue;

		vis[u]=1;

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(!vis[v] && lowcost[v]>lowcost[u]+E[i].cost)
			{
				lowcost[v]=lowcost[u]+E[i].cost;
				que.push(Node(v,lowcost[v]));
			}
		}
	}
}

int ans[MaxN];
int Eu[MaxM],Ev[MaxM];
long long Ec[MaxM];
long long lowcost[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,m;
	int a,b;
	long long c;

	ios::sync_with_stdio(false);

	cin>>n>>m;

	init();

	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		addEdge(a,b,c,i);
		addEdge(b,a,c,i);

		Eu[i]=a;
		Ev[i]=b;
		Ec[i]=c;
	}

	cin>>a;

	Dijkstra(lowcost,n,a);

	for(int i=1;i<=n;++i)
		ans[i]=-1;

	long long sum=0;

	for(int i=1;i<=m;++i)
		if(lowcost[Eu[i]]+Ec[i]==lowcost[Ev[i]])
		{
			if(ans[Ev[i]]==-1 || Ec[ans[Ev[i]]]>Ec[i])
				ans[Ev[i]]=i;
		}
		else if(lowcost[Ev[i]]+Ec[i]==lowcost[Eu[i]])
		{
			if(ans[Eu[i]]==-1 || Ec[ans[Eu[i]]]>Ec[i])
				ans[Eu[i]]=i;
		}

	for(int i=1;i<=n;++i)
		if(i!=a)
			sum+=Ec[ans[i]];

	cout<<sum<<endl;

	for(int i=1;i<=n;++i)
		if(i!=a)
			cout<<ans[i]<<' ';
	cout<<endl;
	
	return 0;
}
