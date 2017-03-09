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

const int MaxN=1010;
const int MaxM=1010*500;
const int INF=10e8;

struct Edge
{
	int to,next,val;
};

Edge E[MaxM];
int head[MaxN],Ecou;
bool vis[MaxN];

void init(int N)
{
	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		vis[i]=0;
	}
	Ecou=0;
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].val=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void SPFA(long long lowcost[],int N,int start)
{
	queue <int> que;
	int t,v,c;

	for(int i=0;i<=N;++i)
		lowcost[i]=-1;

	lowcost[start]=0;
	que.push(start);
	vis[start]=1;

	while(!que.empty())
	{
		t=que.front();
		que.pop();

		vis[t]=0;

		for(int i=head[t];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			c=E[i].val;

			if(lowcost[v]<lowcost[t]+c)
			{
				lowcost[v]=lowcost[t]+c;

				if(!vis[v])
				{
					vis[v]=1;
					que.push(v);
				}
			}
		}
	}
}

int N,M,R;
int sh[1010],eh[1010],ef[1010];
long long ans[1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&M,&R);

	init(M);

	for(int i=1;i<=M;++i)
		scanf("%d %d %d",&sh[i],&eh[i],&ef[i]);

	for(int i=1;i<=M;++i)
		for(int j=i+1;j<=M;++j)
			if(i!=j && max(sh[i],sh[j])-R>=min(eh[i],eh[j]))
				if(sh[i]<sh[j])
					addEdge(i,j,ef[j]);
				else
					addEdge(j,i,ef[i]);

	for(int i=1;i<=M;++i)
		addEdge(0,i,ef[i]);

	SPFA(ans,M,0);

	long long zans=-1;

	for(int i=1;i<=M;++i)
		zans=max(zans,ans[i]);

	printf("%I64d\n",zans);
	
	return 0;
}
