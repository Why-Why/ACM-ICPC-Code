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
// Created Time  : 2015年09月27日 星期日 14时40分07秒
// File Name     : 1010.cpp

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

int num[MaxN];

struct State
{
	int h,k;

	bool operator < (const State &b) const
	{
		return h>b.h;
	}
};
State sta[MaxN];
int N;
int ans[MaxN];

int C[MaxN];

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int d)
{
	while(x<=N)
	{
		C[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int x)
{
	int ret=0;

	while(x>0)
	{
		ret+=C[x];
		x-=lowbit(x);
	}

	return ret;
}

int find(int x)		// 寻找树状数组中和为x的第一个位置。
{
	int ans=0,sum=0;

	for(int i=18;i>=0;--i)
	{
		ans+=(1<<i);

		if(ans>N || sum+C[ans]>=x)
			ans-=(1<<i);
		else
			sum+=C[ans];
	}

	return ans+1;
}

void initC()
{
	for(int i=0;i<=N;++i)
		C[i]=0;
	for(int i=1;i<=N;++i)
		add(i,1);
}

void getans()
{
	initC();
	int t;
	for(int i=N;i>=1;--i)
	{
		ans[t=find(num[i]+1)]=sta[i].h;
		add(t,-1);
	}
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
		scanf("%d",&N);
		for(int i=1;i<=N;++i)
			scanf("%d %d",&sta[i].h,&sta[i].k);
		sort(sta+1,sta+N+1);
		for(int i=0;i<=N;++i)
			num[i]=0;

		for(int i=1;i<=N;++i)
			if(sta[i].k>=i)
			{
				ok=0;
				break;
			}
			else
			{
				sta[i].k=max(sta[i].k,i-1-sta[i].k);
				num[i]=sta[i].k;
			}

		getans();
		printf("Case #%d:",cas++);
		if(ok)
		for(int i=N;i>=1;--i)
			printf(" %d",ans[i]);
		else printf(" impossible");
		puts("");
	}
	
	return 0;
}
