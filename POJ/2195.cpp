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
const int MaxM=200000;
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
	Ecou=0;
	S=_S;
	T=_T;

	for(int i=1;i<=N;++i)
		head[i]=-1;
}

void addEdge(int u,int v,int cap,int cost)
{
	E[Ecou].to=v;
	E[Ecou].cap=cap;
	E[Ecou].cost=cost;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
	E[Ecou].to=u;
	E[Ecou].cap=0;
	E[Ecou].cost=-cost;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

bool SPFA(int N)
{
	queue <int> que;
	int u,v,c;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
		pre[i]=-1;
	}
	vis[S]=1;
	lowcost[S]=0;
	couNode[S]=1;

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

int MinCostMaxFlow(int N,int &minCost)		//返回最大流，minCost是在最大流时的最小费用。
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

int Hx[110],Hy[110],mx[110],my[110];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M,cou1,cou2;
	char s[200],c;
	int ans;

	while(~scanf("%d %d",&N,&M) && (N+M))
	{
		cou1=cou2=0;
		for(int i=1;i<=N;++i)
		{
			scanf("%s",s);
			for(int j=1;j<=M;++j)
			{
				if(s[j-1]=='H')
				{
					Hx[cou1]=i;
					Hy[cou1++]=j;
				}
				else if(s[j-1]=='m')
				{
					mx[cou2]=i;
					my[cou2++]=j;
				}
			}
		}

		init(cou1*2+2,1,2);

		for(int i=0;i<cou2;++i)
			addEdge(1,i+3,1,0);
		for(int i=0;i<cou1;++i)
			addEdge(cou2+3+i,2,1,0);
		for(int i=0;i<cou2;++i)
			for(int j=0;j<cou1;++j)
				addEdge(i+3,cou2+j+3,1,abs(mx[i]-Hx[j])+abs(my[i]-Hy[j]));

		MinCostMaxFlow(cou1*2+2,ans);
		printf("%d\n",ans);
	}
	
	return 0;
}
