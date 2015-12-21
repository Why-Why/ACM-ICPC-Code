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
// Created Time  : 2015年09月24日 星期四 23时56分33秒
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

const int MaxN=1010;

int num[MaxN];
int N;
int ans[MaxN];
bool vis[MaxN];

int getans(int x)
{
	for(int i=1;i<=N;++i)
	{
		if(!vis[i])
			--x;
		if(x==-1) return i;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N))
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=N;++i)
			scanf("%d",num+i);
		for(int i=1;i<=N;++i)
		{
			ans[i]=getans(num[i]);
			vis[ans[i]]=1;
		}
		for(int i=1;i<N;++i)
			printf("%d ",ans[i]);
		printf("%d\n",ans[N]);
	}	
	
	return 0;
}
