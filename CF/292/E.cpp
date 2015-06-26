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
// Created Time  : 2015年06月02日 星期二 00时50分19秒
// File Name     : E.cpp

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

int n,m,N;
long long d[MaxN];
long long h[MaxN];

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

long long BIT[MaxN*4];
long long ZUO[MaxN*4];
long long YOU[MaxN*4];
long long SUM[MaxN];

void pushUP(int L,int R,int po)
{
	int M=(L+R)>>1;

	BIT[po]=max(BIT[lc],BIT[rc]);
	BIT[po]=max(BIT[po],ZUO[rc]+YOU[lc]+SUM[M+1]-SUM[M]);
	ZUO[po]=max(ZUO[lc],SUM[M+1]-SUM[L]+ZUO[rc]);
	YOU[po]=max(YOU[rc],SUM[R]-SUM[M]+YOU[lc]);
}

void build_tree(int L,int R,int po)
{
	if(L==R)
	{
		BIT[po]=0;
		ZUO[po]=2*h[L];
		YOU[po]=2*h[L];

		return;
	}

	int M=(L+R)>>1;

	build_tree(lson);
	build_tree(rson);

	pushUP(L,R,po);
}

long long query_YOU(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return YOU[po];

	int M=(L+R)>>1;

	if(ql>M)
		return query_YOU(ql,qr,rson);

	if(qr<=M)
		return query_YOU(ql,qr,lson);

	return max(query_YOU(ql,qr,rson),SUM[R]-SUM[M]+query_YOU(ql,qr,lson));
}

long long query_ZUO(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return ZUO[po];

	int M=(L+R)>>1;

	if(ql>M)
		return query_ZUO(ql,qr,rson);

	if(qr<=M)
		return query_ZUO(ql,qr,lson);

	return max(query_ZUO(ql,qr,lson),SUM[M+1]-SUM[L]+query_ZUO(ql,qr,rson));
}

long long query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return BIT[po];

	int M=(L+R)>>1;
	int ret=0;

	if(ql>M)
		return query(ql,qr,rson);
	
	if(qr<=M)
		return query(ql,qr,lson);

	return max(max(query(ql,M,lson),query(M+1,qr,rson)),query_YOU(ql,M,1,N,1)+query_ZUO(M+1,qr,1,N,1)+SUM[M+1]-SUM[M]);			// !!!
}

void chuli()
{
	SUM[1]=0;

	for(int i=2;i<=N;++i)
		SUM[i]=SUM[i-1]+d[i-1];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	ios::sync_with_stdio(false);

	cin>>n>>m;
	N=n+n;

	for(int i=1;i<=n;++i)
	{
		cin>>d[i];
		d[i+n]=d[i];
	}

	for(int i=1;i<=n;++i)
	{
		cin>>h[i];
		h[i+n]=h[i];
	}

	chuli();
	build_tree(1,N,1);

	while(m--)
	{
		cin>>a>>b;

		if(a<=b)
			cout<<query(b+1,n+a-1,1,N,1)<<endl;
		else
			cout<<query(b+1,a-1,1,N,1)<<endl;
	}
	
	return 0;
}

