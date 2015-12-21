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
// Created Time  : 2015年08月18日 星期二 14时39分46秒
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

const int MaxN=110;
const int mod=1000000007;

int N,M;
int rem[MaxN][MaxN];
bool vis[MaxN];

long long jie[MaxN];

void init()
{
	jie[0]=1;
	for(int i=1;i<=101;++i)
	{
		jie[i]=jie[i-1]*i;
		jie[i]%=mod;
	}
}

int getans(int cou,long long jie)
{
	long long ret=1;
	for(int i=0;i<cou;++i)
		(ret*=jie)%=mod;

	return (int)ret;
}

int getnum(int x)
{
	for(int i=M;i>=1;--i)
		x=rem[i][x];

	return x;
}

bool judge()
{
	for(int i=1;i<=N;++i)
		if(getnum(i)!=i)
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	int cou;
	bool ok;

	init();

	while(~scanf("%d %d",&N,&M))
	{
		ok=1;
		cou=0;
		for(int i=1;i<=M;++i)
		{
			scanf("%d",&t);
			if(t==-1) ++cou;
			else
			{
				for(int j=1;j<=N;++j) vis[j]=0;
				vis[t]=1;
				rem[i][1]=t;
				for(int j=2;j<=N;++j)
				{
					scanf("%d",&t);
					rem[i][j]=t;
					if(t<1 || t>N || vis[t]) ok=0;
					vis[t]=1;
				}
			}
		}

		if(!ok)
		{
			puts("0");
			continue;
		}

		if(!cou)
		{
			if(judge()) puts("1");
			else puts("0");
			continue;
		}

		printf("%d\n",getans(cou-1,jie[N]));
	}
	
	return 0;
}
