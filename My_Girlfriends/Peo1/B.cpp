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
// Created Time  : 2015年09月16日 星期三 21时17分32秒
// File Name     : B.cpp

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

const int INF=10e8;
const int MaxN=5010;
const int MaxM=100;
const int MaxNode=MaxN*MaxM;            // 这个的大小可以适当减少。 。 。

struct REM
{
	int a,b,c,d;

	REM(int x,int y,int z,int t)
	{
		a=x;
		b=y;
		c=z;
		d=t;
	}
	
	REM()
	{}
};

REM rem[5010];
int X[30],Y[30];

struct State
{
	int x,y;

	State(int a,int b)
	{
		x=a;
		y=b;
	}

	State() {}

	bool operator < (const State &b) const
	{
		if(x==b.x) return y<b.y;
		return x<b.x;
	}
};

bool judge(int a,int b,int c,int d)
{
	State sta[4];
	sta[0]=State(X[a],Y[a]);
	sta[1]=State(X[b],Y[b]);
	sta[2]=State(X[c],Y[c]);
	sta[3]=State(X[d],Y[d]);
	sort(sta,sta+4);

	if(sta[0].x!=sta[1].x) return 0;
	if(sta[2].x!=sta[3].x) return 0;

	if(sta[0].y!=sta[2].y) return 0;
	if(sta[1].y!=sta[3].y) return 0;

	if(sta[2].x-sta[0].x!=sta[1].y-sta[0].y) return 0;
	return 1;
}

bool vis[30];
int cou=0;

int getans(int d)
{
	int ret=0;

	for(int i=d;i<=cou;++i)
		if(!vis[rem[i].a] && !vis[rem[i].b] && !vis[rem[i].c] && !vis[rem[i].d])
		{
			vis[rem[i].a]=vis[rem[i].b]=vis[rem[i].c]=vis[rem[i].d]=1;
			ret=max(1+getans(i+1),ret);
			vis[rem[i].a]=vis[rem[i].b]=vis[rem[i].c]=vis[rem[i].d]=0;
		}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int minX,minY,maxX,maxY;

	while(~scanf("%d",&N) && N!=-1)
	{
		cou=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=N;++i)
			scanf("%d %d",&X[i],&Y[i]);

		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				for(int k=j+1;k<=N;++k)
					for(int t=k+1;t<=N;++t)
						if(judge(i,j,k,t))
							rem[++cou]=REM(i,j,k,t);

		printf("%d\n",4*getans(1));
	}
	
	return 0;
}
