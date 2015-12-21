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
// Created Time  : 2015年10月04日 星期日 13时20分19秒
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

#include <bitset>

using namespace std;

const int MaxN=10004;

int N,K;

struct State
{
	int id,sorce;
	int type;

	bool operator < (const State & b) const
	{
		return sorce>b.sorce;
	}
};

State rem[MaxN],sta[MaxN];

struct Query
{
	int pid;
	int id;
	int s;
	int type;

	bool operator < (const Query & b) const
	{
		return s>b.s;
	}
};

Query que[100005];

bitset <MaxN> brem[2][12];

int ans[100005];
bitset <MaxN> baset;

void add(int p)
{
	baset[sta[p].id-1]=1;

	for(int i=0;i<K;++i)
		if(sta[p].type & (1<<i))
			brem[1][i][sta[p].id-1]=1;
		else
			brem[0][i][sta[p].id-1]=1;
}

int query(int p)
{
	bitset <MaxN> t=baset;

	for(int i=0;i<K;++i)
		if(que[p].type & (1<<i))
		{
			if(rem[que[p].pid].type & (1<<i))
				t &= brem[1][i];
			else
				t &= brem[0][i];
		}

	return t.count()+1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int t,a,temp;
	int type;
	int Q;

	while(~scanf("%d %d",&N,&K))
	{
		for(int i=0;i<2;++i)
			for(int j=0;j<12;++j)
				brem[i][j].reset();
		baset.reset();

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&sta[i].sorce,&t);
			sta[i].id=i;
			sta[i].type=0;

			while(t--)
			{
				scanf("%d",&a);
				sta[i].type|=(1<<(a-1));
			}

			rem[i]=sta[i];
		}

		sort(sta+1,sta+N+1);

		scanf("%d",&Q);
		for(int i=1;i<=Q;++i)
		{
			scanf("%d %d",&temp,&t);
			que[i].pid=temp;
			que[i].id=i;
			que[i].s=rem[temp].sorce;
			que[i].type=0;
			while(t--)
			{
				scanf("%d",&a);
				que[i].type|=(1<<(a-1));
			}
		}

		sort(que+1,que+Q+1);

		int p=1;

		for(int i=1;i<=Q;++i)
		{
			while(p<=N && sta[p].sorce>que[i].s)
			{
				add(p);
				++p;
			}

			ans[que[i].id]=query(i);
		}

		for(int i=1;i<=Q;++i)
			printf("%d\n",ans[i]);
	}
	
	return 0;
}
