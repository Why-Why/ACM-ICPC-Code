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
// Created Time  : 2015年07月30日 星期四 13时23分34秒
// File Name     : 1009.cpp

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

const int MaxN=1010;

char map1[MaxN][MaxN];
int N,M;

const int INF=0x3f3f3f3f;

int lowcost[MaxN][MaxN];
bool vis[MaxN][MaxN],vis1[MaxN][MaxN];
int QUE1[MaxN*MaxN],QUE2[MaxN*MaxN];
int first1,last1,first,last;
int *que,*que1;

int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int rem[MaxN][MaxN];
int tcou;
int trem[MaxN*3];
int minn;

int zhong[MaxN][MaxN];

void chushi()
{
	if(map1[1][1]=='1')
	{
		minn=N+M-2;
		rem[1][1]=minn;
		que[last++]=1*10000+1;
		
		return;
	}

	int t,x,y;
	int nx,ny;

	minn=INF;
	tcou=0;

	first1=last1=0;
	que1[last1++]=1*10000+1;
	vis1[1][1]=1;

	while(last1-first1)
	{
		t=que1[first1++];
		x=t/10000;
		y=t-x*10000;

		if(map1[x][y]=='1')
			continue;
		
		rem[x][y]=N-x+M-y;
		minn=min(minn,N+M-x-y);

		for(int i=0;i<4;++i)
		{
			nx=x+step[i][0];
			ny=y+step[i][1];

			if(nx>=1 && ny>=1 && nx<=N && ny<=M)
				if(vis1[nx][ny]==0 && map1[nx][ny]=='0')
				{
					vis1[nx][ny]=1;
					que1[last1++]=nx*10000+ny;
				}
		}
	}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(rem[i][j]==minn)
			{
				que[last++]=i*10000+j;
				lowcost[i][j]=0;
				trem[tcou++]=i*10000+j;
			}
}

void getans()
{
	int u,v,t;
	bool ok,ok1;
	int x,y,nx,ny;
	
	first1=last1=first=last=0;
	que=QUE1;
	que1=QUE2;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
		{
			rem[i][j]=INF;
			vis[i][j]=0;
			vis1[i][j]=0;
			lowcost[i][j]=INF;
			zhong[i][j]=INF;
		}

	chushi();
	ok=1;

	if(minn==0)
		return;

	for(int i=1;i<=(N+M-1);++i)
	{
		last1=first1=0;
		ok1=1;

		while(last-first)
		{
			u=que[first++];
			x=u/10000;
			y=u-x*10000;

			if(map1[x][y]=='1' && ok==0)
				continue;

			lowcost[x][y]=0;

			if(x<N && vis[x+1][y]==0)
			{
				que1[last1++]=(x+1)*10000+y;
				vis[x+1][y]=1;

				if(map1[x+1][y]=='0')
					ok1=0;
			}

			if(y<M && vis[x][y+1]==0)
			{
				que1[last1++]=x*10000+y+1;
				vis[x][y+1]=1;

				if(map1[x][y+1]=='0')
					ok1=0;
			}
			/*
			if(x>1 && vis[x-1][y]==0)
			{
				cout<<x-1<<' '<<y<<endl;
				que1[last1++]=(x-1)*10000+y;
				vis[x-1][y]=1;

				if(map1[x-1][y]=='0')
					ok1=0;
			}

			if(y<M && vis[x][y+1]==0)
			{
				que1[last1++]=x*10000+y+1;
				vis[x][y+1]=1;

				if(map1[x][y+1]=='0')
					ok1=0;
			}*/
		}

		swap(ok,ok1);
		swap(first,first1);
		swap(last,last1);
		swap(que,que1);
	}
}

void showans()
{
	if(N==1 && M==1)
	{
		printf("%c\n",map1[1][1]);
		return;
	}

	if(minn==0)
	{
		puts("0");
		return;
	}

	first=last=0;
	que[last++]=N*10000+M;
	zhong[N][M]=0;

	int t,x,y;

	while(last-first)
	{
		t=que[first++];
		x=t/10000;
		y=t-x*10000;

		if(rem[x][y]==minn)
			break;

		if(x-1>=1 && zhong[x-1][y]==INF && lowcost[x-1][y]==0)
		{
			zhong[x-1][y]=zhong[x][y]+1;
			que[last++]=(x-1)*10000+y;
		}

		if(y-1>=1 && zhong[x][y-1]==INF && lowcost[x][y-1]==0)
		{
			zhong[x][y-1]=zhong[x][y]+1;
			que[last++]=x*10000+y-1;
		}
	}

	int cou=0;
	bool first=1;

	while(1)
	{
		if(map1[x][y]=='0' && !first)
			printf("0");
		else if(map1[x][y]=='1')
		{
			printf("1");
			first=0;
		}

		if(x==N && y==M)
			break;

		if(x+1<=N && zhong[x+1][y]==zhong[x][y]-1)
			++x;
		else
			++y;
	}

	puts("");
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);

		for(int i=1;i<=N;++i)
			scanf("%s",map1[i]+1);

		getans();
		showans();
	}
	
	return 0;
}
