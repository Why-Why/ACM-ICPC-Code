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
// Created Time  : 2015年08月06日 星期四 14时24分53秒
// File Name     : 1008.cpp

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

struct state
{
	int L,R;
	int id;

	bool operator < (const state &b) const
	{
		if(L==b.L)
			return R<b.R;

		return L<b.L;
	}
};

state sta[MaxN];
int N;
int ans;
int rem[MaxN];

struct node
{
	int val,id;

	bool operator < (const node &b) const
	{
		return val>b.val;
	}
};

priority_queue <node> que;

int vis[MaxN],flag=0;

void insert(int val,int id)
{
	node temp;
	temp.val=val;
	temp.id=id;
	que.push(temp);
}

int find(int val)
{
	node temp;

	while(!que.empty())
	{
		temp=que.top();
		que.pop();

		if(temp.val>=val)
			return temp.id;
	}

	return -1;
}

void getans()
{
	sort(sta+1,sta+N+1);
	ans=0;

	int p=1,t;

	while(!que.empty())
		que.pop();

	for(ans=1;ans<=N;++ans)
	{
		while(p<=N && sta[p].L<=ans-1)
		{
			insert(sta[p].R,sta[p].id);
			++p;
		}

		t=find(ans-1);

		if(t==-1)
			break;

		rem[ans]=t;
		vis[t]=flag;
	}

	--ans;
	
	for(int i=1,j=ans+1;i<=N;++i)
		if(vis[i]!=flag)
			rem[j++]=i;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		++flag;
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
		{
			sta[i].id=i;
			scanf("%d",&sta[i].L);
		}

		for(int i=1;i<=N;++i)
			scanf("%d",&sta[i].R);

		getans();
		printf("%d\n",ans);

		printf("%d",rem[1]);
		for(int i=2;i<=N;++i)
			printf(" %d",rem[i]);
		puts("");
	}
	
	return 0;
}
