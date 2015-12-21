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
// Created Time  : 2015年10月14日 星期三 23时50分04秒
// File Name     : I.cpp

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

bool vis[10000007];

void init()
{
	vis[1]=1;
	for(long long i=2;i<=10000001;++i)
		if(!vis[i])
			for(long long j=i*i;j<=10000001;j+=i)
				vis[j]=1;
}

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

const int MaxN=100005;

int BIT[MaxN<<2];
int COL[MaxN<<2];

int num[MaxN];

void pushUP(int po)
{
	BIT[po]=BIT[lc]+BIT[rc];
}

void pushDown(int L,int M,int R,int po)
{
	if(COL[po])
	{
		COL[lc]=COL[rc]=COL[po];
		if(vis[COL[po]]==0) BIT[lc]=M-L+1,BIT[rc]=R-M;
		else BIT[lc]=BIT[rc]=0;
		COL[po]=0;
	}
}

void build(int L,int R,int po)
{
	COL[po]=0;
	if(L==R)
	{
		int t;
		scanf("%d",&t);
		num[L]=t;
		BIT[po]=!vis[t];
		return;
	}

	int M=(L+R)>>1;
	build(lson);
	build(rson);
	pushUP(po);
}

void update(int up,int ut,int L,int R,int po)
{
	if(L==R)
	{
		if(COL[po]) { num[L]=COL[po];COL[po]=0; }
		if(vis[num[L]+ut]) BIT[po]=0;
		else BIT[po]=1;
		num[L]+=ut;
		return;
	}

	int M=(L+R)>>1;
	pushDown(L,M,R,po);
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);

	pushUP(po);
}

void update(int ul,int ur,int ut,int L,int R,int po)
{
	if(ul<=L && ur>=R)
	{
		COL[po]=ut;
		if(!vis[ut]) BIT[po]=R-L+1;
		else BIT[po]=0;
		return;
	}

	int M=(L+R)>>1;
	pushDown(L,M,R,po);

	if(ul<=M) update(ul,ur,ut,lson);
	if(ur>M) update(ul,ur,ut,rson);

	pushUP(po);
}

int query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return BIT[po];

	int M=(L+R)>>1;
	pushDown(L,M,R,po);
	int ret=0;

	if(ql<=M) ret+=query(ql,qr,lson);
	if(qr>M) ret+=query(ql,qr,rson);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T;
	int N,Q;
	char s[10];
	int a,b,c;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&Q);
		build(1,N,1);

		while(Q--)
		{
			scanf("%s",s);
			if(s[0]=='A')
			{
				scanf("%d %d",&a,&b);
				update(b,a,1,N,1);
			}
			if(s[0]=='Q')
			{
				scanf("%d %d",&a,&b);
				printf("%d\n",query(a,b,1,N,1));
			}
			if(s[0]=='R')
			{
				scanf("%d %d %d",&a,&b,&c);
				update(b,c,a,1,N,1);
			}
		}
	}
	
	return 0;
}
