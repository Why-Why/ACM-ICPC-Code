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
// Created Time  : 2015年06月25日 星期四 00时02分13秒
// File Name     : 2528.cpp

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

const int MaxN=40005;

int COL[MaxN<<2];

void pushDown(int po)
{
	if(COL[po])
	{
		COL[lc]=COL[rc]=COL[po];
		COL[po]=0;
	}
}

int query(int qd,int L,int R,int po)
{
	if(L==R)
		return COL[po];

	pushDown(po);

	int M=(L+R)>>1;

	if(qd<=M)
		return query(qd,lson);
	else
		return query(qd,rson);
}

void update(int ul,int ur,int ut,int L,int R,int po)
{
	if(ul<=L && ur>=R)
	{
		COL[po]=ut;
		return;
	}

	pushDown(po);

	int M=(L+R)>>1;

	if(ul<=M)
		update(ul,ur,ut,lson);
	if(ur>M)
		update(ul,ur,ut,rson);
}

int ans[10010];
int remL[10010],remR[10010];
int N;
int cou;
int rem[MaxN];

int find(int x)
{
	int L=1,R=cou,M;

	while(R>L)
	{
		M=(L+R+1)>>1;

		if(rem[M]==x)
			return M;

		if(rem[M]>x)
			R=M-1;
		else
			L=M;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;
	int zans;
	int k;

	scanf("%d",&T);

	while(T--)
	{
		zans=0;
		scanf("%d",&N);
		cou=0;
		memset(ans,0,sizeof(ans));

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&a,&b);
			rem[++cou]=a;
			rem[++cou]=b;
			remL[i]=a;
			remR[i]=b;
		}

		sort(rem+1,rem+cou+1);
		
		k=1;

		for(int i=2;i<=cou;++i)
			if(rem[i]!=rem[i-1])
				rem[++k]=rem[i];

		cou=k;


		for(int i=1;i<k;++i)
			if(rem[i]+1!=rem[i+1])
				rem[++cou]=(rem[i]+rem[i+1])>>1;

		sort(rem+1,rem+cou+1);
		memset(COL,0,sizeof(COL));

		for(int i=1;i<=N;++i)
		{
			a=find(remL[i]);
			b=find(remR[i]);
			update(a,b,i,1,cou,1);
		}

		for(int i=1;i<=cou;++i)
		{
			a=query(i,1,cou,1);

			if(a && ans[a]==0)
			{
				ans[a]=1;
				++zans;
			}
		}

		printf("%d\n",zans);
	}
	
	return 0;
}
