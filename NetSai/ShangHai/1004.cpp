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
// Created Time  : 2015年09月26日 星期六 13时17分41秒
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

const int mod=1000000007;
int h,w,m,n;

struct State
{
	int x1,y1,x2,y2;
	int v;

	bool operator < (const State & b) const
	{
		return v<b.v;
	}
};

State sta[20];

bool chuli(int x)
{
	long long
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	bool ok;

	scanf("%d",&T);

	while(T--)
	{
		ok=1;
		scanf("%d %d %d %d",&h,&w,&m,&n);
		for(int i=1;i<=n;++i)
			scanf("%d %d %d %d %d",&sta[i].x1,&sta[i].y1,&sta[i].x2,&sta[i].y2,&sta[i].v);
		sort(sta+1,sta+n+1);
		for(int i=1;i<=n;++i)
			if(chuli(i)==0)
				ok=0;

		printf("Case #%d: ",cas++);
		if(!ok) printf("0\n");
		else printf("%d\n",(int)getans());
	}
	
	return 0;
}
