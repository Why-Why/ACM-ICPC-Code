#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

const int INF=10e8;
const int MaxN=110;

struct Edge
{
	int v;
	double R,C;

	Edge(int _v,double _R,double _C):v(_v),R(_R),C(_C) {}
};

vector <Edge> E[MaxN];
bool vis[MaxN];
int couNode[MaxN];

bool SPFA(double S,double lowcost[],int n,int start)
{
	queue <int> que;
	int u,v;
	double R,C;
	int len;

	for(int i=1;i<=n;++i)
	{
		lowcost[i]=0;
		vis[i]=0;
		couNode[i]=0;
	}
	vis[start]=1;
	couNode[start]=1;
	lowcost[start]=S;

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
			R=E[u][i].R;
			C=E[u][i].C;

			if(lowcost[u]>=C && (lowcost[u]-C)*R>=0 && (lowcost[u]-C)*R>lowcost[v])
			{
				lowcost[v]=(lowcost[u]-C)*R;

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

inline void addEdge(int u,int v,double R,double C)
{
	E[u].push_back(Edge(v,R,C));
}

double ans[MaxN];

int main()
{
	int N,M,X,u,v;
	double S,r1,r2,c1,c2;

	while(~scanf("%d %d %d %lf",&N,&M,&X,&S))
	{
		for(int i=1;i<=N;++i)
			E[i].clear();

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %lf %lf %lf %lf",&u,&v,&r1,&c1,&r2,&c2);

			addEdge(u,v,r1,c1);
			addEdge(v,u,r2,c2);
		}

		if(SPFA(S,ans,N,X))
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
