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
// Created Time  : 2015年09月16日 星期三 11时16分13秒
// File Name     : 1009.cpp

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

const int MaxN=60005;
const int INF=0x3f3f3f3f;

int N,M,P;
int dp1[MaxN];

int rlog[110][20],cou[110];

void init()
{
	int t,sum;

	for(int i=1;i<=105;++i)
	{
		sum=0;
		t=1;
		while(sum<i)
		{
			if(sum+t>i) t=i-sum;
			rlog[i][cou[i]++]=t;
			sum+=t;
			t<<=1;
		}
	}
}

struct Cake
{
	int t,u,v;
}cake[210];

struct Car
{
	int x,y,z;
}car[210];

int getdp1()
{
	int LIM=P+1001;
	int t,r;

	for(int i=0;i<=LIM;++i) dp1[i]=INF;
	dp1[0]=0;

	for(int i=1;i<=N;++i)
		for(int j=0;j<cou[cake[i].v];++j)
		{
			t=cake[i].t*rlog[cake[i].v][j];
			r=cake[i].u*rlog[cake[i].v][j];
			for(int k=LIM;k>=t;--k)
				if(dp1[k-t]!=INF)				// !!!
					dp1[k]=min(dp1[k],dp1[k-t]+r);
		}

	int ret=INF;
	for(int i=P;i<=LIM;++i)
		ret=min(ret,dp1[i]);
	return ret;
}

int getdp2(int minn)
{
	int LIM=50000;
	int t,r;

	for(int i=0;i<=LIM;++i) dp1[i]=-1;
	dp1[0]=0;

	for(int i=1;i<=M;++i)						// !!!
		for(int j=0;j<cou[car[i].z];++j)
		{
			t=car[i].y*rlog[car[i].z][j];
			r=car[i].x*rlog[car[i].z][j];
			for(int k=LIM;k>=t;--k)
				if(dp1[k-t]!=-1)
					dp1[k]=max(dp1[k],dp1[k-t]+r);
		}

	for(int i=0;i<=LIM;++i)
		if(dp1[i]>=minn)
			return i;
	return -1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int t;

	init();

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&N,&M,&P);
		for(int i=1;i<=N;++i)
			scanf("%d %d %d",&cake[i].t,&cake[i].u,&cake[i].v);
		for(int i=1;i<=M;++i)
			scanf("%d %d %d",&car[i].x,&car[i].y,&car[i].z);

		t=getdp2(getdp1());
		if(t==-1 || t>50000)
			puts("TAT");
		else printf("%d\n",t);
	}
	
	return 0;
}
