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
// Created Time  : 2015年09月16日 星期三 20时24分32秒
// File Name     : C.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
const int INF=0x3f3f3f3f;

int N;
int x1,Y1,D1;
int x2,y2,D2;

int T1,T2;

int map1[1010][1010];
int map2[1010][1010];

bool judge1(int x,int y)
{
	return x<N && x>=0 && y<N && y>=0 && map1[x][y]==-1;
}

bool judge2(int x,int y)
{
	return x<N && x>=0 && y<N && y>=0 && map2[x][y]==-1;
}

void run1()
{
	int nx,ny;

	map1[x1][Y1]=0;

	while(1)
	{
		nx=x1+step[D1][0];
		ny=Y1+step[D1][1];

		if(judge1(nx,ny)==0)
			(D1+=1)%=4;

		nx=x1+step[D1][0];
		ny=Y1+step[D1][1];

		if(judge1(nx,ny)==0)
		{
			T1=map1[x1][Y1];
			break;
		}

		map1[nx][ny]=map1[x1][Y1]+1;
		x1=nx;
		Y1=ny;
	}
}

bool run2()
{
	int nx,ny;

	map2[x2][y2]=0;

	while(1)
	{
		nx=x2+step[D2][0];
		ny=y2+step[D2][1];

		if(judge2(nx,ny)==0)
		{
			--D2;
			if(D2<0) D2+=4;
		}

		nx=x2+step[D2][0];
		ny=y2+step[D2][1];

		if(judge2(nx,ny)==0)
		{
			T2=map2[x2][y2];
			break;
		}

		map2[nx][ny]=map2[x2][y2]+1;
		x2=nx;
		y2=ny;
	}

	int rem1,rem2,minn=INF;

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			if((map1[i][j]!=-1 && map1[i][j]==map2[i][j]) || (map1[i][j]>T2 && map2[i][j]==T2) || (map1[i][j]==T1 && map2[i][j]>T1))
			{
				int t=max(map1[i][j],map2[i][j]);
				if(minn>t)
				{
					rem1=i;
					rem2=j;
					minn=t;
				}
			}

	if(minn==INF) return 0;
	printf("%d %d\n",rem1,rem2);
	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N) && N)
	{
		scanf("%d %d %d",&x1,&Y1,&D1);
		scanf("%d %d %d",&x2,&y2,&D2);

		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				map1[i][j]=map2[i][j]=-1;

		run1();
		if(run2()==0)
			puts("-1");
	}
	
	return 0;
}
