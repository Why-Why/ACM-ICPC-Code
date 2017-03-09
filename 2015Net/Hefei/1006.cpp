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
// Created Time  : 2015年09月27日 星期日 15时12分44秒
// File Name     : 1006.cpp

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
const int INF=1000000009;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];

void pushUP(int po)
{
	BIT[po]=max(BIT[lc],BIT[rc]);
}

void build(int L,int R,int po)
{
	BIT[po]=-INF;
	if(L==R) return;

	int M=(L+R)>>1;
	build(lson);
	build(rson);
}

void update(int up,int ut,int L,int R,int po)
{
	if(L==R)
	{
		BIT[po]=max(BIT[po],ut);
		return;
	}

	int M=(L+R)>>1;
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);

	pushUP(po);
}

int query(int qt,int L,int R,int po)
{
	if(L==R) return L;
	
	int M=(L+R)>>1;

	if(BIT[rc]>qt) return query(qt,rson);
	else return query(qt,lson);
}

int N,L;
int num[MaxN];
int dp1[MaxN],dp2[MaxN];
int f[MaxN];

void LIS(int dp[],int num[])
{
	for(int i=1;i<=N;++i) f[i]=INF;
	for(int i=1;i<=N;++i)
	{
		int x=lower_bound(f+1,f+N+1,num[i])-f;
		f[x]=num[i];
		dp[i]=x;
	}
}

int num1[MaxN];

void init()
{
	LIS(dp1,num);
	for(int i=1;i<=N;++i)
		num1[i]=-num[N+1-i];
	LIS(dp2,num1);

	reverse(dp2+1,dp2+N+1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&L);
		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);
		build(1,N,1);
		init();

		int ans=-1;
		for(int i=N-L;i>=1;--i)
		{
			ans=max(ans,dp1[i]);
			if(BIT[1]>num[i])
				ans=max(ans,dp1[i]+query(num[i],1,N,1));
			update(dp2[i+L],num[i+L],1,N,1);
		}
		for(int i=1+L;i<=N;++i)
			ans=max(ans,dp2[i]);

		if(L==N) ans=0;
		
		printf("Case #%d: %d\n",cas++,ans);
	}
	
	return 0;
}
