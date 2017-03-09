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
// Created Time  : 2017年02月13日 星期一 11时20分41秒
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

const long long MaxN=1000015;
const long long INF=100000000000000000LL;

struct Node {
	long long v,val;

	Node(long long _v=0,long long _val=0):v(_v),val(_val) {}
	bool operator < (const Node &a) const {
		return val>a.val;
	}
};

struct Edge {
	int to,next;
	long long v;
};

Edge E[MaxN<<2];
int head[MaxN],Ecou;
bool vis[MaxN];

void Dijkstra(long long lowcost[],long long n,long long start) {
	priority_queue <Node> que;
	Node qtemp;
	long long len;
	long long u,v,cost;

	for(long long i=1;i<=n;++i) {
		lowcost[i]=INF;
		vis[i]=0;
	}
	lowcost[start]=0;

	que.push(Node(start,0));

	while(!que.empty()) {
		qtemp=que.top();
		que.pop();

		u=qtemp.v;

		if(vis[u]) continue;

		vis[u]=1;

		for(int i=head[u];i!=-1;i=E[i].next) {
			v=E[i].to;
			cost=E[i].v;

			if(!vis[v] && lowcost[v]>lowcost[u]+cost)
			{
				lowcost[v]=lowcost[u]+cost;
				que.push(Node(v,lowcost[v]));
			}
		}
	}
}

inline void addEdge(long long u,long long v,long long c) {
	E[Ecou].to=v;
	E[Ecou].v=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void init(int N) {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1;
}

long long ans[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,a;

	while(~scanf("%d",&N)) {
		init(N+N+2);
		for(int i=1;i<=N;++i) {
			scanf("%d",&a);
			addEdge(i<<1,N+N+2,a);
			addEdge(N+N+2,i<<1,a);
		}
		for(int i=1;i<=N;++i) {
			scanf("%d",&a);
			addEdge(i+i-1,N+N+1,a);
			addEdge(N+N+1,i+i-1,a);
		}

		scanf("%d",&a);
		addEdge(1,N+N+1,a);
		addEdge(N+N+1,1,a);

		for(int i=2;i<=N+N;++i) {
			scanf("%d",&a);
			addEdge(i-1,i,a);
			addEdge(i,i-1,a);
		}

		scanf("%d",&a);
		addEdge(N+N,N+N+2,a);
		addEdge(N+N+2,N+N,a);

		Dijkstra(ans,N+N+2,N+N+1);
		printf("%lld\n",ans[N+N+2]);
	}

	return 0;
}
