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

int ans;
int N;
int M[110];
int jishu[10][110];
int couji[10];
bool vis[10];
int C[110][110];
int K[110][110];
int kji[110][110][10];

bool manzu(int x,int y)
{
	for(int i=1;i<=K[x][y];++i)
		if(vis[kji[x][y][i]]==0)
			return 0;
	return 1;
}

int getxiao(int x)
{
	int minn=INF;

	for(int i=1;i<=M[x];++i)
	{
		if(manzu(x,i))
			minn=min(minn,C[x][i]);
	}

	if(minn!=INF)
		return minn;

	return -1;
}

void dfs(int d,int rem)
{
	if(d==6)
	{
		if(rem<ans)
			ans=rem;
		return;
	}

	int minn=INF;

	for(int i=0;i<6;++i)
		if(!vis[i])
		{
			minn=INF;
			for(int j=0;j<couji[i];++j)
				minn=min(minn,getxiao(jishu[i][j]));

			if(minn==-1 || minn==INF)
				continue;

			vis[i]=1;
			dfs(d+1,rem+minn);
			vis[i]=0;
		}
}

void slove()
{
	for(int i=0;i<6;++i)
		if(couji[i]==0)
		{
			printf("%d\n",-1);
			return;
		}
	memset(vis,0,sizeof(vis));

	dfs(0,0);

	printf("%d\n",ans==INF ? -1 : ans);
}

int minC[10];
bool have[10];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a;

	scanf("%d",&T);

	while(T--)
	{
		memset(K,0,sizeof(K));
		memset(C,0,sizeof(C));
		ans=INF;
		memset(couji,0,sizeof(couji));
		memset(M,0,sizeof(M));
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&M[i],&a);

			jishu[a][couji[a]++]=i;

			for(int j=1;j<=M[i];++j)
			{
				scanf("%d",&K[i][j]);

				for(int k=1;k<=K[i][j];++k)
					scanf("%d",&kji[i][j][k]);

				scanf("%d",&C[i][j]);
			}
		}

		slove();
	}
	
	return 0;
}
