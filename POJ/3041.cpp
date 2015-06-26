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

const int MaxN=510;
const int MaxM=10004;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next;
};

Edge E[MaxM*2];
int head[MaxN],Ecou;

int dis,disU[MaxN],disV[MaxN];
int linkU[MaxN],linkV[MaxN];
bool vis[MaxN];
int que[MaxN*2];
int first,last;

bool searchPath(int uN,int vN)
{
	first=last=0;
	
	int u,v;
	int len;

	dis=INF;

	for(int i=1;i<=uN;++i)
		if(linkU[i]==-1)
		{
			que[last++]=i;
			disU[i]=0;
		}
		else
			disU[i]=-1;

	for(int i=1;i<=vN;++i)
		disV[i]=-1;

	while(last-first)
	{
		u=que[first++];

		if(disU[u]>dis)
			break;

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(disV[v]==-1)
			{
				disV[v]=disU[u]+1;

				if(linkV[v]==-1)
					dis=disV[v];
				else
				{
					disU[linkV[v]]=disV[v]+1;
					que[last++]=linkV[v];
				}
			}
		}
	}

	return dis!=INF;
}

bool find(int u)
{
	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(!vis[v] && disV[v]==disU[u]+1)
		{
			vis[v]=1;

			if(linkV[v]!=-1 && disV[v]==dis)
				continue;

			if(linkV[v]==-1 || find(linkV[v]))
			{
				linkV[v]=u;
				linkU[u]=v;

				return 1;
			}
		}
	}

	return 0;
}

int MaxMatch(int uN,int vN)
{
	int ret=0;

	while(searchPath(uN,vN))
	{
		for(int v=1;v<=vN;++v)
			vis[v]=0;

		for(int u=1;u<=uN;++u)
			if(linkU[u]==-1 && find(u))
				++ret;
	}

	return ret;
}

void init(int uN,int vN)
{
	memset(head,-1,sizeof(head));
	Ecou=0;

	for(int i=1;i<=uN;++i)
		linkU[i]=linkV[i]=-1;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int N,K;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&K))
	{
		init(N,N);

		while(K--)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
		}

		printf("%d\n",MaxMatch(N,N));
	}
	
	return 0;
}
