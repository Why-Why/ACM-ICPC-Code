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
// Created Time  : 2015年10月05日 星期一 20时47分39秒
// File Name     : C.cpp

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

const int MaxN=200005;

int N,M;
int rem[1000006];

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];
int ZUO[MaxN<<2];
int YOU[MaxN<<2];
int REM[MaxN<<2];

void pushUP(int L,int R,int po)
{
	int len=R-L+1;
	int M=(L+R)>>1;

	ZUO[po]=ZUO[lc];
	if(ZUO[lc]==M-L+1) ZUO[po]+=ZUO[rc];

	YOU[po]=YOU[rc];
	if(YOU[rc]==R-M) YOU[po]+=YOU[lc];

	if(BIT[lc]>=BIT[rc]) REM[po]=REM[lc],BIT[po]=BIT[lc];
	else REM[po]=REM[rc],BIT[po]=BIT[rc];

	int d=(ZUO[rc]+YOU[lc]+1)/2;

	if(d>BIT[po])
	{
		BIT[po]=d;
		REM[po]=M-YOU[lc]+1;
	}
	else if(d==BIT[po])
		REM[po]=min(REM[po],M-YOU[lc]+1);
}

void build(int L,int R,int po)
{
	REM[po]=L;
	ZUO[po]=YOU[po]=R-L+1;

	if(L==R) return;

	int M=(L+R)>>1;
	build(lson);
	build(rson);
}

void update(int up,int ut,int L,int R,int po)
{
	if(L==R)
	{
		ZUO[po]=YOU[po]=ut;
		REM[po]=L;
		return;
	}

	int M=(L+R)>>1;
	
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);


	pushUP(L,R,po);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int t,d;

	scanf("%d %d",&N,&M);
	build(1,N,1);

	while(M--)
	{
		scanf("%d %d",&a,&b);
		if(a==1)
		{
			d=BIT[1];
			if(ZUO[1]>=d && ZUO[1]>=YOU[1]) t=1;
			if(YOU[1]>d && YOU[1]>ZUO[1]) t=N;
			if(d>ZUO[1] && d>=YOU[1]) t=REM[1]+d-1;
			printf("%d\n",t);

			update(t,0,1,N,1);
			rem[b]=t;
		}
		else
		{
			update(rem[b],1,1,N,1);
			rem[b]=0;
		}
	}

	return 0;
}
