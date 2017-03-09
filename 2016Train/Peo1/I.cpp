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
// Created Time  : 2016年02月20日 星期六 14时17分27秒
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

const int MaxN=100005;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];
const int INF=0x3f3f3f3f;

inline void pushUP(int po) {
	BIT[po]=max(BIT[lc],BIT[rc]);
}

void build(int L,int R,int po) {
	BIT[po]=-INF;
	if(L==R) return;
	int M=(L+R)>>1;
	build(lson);
	build(rson);
}

void update(int up,int ut,int L,int R,int po) {
	if(L==R) { BIT[po]=max(BIT[po],ut); return; }

	int M=(L+R)>>1;
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);

	pushUP(po);
}

int query(int ql,int qr,int L,int R,int po) {
	if(ql>qr) return -INF;
	if(ql<=L && qr>=R) return BIT[po];

	int M=(L+R)>>1,ret=-INF;
	if(ql<=M) ret=max(ret,query(ql,qr,lson));
	if(qr>M) ret=max(ret,query(ql,qr,rson));

	return ret;
}

int num[MaxN];
int zuo[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",num+i);

	int t,t1;

	build(1,100000,1);
	for(int i=1;i<=N;++i) {
		t=query(1,num[i]-1,1,100000,1);
		if(t==-INF) t=0;
		t1=query(num[i]+2,100000,1,100000,1);
		if(t1==-INF) t1=0;
		t=max(t1,t);

		zuo[i]=i-t;
		update(num[i],i,1,100000,1);
	}

	int ans=0;

	build(1,100000,1);
	for(int i=N;i>=1;--i) {
		t=query(1,num[i]-1,1,100000,1);
		if(t==-INF) t=-(N+1);
		t1=query(num[i]+2,100000,1,100000,1);
		if(t1==-INF) t1=-(N+1);
		t=max(t,t1);
		t=-t;

		ans=max(ans,zuo[i]-1+t-i);
		update(num[i],-i,1,100000,1);
	}

	printf("%d\n",ans);
	
	return 0;
}
