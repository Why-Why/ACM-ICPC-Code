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
// Created Time  : 2015年07月20日 星期一 08时55分13秒
// File Name     : 1054.cpp

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

const int MaxN=5005;

int R,C;
short dp[MaxN][MaxN];
int N;

struct Point
{
	int x,y;

	bool operator < (const Point &b) const
	{
		if(x==b.x)
			return y<b.y;

		return x<b.x;
	}
}P[MaxN];

inline bool in(int x,int y)
{
	return x<=R && x>=1 && y<=C && y>=1;
}

const int HASH=1000003;

struct HASHMAP
{
	int head[HASH],next[MaxN],Hcou;
	unsigned long long key[MaxN];
	int rem[MaxN];

	void init()
	{
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(unsigned long long val,int id)
	{
		int h=val%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(val==key[i])
				return;

		rem[Hcou]=id;
		key[Hcou]=val;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	int find(unsigned long long val)
	{
		int h=val % HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(val==key[i])
				return rem[i];

		return 0;
	}
}map1;

int dfs(int u,int v)
{
	if(dp[u][v])
		return dp[u][v];

	int dx=(P[v].x<<1)-P[u].x,dy=(P[v].y<<1)-P[u].y;

	if(!in(dx,dy))
		return 2;

	int rP=map1.find(dx*10000+dy);

	if(!rP)
	{
		dp[u][v]=-1;
		return -1;
	}

	dp[u][v]=dfs(v,rP)+1;

	return dp[u][v];
}

inline bool judge(int u,int v)
{
	int dx=(P[u].x<<1)-P[v].x,dy=(P[u].y<<1)-P[v].y;

	return !in(dx,dy);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=-100;

	scanf("%d %d",&R,&C);
	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d %d",&P[i].x,&P[i].y);

	sort(P+1,P+N+1);

	map1.init();

	for(int i=1;i<=N;++i)
		map1.insert(10000*P[i].x+P[i].y,i);

	for(int i=1;i<=N;++i)
		for(int j=i+1;j<=N;++j)
			if(judge(i,j))
				ans=max(ans,dfs(i,j));

	if(ans<3)
		ans=0;

	printf("%d\n",ans);
	
	return 0;
}
