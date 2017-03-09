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
// Created Time  : 2015年09月13日 星期日 10时25分09秒
// File Name     : 1005.cpp

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

const int MaxM=100005;
const int MaxN=20004;

/*
struct Edge
{
	int to,next;
};

Edge E[MaxM<<1];
int head[MaxN],Ecou;*/

long long zans=0;
int fa[MaxN];
int size[MaxN];

int N,M,Q;

struct Edge
{
	int u,v,c;

	bool operator < (const Edge &b) const
	{
		return c<b.c; 
	}
};

Edge E[MaxM<<1];

void init(int N)
{
	zans=0;
	for(int i=1;i<=N;++i)
	{
		fa[i]=-1;
		size[i]=1;
	}
}

int find(int x)
{
	if(fa[x]==-1)
		return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

struct Query
{
	int id,v;

	Query(int a=0,int b=0)
	{
		id=a;
		v=b;
	}

	bool operator < (const Query & b) const
	{
		return v<b.v;
	}
};

Query que[5005];
long long ans[5005];

inline long long getnum(long long x)
{
	return x*(x-1LL);
}

void chuli(int u,int v)
{
	int x=find(u),y=find(v);

	if(x==y) return;

	zans-=getnum(size[x]);
	zans-=getnum(size[y]);
	zans+=getnum(size[x]+size[y]);
	size[y]+=size[x];
	fa[x]=y;
}

void getans()
{
	zans=0;
	int p=1;

	for(int i=1;i<=Q;++i)
	{
		while(p<=M && E[p].c<=que[i].v)
		{
			chuli(E[p].u,E[p].v);
			++p;
		}

		ans[que[i].id]=zans;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b,c;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&N,&M,&Q);
		init(N);

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			E[i].u=a;
			E[i].v=b;
			E[i].c=c;
		}

		for(int i=1;i<=Q;++i)
		{
			scanf("%d",&a);
			que[i].id=i;
			que[i].v=a;
		}

		sort(E+1,E+M+1);
		sort(que+1,que+Q+1);
		getans();

		for(int i=1;i<=Q;++i)
			printf("%I64d\n",ans[i]);
	}
	
	return 0;
}
