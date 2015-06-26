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

const int MaxN=1100;
const int INF=0x3f3f3f3f;

int lowc[MaxN];
bool vis[MaxN];

int Prim(int cost[][MaxN],int N)
{
	int ret=0;
	int minn,k;

	memset(vis,0,sizeof(vis));
	vis[1]=1;

	for(int i=1;i<=N;++i)
		lowc[i]=cost[1][i];

	for(int i=1;i<N;++i)
	{
		minn=INF;

		for(int j=1;j<=N;++j)
			if(!vis[j] && minn>lowc[j])
			{
				minn=lowc[j];
				k=j;
			}

		ret+=minn;
		vis[k]=1;

		for(int j=1;j<=N;++j)
			if(!vis[j] && lowc[j]>cost[k][j])
				lowc[j]=cost[k][j];
	}

	return ret;
}

const int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

char s[600][600];
int id[600][600];
int cou;
int cost[1100][1100];
int N,M;
int que[30000];
int first,last;
int remm[110][110];

void bfs(int x,int y)
{
	int temp,tx,ty,nx,ny;
	int rem=id[x][y];

	memset(remm,0,sizeof(remm));

	first=last=0;
	remm[x][y]=1;
	que[last++]=x*100+y;
	cost[id[x][y]][id[x][y]]=0;

	while(last-first)
	{
		temp=que[first++];
		tx=temp/100;
		ty=temp-tx*100;

		for(int i=0;i<4;++i)
		{
			nx=tx+step[i][0];
			ny=ty+step[i][1];

			if(s[nx][ny]=='#')
				continue;

			if(remm[nx][ny]==0)
			{
				remm[nx][ny]=remm[tx][ty]+1;
				que[last++]=nx*100+ny;

				if(s[nx][ny]=='S' || s[nx][ny]=='A')
					cost[rem][id[nx][ny]]=remm[nx][ny]-1;
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		cou=0;
		scanf("%d %d",&M,&N);
		gets(s[0]);

		for(int i=1;i<=N;++i)
			gets(s[i]+1);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				if(s[i][j]=='A' || s[i][j]=='S')
					id[i][j]=++cou;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				if(s[i][j]=='A' || s[i][j]=='S')
					bfs(i,j);

		printf("%d\n",Prim(cost,cou));
	}
	
	return 0;
}
