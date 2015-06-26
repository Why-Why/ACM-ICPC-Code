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
// Created Time  : 2015年05月07日 星期四 23时59分59秒
// File Name     : 3022.cpp

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

int dp[1000][9000];
int que[9000006];
int first,last;

void init()
{
	int t;
	int tx,ty,nx,ny;

	que[last++]=0;

	while(last-first)
	{
		t=que[first++];
		tx=t/10000;
		ty=t-tx*10000;

		for(int i=1;i<=9;++i)
		{
			nx=tx+i;
			ny=ty+i*i;

			if(nx<=900 && ny<=8100)
				if(dp[nx][ny]==0 || dp[nx][ny]>dp[tx][ty]+1)
				{
					dp[nx][ny]=dp[tx][ty]+1;
					que[last++]=nx*10000+ny;
				}
		}
	}
}

int rem[110];

void dfs(int x,int y,int d)
{
	if(x==0 && y==0)
		return;

	int t=dp[x][y];

	if(t==1)
	{
		rem[d]=x;
		return;
	}

	for(int i=1;i<=9;++i)
		if(x>=i && y>=i*i && dp[x-i][y-i*i]==t-1)
		{
			rem[d]=i;
			dfs(x-i,y-i*i,d+1);
			return;
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int sa,sb;
	int T;
	int t;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&sa,&sb);

		if(sa<=0 || sb<=0 || sa>900 || sb>8100 || dp[sa][sb]>100 || dp[sa][sb]==0)
		{
			puts("No solution");
			continue;
		}

		dfs(sa,sb,0);

		t=dp[sa][sb];

		sort(rem,rem+t);

		for(int i=0;i<t;++i)
			printf("%d",rem[i]);
		puts("");
	}
	
	return 0;
}
