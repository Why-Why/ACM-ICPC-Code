#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

////////////////////////////////////

const int MaxN=110;
const int INF=10e8;

bool vis[MaxN];
bool visEdge[MaxN][MaxN];			//
int lowc[MaxN];
int fa[MaxN];
int maxc[MaxN][MaxN];

int Prim(int cost[][MaxN],int n)
{
	int ans=0;
	int minn,k;
	
	memset(vis,0,sizeof(vis));
	memset(maxc,0,sizeof(maxc));
	memset(visEdge,0,sizeof(visEdge));

	vis[1]=1;
	fa[1]=-1;

	for(int i=2;i<=n;++i)		//
	{
		lowc[i]=cost[1][i];
		fa[i]=1;
	}

	for(int i=1;i<n;++i)		//
	{
		minn=INF;
		k=-1;

		for(int j=1;j<=n;++j)
			if(!vis[j] && minn>lowc[j])
			{
				minn=lowc[j];
				k=j;
			}

		if(minn==INF)
			return -1;

		ans+=minn;
		vis[k]=1;
		visEdge[k][fa[k]]=visEdge[fa[k]][k]=1;

		for(int j=1;j<=n;++j)
		{
			if(vis[j])
				maxc[k][j]=maxc[j][k]=max(maxc[j][fa[k]],minn);
			if(!vis[j] && lowc[j]>cost[k][j])
			{
				lowc[j]=cost[k][j];
				fa[j]=k;
			}
		}
	}

	return ans;
}

int getCST(int cost[][MaxN],int n)
{
	int ans=Prim(cost,n);
	int minn=INF;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(visEdge[i][j]==0)
			{
				visEdge[i][j]=visEdge[j][i]=1;

				if(minn>cost[i][j]-maxc[i][j])
					minn=cost[i][j]-maxc[i][j];
			}

	if(minn)
		return ans;
	else
		return -1;
//	return ans+minn;		/////
}

////////////////////////////////////

int map1[MaxN][MaxN];

int main()
{
	int T;
	int n,m;
	int a,b,c;
	int ans;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&n,&m);

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				map1[i][j]=INF;

		for(int i=1;i<=m;++i)
		{
			scanf("%d %d %d",&a,&b,&c);

			map1[a][b]=map1[b][a]=c;
		}

		ans=getCST(map1,n);

		if(ans==-1)
			printf("Not Unique!\n");
		else
			printf("%d\n",ans);
	}

	return 0;
}
