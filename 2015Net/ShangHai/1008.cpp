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
// Created Time  : 2015年09月26日 星期六 12时32分55秒
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

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

using namespace std;

const int MaxN=100005;

struct QUE
{
	int t;
	int n;
}que[MaxN];

int Mod,Q;
int N;
long long num[MaxN];

long long BIT[MaxN<<2];

void pushUP(int po)
{
	BIT[po]=(BIT[lc]*BIT[rc])%Mod;
}

void update(int up,int L,int R,int po)
{
	if(L==R)
	{
		BIT[po]=1%Mod;
		return;
	}

	int M=(L+R)>>1;
	if(up<=M) update(up,lson);
	else update(up,rson);
	
	pushUP(po);
}

long long query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return BIT[po];
	int M=(L+R)>>1;
	long long ret=1%Mod;

	if(ql<=M) (ret*=query(ql,qr,lson))%=Mod;
	if(qr>M) (ret*=query(ql,qr,rson))%=Mod;

	return ret;
}

void build(int L,int R,int po)
{
	if(L==R)
	{
		BIT[po]=num[L];
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

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&Q,&Mod);
		N=0;
		for(int i=1;i<=Q;++i)
		{
			scanf("%d %d",&que[i].t,&que[i].n);
			if(que[i].t==1)
				num[++N]=que[i].n;
			else num[++N]=1;
		}

		build(1,N,1);

		printf("Case #%d:\n",cas++);
		for(int i=1;i<=Q;++i)
		{
			if(que[i].t==2) update(que[i].n,1,N,1);
			printf("%d\n",(int)query(1,i,1,N,1));
		}
	}
	
	return 0;
}
