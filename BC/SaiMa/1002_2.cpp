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

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int MaxN=200005;
const int MaxM=600005;

struct Edge
{
	int to,next;
};

Edge E[MaxM*2];
int head[MaxN],Ecou;

int vis[MaxN];

void init(int N)
{
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		vis[i]=0;
	}
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool ans1,ans2;

void dfs(int u,int pre,int type)
{
	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)
			continue;

		if(vis[v]==0)
		{
			vis[v]=-type;
			dfs(v,u,-type);
		}
		else if(vis[v]==type)
		{
			ans1=1;
			vis[v]=-type;
		}
		else if(vis[v]==-type)
			ans2=1;
		else if(vis[v]==2)
			ans1=ans2=1;
	}
}

int N,M;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init(N);
		ans1=ans2=0;

		while(M--)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		for(int i=1;i<=N;++i)
			if(vis[i]==0)
			{
				vis[i]=1;
				dfs(i,i,1);

				if(ans1 && ans2)
					break;
			}

		if(ans1)
			printf("YES\n");
		else
			printf("NO\n");

		if(ans2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
