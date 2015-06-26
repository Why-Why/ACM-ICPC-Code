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
// Created Time  : 2015年05月10日 星期日 10时18分30秒
// File Name     : 2362.cpp

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

int num[30];
int N;
int len;
bool vis[30];

bool dfs(int bian,int chang,int kai)
{
	if(bian==4)
		return 1;

	for(int i=kai;i<=N;++i)
	{
		if(vis[i-1]==0 && num[i]==num[i-1])
			continue;

		if(vis[i])
			continue;

		if(chang<num[i])
			continue;
		else if(chang==num[i])
		{
			vis[i]=1;
			if(dfs(bian+1,len,0))
				return 1;
			else if(chang==len)
			{
				vis[i]=0;
				return 0;
			}
			vis[i]=0;
		}
		else
		{
			vis[i]=1;
			if(dfs(bian,chang-num[i],i))
				return 1;
			else if(chang==len)
			{
				vis[i]=0;
				return 0;
			}
			vis[i]=0;
		}
	}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		len=0;
		memset(vis,0,sizeof(vis));

		scanf("%d",&N);
		num[0]=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&num[i]);
			len+=num[i];
		}

		sort(num+1,num+N+1,greater<int>());

		if(N<4 || len%4)
		{
			puts("no");
			continue;
		}

		len>>=2;

		if(len<num[1])
		{
			puts("no");
			continue;
		}

		if(dfs(1,len,1))
			puts("yes");
		else
			puts("no");
	}
	
	return 0;
}
