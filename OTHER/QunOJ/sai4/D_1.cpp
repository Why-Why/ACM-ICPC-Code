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

typedef int typeM;

const int MaxN=110*110;
const int INF=10e7;					// 注意不要太大，防止溢出。

const int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

bool vis[MaxN][MaxN];
int M;

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
	lowcost[start]=0;
	couNode[start]=1;

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

			if(lowcost[v]>lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;

				if(!vis[v])
				{
					vis[v]=1;
					++couNode[v];
					que.push(v);

					if(couNode[v]>n)			//这里应该是>=，也可能是>。
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

int map1[MaxN][MaxN];
int ans[MaxN][MaxN];
int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int zans;
	int rmin,rmax;

	while(~scanf("%d",&N))
	{
		rmin=INF;
		rmax=0;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
			{
				scanf("%d",&map1[i][j]);
				rmin=min(rmin,map1[i][j]);
				rmax=max(rmax,map1[i][j]);
			}

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
			{
				addEdge(i*N+j,
			}


		zans=INF;

		for(M=rmin;M<=map1[1][1];++M)
		{
			Dijkstra(map1,ans,N);

			zans=min(zans,ans[N][N]-M);

			if(zans==0)
				break;
		}

		printf("%d\n",zans);
	}
	
	return 0;
}
