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
// Created Time  : 2015年11月01日 星期日 11时13分18秒
// File Name     : 1009_1.cpp

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

struct State
{
	int a,b,c;
	long long cou;

	bool operator < (const State & y) const
	{
		if(c==y.c)
		{
			if(b==y.b) return a>y.a;
			return b>y.b;
		}
		return c>y.c;
	}

	bool operator == (const State & y) const
	{
		return a==y.a && b==y.b && c==y.c;
	}

}sta[MaxN];

int N;

int maxn[MaxN],cou[MaxN];

void unique()
{
	int k=0;
	long long tcou=0;

	sta[N+1].a=-1;

	for(int i=2;i<=N+1;++i)
		if(!(sta[i]==sta[i-1]))
		{
			sta[++k]=sta[i-1];
			sta[k].cou=tcou+sta[i-1].cou;
			tcou=0;
		}
		else tcou+=sta[i-1].cou;
	N=k;
}

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[4010];

void pushUP(int po)
{
	BIT[po]=max(BIT[lc],BIT[rc]);
}

int query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R) return BIT[po];

	int M=(L+R)>>1;
	int ret=0;
	if(ql<=M) ret=max(ret,query(ql,qr,lson));
	if(qr>M) ret=max(ret,query(ql,qr,rson));
	
	return ret;
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

bool judge(int u)
{
	int t=query(sta[u].b,1000,1,1000,1);
	return t<sta[u].a;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int A,B;
	int a,b,c;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&A,&B);
		memset(maxn,0,sizeof(maxn));
		memset(cou,0,sizeof(cou));
		N=0;
		while(A--)
		{
			scanf("%d %d",&a,&b);
			if(maxn[b]<a)
			{
				maxn[b]=a;
				cou[b]=1;
			}
			else if(maxn[b]==a) ++cou[b];
		}
		while(B--)
		{
			scanf("%d %d %d",&a,&b,&c);
			sta[++N].a=maxn[c];
			sta[N].b=a;
			sta[N].c=b;
			sta[N].cou=cou[c];
		}

		sort(sta+1,sta+N+1);
		unique();
		memset(BIT,0,sizeof(BIT));
		long long ans=0;

		for(int i=1;i<=N;++i)
		{
			if(judge(i)) ans+=sta[i].cou;
			update(sta[i].b,sta[i].a,1,1000,1);
		}

		printf("Case #%d: %I64d\n",cas++,ans);
	}
	
	return 0;
}
