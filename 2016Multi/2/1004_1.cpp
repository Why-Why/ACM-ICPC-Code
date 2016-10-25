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
// Created Time  : 2016年07月22日 星期五 17时09分01秒
// File Name     : 1004.cpp

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

const int mod=1000000007;

inline int read() {
	int ret,c=0;
	while(c<'0' || c>'9') c=getchar();
	ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

inline void add(long long & a,long long b) {
	a+=b; if(a>=mod) a-=mod;
}

int a,b,C=~(1<<31),M=(1<<16)-1;
int rnd(int last) {
	a = (36969 + (last >> 3)) * (a & M) + (a >> 16);
	b = (18000 + (last >> 3)) * (b & M) + (b >> 16);
	return (C & ((a << 16) + b)) % 1000000000;
}

/////////////////////////////

const int MaxN=100005;

int A[MaxN],B[MaxN];
int N;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int pos[MaxN<<2],val[MaxN<<2];
int COL[MaxN<<2];
int buf[20*MaxN],num[20*MaxN];
int bcou;

inline void pushUP(int L,int M,int R,int po) {
	val[po]=val[lc]+val[rc];

	int len1=M-L+1,len2=R-M,len=R-L+1,p1=pos[lc],p2=pos[rc];
	int t,v;
	len1+=p1;
	len2+=p2;
	pos[po]=bcou;

	for(int i=0;i<len;++i) {
		if(p2>=len2 || (p1<len1 && buf[p1]<buf[p2])) {
			t=buf[p1++];
			v=1;
		}
		else {
			t=buf[p2++];
			v=0;
		}

		if(i==0) num[bcou]=v;
		else num[bcou]=num[bcou-1]+v;
		buf[bcou++]=t;
	}
}

inline void pushDown(int L,int M,int R,int po) {
	if(COL[po]==-1) return;

	int u1,u2;

	if(COL[po]==0) u1=u2=0;
	else {
		u1=num[pos[po]+COL[po]-1];
		u2=COL[po]-u1;
	}

	COL[lc]=val[lc]=u1;
	COL[rc]=val[rc]=u2;
	COL[po]=-1;
}

void build(int L,int R,int po) {
	COL[po]=-1;

	if(L==R) {
		pos[po]=bcou;
		val[po]=A[L]>=B[L] ? 1 : 0;
		buf[bcou]=B[L];
		num[bcou++]=0;
		return;
	}

	int M=(L+R)>>1;

	build(lson);
	build(rson);
	pushUP(L,M,R,po);
}

int getans(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return val[po];

	int ret=0;
	int M=(L+R)>>1;
	pushDown(L,M,R,po);

	if(ql<=M) ret+=getans(ql,qr,lson);
	if(qr>M) ret+=getans(ql,qr,rson);
	return ret;
}

void update(int ul,int ur,int ut,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		val[po]=ut;
		COL[po]=ut;
		return;
	}


	int M=(L+R)>>1;
	int u1,u2;

	pushDown(L,M,R,po);

	if(ut==0) u1=u2=0;
	else {
		u1=num[pos[po]+ut-1];
		u2=ut-u1;
	}

	if(ul<=M) update(ul,ur,u1,lson);
	if(ur>M) update(ul,ur,u2,rson);

	val[po]=val[lc]+val[rc];
}

inline void update(int l,int r,int x) {
	int t=upper_bound(B+1,B+N+1,x)-B-1;
	update(l,r,t,1,N,1);
}

void chuli() {
	bcou=0;
	build(1,N,1);
	sort(B+1,B+N+1);
}

void show(int L,int R,int po) {
	cout<<"####\n"<<po<<endl;
	cout<<val[po]<<' '<<COL[po]<<endl;
	for(int i=pos[po];i<pos[po]+R-L+1;++i)
		cout<<buf[i]<<" @ "<<num[i]<<endl;
	cout<<endl;

	if(L==R) return;
	int M=(L+R)/2;
	show(lson);
	show(rson);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T=read();
	int M;

	while(T--) {
		N=read();
		M=read();
		a=read();
		b=read();

		for(int i=1;i<=N;++i) A[i]=read();
		for(int i=1;i<=N;++i) B[i]=read();

		chuli();

		int last=0,l,r,x,t;
		long long ans=0;

		for(int i=1;i<=M;++i) {
			l=rnd(last)%N+1;
			r=rnd(last)%N+1;
			x=rnd(last)+1;
			if(l>r) swap(l,r);

			if((l+0LL+r+x)&1LL) update(l,r,x);
			else {
				last=getans(l,r,1,N,1);
				add(ans,i*(long long)last%mod);
			}
		}

		printf("%d\n",(int)ans);
	}

	return 0;
}
