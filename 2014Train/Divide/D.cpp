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
// Created Time  : 2015年11月28日 星期六 17时10分26秒
// File Name     : D.cpp

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

const int MaxN=50004;
const int MaxM=50004;
const long long INF=10000000000000000LL;

struct OPE {
	int type,id;
	int a,b,c;
}ope[MaxM],to1[MaxM],to2[MaxM];

int N,M;
long long ans[MaxN];

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];

inline void pushUP(int po) {
	BIT[po]=BIT[lc]+BIT[rc];
}

int query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R)
		return BIT[po];

	int M=(L+R)>>1,ret=0;
	if(ql<=M) ret+=query(ql,qr,lson);
	if(qr>M) ret+=query(ql,qr,rson);
	return ret;
}

void update(int ul,int ur,int ut,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		BIT[po]=(R-L+1)*ut;
		return;
	}

	int M=(L+R)>>1;
	if(ul<=M) update(ul,ur,ut,lson);
	if(ur>M) update(ul,ur,ut,rson);
	pushUP(po);
}

int rem[MaxN];

void solve(int ql,int qr,long long L,long long R) {

	cout<<ql<<' '<<qr<<' '<<L<<' '<<R<<endl;

	if(ql>qr) return;
	if(L==R) {
		for(int i=ql;i<=qr;++i)
			if(ope[i].type==2) ans[ope[i].id]=L;
		return;
	}

	long long M=(L+R+1)>>1;

	for(int i=ql;i<=qr;++i)
		if(ope[i].type==1) {
			if(ope[i].c<M) update(ope[i].a,ope[i].b,1,1,N,1);
		}
		else rem[i]=query(ope[i].a,ope[i].b,1,N,1);

	int cou1=0,cou2=0;

	for(int i=ql;i<=qr;++i)
		if(ope[i].type==1)
			if(ope[i].c<M) update(ope[i].a,ope[i].b,-1,1,N,1),to1[cou1++]=ope[i];
			else to2[cou2++]=ope[i];
		else
			if(ope[i].c<=rem[i]) to1[cou1++]=ope[i];
			else ope[i].c-=rem[i],to2[cou2++]=ope[i];
	
	int i=ql;
	for(int j=0;j<cou1;++j) ope[i++]=to1[j];
	for(int j=0;j<cou2;++j) ope[i++]=to2[j];

	solve(ql,ql+cou1-1,L,M-1);
	solve(ql+cou1,qr,M,R);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int anscou=0;

	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;++i) {
		scanf("%d %d %d %d",&ope[i].type,&ope[i].a,&ope[i].b,&ope[i].c);
		if(ope[i].type==2) ope[i].id=++anscou;
	}

	solve(1,M,-INF,INF);

	memset(ans,0,sizeof(ans));
	for(int i=1;i<=anscou;++i)
		printf("%lld\n",ans[i]);
	
	return 0;
}
