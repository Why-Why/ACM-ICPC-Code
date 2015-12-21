// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年10月12日 星期一 18时20分55秒
// File Name     : D.cpp

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

const int MaxN=110;

int N,K;

char map1[5][MaxN];
int vis[5][MaxN];

int que[1000000];
int first,last;

void bfs()
{
	first=last=0;
	int p;
	int x,y;
	int t;
	int u;
	for(int i=1;i<=3;++i) if(map1[i][1]=='s') p=i;

	que[last++]=p*1000+1;
	vis[p][1]=1;

	while(last-first)
	{
		u=que[first++];
		x=u/1000;
		y=u%1000;
		t=vis[x][y];

		if(y<N && vis[x][y+1]!=1 && map1[x][y+1]=='.')
		{
			vis[x][y+1]=1;
			que[last++]=x*1000+y+1;
		}

		if(y%3==2 && x>1 && t==1 && vis[x-1][y]==0 && map1[x-1][y]=='.')
		{
			vis[x-1][y]=2;
			que[last++]=(x-1)*1000+y;
		}

		if(y%3==2 && x<3 && t==1 && vis[x+1][y]==0 && map1[x+1][y]=='.')
		{
			vis[x+1][y]=2;
			que[last++]=(x+1)*1000+y;
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
		scanf("%d %d",&N,&K);
		for(int i=1;i<=3;++i)
			scanf("%s",map1[i]+1);
		memset(vis,0,sizeof(vis));

		bfs();

		if(vis[1][N] || vis[2][N] || vis[3][N])
			puts("YES");
		else puts("NO");
	}
	
	return 0;
}
