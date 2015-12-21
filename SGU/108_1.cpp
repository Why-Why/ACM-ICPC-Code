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
// Created Time  : 2015年08月15日 星期六 09时59分09秒
// File Name     : 108_1.cpp

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

char vis[10000000/8+10];

int bian(int x)
{
	int ret=x;
	int t;

	while(x)
	{
		t=x/10;
		ret+=x-10*t;
		x=t;
	}

	return ret;
}

struct state
{
	int id,num;

	bool operator < (const state &b) const
	{
		return num<b.num;
	}
};

state sta[5010];
int ans[5010];

int getans(int N)
{
	int p=1;
	int cou=0;
	for(int i=1;i<=N;++i)
		if(!(vis[(i-1)/8] & (1<<((i-1)%8))))
		{
			++cou;
			while(cou==sta[p].num)
			{
				ans[sta[p].id]=i;
				++p;
			}
			for(int j=bian(i);!(vis[(j-1)/8] & (1<<((j-1)%8))) && j<=N;j=bian(j))
				vis[(j-1)/8]|=(1<<((j-1)%8));
		}

	return cou;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,K;
	int a;

	scanf("%d %d",&N,&K);
	for(int i=1;i<=K;++i)
	{
		scanf("%d",&sta[i].num);
		sta[i].id=i;
	}

	sort(sta+1,sta+K+1);
	sta[K+1].num=-1;

	printf("%d\n",getans(N));
	for(int i=1;i<K;++i)
		printf("%d ",ans[i]);
	printf("%d\n",ans[K]);
	
	return 0;
}
