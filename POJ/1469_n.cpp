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

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxU],Ecou=0;
int vis[MaxV];
int flag=0;
int linker[MaxV];

bool find(int u)
{
	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(vis[v]!=flag)
		{
			vis[v]=flag;

			if(linker[v]==-1 || find(linker[v]))
			{
				linker[v]=u;

				return 1;
			}
		}
	}

	return 0;
}

int Hungary(int uN)
{
	int ret=0;

	for(int i=1;i<=uN;++i)
	{
		++flag;

		if(find(i))
			++ret;
	}

	return ret;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou;
	++Ecou;
}

void init(int uN,int vN)
{
	Ecou=0;

	for(int i=1;i<=uN;++i)
		head[i]=-1;

	for(int i=1;i<=vN;++i)
		linker[i]=-1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int P,N;
	int t,temp;

	cin>>T;

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

		if(P>N || Hungary(P)<P)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
