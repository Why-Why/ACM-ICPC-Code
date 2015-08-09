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
// Created Time  : 2015年08月08日 星期六 12时46分53秒
// File Name     : 3140.cpp

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

const int MaxN=100005;
const int MaxM=1000006;
const long long INF=10000000000000000LL;

inline long long abs1(long long x)
{
	return x<0 ? -x : x;
}

struct Edge
{
	int to,next;
};

Edge E[MaxM<<1];
int head[MaxN],Ecou;
long long sum=0;

int N,M;
long long val[MaxN];

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

long long ans;

long long dfs(int u,int pre)
{
	long long size=0;
	long long temp;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			temp=dfs(E[i].to,u);
			ans=min(ans,abs1(sum-temp-temp));
			size+=temp;
		}

	return size+val[u];
}

long long getans()
{
	ans=INF;
	dfs(1,-1);
	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int cas=1;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		init();
		sum=0;
		for(int i=1;i<=N;++i)
		{
			scanf("%lld",&val[i]);
			sum+=val[i];
		}

		while(M--)
		{
			scanf("%d %d",&a,&b);
			if(a==b)
				continue;
			addEdge(a,b);
			addEdge(b,a);
		}

		printf("Case %d: %lld\n",cas++,getans());
	}
	
	return 0;
}
