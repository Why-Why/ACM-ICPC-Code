// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月08日 星期五 16时16分14秒
// File Name     : 3083.cpp

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

int n,m;
int map1[50][50];
int sx,sy;

const int step[4][2]={{0,1},{-1,0},{0,-1},{1,0}};

int zouL()
{
	int x=sx,y=sy;
	int tx,ty;
	int fang;
	int ret=1;

	if(y==1)
		fang=0;
	else if(x==n)
		fang=1;
	else if(y==m)
		fang=2;
	else
		fang=3;

	while(map1[x][y]!=-1)
	{
		for(int i=1;i>=-2;--i)
		{
			tx=x+step[(fang+4+i)%4][0];
			ty=y+step[(fang+4+i)%4][1];

			if(map1[tx][ty]<=0)
			{
				fang=(fang+4+i)%4;
				++ret;

				x=tx;
				y=ty;

				break;
			}
		}
	}

	return ret;
}

int zouR()
{
	int x=sx,y=sy;
	int tx,ty;
	int fang;
	int ret=1;

	if(y==1)
		fang=0;
	else if(x==n)
		fang=1;
	else if(y==m)
		fang=2;
	else
		fang=3;

	while(map1[x][y]!=-1)
	{
		for(int i=-1;i<=2;++i)
		{
			tx=x+step[(fang+4+i)%4][0];
			ty=y+step[(fang+4+i)%4][1];

			if(map1[tx][ty]<=0)
			{
				fang=(fang+4+i)%4;
				++ret;

				x=tx;
				y=ty;

				break;
			}
		}
	}

	return ret;
}

int que[2000];
int first,last;
int vis[50][50];

int bfs()
{
	int t,tx,ty,nx,ny;

	memset(vis,0,sizeof(vis));
	vis[sx][sy]=1;

	first=last=0;

	que[last++]=100*sx+sy;

	while(last-first)
	{
		t=que[first++];
		tx=t/100;
		ty=t-tx*100;

		if(map1[tx][ty]==-1)
			break;

		for(int i=0;i<4;++i)
		{
			nx=tx+step[i][0];
			ny=ty+step[i][1];

			if(nx>0 && ny>0 && nx<=n && ny<=m)
				if(map1[nx][ny]<=0 && vis[nx][ny]==0)
				{
					vis[nx][ny]=vis[tx][ty]+1;
					que[last++]=nx*100+ny;
				}
		}
	}

	return vis[tx][ty];
}

char s[100];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&m,&n);

		for(int i=1;i<=n;++i)
		{
			scanf("%s",s+1);

			for(int j=1;j<=m;++j)
				if(s[j]=='S')
				{
					sx=i;
					sy=j;
					map1[i][j]=1;
				}
				else if(s[j]=='#')
					map1[i][j]=1;
				else if(s[j]=='E')
					map1[i][j]=-1;
				else
					map1[i][j]=0;
		}

		printf("%d %d %d\n",zouL(),zouR(),bfs());
	}
	
	return 0;
}
