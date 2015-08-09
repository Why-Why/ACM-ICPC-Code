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
// Created Time  : 2015年07月31日 星期五 09时30分47秒
// File Name     : 1012.cpp

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
const int INF=0x3f3f3f3f;

int num[MaxN];
int N;

int dp[MaxN][20];
int logN[MaxN];

int rem[MaxN];
int ans[MaxN];
int kuo[MaxN];

set <int> sta;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];
int COL[MaxN<<2];

void pushUP(int po)
{
	BIT[po]=max(BIT[lc],BIT[rc]);
}

void pushDown(int po)
{
	if(COL[po])
	{
		COL[lc]=COL[rc]=COL[po];
		BIT[lc]=BIT[rc]=BIT[po];
		COL[po]=0;
	}
}

void build(int L,int R,int po)
{
	COL[po]=0;
	
	if(L==R)
	{
		BIT[po]=num[L];
		COL[po]=0;
		return;
	}

	int M=(L+R)>>1;

	build(lson);
	build(rson);

	pushUP(po);
}

void update(int ul,int ur,int ut,int L,int R,int po)
{
	if(ul<=L && ur>=R)
	{
		COL[po]=ut;
		BIT[po]=ut;
		return;
	}

	pushDown(po);

	int M=(L+R)>>1;

	if(ul<=M)
		update(ul,ur,ut,lson);
	if(ur>M)
		update(ul,ur,ut,rson);

	pushUP(po);
}

int query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return BIT[po];

	pushDown(po);

	int M=(L+R)>>1;

	if(qr<=M)
		return query(ql,qr,lson);
	else if(ql>M)
		return query(ql,qr,rson);

	return max(query(ql,qr,lson),query(ql,qr,rson));
}

bool isin(int x)
{
	return query(x,x,1,N,1)==INF;
}

int findYou(int x)
{
	set <int> ::iterator iter=sta.upper_bound(x);

	if(iter==sta.begin())
		return 1;

	--iter;
	
	return *iter;
}

int findMax(int x)
{
	int tou=findYou(x);
	int ret;

	ret=query(tou,x,1,N,1);

	if(kuo[x+1]!=1 && kuo[x+1]!=3 && x<N)
		ret=max(ret,num[x+1]);

	ret=rem[ret];

	return ret;
}

void chuli(int wei,int yuan)
{
	if(wei==yuan+1)
	{
		kuo[wei]=4;
		update(wei,wei,-1,1,N,1);
		return;
	}

	kuo[wei]+=1;
	kuo[yuan+1]+=2;
	update(wei,yuan,INF,1,N,1);
	sta.insert(yuan+1);
}

void getnum()
{
	int rem;

	for(int i=1;i<=N;++i)
	{
		if(kuo[i]==1 || kuo[i]==3)
			rem=i;

		if(kuo[i+1]!=2 && kuo[i+1]!=3)
			ans[num[i]]=num[i+1];
		else
			ans[num[i]]=num[rem];
	}
}

void getans()
{
	int t;

	for(int i=1;i<=N;++i)
	{
		if(isin(rem[i]))
			continue;

		t=findMax(rem[i]);
		chuli(t,rem[i]);
	}

	getnum();
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		kuo[N+1]=0;
		sta.clear();

		for(int i=1;i<=N;++i)
		{
			ans[i]=kuo[i]=0;
			scanf("%d",&num[i]);
			rem[num[i]]=i;
		}

		build(1,N,1);
		getans();

		printf("%d",ans[1]);
		for(int i=2;i<=N;++i)
			printf(" %d",ans[i]);
		puts("");
	}
	
	return 0;
}
