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
// Created Time  : 2015年07月01日 星期三 22时48分20秒
// File Name     : 2777.cpp

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

#define lc po*2
#define rc po*2+1
#define lson L,M,lc
#define rson M+1,R,rc

const int MaxN=100005;

int BIT[MaxN<<2];
int COL[MaxN<<2];

void pushUP(int po)
{
	BIT[po]=BIT[lc]|BIT[rc];
}

void pushDown(int po)
{
	if(COL[po])
	{
		COL[lc]=COL[rc]=COL[po];
		BIT[lc]=BIT[rc]=(1<<(COL[po]-1));
		COL[po]=0;
	}
}

void update(int ul,int ur,int ut,int L,int R,int po)
{
	if(ul<=L && ur>=R)
	{
		BIT[po]=(1<<(ut-1));
		COL[po]=ut;

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

	if(ql>M)
		return query(ql,qr,rson);
	if(qr<=M)
		return query(ql,qr,lson);

	return query(ql,qr,lson)|query(ql,qr,rson);
}

int getans(int x)
{
	int ret=0;

	while(x)
	{
		if(x&1)
			++ret;
		x>>=1;
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,T,O;
	int a,b,c;
	char s[10];

	scanf("%d %d %d",&N,&T,&O);

	update(1,N,1,1,N,1);

	while(O--)
	{
		scanf("%s",s);

		if(s[0]=='C')
		{
			scanf("%d %d %d",&a,&b,&c);
			
			if(a>b)
				swap(a,b);

			update(a,b,c,1,N,1);
		}
		else
		{
			scanf("%d %d",&a,&b);

			if(a>b)
				swap(a,b);

			printf("%d\n",getans(query(a,b,1,N,1)));
		}
	}

	return 0;
}
