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
// Created Time  : 2015年07月28日 星期二 12时56分49秒
// File Name     : 1001.cpp

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

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

const int MaxN=100005;
const long long NO=-100000000000000000LL;

long long JJ[MaxN<<2],OO[MaxN<<2],JO[MaxN<<2],OJ[MaxN<<2],BIT[MaxN<<2];
int MAXN[MaxN<<2];

void pushUP(int po)
{
	long long a,b;
	
	if(JO[lc]!=NO && JJ[rc]!=NO)
		a=JO[lc]+JJ[rc];
	else
		a=NO;
	if(JJ[lc]!=NO && OJ[rc]!=NO)
		b=JJ[lc]+OJ[rc];
	else
		b=NO;

	JJ[po]=max(a,b);

	if(OJ[lc]!=NO && OO[rc]!=NO)
		a=OJ[lc]+OO[rc];
	else
		a=NO;
	if(OO[lc]!=NO && JO[rc]!=NO)
		b=OO[lc]+JO[rc];
	else
		b=NO;

	OO[po]=max(a,b);
	
	if(JJ[lc]!=NO && OO[rc]!=NO)
		a=JJ[lc]+OO[rc];
	else
		a=NO;
	if(JO[lc]!=NO && JO[rc]!=NO)
		b=JO[lc]+JO[rc];
	else
		b=NO;

	JO[po]=max(a,b);

	if(OO[lc]!=NO && JJ[rc]!=NO)
		a=OO[lc]+JJ[rc];
	else
		a=NO;
	if(OJ[lc]!=NO && OJ[rc]!=NO)
		b=OJ[lc]+OJ[rc];
	else
		b=NO;

	OJ[po]=max(a,b);

	JJ[po]=max(JJ[po],max(JJ[lc],JJ[rc]));
	JO[po]=max(JO[po],max(JO[lc],JO[rc]));
	OJ[po]=max(OJ[po],max(OJ[lc],OJ[rc]));
	OO[po]=max(OO[po],max(OO[lc],OO[rc]));

	BIT[po]=max(max(JJ[po],OO[po]),max(JO[po],OJ[po]));
	MAXN[po]=max(MAXN[lc],MAXN[rc]);
}

void build(int L,int R,int po)
{
	if(L==R)
	{
		int t;
		scanf("%d",&t);
		OO[po]=JJ[po]=OJ[po]=JO[po]=NO;

		MAXN[po]=t;

		if(L&1)
			JJ[po]=t;
		else
			OO[po]=t;

		BIT[po]=max(max(JJ[po],OO[po]),max(JO[po],OJ[po]));

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
		JJ[po]=OO[po]=OJ[po]=JO[po]=NO;

		if(L&1)
			JJ[po]=ut;
		else
			OO[po]=ut;

		MAXN[po]=ut;
		BIT[po]=max(max(JJ[po],OO[po]),max(JO[po],OJ[po]));

		return;
	}

	int M=(L+R)>>1;

	if(up<=M)
		update(up,ut,lson);
	else
		update(up,ut,rson);

	pushUP(po);
}

struct state
{
	long long bit,jj,oo,jo,oj;

	state()
	{
	}

	state(long long a,long long b,long long c,long long d,long long e)
	{
		bit=a;
		jj=b;
		oo=c;
		jo=d;
		oj=e;
	}
};

state query_1(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return state(BIT[po],JJ[po],OO[po],JO[po],OJ[po]);

	int M=(L+R)>>1;

	if(qr<=M)
		return query_1(ql,qr,lson);
	else if(ql>M)
		return query_1(ql,qr,rson);

	state t1,t2,t3;

	t1=query_1(ql,qr,lson);
	t2=query_1(ql,qr,rson);

	long long a,b;

	if(t1.jj!=NO && t2.oj!=NO)
		a=t1.jj+t2.oj;
	else
		a=NO;
	if(t1.jo!=NO && t2.jj!=NO)
		b=t1.jo+t2.jj;
	else
		b=NO;
	t3.jj=max(a,b);


	if(t1.oo!=NO && t2.jo!=NO)
		a=t1.oo+t2.jo;
	else
		a=NO;
	if(t1.oj!=NO && t2.oo!=NO)
		b=t1.oj+t2.oo;
	else
		b=NO;
	t3.oo=max(a,b);


	if(t1.jo!=NO && t2.jo!=NO)
		a=t1.jo+t2.jo;
	else
		a=NO;
	if(t1.jj!=NO && t2.oo!=NO)
		b=t1.jj+t2.oo;
	else
		b=NO;
	t3.jo=max(a,b);


	if(t1.oo!=NO && t2.jj!=NO)
		a=t1.oo+t2.jj;
	else
		a=NO;
	if(t1.oj!=NO && t2.oj!=NO)
		b=t1.oj+t2.oj;
	else
		b=NO;
	t3.oj=max(a,b);

	t3.jj=max(t3.jj,max(t1.jj,t2.jj));
	t3.oo=max(t3.oo,max(t1.oo,t2.oo));
	t3.oj=max(t3.oj,max(t1.oj,t2.oj));
	t3.jo=max(t3.jo,max(t1.jo,t2.jo));

	t3.bit=max(max(t3.jj,t3.oo),max(t3.jo,t3.oj));

	return t3;
}

long long query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return MAXN[po];

	int M=(L+R)>>1;

	if(qr<=M)
		return query(ql,qr,lson);
	else if(ql>M)
		return query(ql,qr,rson);

	return max(query(ql,qr,lson),query(ql,qr,rson));
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	int N,M;
	int a,b,c;
	long long t1;
	state t2;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);

		build(1,N,1);

		while(M--)
		{
			scanf("%d %d %d",&a,&b,&c);

			if(a)
				update(b,c,1,N,1);
			else
			{
				t2=query_1(b,c,1,N,1);
				
				printf("%I64d\n",t2.bit);
			}
		}
	}
	
	return 0;
}
