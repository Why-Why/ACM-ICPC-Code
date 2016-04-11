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
// Created Time  : 2016年04月01日 星期五 16时44分04秒
// File Name     : SAMER08A.cpp

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

const int MaxN=505;
const int MaxM=10004;
const int INF=0x3f3f3f3f;

struct Node
{
	int v,val;

	Node(int _v=0,int _val=0):v(_v),val(_val) {}
	bool operator < (const Node &a) const
	{
		return val>a.val;
	}
};

struct Edge
{
	int v,cost;
	int id;

	Edge(int _v=0,int _cost=0,int _id=0):v(_v),cost(_cost),id(_id) {}
};

vector <Edge> E[MaxN],FE[MaxN];
bool vis[MaxN];

bool cvis[MaxM];
int idcou;

void Dijkstra(int lowcost[],int n,int start)
{
	priority_queue <Node> que;
	Node qtemp;
	int len;
	int u,v,cost;

	for(int i=1;i<=n;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
	}
	lowcost[start]=0;

	que.push(Node(start,0));

	while(!que.empty())
	{
		qtemp=que.top();
		que.pop();

		u=qtemp.v;

		if(vis[u])
			continue;

		vis[u]=1;

		len=E[u].size();

		for(int i=0;i<len;++i)
		{
			v=E[u][i].v;
			cost=E[u][i].cost;

			if(cvis[E[u][i].id]) continue;

			if(!vis[v] && lowcost[v]>lowcost[u]+cost)
			{
				lowcost[v]=lowcost[u]+cost;
				que.push(Node(v,lowcost[v]));
			}
		}
	}
}

inline void addEdge(int u,int v,int c)
{
	++idcou;
	E[u].push_back(Edge(v,c,idcou));
	FE[v].push_back(Edge(u,c,idcou));
}

inline void init(int N) {
	idcou=0;
	memset(cvis,0,sizeof(cvis));
	for(int i=1;i<=N;++i) E[i].clear(),FE[i].clear();
}

int N,M;
int lowcost[MaxN];
int S,T;

void bfs() {
	queue <int> que;
	que.push(T);
	int u,v,c,len;

	while(!que.empty()) {
		u=que.front();
		que.pop();

		len=FE[u].size();
		for(int i=0;i<len;++i) {
			v=FE[u][i].v;
			c=FE[u][i].cost;
			if(lowcost[v]+c!=lowcost[u]) continue;
			cvis[FE[u][i].id]=1;
			que.push(v);
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	while(~scanf("%d %d",&N,&M) && N+M) {
		scanf("%d %d",&S,&T);
		++S; ++T;
		init(N);
		while(M--) {
			scanf("%d %d %d",&a,&b,&c);
			++a; ++b;
			addEdge(a,b,c);
		}
		Dijkstra(lowcost,N,S);
		bfs();
		Dijkstra(lowcost,N,S);
		printf("%d\n",lowcost[T]==INF ? -1 : lowcost[T]);
	}
	
	return 0;
}
