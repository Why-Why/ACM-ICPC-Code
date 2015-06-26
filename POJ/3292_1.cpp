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
// Created Time  : 2015年05月16日 星期六 16时07分46秒
// File Name     : 3292_1.cpp

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

bool vis[300000];
int prime[100000];
int pcou=0;

int ans[300000];

bool judge(int x)
{
	int t;

	for(int i=0;i<pcou;++i)
	{
		t=(x-prime[i])/((prime[i]<<2)+1);

		if(t<prime[i])
			break;

		if(vis[t]==0 && t*((prime[i]<<2)+1)==x-prime[i])
			return 1;
	}

	return 0;
}

void init()
{
	for(int i=1;i<=250000;++i)
		if(vis[i]==0)
		{
			prime[pcou++]=i;

			for(int j=4*i+i+1;j<=250000;j+=(i<<2)+1)
				vis[j]=1;
		}

	for(int i=1;i<=250000;++i)
	{
		ans[i]=ans[i-1];

		if(judge(i))
			++ans[i];
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	init();

	while(~scanf("%d",&a) && a)
		printf("%d %d\n",a,ans[(a-1)/4]);
	
	return 0;
}
