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
// Created Time  : 2015年09月28日 星期一 22时31分21秒
// File Name     : 3.cpp

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

int N,M;
int A[MaxN],B[MaxN];

struct C
{
	int x,y;
};

C COL[MaxN<<2];
C zong;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

void pushDown(int po)
{
	if(COL[po].x)
	{
		COL[lc]=COL[rc]=COL[po];
		COL[po].x=0;
	}
}

void update(int ul,int ur,int L,int R,int po)
{
	if(ul<=L && ur>=R)
	{
		COL[po]=zong;
		return;
	}
	pushDown(po);
	int M=(L+R)>>1;

	if(ul<=M) update(ul,ur,lson);
	if(ur>M) update(ul,ur,rson);
}

C query(int qp,int L,int R,int po)
{
	if(L==R)
		return COL[po];

	pushDown(po);
	int M=(L+R)>>1;

	if(qp<=M) return query(qp,lson);
	else return query(qp,rson);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d;

	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i)
		scanf("%d",A+i);
	for(int i=1;i<=N;++i)
		scanf("%d",B+i);

	int t;
	C temp;
	t=MaxN<<2;
	for(int i=0;i<t;++i)
		COL[i].x=0;

	while(M--)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d %d %d",&b,&c,&d);
			temp.x=b;
			temp.y=c;
			zong=temp;
			update(c,c+d-1,1,N,1);
		}
		else
		{
			scanf("%d",&b);
			temp=query(b,1,N,1);
			if(temp.x==0) printf("%d\n",B[b]);
			else printf("%d\n",A[b-temp.y+temp.x]);
		}
	}
	
	return 0;
}
