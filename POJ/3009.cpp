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
// Created Time  : 2015年05月08日 星期五 16时46分33秒
// File Name     : 3009.cpp

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
int map1[30][30];
int sx,sy;
int ex,ey;
int ans;

const int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int judge(int x,int y,int fang,int &tx,int &ty)
{
	int dx=step[fang][0],dy=step[fang][1];

	if(map1[x+dx][y+dy]==1)
		return 0;

	while(1)
	{
		x+=dx;
		y+=dy;

		if(x==ex && y==ey)
			return 2;

		if(x<1 || y<1 || x>n || y>m)
			return 0;

		if(map1[x][y]==1)
		{
			tx=x-dx;
			ty=y-dy;

			return 1;
		}
	}
}

void chuli(int x,int y,int fang,int t)
{
	map1[x+step[fang][0]][y+step[fang][1]]=t;
}

void dfs(int x,int y,int d)
{
	if(d>10)
		return;

	int tx,ty;
	int t;

	for(int i=0;i<4;++i)
	{
		t=judge(x,y,i,tx,ty);

		if(t==1)
		{
			chuli(tx,ty,i,0);
			dfs(tx,ty,d+1);
			chuli(tx,ty,i,1);
		}
		else if(t==2)
			ans=min(ans,d+1);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&m,&n) && n+m)
	{
		ans=20;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				scanf("%d",&map1[i][j]);

				if(map1[i][j]==2)
				{
					sx=i,sy=j;
					map1[i][j]=0;
				}

				if(map1[i][j]==3)
					ex=i,ey=j;
			}

		dfs(sx,sy,0);

		if(ans>10)
			ans=-1;

		printf("%d\n",ans);
	}
	
	return 0;
}
