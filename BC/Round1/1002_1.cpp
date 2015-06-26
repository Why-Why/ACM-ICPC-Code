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
// Created Time  : 2015年05月30日 星期六 17时02分16秒
// File Name     : 1002_1.cpp

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

bool ans[10004][1010];
int n,m;
long long num[10004];
int rem[3000];
int flag=1;

int getans(int x)
{
	if(x>n)
		return 0;

	int ret=0;

	for(int i=1;i<=n;++i)
		if(ans[i][x])
			++ret;

	return ret;
}

void init()
{
	long long minn,maxn;
	int cou;
	long long d;

	for(int i=1;i<=n;++i)
	{
		minn=maxn=num[i];
		cou=1;
		++flag;
		rem[1500]=flag;

		for(int j=2;j+i-1<=n;++j)
		{
			d=num[j+i-1]-num[i];

			if(d>1000 || d<-1000)
				break;

			if(rem[1500+d]==flag)
				break;

			rem[1500+d]=flag;

			minn=min(minn,num[j+i-1]);
			maxn=max(maxn,num[j+i-1]);

			if(maxn-minn+1==j)
				ans[i][j]=1;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T=1,cas=1;
	int a;

	while(T--)
	{
		scanf("%d %d",&n,&m);

		for(int i=1;i<=n;++i)
		{
			scanf("%I64d",&num[i]);
			ans[i][1]=1;
		}

		init();

		puts("Case #1:");

		while(m--)
		{
			scanf("%d",&a);
			printf("%d\n",getans(a));
		}
	}
	
	return 0;
}
