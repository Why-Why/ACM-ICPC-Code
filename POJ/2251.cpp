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
// Created Time  : 2015年05月08日 星期五 23时47分36秒
// File Name     : 2251.cpp

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

const int step[6][3]={{0,0,-1},{0,0,1},{0,-1,0},{0,1,0},{1,0,0},{-1,0,0}};

int map1[40][40][40];
int vis[40][40][40];
char s[40];
int N,M,C;
int sx,sy,sz;
int que[40*40*40];
int first,last;

int bfs()
{
	int t,tx,ty,tz,nx,ny,nz;

	first=last=0;
	vis[sx][sy][sz]=1;
	que[last++]=sx*10000+sy*100+sz;

	while(last-first)
	{
		t=que[first++];
		tx=t/10000;
		ty=(t-tx*10000)/100;
		tz=t%100;

		if(map1[tx][ty][tz]==2)
			return vis[tx][ty][tz]-1;

		for(int i=0;i<6;++i)
		{
			nx=tx+step[i][0];
			ny=ty+step[i][1];
			nz=tz+step[i][2];

			if(map1[nx][ny][nz] && vis[nx][ny][nz]==0)
			{
				vis[nx][ny][nz]=vis[tx][ty][tz]+1;
				que[last++]=nx*10000+ny*100+nz;
			}
		}
	}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d",&N,&M,&C) && N+M+C)
	{
		memset(vis,0,sizeof(vis));
		memset(map1,0,sizeof(map1));

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
			{
				scanf("%s",s+1);

				for(int k=1;k<=C;++k)
					if(s[k]=='S')
					{
						sx=i;
						sy=j;
						sz=k;
						map1[i][j][k]=1;
					}
					else if(s[k]=='E')
						map1[i][j][k]=2;
					else if(s[k]=='.')
						map1[i][j][k]=1;
			}

		int t=bfs();

		if(t)
			printf("Escaped in %d minute(s).\n",t);
		else
			printf("Trapped!\n");
	}
	
	return 0;
}
