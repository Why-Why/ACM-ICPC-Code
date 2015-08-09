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
// Created Time  : 2015年07月30日 星期四 12时03分08秒
// File Name     : A.cpp

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

int ans[100005];
int a,b;

bool judge(int x)
{
	bool vis[12]={0};
	int t;

	while(x)
	{
		t=x%10;

		if(vis[t])
			return 0;

		vis[t]=1;

		x/=10;
	}

	return 1;
}

void init()
{
	ans[0]=1;

	for(int i=1;i<=100000;++i)
		if(judge(i))
			ans[i]=ans[i-1]+1;
		else
			ans[i]=ans[i-1];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	init();

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",ans[b]-ans[a-1]);
	}
	
	return 0;
}
