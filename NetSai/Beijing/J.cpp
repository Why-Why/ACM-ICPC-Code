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
// Created Time  : 2015年09月21日 星期一 22时18分24秒
// File Name     : J.cpp

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

const int MaxN=50005;

struct State
{
	int a,id;

	bool operator < (const State &b) const
	{
		return a<b.a;
	}
};

State sta[5][MaxN];
State que[5];
int N,M;
int len;
int Q;

bitset <MaxN> rem[10][230];
int zcou;

void init()
{
	for(int i=0;i<5;++i)
		sort(sta[i]+1,sta[i]+N+1);

	int cou=0;
	zcou=0;

	for(int i=1;i<=N;++i)
	{
		for(int j=0;j<5;++j)
			rem[j][zcou].set(sta[j][i].id);
		++cou;
		if(cou>=len)
		{
			cou=0;
			++zcou;
			for(int j=0;j<5;++j) rem[j][zcou]=rem[j][zcou-1];
		}
	}
}

int query()
{
	bitset <MaxN> ret[5];
	int t;
	int r;

	for(int i=0;i<5;++i)
	{
		t=upper_bound(sta[i]+1,sta[i]+N+1,que[i])-sta[i]-1;
		if(t/len-1>=0)
			ret[i]|=rem[i][t/len-1];
		r=t%len;

		for(int j=0,p=t;j<r;--p,++j)
			ret[i].set(sta[i][p].id);
	}

	for(int i=1;i<5;++i)
		ret[0]&=ret[i];

	return ret[0].count();
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int t;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		len=ceil(sqrt(double(N)));
		for(int i=0;i<5;++i)
			for(int j=0;j<230;++j)
				rem[i][j].reset();
		for(int i=1;i<=N;++i)
			for(int j=0;j<5;++j)
			{
				scanf("%d",&sta[j][i].a);
				sta[j][i].id=i;
			}
		init();

		scanf("%d",&Q);
		t=0;
		while(Q--)
		{
			for(int i=0;i<5;++i)
			{
				scanf("%d",&que[i].a);
				que[i].a^=t;
			}
			t=query();
			printf("%d\n",t);
		}
	}
	
	return 0;
}
