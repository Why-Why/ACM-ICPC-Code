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

const int MaxN=110;
const int INF=10e8;

int vis[MaxN];

void Dijkstra(int lowcost[],int cost[][MaxN],int N,int start)
{
	int minn,minp;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
	}
	lowcost[start]=0;

	for(int cas=1;cas<=N;++cas)
	{
		minn=INF;
		minp=-1;
		for(int i=1;i<=N;++i)
			if(!vis[i] && lowcost[i]<minn)
			{
				minn=lowcost[i];
				minp=i;
			}

		if(minp==-1)
			return;
		vis[minp]=1;

		for(int i=1;i<=N;++i)
			if(!vis[i] && cost[minp][i]!=-1 && lowcost[i]>lowcost[minp]+cost[minp][i])
				lowcost[i]=lowcost[minp]+cost[minp][i];
	}
}

int map1[MaxN][MaxN];
int ans[MaxN];
int N,A,B;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int k,a;

	for(int i=1;i<=MaxN;++i)
		for(int j=1;j<=MaxN;++j)
			map1[i][j]=-1;


	scanf("%d %d %d",&N,&A,&B);

	for(int i=1;i<=N;++i)
	{
		scanf("%d",&k);

		if(k==0)
			continue;

		scanf("%d",&a);

		map1[i][a]=0;
		--k;

		while(k--)
		{
			scanf("%d",&a);

			if(map1[i][a]==-1)
				map1[i][a]=1;
		}
	}

	//for(int i=1;i<=N;++i)
	//	for(int j=1;j<=N;++j)
	//		cout<<map1[i][j]<<' ';

	Dijkstra(ans,map1,N,A);

	printf("%d\n",ans[B]==INF ? -1 : ans[B]);

	return 0;
}
