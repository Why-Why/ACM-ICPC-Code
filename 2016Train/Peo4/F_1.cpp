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
// Created Time  : 2016年03月17日 星期四 23时35分46秒
// File Name     : F_1.cpp

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

const int step[15][15][3]={
{{0,0,1},{0,0,2},{0,1,3},{0,3,3},{0,5,3},{1,0,3},{2,0,3},{4,0,3}},
{{1,1,3}},
{{0,1,1},{0,2,1},{0,2,2},{0,6,3},{0,9,3},{1,2,3},{2,1,3},{2,2,3},{4,2,3}},
{{1,0,1},{1,3,3},{3,0,1},{3,0,2},{3,1,3},{3,3,3},{3,5,3},{6,0,3},{8,0,3}},
{{0,1,2},{0,4,1},{0,4,2},{0,7,3},{0,8,3},{1,4,3},{2,4,3},{4,1,3},{4,4,3}},
{{1,0,2},{1,5,3},{5,0,1},{5,0,2},{5,1,3},{5,3,3},{5,5,3},{7,0,3},{9,0,3}},
{{1,1,1},{1,2,1},{1,6,3},{3,1,1},{3,2,1},{3,2,2},{3,6,3},{3,9,3},{6,1,3},{6,2,3},{8,2,3}},
{{1,1,2},{1,4,2},{1,7,3},{5,1,2},{5,4,1},{5,4,2},{5,7,3},{5,8,3},{7,1,3},{7,4,3},{9,4,3}},
{{1,4,1},{1,8,3},{3,1,2},{3,4,1},{3,4,2},{3,7,3},{3,8,3},{6,4,3},{8,1,3},{8,4,3}},
{{1,2,2},{1,9,3},{5,1,1},{5,2,1},{5,2,2},{5,6,3},{5,9,3},{7,2,3},{9,1,3},{9,2,3}}
};

const int rlen[15]={8,1,9,9,9,9,11,11,10,10};

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct State {
	long long num[10];
};

const int MaxN=60005;
const long long INF=1000000000000000LL;

int num1[MaxN],num2[MaxN],num3[MaxN];
int N,M;

State BIT[MaxN<<2];

inline void merge(State & to,const State & A,const State & B,int x,int y) {
	int tbian[4]={0,x,y,x+y};

	for(int i=0;i<10;++i) {
		to.num[i]=INF;
		for(int j=0;j<rlen[i];++j) {
			to.num[i]=min(to.num[i],A.num[step[i][j][0]]+B.num[step[i][j][1]]+tbian[step[i][j][2]]);
		}
	}
}

inline void pushUP(int M,int po) {
	merge(BIT[po],BIT[lc],BIT[rc],num1[M],num2[M]);
}

void build(int L,int R,int po) {
	if(L==R) {
		for(int i=0;i<10;++i) BIT[po].num[i]=INF;
		BIT[po].num[0]=num3[L];
		BIT[po].num[1]=0;
		return;
	}

	int M=(L+R)>>1;
	build(lson);
	build(rson);
	pushUP(M,po);
}

void update(int up,int L,int R,int po) {
	if(L==R) {
		for(int i=0;i<10;++i) BIT[po].num[i]=INF;
		BIT[po].num[0]=num3[L];
		BIT[po].num[1]=0;
		return;
	}

	int M=(L+R)>>1;
	if(up<=M) update(up,lson);
	else update(up,rson);
	pushUP(M,po);
}

State query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];

	int M=(L+R)>>1;

	if(ql>M) return query(ql,qr,rson);
	if(qr<=M) return query(ql,qr,lson);

	State r1,r2,r;
	r1=query(ql,qr,lson);
	r2=query(ql,qr,rson);
	merge(r,r1,r2,num1[M],num2[M]);
	return r;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[10];
	int a,b,c,d,e;
	State temp;

	while(~scanf("%d %d",&N,&M)) {
		for(int i=1;i<N;++i) scanf("%d",num1+i);
		for(int i=1;i<N;++i) scanf("%d",num2+i);
		for(int i=1;i<=N;++i) scanf("%d",num3+i);

		build(1,N,1);
		while(M--) {
			scanf("%s",s);
			if(s[0]=='Q') {
				scanf("%d %d",&a,&b);
				temp=query(a,b,1,N,1);
				printf("%lld\n",temp.num[0]);
			}
			else {
				scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
				if(a==c) {
					if(a==1) num1[min(b,d)]=e;
					else num2[min(b,d)]=e;
					update(min(b,d),1,N,1);
				}
				else {
					num3[b]=e;
					update(b,1,N,1);
				}
			}
		}
	}
	
	return 0;
}
