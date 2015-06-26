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

const int MaxN=100005;
const int MaxM=100005;

struct Edge
{
	int to,next;
};

Edge E[MaxM*3];
int head[MaxN],Ecou;

void init(int N)
{
	for(int i=1;i<=N;++i)
		head[i]=-1;
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int que[MaxN*3];
int first,last;

bool vis[MaxN];

void bfs(int u)
{
	int t;

	first=last=0;

	que[last++]=u;
	vis[u]=1;

	while(last-first)
	{
		t=que[first++];

		for(int i=head[t];i!=-1;i=E[i].next)
			if(!vis[E[i].to])
			{
				vis[E[i].to]=1;
				que[last++]=E[i].to;
			}
	}
}

void slove(int N)
{
	int ans=0;

	memset(vis,0,sizeof(vis));

	for(int i=1;i<=N;++i)
		if(!vis[i])
		{
			++ans;
			bfs(i);
		}

	printf("%d\n",ans-1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	int n,m;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&n,&m);

		init(n);

		while(m--)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		slove(n);
	}

	return 0;
}
