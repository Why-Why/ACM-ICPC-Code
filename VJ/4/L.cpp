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

const int INF=10e8;

bool vis[300];

void Dijkstra(double lowcost[],double cost[][300],int N,int start)
{
	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
	}
	lowcost[start]=0;

	int k;
	double minn;

	for(int cas=1;cas<=N;++cas)
	{
		minn=INF;
		k=-1;

		for(int i=1;i<=N;++i)
			if(!vis[i] && minn>lowcost[i])
			{
				minn=lowcost[i];
				k=i;
			}

		if(k==-1)
			return;

		vis[k]=1;

		for(int i=1;i<=N;++i)
			if(!vis[i] && cost[k][i]>=0 && lowcost[i]>lowcost[k]+cost[k][i])
				lowcost[i]=lowcost[k]+cost[k][i];
	}
}

int X[300],Y[300];
int N;
double map1[300][300];
double ans[300];

double getdis(int a,int b)
{
	return sqrt((double(X[a]-X[b]))*(X[a]-X[b])+(double(Y[a]-Y[b]))*(Y[a]-Y[b]));
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<=250;++i)
		for(int j=1;j<=250;++j)
			map1[i][j]=-1;

	scanf("%d %d %d %d",&X[1],&Y[1],&X[2],&Y[2]);
	
	N=3;
	int base;

	while(~scanf("%d %d",&X[N],&Y[N]))
	{
		base=N;
		while(X[N]!=-1 || Y[N]!=-1)
		{
			++N;
			scanf("%d %d",&X[N],&Y[N]);
		}

		for(int i=base;i<N-1;++i)
			map1[i][i+1]=map1[i+1][i]=3.0*getdis(i,i+1)/2000.0;
	}
	--N;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=i;++j)
			if(map1[i][j]<0)
				map1[i][j]=map1[j][i]=3.0*getdis(i,j)/500.0;

	Dijkstra(ans,map1,N,1);

	printf("%d\n",(int)(ans[2]+0.5));
	
	return 0;
}
