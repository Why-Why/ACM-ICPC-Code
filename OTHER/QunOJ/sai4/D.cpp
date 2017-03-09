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

int map1[200][200];
int N;
bool vis[110][110];
int que[8000000];
int first,last;
int maxn[200][200],minn[200][200];
int cou[200][200];

const int step[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

bool isok(int x,int y)
{
	if(x>0 && x<=N && y>0 && y<=N)
		return 1;

	return 0;
}

bool judge(int M)
{
	memset(vis,0,sizeof(vis));
	memset(cou,0,sizeof(cou));

	first=last=0;

	que[last++]=1*1000+1;
	vis[1][1]=1;
	cou[1][1]=1;

	int tx,ty;

	minn[1][1]=maxn[1][1]=map1[1][1];

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			minn[i][j]=maxn[i][j]=map1[i][j];

	int temp,x,y;

	while(last-first)
	{
		temp=que[first++];
		
		x=temp/1000;
		y=temp%1000;

		vis[x][y]=0;

		if(x==N && y==N)
			return 1;

		for(int i=0;i<4;++i)
		{
			tx=step[i][0]+x;
			ty=step[i][1]+y;

			if(isok(tx,ty) && max(maxn[x][y],map1[tx][ty])-min(minn[x][y],map1[tx][ty])<=M)
			{
				maxn[tx][ty]=max(maxn[x][y],map1[tx][ty]);
				minn[tx][ty]=min(minn[x][y],map1[tx][ty]);
				
				if(vis[tx][ty]==0)
				{
					vis[tx][ty]=1;
					que[last++]=tx*1000+ty;

					++cou[tx][ty];

					if(cou[tx][ty]>N)
						return 0;
				}
			}
		}
	}

	return 0;
}

int getans()
{
	int L,R,M;
	L=0;
	R=121;

	while(R>L)
	{
		M=(L+R)/2;

		if(judge(M))
			R=M;
		else
			L=M+1;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&map1[i][j]);

//		cout<<judge(1)<<endl;

		printf("%d\n",getans());
	}
	
	return 0;
}
