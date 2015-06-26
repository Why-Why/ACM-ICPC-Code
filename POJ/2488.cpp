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
// Created Time  : 2015年05月08日 星期五 15时34分17秒
// File Name     : 2488.cpp

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

int rem[1000];
bool vis[30][30];
int n,m;

const int step[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};

bool dfs(int x,int y,int d)
{
	int tx,ty;

	if(d==n*m)
		return 1;

	for(int i=0;i<8;++i)
	{
		tx=x+step[i][0];
		ty=y+step[i][1];

		if(tx>=1 && ty>=1 && tx<=n && ty<=m && vis[tx][ty]==0)
		{
			vis[tx][ty]=1;
			rem[d]=tx*100+ty;

			if(dfs(tx,ty,d+1))
				return 1;

			vis[tx][ty]=0;
		}
	}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int x,y;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&n,&m);

		if(cas!=1)
			puts("");

		printf("Scenario #%d:\n",cas++);

		memset(vis,0,sizeof(vis));
		vis[1][1]=1;
		rem[0]=101;

		if(!dfs(1,1,1))
			puts("impossible");
		else
		{
			for(int i=0;i<n*m;++i)
			{
				x=rem[i]/100;
				y=rem[i]-x*100;

				printf("%c%d",y-1+'A',x);
			}

			puts("");
		}
	}
	
	return 0;
}
