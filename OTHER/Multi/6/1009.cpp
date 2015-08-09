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
// Created Time  : 2015年08月06日 星期四 16时22分19秒
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

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int MaxN=200005;
const long long INF=100000000000000000LL;

long long BIT[MaxN<<2];

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int N;

struct state
{
	int L,R,c;
};
state sta[MaxN];

void pushUP(int po)
{
	BIT[po]=max(BIT[lc],BIT[rc]);
}

void build(int L,int R,int po)
{
	BIT[po]=INF;

	if(L==R && L==1)
		BIT[po]=0;

	if(L==R)
		return;

	int M=(L+R)>>1;

	build(lson);
	build(rson);
}

long long query(int qt,int L,int R,int po)
{
	if(L==R)
		return BIT[po];

	int M=(L+R)>>1;
	
	if(qt<=M)
		return query(qt,lson);
	else
		return query(qt,rson);
}

struct node
{
	long long val;
	int id;
	long long c;

	bool operator < (const node &b) const
	{
		if(val==b.val)
			return c>b.c;

		return val>b.val;
	}
};

priority_queue <node> que;

int vis[MaxN],flag=1;
node ttt;

long long query_max(int ul,int ur,int L,int R,int po)
{
	if(ul<=L && ur>=R)
		return BIT[po];

	int M=(L+R)>>1;

	if(ul>M)
		return query_max(ul,ur,rson);
	if(ur<=M)
		return query_max(ul,ur,lson);

	return max(query_max(ul,ur,lson),query_max(ul,ur,rson));
}

void update(int ul,int ur,long long ut,int L,int R,int po)
{
	if(L==R)
	{
		if(BIT[po]>ut && vis[L]!=flag)
		{
			BIT[po]=ut;
			ttt.val=ut;
			ttt.id=L;
			ttt.c=sta[L].c;
			que.push(ttt);
		}

		return;
	}

	int M=(L+R)>>1;

	if(ul>M)
		update(ul,ur,ut,rson);
	else if(ur<=M)
		update(ul,ur,ut,lson);
	else
	{
		if(query_max(ul,M,lson)>ut)
			update(ul,ur,ut,lson);
		if(query_max(M+1,ur,rson)>ut)
			update(ul,ur,ut,rson);
	}

	pushUP(po);
}

void getans()
{
	++flag;
	while(!que.empty())
		que.pop();

	node temp;
	temp.val=0;
	temp.id=1;
	temp.c=sta[1].c;
	que.push(temp);

	int id,L,R;

	while(!que.empty())
	{
		temp=que.top();
		que.pop();
		id=temp.id;

		if(vis[id]==flag)
			continue;

		vis[id]=flag;
		L=id+sta[id].L;
		R=id+sta[id].R;
		R=min(R,N);

		if(L<=R)
			update(L,R,temp.val+sta[id].c,1,N,1);

		L=id-sta[id].R;
		R=id-sta[id].L;
		L=max(1,L);

		if(L<=R)
			update(L,R,temp.val+sta[id].c,1,N,1);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	long long t;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;++i)
			scanf("%d",&sta[i].L);
		for(int i=1;i<=N;++i)
			scanf("%d",&sta[i].R);
		for(int i=1;i<=N;++i)
			scanf("%d",&sta[i].c);

		build(1,N,1);
		getans();
		t=query(1,1,N,1);
		printf("%lld",t==INF ? -1 : t);
		for(int i=2;i<=N;++i)
		{
			t=query(i,1,N,1);
			printf(" %lld",t==INF ? -1 : t);
		}
		puts("");
	}

	return 0;
}
