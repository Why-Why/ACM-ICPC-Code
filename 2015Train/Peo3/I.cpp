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
// Created Time  : 2015年09月23日 星期三 21时31分46秒
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

const int MaxN=200005;
const int INF=MaxN+100000;

int N;
int wei[MaxN],num[MaxN];

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];

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

	BIT[po]=min(BIT[lc],BIT[rc]);
}

void update(int up,int ut,int L,int R,int po)
{
	if(L==R)
	{
		BIT[po]=ut;
		num[L]=ut;
		return;
	}

	int M=(L+R)>>1;
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);

	BIT[po]=min(BIT[lc],BIT[rc]);
}

int query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return BIT[po];

	int M=(L+R)>>1;
	int ret=INF;

	if(ql<=M) ret=min(ret,query(ql,qr,lson));
	if(qr>M) ret=min(ret,query(ql,qr,rson));

	return ret;
}

int getans(int L,int R)
{
	while(L!=R && num[L]>=INF) ++L;
	while(L!=R && num[R]>=INF) --R;
	if(R<L) return 0;

	int t=query(L,R,1,N,1);

	if(t>=INF) return 0;
	if(L==R) return 1;

	int w=wei[t];

	if(w==L) return getans(L+1,R)+1;
	if(w==R) return getans(L,R-1)+1;

	int a=getans(L,w-1),b=getans(w+1,R);
	update(w,INF,1,N,1);
	int c=getans(L,R);

	return max(max(a+1,b+1),c);
}

int main()
{
	freopen("improvements.in","r",stdin);
	freopen("improvements.out","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",wei+i);
		num[wei[i]]=i;
	}

	build(1,N,1);

	printf("%d\n",getans(1,N));
	
	return 0;
}
