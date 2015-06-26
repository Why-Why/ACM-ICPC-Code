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
// Created Time  : 2015年06月18日 星期四 21时01分56秒
// File Name     : 1716.cpp

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

const int MaxN=10004;

struct state
{
	int L,R;

	bool operator < (const state &b) const
	{
		if(R!=b.R)
			return R<b.R;

		return L>b.L;
	}
};

state sta[MaxN];
int N;

int getans()
{
	int ret=0;
	int a=-1,b=-1;

	for(int i=1;i<=N;++i)
	{
		if(sta[i].L<=a)
			continue;

		if(sta[i].L>a && sta[i].L<=b)
		{
			++ret;
			a=b;
			b=sta[i].R;

			continue;
		}

		ret+=2;
		a=sta[i].R-1;
		b=sta[i].R;
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%d %d",&sta[i].L,&sta[i].R);

		sort(sta+1,sta+N+1);

		printf("%d\n",getans());
	}
	
	return 0;
}
