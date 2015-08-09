// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年07月16日 星期四 19时07分04秒
// File Name     : 2750.cpp

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

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int LN[MaxN<<2],RN[MaxN<<2],BIT[MaxN<<2],SUM[MaxN<<2];
int ln[MaxN<<2],rn[MaxN<<2],bit[MaxN<<2];
int minn[MaxN<<2];

void pushUP(int po)
{
	SUM[po]=SUM[lc]+SUM[rc];

	minn[po]=min(minn[lc],minn[rc]);

	BIT[po]=max(BIT[lc],BIT[rc]);
	BIT[po]=max(BIT[po],max(SUM[lc]+LN[rc],SUM[rc]+RN[lc]));
	BIT[po]=max(BIT[po],LN[rc]+RN[lc]);

	LN[po]=max(LN[lc],SUM[lc]+LN[rc]);
	RN[po]=max(RN[rc],SUM[rc]+RN[lc]);

	bit[po]=min(bit[lc],bit[rc]);
	bit[po]=min(bit[po],min(SUM[lc]+ln[rc],SUM[rc]+rn[lc]));
	bit[po]=min(bit[po],ln[rc]+rn[lc]);

	ln[po]=min(ln[lc],SUM[lc]+ln[rc]);
	rn[po]=min(rn[rc],SUM[rc]+rn[lc]);
}

void update(int up,int ut,int L,int R,int po)
{
	if(L==R)
	{
		SUM[po]=BIT[po]=LN[po]=RN[po]=ut;
		bit[po]=ln[po]=rn[po]=ut;
		minn[po]=ut;
		return;
	}

	int M=(L+R)>>1;

	if(up<=M)
		update(up,ut,lson);
	else
		update(up,ut,rson);

	pushUP(po);
}

int num[MaxN];

void build(int L,int R,int po)
{
	if(L==R)
	{
		LN[po]=RN[po]=BIT[po]=SUM[po]=num[L];
		ln[po]=rn[po]=bit[po]=num[L];
		minn[po]=num[L];
		return;
	}

	int M=(L+R)>>1;

	build(lson);
	build(rson);

	pushUP(po);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int ans;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d",&num[i]);

	build(1,N,1);

	int M,a,b;

	scanf("%d",&M);

	while(M--)
	{
		scanf("%d %d",&a,&b);

		update(a,b,1,N,1);

		ans=max(BIT[1],SUM[1]-bit[1]);

		if(ans==SUM[1])
			ans-=minn[1];

		printf("%d\n",ans);
	}
	
	return 0;
}
