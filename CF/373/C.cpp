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
// Created Time  : 2016年09月23日 星期五 21时55分57秒
// File Name     : C.cpp

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

const int MaxN=200005;
const int mod=1000000007;

inline void add(long long &a,long long b) {
	a+=b;
	if(a>=mod) a-=mod;
}

struct MAT {
	long long num[2][2];

	MAT operator * (const MAT & b) const {
		MAT ret;

		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j) {
				ret.num[i][j]=0;
				for(int k=0;k<2;++k)
					add(ret.num[i][j],(num[i][k]*b.num[k][j])%mod);
			}

		return ret;
	}
};

inline void getF(long long x,long long & fx,long long & fxj,long long & fx1) {
	--x;

	MAT ret,base;

	ret.num[0][1]=ret.num[1][0]=0;
	ret.num[0][0]=ret.num[1][1]=1;

	base.num[0][0]=0;
	base.num[0][1]=base.num[1][0]=base.num[1][1]=1;

	if(x<0) {
		fx=0;
		fxj=1;
		fx1=1;
	}

	for(;x;x>>=1,base=base*base)
		if(x&1)
			ret=ret*base;


	fx=ret.num[1][1];
	fxj=ret.num[0][1];

	base.num[0][0]=0;
	base.num[0][1]=base.num[1][0]=base.num[1][1]=1;
	ret=ret*base;

	fx1=ret.num[1][1];
}

int N;
int a[MaxN];
long long sum[MaxN<<2],sumj[MaxN<<2],COL[MaxN<<2];

inline void update(int po,long long x) {
	long long fx,fxj,fx1;

	//getF(x+1,fx1,fx);
	getF(x,fx,fxj,fx1);

	long long ts=((sum[po]*fx1)%mod+(sumj[po]*fx)%mod)%mod;
	long long tsj=((sum[po]*fx)%mod+(sumj[po]*fxj)%mod)%mod;

	sum[po]=ts;
	sumj[po]=tsj;
}

inline void pushUP(int po) {
	sum[po]=(sum[lc]+sum[rc])%mod;
	sumj[po]=(sumj[lc]+sumj[rc])%mod;
}

inline void pushDown(int po) {
	if(COL[po]) {
		COL[lc]+=COL[po];
		COL[rc]+=COL[po];

		//update(lc,COL[po]);
		//update(rc,COL[po]);

		long long fx,fxj,fx1;
		long long x=COL[po];
    
		getF(x,fx,fxj,fx1);
		//getF(x,fx,fxj);
    
		long long ts=((sum[lc]*fx1)%mod+(sumj[lc]*fx)%mod)%mod;
		long long tsj=((sum[lc]*fx)%mod+(sumj[lc]*fxj)%mod)%mod;

		sum[lc]=ts;
		sumj[lc]=tsj;

		ts=((sum[rc]*fx1)%mod+(sumj[rc]*fx)%mod)%mod;
		tsj=((sum[rc]*fx)%mod+(sumj[rc]*fxj)%mod)%mod;

		sum[rc]=ts;
		sumj[rc]=tsj;

		COL[po]=0;
	}
}

void build(int L,int R,int po) {
	COL[po]=0;

	if(L==R) {
		long long a,b,c;

		getF((long long)::a[L],a,b,c);
		sum[po]=a;
		sumj[po]=b;

		return;
	}

	int M=(L+R)>>1;
	build(lson);
	build(rson);

	pushUP(po);
}

void add(int ul,int ur,long long ud,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		COL[po]+=ud;
		update(po,ud);
		return;
	}

	pushDown(po);

	int M=(L+R)>>1;
	if(ul<=M) add(ul,ur,ud,lson);
	if(ur>M) add(ul,ur,ud,rson);

	pushUP(po);
}

long long query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return sum[po];

	pushDown(po);

	int M=(L+R)>>1;
	long long ret=0;

	if(ql<=M) add(ret,query(ql,qr,lson));
	if(qr>M) add(ret,query(ql,qr,rson));

	return ret;
}

inline int read() {
	char c=0;
	while(c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b,c,d;

	N=read(); M=read();
	for(int i=1;i<=N;++i) ::a[i]=read();

	build(1,N,1);

	while(M--) {
		a=read(); b=read(); c=read();
		if(a==1) {
			d=read();
			add(b,c,d,1,N,1);
		}
		else printf("%d\n",(int)query(b,c,1,N,1));
	}

	return 0;
}
