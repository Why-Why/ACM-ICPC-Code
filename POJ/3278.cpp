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
// Created Time  : 2015年05月08日 星期五 20时28分59秒
// File Name     : 3278.cpp

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

int vis[300005];
int N,K;
int que[300005];
int first,last;

int bfs(int sx)
{
	int x;

	first=last=0;
	vis[sx]=1;
	que[last++]=sx;

	while(last-first)
	{
		x=que[first++];

		if(x==K)
			return vis[x]-1;

		if(x+1<=300000 && !vis[x+1])
		{
			vis[x+1]=vis[x]+1;
			que[last++]=x+1;
		}
		if(x-1>=0 && !vis[x-1])
		{
			vis[x-1]=vis[x]+1;
			que[last++]=x-1;
		}
		if(x*2<=300000 && !vis[x*2])
		{
			vis[x*2]=vis[x]+1;
			que[last++]=x*2;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&K))
	{
		memset(vis,0,sizeof(vis));
		printf("%d\n",bfs(N));
	}
	
	return 0;
}
