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
// Created Time  : 2015年07月28日 星期二 12时24分17秒
// File Name     : 1004.cpp

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

const int MaxN=55;

char map1[MaxN][MaxN];
int N,M;
int sumR=0,sumB=0,sumG=0;

void chuli(int x,int y,int t)
{
	if(t)
	{
		for(;x<=N && y<=M;++x,++y)
		{
			if(map1[x][y]=='R')
			{
				--sumR;
				map1[x][y]='r';
			}
			else if(map1[x][y]=='G')
			{
				--sumG;
				++sumB;
				map1[x][y]='B';
			}
			else if(map1[x][y]=='B' || map1[x][y]=='b' || map1[x][y]=='.')
				break;
		}
	}
	else
	{
		for(;x<=N && y>=1;++x,--y)
		{
			if(map1[x][y]=='B')
			{
				--sumB;
				map1[x][y]='b';
			}
			else if(map1[x][y]=='G')
			{
				--sumG;
				++sumR;
				map1[x][y]='R';
			}
			else if(map1[x][y]=='R' || map1[x][y]=='r' || map1[x][y]=='.')
				break;
		}
	}
}

int getans()
{
	int ret=0;
	sumR=sumB=sumG=0;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map1[i][j]=='R')
				++sumR;
			else if(map1[i][j]=='B')
				++sumB;
			else if(map1[i][j]=='G')
				++sumG;

	while(sumR+sumB+sumG)
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				if(map1[i][j]=='R')
				{
					chuli(i,j,1);
					++ret;
				}
				else if(map1[i][j]=='B')
				{
					chuli(i,j,0);
					++ret;
				}
				else if(map1[i][j]=='G')
				{
					chuli(i,j,0);
					chuli(i,j,1);
					ret+=2;
				}
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%s",map1[i]+1);

		M=strlen(map1[1]+1);

		printf("%d\n",getans());
	}
	
	return 0;
}
