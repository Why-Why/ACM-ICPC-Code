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
// Created Time  : 2015年09月10日 星期四 20时16分46秒
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

const int MaxN=300005;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int N,M;

int BIT[MaxN<<2];
bool num[MaxN];

void pushUP(int M,int po)
{
	BIT[po]=BIT[lc]+BIT[rc];
	if(!num[M] && !num[M+1]) ++BIT[po];
}

void build(int L,int R,int po)
{
	if(L==R)
	{
		BIT[po]=0;
		return;
	}

	int M=(L+R)>>1;

	build(lson);
	build(rson);
	pushUP(M,po);
}

void update(int up,int ut,int L,int R,int po)
{
	if(L==R)
	{
		num[L]=ut;
		return;
	}

	int M=(L+R)>>1;
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);

	pushUP(M,po);
}

char s[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	scanf("%s",s+1);

	int a;

	for(int i=1;i<=N;++i)
		num[i]=(s[i]!='.');
	build(1,N,1);

	while(M--)
	{
		scanf("%d %s",&a,s);
		update(a,s[0]!='.',1,N,1);
		printf("%d\n",BIT[1]);
	}
	
	return 0;
}
