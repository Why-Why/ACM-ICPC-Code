#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int MaxN=110;
const int INF=10e8;

bool vis[MaxN];

void Dijkstra(int cost[][MaxN],int lowcost[],int n,int start)
{
	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
		lowcost[i]=INF;
	}
	lowcost[start]=0;

	for(int j=1;j<=n;++j)
	{
		int k=-1;
		int minn=INF;

		for(int i=1;i<=n;++i)
			if(!vis[i] && lowcost[i]<minn)
			{
				minn=lowcost[i];
				k=i;
			}

		if(k==-1)
			break;

		vis[k]=1;

		for(int i=1;i<=n;++i)
			if(!vis[i])
				lowcost[i]=min(lowcost[k]+cost[k][i],lowcost[i]);
	}
}

int ans[MaxN];
int map1[MaxN][MaxN];

int main()
{
	int n;
	int maxn;
	char c[20];

	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=i;++j)
				if(i==j)
					map1[i][j]=0;
				else
				{
					scanf("%s",c);

					if(c[0]!='x')
						sscanf(c,"%d",&map1[i][j]);
					else
						map1[i][j]=INF;

					map1[j][i]=map1[i][j];
				}

		Dijkstra(map1,ans,n,1);

		maxn=-1;

		for(int i=1;i<=n;++i)
			if(ans[i]>maxn)
				maxn=ans[i];

		cout<<maxn<<endl;
	}

	return 0;
}
