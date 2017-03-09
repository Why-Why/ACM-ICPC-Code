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

int M,N;
int L[MaxN];
int minL[MaxN],maxL[MaxN];

bool vis[MaxN];

void Dijkstra(int lowcost[],int cost[][MaxN],int N,int start)
{
	for(int i=0;i<=N;++i)
	{
		vis[i]=0;
		lowcost[i]=INF;
		minL[i]=INF;
		maxL[i]=-INF;
	}
	minL[start]=maxL[start]=L[start];

	lowcost[start]=0;

	int minn,minp;

	for(int cas=0;cas<=N;++cas)
	{
		minn=INF;
		minp=-1;

		for(int i=0;i<=N;++i)
			if(!vis[i] && minn>lowcost[i])
			{
				minn=lowcost[i];
				minp=i;
			}

		if(minp==-1)
			return;
		vis[minp]=1;

		for(int i=0;i<=N;++i)
			if(!vis[i] && cost[minp][i]!=-1 && (i==0 || (L[i]-minL[minp]<=M && maxL[minp]-L[i]<=M)) && lowcost[i]>lowcost[minp]+cost[minp][i])
			{
				lowcost[i]=lowcost[minp]+cost[minp][i];
				minL[i]=min(minL[minp],L[i]);
				maxL[i]=max(maxL[minp],L[i]);
			}
	}
}

int map1[MaxN][MaxN];
int ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&M,&N);

	for(int i=0;i<=N;++i)
		for(int j=0;j<=N;++j)
			map1[i][j]=-1;

	int P,X,a,b;

	for(int i=1;i<=N;++i)
	{
		scanf("%d %d %d",&P,&L[i],&X);
		
		map1[i][0]=P;

		while(X--)
		{
			scanf("%d %d",&a,&b);

			map1[i][a]=b;
		}
	}

	Dijkstra(ans,map1,N,1);

	printf("%d\n",ans[0]);

	return 0;
}
