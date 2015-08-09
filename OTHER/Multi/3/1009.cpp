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
// Created Time  : 2015年07月28日 星期二 23时01分53秒
// File Name     : 1009.cpp

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
#include <climits>

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int MaxN=100005;
const int MaxNode=MaxN*20;

struct TreapForest
{
	int tot;
	int root[MaxN<<2];
	int ch[MaxNode][2];
	int key[MaxNode],pri[MaxNode];
	int cou[MaxNode];
	int val[MaxNode],maxval[MaxNode];

	void init()
	{
		tot=1;
		pri[0]=INT_MAX;
		maxval[0]=val[0]=0;
	}

	void update(int x)
	{
		maxval[x]=max(val[x],max(maxval[ch[x][0]],maxval[ch[x][1]]));
	}

	void rotate(int &x,int t)
	{
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;
		update(x);
		update(y);
		x=y;
	}

	void _insert(int &x,int k,int tval)
	{
		if(x)
		{
			if(key[x]==k)
			{
				++cou[x];
				val[x]=max(val[x],tval);
			}
			else
			{
				int t=key[x]<k;

				_insert(ch[x][t],k,tval);

				if(pri[ch[x][t]]<pri[x])
					rotate(x,t);
			}
		}
		else
		{
			x=tot++;
			key[x]=k;
			val[x]=tval;
			cou[x]=1;
			pri[x]=rand();
			ch[x][0]=ch[x][1]=0;
		}

		update(x);
	}

	void insert(int id,int k,int tval)
	{
		_insert(root[id],k,tval);
	}

	int findMax(int id,int k)
	{
		int u=root[id];
		int ret=0;

		while(u)
		{
			if(key[u]==k)
				return max(ret,max(maxval[ch[u][1]],val[u]));

			if(key[u]<k)
				u=ch[u][1];
			else
			{
				ret=max(ret,max(val[u],maxval[ch[u][1]]));
				u=ch[u][0];
			}
		}

		return ret;
	}
};

TreapForest forest;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

void build(int L,int R,int po)
{
	forest.root[po]=0;

	if(L==R)
		return;

	int M=(L+R)>>1;

	build(lson);
	build(rson);
}
/*
void insert(int up,int ut1,int ut2,int L,int R,int po)
{
	forest.insert(po,ut1,ut2);

	if(L==R)
		return;

	int M=(L+R)>>1;

	if(up<=M)
		insert(up,ut1,ut2,lson);
	else
		insert(up,ut1,ut2,rson);
}*/

void insert(int up,int ut1,int ut2,int L,int R,int po)
{
	int M;

	while(R>L)
	{
		forest.insert(po,ut1,ut2);
		M=(L+R)>>1;

		if(up<=M)
		{
			R=M;
			po<<=1;
		}
		else
		{
			L=M+1;
			po=((po<<1)|1);
		}
	}

	forest.insert(po,ut1,ut2);
}

int query(int ql,int qr,int qt,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return forest.findMax(po,qt);

	int M=(L+R)>>1;

	if(qr<=M)
		return query(ql,qr,qt,lson);
	else if(ql>M)
		return query(ql,qr,qt,rson);

	return max(query(ql,qr,qt,lson),query(ql,qr,qt,rson));
}

int Hnum[MaxN],Hcou;
int num1[MaxN],num2[MaxN];

int dp[MaxN];
int ans[MaxN];

void Hash_init()
{
	sort(Hnum+1,Hnum+Hcou+1);
	Hcou=unique(Hnum+1,Hnum+Hcou+1)-Hnum-1;
}

int hash1(int x)
{
	return lower_bound(Hnum+1,Hnum+Hcou+1,x)-Hnum;
}

void getans(int N)
{
	int ret=0;
	int t;

	for(int i=N;i>=1;--i)
	{	
		t=query(1,hash1(num1[i]),num2[i],1,Hcou,1)+1;
		ret=max(ret,t);
		dp[i]=t;
		insert(hash1(num1[i]),num2[i],t,1,Hcou,1);
	}
	
	printf("%d\n",ret);

	int cou=0;
	int rem1=1000000009,rem2=-10;

	for(int i=1;i<=N;++i)
		if(dp[i]==ret && num1[i]<=rem1 && num2[i]>=rem2)
		{
			ans[cou++]=i;
			--ret;
			rem1=num1[i];
			rem2=num2[i];
		}

	printf("%d",ans[0]);

	for(int i=1;i<cou;++i)
		printf(" %d",ans[i]);

	puts("");
}

int main()
{
	int N;
	int a,b;

	while(~scanf("%d",&N))
	{
		forest.init();
		Hcou=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&num1[i]);
			Hnum[++Hcou]=num1[i];
		}

		for(int i=1;i<=N;++i)
			scanf("%d",&num2[i]);

		Hash_init();
		build(1,Hcou,1);

		getans(N);
	}

	return 0;
}
