#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>

#define min(a,b) (a<b ? a:b)

using namespace std;

const int INF=10e8;
const int MaxN=1010;

struct Node
{
	int v,val;

	Node(int _v=0,int _val=0):v(_v),val(_val) {}
	bool operator < (const Node &a) const
	{
		return val<a.val;
	}
};

struct Edge
{
	int v,cost;

	Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};

vector <Edge> E[MaxN];
bool vis[MaxN];

void Dijkstra(int lowcost[],int n,int start)
{
	priority_queue <Node> que;
	Node qtemp;
	int len;
	int u,v,cost;

	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
		lowcost[i]=0;
	}
	lowcost[start]=INF;

	que.push(Node(start,INF));

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

			if(!vis[v] && min(cost,lowcost[u])>lowcost[v])
			{
				lowcost[v]=min(cost,lowcost[u]);
				que.push(Node(v,lowcost[v]));
			}
		}
	}
}

inline void addEdge(int u,int v,int c)
{
	E[u].push_back(Edge(v,c));
}

int ans[MaxN];

int main()
{
//	ios::sync_with_stdio(false);

	int N,M;
	int a,b,c;
	int T;

	scanf("%d",&T);

	for(int cas=1;cas<=T;++cas)
	{
		scanf("%d %d",&N,&M);

		for(int i=1;i<=N;++i)
			E[i].clear();

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&a,&b,&c);

			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		Dijkstra(ans,N,1);

		printf("Scenario #%d:\n",cas);
		printf("%d\n\n",ans[N]);
	}

	return 0;
}
