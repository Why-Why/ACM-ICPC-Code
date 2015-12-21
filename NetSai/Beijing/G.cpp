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
// Created Time  : 2015年09月20日 星期日 13时46分16秒
// File Name     : G.cpp

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

const int INF=0x3f3f3f3f;

int que[(1<<22)+10];
int first,last;

int zong;

long long vis[7][(1<<22)+10];

int zhuan(int num[])
{
	int ret=0;
	for(int i=1;i<zong;++i)
		ret|=(num[i]<<(3*(i-1)));

	return ret;
}

void chuli(int sta,int lll)
{
	int num[10];
	for(int i=1;i<zong;++i)
		num[i]=((7<<(3*(i-1))) & sta)>>(3*(i-1));

	int wei[10];
	for(int i=1;i<zong;++i) wei[i]=100000;
	for(int i=zong-1;i>=1;--i)
		wei[num[i]+1]=i;

	int t,lt;

	for(int i=1;i<zong;++i)
	{
		if(wei[i]==100000) continue;

		if(i>1 && wei[i-1]>wei[i])
		{
			num[wei[i]]=i-2;
			t=zhuan(num);
			num[wei[i]]=i-1;

			if(vis[zong-2][t]==0)
			{
				vis[zong-2][t]=lll+1;
				que[last++]=t;
			}
		}
		if(i<zong-1 && wei[i+1]>wei[i])
		{
			num[wei[i]]=i;
			t=zhuan(num);
			num[wei[i]]=i-1;

			if(vis[zong-2][t]==0)
			{
				vis[zong-2][t]=lll+1;
				que[last++]=t;
			}
		}
	}
}

void bfs(int start)
{
	first=last=0;
	int t;
	
	que[last++]=start;
	vis[zong-2][start]=1;

	while(last-first)
	{
		t=que[first++];
		chuli(t,vis[zong-2][t]);
	}
}

void init()
{
	int e=0;
	for(int i=1;i<zong;++i)
		e|=((i-1)<<(3*(i-1)));

	bfs(e);
}

int rem[10005];
int temp[30];
int N;
int num[20];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(zong=2;zong<=8;++zong)
		init();

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		zong=N+1;
		int cou=0;
		for(int i=1;i<=N;++i)
		{
			scanf("%d",&num[i]);
			temp[i]=num[i];
		}
		sort(temp+1,temp+N+1);
		for(int i=1;i<=N;++i)
			rem[temp[i]]=i-1;
		for(int i=1;i<=N;++i)
			num[i]=rem[num[i]];
		for(int i=N+1;i<zong;++i)
			num[i]=i-1;

		int s=0;
		for(int i=1;i<zong;++i)
			s|=((i-1)<<(3*num[i]));
		printf("%lld\n",vis[zong-2][s]-1);
	}
	
	return 0;
}
