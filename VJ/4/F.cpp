#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

const int INF=10e8;
const int MaxN=510;

struct Edge
{
	int v,cost;

	Edge(int _v,int _cost):v(_v),cost(_cost) {}
};

vector <Edge> E[MaxN];
bool vis[MaxN];
int couNode[MaxN];

bool SPFA(int lowcost[],int n,int start)
{
	queue <int> que;
	int u,v,c;
	int len;

	for(int i=1;i<=n;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
	}
	vis[start]=1;
	couNode[start]=1;
	lowcost[start]=0;

	que.push(start);

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		vis[u]=0;
		len=E[u].size();

		for(int i=0;i<len;++i)
		{
			v=E[u][i].v;
			c=E[u][i].cost;

			if(lowcost[u]+c<lowcost[v])
			{
				lowcost[v]=lowcost[u]+c;

				if(!vis[v])
				{
					vis[v]=1;
					++couNode[v];
					que.push(v);

					if(couNode[v]>=n)
						return 0;
				}
			}
		}
	}

	return 1;
}

inline void addEdge(int u,int v,int c)
{
	E[u].push_back(Edge(v,c));
}

int ans[MaxN];

int main()
{
	int T;
	int N,M,W;
	int a,b,c;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&N,&M,&W);

		for(int i=1;i<=N;++i)
			E[i].clear();

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&a,&b,&c);

			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		for(int i=1;i<=W;++i)
		{
			scanf("%d %d %d",&a,&b,&c);

			addEdge(a,b,-c);
		}

		if(SPFA(ans,N,1))
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
