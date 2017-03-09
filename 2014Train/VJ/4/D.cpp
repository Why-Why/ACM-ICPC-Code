#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int INF=10e8;
const int MaxN=1010;

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

	Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};

vector <Edge> E[2][MaxN];
bool vis[MaxN];

void Dijkstra(int type,int lowcost[],int n,int start)
{
	priority_queue <Node> que;
	Node qtemp;
	int u,v,c,len;

	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
		lowcost[i]=INF;
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
		len=E[type][u].size();

		for(int i=0;i<len;++i)
		{
			v=E[type][u][i].v;
			c=E[type][u][i].cost;

			if(!vis[v] && lowcost[u]+c<lowcost[v])
			{
				lowcost[v]=lowcost[u]+c;
				que.push(Node(v,lowcost[v]));
			}
		}
	}
}

inline void addEdge(int type,int u,int v,int c)
{
	E[type][u].push_back(Edge(v,c));
}

int ans1[MaxN],ans2[MaxN];
int maxans;

int main()
{
	int N,M,X;
	int a,b,c;

	while(~scanf("%d %d %d",&N,&M,&X))
	{
		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&a,&b,&c);

			addEdge(0,a,b,c);
			addEdge(1,b,a,c);
		}

		for(int i=1;i<=N;++i)
			ans1[i]=ans2[i]=0;
		maxans=-1;

		Dijkstra(0,ans1,N,X);
		Dijkstra(1,ans2,N,X);

		for(int i=1;i<=N;++i)
			if(ans1[i]+ans2[i]>maxans)
				maxans=ans1[i]+ans2[i];

		cout<<maxans<<endl;
	}

	return 0;
}
