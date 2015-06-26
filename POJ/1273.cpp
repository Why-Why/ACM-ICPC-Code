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

const int MaxN=210;
const int INF=10e8;

int cost[MaxN][MaxN];
int path[MaxN],flow[MaxN];
int S,T;
int que[MaxN],first,last;

int find(int N)
{
	int temp;

	first=last=0;
	memset(path,-1,sizeof(path));
	que[last++]=S;
	path[S]=0;
	flow[S]=INF;

	while(last-first)
	{
		temp=que[first++];

		if(temp==T)
			break;

		for(int i=1;i<=N;++i)
			if(cost[temp][i] && path[i]==-1)
			{
				path[i]=temp;
				flow[i]=min(flow[temp],cost[temp][i]);

				que[last++]=i;
			}
	}

	if(path[T]==-1)
		return -1;
	return flow[T];
}

void update(int step)
{
	int p=T,temp;

	while(p!=S)
	{
		temp=path[p];
		cost[temp][p]-=step;
		cost[p][temp]+=step;

		p=temp;
	}
}

int E_K(int N)
{
	int ret=0,step;

	while((step=find(N))!=-1)
	{
		ret+=step;

		update(step);
	}

	return ret;
}

void init(int N,int _S,int _T)
{
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			cost[i][j]=0;
	
	S=_S;
	T=_T;
}

void addEdge(int u,int v,int c)
{
	cost[u][v]+=c;		//!!!
}

int N,M;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;
	
	while(~scanf("%d %d",&M,&N))
	{
		init(N,1,N);

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&a,&b,&c);

			addEdge(a,b,c);
		}

		printf("%d\n",E_K(N));
	}

	return 0;
}
