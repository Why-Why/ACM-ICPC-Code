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
// Created Time  : 2015年12月02日 星期三 09时30分14秒
// File Name     : D_2.cpp

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

const int MaxN=50005;

struct OPE {
	int type,id,a,b,c;
}ope[MaxN],to1[MaxN],to2[MaxN];

int N,M;
int ans[MaxN];

typedef long long LL;
const LL INF=100000000000LL;
#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

LL rem[MaxN];				// !!!
LL BIT[MaxN<<2],COL[MaxN<<2];

inline void pushUP(int po) {
	BIT[po]=BIT[lc]+BIT[rc];
}

inline void pushDown(int L,int R,int po) {
	if(COL[po]) {
		COL[lc]+=COL[po];			// !!!
		COL[rc]+=COL[po];
		int M=(L+R)>>1;
		BIT[lc]+=COL[po]*(M-L+1);
		BIT[rc]+=COL[po]*(R-M);
		COL[po]=0;
	}
}

LL query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];

	pushDown(L,R,po);
	int M=(L+R)>>1;
	LL ret=0;
	if(ql<=M) ret+=query(ql,qr,lson);
	if(qr>M) ret+=query(ql,qr,rson);
	return ret;
}

void update(int ul,int ur,int ut,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		BIT[po]+=ut*(R-L+1LL);
		COL[po]+=ut;
		return;
	}
	pushDown(L,R,po);
	int M=(L+R)>>1;
	if(ul<=M) update(ul,ur,ut,lson);
	if(ur>M) update(ul,ur,ut,rson);
	pushUP(po);
}

void solve(int ql,int qr,LL L,LL R) {
	if(ql>qr) return;
	if(L==R) {
		for(int i=ql;i<=qr;++i) if(ope[i].type==2) ans[ope[i].id]=L;
		return;
	}

	LL M=(L+R)>>1;
	int cou1=0,cou2=0;

	for(int i=ql;i<=qr;++i)
		if(ope[i].type==2) rem[i]=query(ope[i].a,ope[i].b,1,N,1);
		else if(ope[i].c>M) update(ope[i].a,ope[i].b,1,1,N,1);
	for(int i=ql;i<=qr;++i)
		if(ope[i].type==2)
			if(rem[i]>=ope[i].c) to1[cou1++]=ope[i];
			else {
				ope[i].c-=rem[i];			// !!!
				to2[cou2++]=ope[i];
			}
		else
			if(ope[i].c>M) update(ope[i].a,ope[i].b,-1,1,N,1),to1[cou1++]=ope[i];
			else to2[cou2++]=ope[i];

	int i=ql;
	for(int j=0;j<cou1;++j) ope[i++]=to1[j];
	for(int j=0;j<cou2;++j) ope[i++]=to2[j];

	solve(ql,ql+cou1-1,M+1,R);
	solve(ql+cou1,qr,L,M);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int anscou=0;

	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;++i) {
		scanf("%d %d %d %d",&ope[i].type,&ope[i].a,&ope[i].b,&ope[i].c);
		if(ope[i].type==2) ope[i].id=++anscou;
	}

	solve(1,M,-INF,INF);
	for(int i=1;i<=anscou;++i) printf("%d\n",ans[i]);
	
	return 0;
}
