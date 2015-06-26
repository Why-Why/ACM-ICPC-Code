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

const int MaxN=32;
const int INF=0x3f3f3f3f;

bool vis[MaxN];
bool can[MaxN];

void Dijkstra(int cost[][MaxN],int lowcost[],int N,int start)
{
	int k,minn;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
	}

	lowcost[start]=0;

	for(int j=1;j<=N;++j)
	{
		k=-1;
		minn=INF;

		for(int i=1;i<=N;++i)
			if(!can[i] && !vis[i] && lowcost[i]<minn)
			{
				minn=lowcost[i];
				k=i;
			}

		if(k==-1)
			break;
		vis[k]=1;

		for(int i=1;i<=N;++i)
			if(!can[i] && !vis[i] && cost[k][i]>=0)
				lowcost[i]=min(lowcost[i],lowcost[k]+cost[k][i]);
	}
}

int map1[MaxN][MaxN];
int N,M;
int lowcost[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;
	int ans;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		ans=0;

		memset(map1,-1,sizeof(map1));
		memset(can,0,sizeof(can));

		while(M--)
		{
			scanf("%d %d %d",&a,&b,&c);

			if(map1[a][b]>=0)
				map1[a][b]=map1[b][a]=min(map1[a][b],c);
			else
				map1[a][b]=map1[b][a]=c;
		}

		for(int i=2;i<N;++i)
		{
			can[i]=1;
			Dijkstra(map1,lowcost,N,1);
			can[i]=0;
			ans=max(ans,lowcost[N]);
		}

		if(ans>=INF)
			printf("Inf\n");
		else
			printf("%d\n",ans);
	}
	
	return 0;
}
