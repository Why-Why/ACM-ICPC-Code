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

const int MaxN=300000;
const int MaxM=300000;

struct Edge
{
	int to,next;
};

int head[MaxN],Ecou;
Edge E[MaxM];
int N;
int M=0;

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int dfs(int u,bool type)
{
	if(head[u]==-1)
	{
		++M;
		return 1;
	}

	int mnum=type ? 0 : 1000000000;
	int v;
	int temp;
	int sum=0;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		temp=dfs(v,!type);
		
		if(type)
			mnum+=temp;
		else
			mnum=min(mnum,temp);
	}

	return mnum;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	memset(head,-1,sizeof(head));

	scanf("%d",&N);

	for(int i=0;i<N-1;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
	}

	int t=dfs(1,0);

	printf("%d ",M+1-t);

	t=dfs(1,1);

	printf("%d\n",t);

	return 0;
}
