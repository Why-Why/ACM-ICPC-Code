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

const int MaxU=110;
const int MaxV=310;
const int MaxM=MaxU*MaxV;
const int INF=10e8;

vector <int> E[MaxU];
int dis,disU[MaxU],disV[MaxV];
int linkU[MaxU],linkV[MaxV];
bool vis[MaxV];

bool searchPath(int uN,int vN)
{
	queue <int> que;
	int u,v;
	int len;

	dis=INF;

	for(int i=1;i<=uN;++i)
		if(linkU[i]==-1)
		{
			que.push(i);
			disU[i]=0;
		}
		else
			disU[i]=-1;
	for(int i=1;i<=vN;++i)
		disV[i]=-1;

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		if(disU[u]>dis)
			break;

		len=E[u].size();

		for(int i=0;i<len;++i)
		{
			v=E[u][i];

			if(disV[v]==-1)
			{
				disV[v]=disU[u]+1;
				
				if(linkV[v]==-1)
					dis=disV[v];
				else
				{
					disU[linkV[v]]=disV[v]+1;
					que.push(linkV[v]);
				}
			}
		}
	}

	return dis != INF;
}

bool find(int u)
{
	int len=E[u].size();
	int v;

	for(int i=0;i<len;++i)
	{
		v=E[u][i];

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

void addEdge(int u,int v)
{
	E[u].push_back(v);
}

void init(int uN,int vN)
{
	for(int i=1;i<=uN;++i)
		E[i].clear();

	for(int i=1;i<=uN;++i)
		linkU[i]=-1;
	for(int i=1;i<=vN;++i)
		linkV[i]=-1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int P,N;
	int t,temp;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&P,&N);

		init(P,N);

		for(int i=1;i<=P;++i)
		{
			scanf("%d",&t);

			while(t--)
			{
				scanf("%d",&temp);

				addEdge(i,temp);
			}
		}

		if(P>N || MaxMatch(P,N)<P)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
