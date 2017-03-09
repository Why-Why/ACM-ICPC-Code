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
// Created Time  : 2017年02月14日 星期二 19时33分32秒
// File Name     : H.cpp

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
const int T=20;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct State {
	double num[T];

	State operator + (const State & b) const {
		State ret;
		for(int i=1;i<T;++i) ret.num[i]=num[i]+b.num[i];
		return ret;
	}

	State operator * (double k) const {
		State ret;
		double t=k;
		for(int i=1;i<T;++i,t*=k) ret.num[i]=num[i]*t;
		return ret;
	}

	double get() const {
		double ret=0;
		for(int i=1;i<T;++i) ret+=num[i]/i;
		return ret;
	}
};

State bit[MaxN<<2];
double col[MaxN<<2];

inline void pushUP(int po) {
	bit[po]=bit[lc]+bit[rc];
}

inline void pushDown(int po) {
	if(col[po]!=1.0) {
		col[lc]*=col[po];
		col[rc]*=col[po];
		bit[lc]=bit[lc]*col[po];
		bit[rc]=bit[rc]*col[po];
		col[po]=1.0;
	}
}

double p[MaxN];

void build(int L,int R,int po) {
	col[po]=1.0;

	if(L==R) {
		double t=p[L];
		for(int i=1;i<T;++i,t*=p[L]) bit[po].num[i]=t;
		return;
	}

	int M=(L+R)>>1;
	build(lson);
	build(rson);
	pushUP(po);
}

void update(int ul,int ur,double uk,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		col[po]*=uk;
		bit[po]=bit[po]*uk;
		return;
	}

	pushDown(po);
	int M=(L+R)>>1;

	if(ul<=M) update(ul,ur,uk,lson);
	if(ur>M) update(ul,ur,uk,rson);

	pushUP(po);
}

double query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return bit[po].get();

	pushDown(po);
	int M=(L+R)>>1;
	double ret=0;

	if(ql<=M) ret+=query(ql,qr,lson);
	if(qr>M) ret+=query(ql,qr,rson);

	return ret;
}

int N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b,c;
	double d;

	while(~scanf("%d %d",&N,&M)) {
		for(int i=1;i<=N;++i) scanf("%lf",p+i);
		build(1,N,1);

		while(M--) {
			scanf("%d %d %d",&a,&b,&c);
			if(a==0) printf("%.14f\n",-query(b,c,1,N,1));
			else {
				scanf("%lf",&d);
				update(b,c,d,1,N,1);
			}
		}
	}

	return 0;
}
