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
// Created Time  : 2016年12月03日 星期六 15时45分23秒
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

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

const int MaxN=300005;

struct VAL {
	// h,lx,rx,ld,rd,ans;
	// 0, 1, 2, 3, 4, 5 ;
	long long num[6];
};

VAL COL[MaxN<<2];
long long BIT[MaxN<<2];
int N;
int A[MaxN];

////////////////////////

inline void pushUP(int po) {
	BIT[po]=max(BIT[lc],BIT[rc]);
}

inline void pushDown(int p,int po) {
	if(COL[po].num[p]) {
		COL[lc].num[p]+=COL[po].num[p];
		COL[rc].num[p]+=COL[po].num[p];

		if(p==5) {
			BIT[lc]+=COL[po].num[p];
			BIT[rc]+=COL[po].num[p];
		}

		COL[po].num[p]=0;
	}
}

void update(int p,int ul,int ur,long long ut,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		COL[po].num[p]+=ut;
		if(p==5) BIT[po]+=ut;
		return;
	}

	pushDown(p,po);

	int M=(L+R)>>1;
	if(ul<=M) update(p,ul,ur,ut,lson);
	if(ur>M) update(p,ul,ur,ut,rson);
	pushUP(po);
}

long long query(int p,int qp,int L,int R,int po) {
	if(L==R) return COL[po].num[p];

	pushDown(p,po);
	int M=(L+R)>>1;

	if(qp<=M) return query(p,qp,lson);
	else return query(p,qp,rson);
}

////////////////////////

int tx[MaxN],td[MaxN];

void init() {
	tx[1]=td[1]=1;
	update(0,1,1,A[1],1,N,1);
	update(1,1,1,1,1,N,1);
	update(3,1,1,1,1,N,1);

	for(int i=2;i<=N;++i) {
		if(A[i]>A[i-1]) {
			tx[i]=tx[i-1]+1;
			td[i]=1;
		}
		else {
			tx[i]=1;
			td[i]=td[i-1]+1;
		}

		update(0,i,i,A[i],1,N,1);
		update(1,i,i,tx[i],1,N,1);
		update(3,i,i,td[i],1,N,1);
	}

	tx[N]=td[N]=1;
	update(2,N,N,1,1,N,1);
	update(4,N,N,1,1,N,1);

	update(5,N,N,tx[N]-1+query(1,N,1,N,1),1,N,1);

	for(int i=N-1;i>=1;--i) {
		if(A[i]>A[i+1]) {
			tx[i]=tx[i+1]+1;
			td[i]=1;
		}
		else {
			tx[i]=1;
			td[i]=td[i+1]+1;
		}

		update(2,i,i,tx[i],1,N,1);
		update(4,i,i,td[i],1,N,1);

		update(5,i,i,tx[i]-1+query(1,i,1,N,1),1,N,1);
	}
}

inline bool judge(int x,int y) {
	return query(0,x,1,N,1)<query(0,y,1,N,1);
}

inline bool judged(int x,int y) {
	return query(0,x,1,N,1)<=query(0,y,1,N,1);
}

inline void getans(int sta) {
	switch(sta) {
		case 2:
			break;
		case 4:
			break;
		case 7:
			break;
		case 14:
			break;
		case 6:
			break;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",A+i);
	init();

	for(int i=1;i<=N;++i) {
		for(int j=0;j<=5;++j)
			cout<<query(j,i,1,N,1)<<' ';
		cout<<endl;
	}

	int M;
	int a,b,c;
	int x;

	scanf("%d",&M);

	while(M--) {
		scanf("%d %d %d",&a,&b,&c);
		x=0;
		x|=(judge(a-1,a)<<3);
		x|=(judged(b,b+1)<<2);

		update(0,a,b,c,1,N,1);

		x|=(judge(a-1,a)<<1);
		x|=(judged(b,b+1)<<0);

		getans(x);
		printf("%d\n",(int)BIT[1]);
	}

	return 0;
}
