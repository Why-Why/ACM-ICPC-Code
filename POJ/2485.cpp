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

const int MaxN=600;
const int INF=0x3f3f3f3f;

bool vis[MaxN];
int lowc[MaxN];

int Prim(int cost[][MaxN],int N)
{
	int ret=0;
	int minn,k;

	memset(vis,0,sizeof(vis));
	vis[1]=1;

	for(int i=1;i<=N;++i)
		lowc[i]=cost[1][i];

	for(int i=1;i<=N-1;++i)
	{
		minn=INF;
		k=-1;

		for(int j=1;j<=N;++j)
			if(!vis[j] && minn>lowc[j])
			{
				minn=lowc[j];
				k=j;
			}

		ret=max(ret,minn);
		vis[k]=1;

		for(int j=1;j<=N;++j)
			if(!vis[j] && lowc[j]>cost[k][j])
				lowc[j]=cost[k][j];
	}

	return ret;
}

int cost[MaxN][MaxN];
int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&cost[i][j]);

		printf("%d\n",Prim(cost,N));
	}
	
	return 0;
}
