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
// Created Time  : 2015年09月12日 星期六 12时34分53秒
// File Name     : F.cpp

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

const int MaxN=50;

int hp[MaxN];
int N,C;

int getans()
{
	int p=1;
	int fang=1;
	int cou=0;

	for(int i=1;i<N+5;++i)
	{
		if(hp[p]<=C)
		{
			hp[p]=0;
			fang=-fang;
			++cou;
			if(cou>=N)
				return p;
		}
		else
		{
			hp[p]-=C;
			p+=fang;
			if(p>N) p=1;
			else if(p<1) p=N;
		}

		if(fang==1)
		{
			while(hp[p]==0)
			{
				++p;
				if(p>N) p-=N;
			}
		}
		else
		{
			while(hp[p]==0)
			{
				--p;
				if(p<1) p=N;
			}
		}
	}

	return p;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&C);

		for(int i=1;i<=N;++i)
			scanf("%d",&hp[i]);

		printf("%d\n",getans());
	}
	
	return 0;
}
