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
// Created Time  : 2015年09月28日 星期一 22时51分09秒
// File Name     : 2.cpp

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

int N,M,K;
int num[MaxN][MaxN];

int vis[MaxN];
int tvis[MaxN];
int ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&M,&K);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			scanf("%d",&num[i][j]);

	for(int i=1;i<=M;++i)
	{
		memset(tvis,0,sizeof(tvis));
		for(int j=1;j<=N;++j)
		{
			if(ans[j]) continue;
			if(num[j][i]==0) continue;
			if(vis[num[j][i]])
			{
				ans[j]=i;
				continue;
			}
			if(tvis[num[j][i]])
			{
				ans[j]=i;
				ans[tvis[num[j][i]]]=i;
				vis[num[j][i]]=1;
				continue;
			}
			tvis[num[j][i]]=j;
		}
	}

	for(int i=1;i<=N;++i)
		printf("%d\n",ans[i]);
	
	return 0;
}
