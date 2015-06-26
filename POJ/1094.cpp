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

const int MaxN=30;
const int MaxM=10000;

struct Edge
{
	int next,to;
};

int head[MaxN],Ecou;
Edge E[MaxM];

int N,M;
char s[10];

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int pai[MaxN];
bool vis[30];

int dfs(int u,int d)
{
	cout<<u<<endl;
	if(u<1)
		return u;

	pai[d]=u;

	if(d==N)
		return 1;

	int v,temp;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(vis[v])
			return -1;

		temp=dfs(v,d+1);

		if(temp==-1)
			return -1;
	}

	return 0;
}

bool ru[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	bool ok;
	int temp;
	int rem;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		memset(ru,0,sizeof(ru));
		init();
		ok=1;

		for(int i=1;i<=M;++i)
		{
			scanf("%s",s);

			if(!ok)
				continue;

			ru[s[2]-'A'+1]=1;
			addEdge(s[0]-'A'+1,s[2]-'A'+1);

			temp=-1;

			for(int j=1;j<=N;++j)
				if(ru[j]==0)
				{
					temp=j;
					break;
				}

			memset(vis,0,sizeof(vis));
			temp=dfs(temp,1);

			if(temp==-1)
			{
				printf("Inconsistency found after %d relations.\n",i);
				ok=0;
			}
			else if(temp==1)
				rem=i;
		}

		if(ok)
		{
			temp=0;

			for(int i=1;i<=N;++i)
				if(ru[i]==0)
				{
					temp=i;
					break;
				}

			memset(vis,0,sizeof(vis));
			temp=dfs(temp,1);

			if(temp==1)
			{
				printf("Sorted sequence determined after %d relations: ",rem);

				for(int i=1;i<=N;++i)
					printf("%c",pai[i]+'A'-1);
				printf(".\n");

				ok=0;
			}
			else if(temp==0)
				printf("Sorted sequence cannot be determined.\n");
		}
	}
	
	return 0;
}
