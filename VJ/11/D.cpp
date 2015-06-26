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

const int MaxN=300;
const int MaxM=90000;
const int INF=10e8;

struct Edge
{
	int to,next,cap,flow,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int pre[MaxN],couNode[MaxN],lowcost[MaxN];
bool vis[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
		head[i]=-1;
}

void addEdge(int u,int v,int cap,int cost)
{
	E[Ecou].to=v;
	E[Ecou].cap=cap;
	E[Ecou].flow=0;
	E[Ecou].cost=cost;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=0;
	E[Ecou].flow=0;
	E[Ecou].cost=-cost;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

bool SPFA(int N)
{
	queue<int> que;
	int u,v,c;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
		pre[i]=-1;
	}

	vis[S]=1;
	couNode[S]=1;
	lowcost[S]=0;
	que.push(S);

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		vis[u]=0;

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			c=E[i].cost;

			if(E[i].cap>E[i].flow && lowcost[v]>lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;
				pre[v]=i;

				if(!vis[v])
				{
					vis[v]=1;
					++couNode[v];

					que.push(v);

					if(couNode[v]>N)
						return 0;
				}
			}
		}
	}

	if(pre[T]==-1)
		return 0;

	return 1;
}

void update(int remm,int &minCost)
{
	for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
	{
		E[i].flow+=remm;
		E[i^1].flow-=remm;

		minCost+=E[i].cost*remm;
	}
}

int MinCostMaxFlow(int N,int &minCost)
{
	int ret=0,remm;
	minCost=0;

	while(SPFA(N))
	{
		remm=INF;

		for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
			remm=min(remm,E[i].cap-E[i].flow);

		update(remm,minCost);

		ret+=remm;
	}

	return ret;
}

int rem1[110],rem2[110];
int cou1,cou2;
int n,m;

inline int getdis(int x,int y)
{
	int x1=rem1[x]/1000,x2=rem2[y]/1000,y1=rem1[x]%1000,y2=rem2[y]%1000;

	return abs(x1-x2)+abs(y1-y2);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[110];
	int ans;
	int N,M;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		cou1=cou2=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%s",s+1);

			for(int j=1;j<=M;++j)
				if(s[j]=='m')
					rem1[cou1++]=i*1000+j;
				else if(s[j]=='H')
					rem2[cou2++]=i*1000+j;
		}

		init(cou1+cou2+2,cou1+cou2+1,cou1+cou2+2);

		for(int i=1;i<=cou1;++i)
			addEdge(cou1+cou2+1,i,1,0);

		for(int i=1;i<=cou2;++i)
			addEdge(cou1+i,cou1+cou2+2,1,0);

		for(int i=1;i<=cou1;++i)
			for(int j=1;j<=cou2;++j)
				addEdge(i,cou1+j,1,getdis(i-1,j-1));

		MinCostMaxFlow(cou1+cou2+2,ans);

		printf("%d\n",ans);
	}
	
	return 0;
}
