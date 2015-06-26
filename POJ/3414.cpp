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
// Created Time  : 2015年05月08日 星期五 23时04分12秒
// File Name     : 3414.cpp

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

int vis[110][110];
int A,B,C;
int ans[10000];
int cou;
int que[100010];
int first,last;

const char fang[7][10]={"","FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};

void showans(int x,int y)
{
	int t;

	cou=0;

	while(x!=0 || y!=0)
	{
		t=vis[x][y];

		ans[cou++]=t/1000000;
		x=(t%1000000)/1000;
		y=t%1000;
	}

	printf("%d\n",cou);
	for(int i=cou-1;i>=0;--i)
		puts(fang[ans[i]]);
}

void bfs()
{
	int t,tx,ty;
	int d;

	cou=0;
	first=last=0;
	vis[0][0]=0;
	que[last++]=0;

	while(last-first)
	{
		t=que[first++];
		tx=t/1000;
		ty=t-tx*1000;

		if(tx==C || ty==C)
		{
			showans(tx,ty);
			return;
		}

		if(vis[A][ty]==-1)
		{
			vis[A][ty]=1*1000000+tx*1000+ty;
			que[last++]=A*1000+ty;
		}

		if(vis[tx][B]==-1)
		{
			vis[tx][B]=2*1000000+tx*1000+ty;
			que[last++]=tx*1000+B;
		}

		if(vis[0][ty]==-1)
		{
			vis[0][ty]=3*1000000+tx*1000+ty;
			que[last++]=ty;
		}

		if(vis[tx][0]==-1)
		{
			vis[tx][0]=4*1000000+tx*1000+ty;
			que[last++]=tx*1000;
		}

		d=min(tx,B-ty);

		if(vis[tx-d][ty+d]==-1)
		{
			vis[tx-d][ty+d]=5*1000000+tx*1000+ty;
			que[last++]=(tx-d)*1000+ty+d;
		}

		d=min(ty,A-tx);

		if(vis[tx+d][ty-d]==-1)
		{
			vis[tx+d][ty-d]=6*1000000+tx*1000+ty;
			que[last++]=(tx+d)*1000+ty-d;
		}
	}

	cou=0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&A,&B,&C);
	memset(vis,-1,sizeof(vis));

	bfs();

	if(cou==0)
		puts("impossible");
	
	return 0;
}
