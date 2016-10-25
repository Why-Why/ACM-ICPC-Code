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

typedef pair<int,int> pii;
pii rem[MaxN];

int bcou,blen;
bitset <MaxN> map1[3005],ans,temp,yi,rlen[20];

inline void getyi(int l,int r) {
	yi.reset();

	for(int len=r-l+1,i=0;len>0;len>>=1,++i)
		if(len&1) yi=(yi<<(1<<i))|rlen[i];

	yi<<=l;
}

inline int find(int x) {
	int L=1,R=N,M;

	while(R>L) {
		M=(L+R+1)>>1;
		if(rem[M].first>x) R=M-1;
		else L=M;
	}

	return L;
}

inline int getans(int l,int r) {
	getyi(l,r);

	return (ans & yi).count();
}

inline void update(int l,int r,int x) {
	return;
	int t=find(x);
	int t1=t/blen;
	temp=map1[t1];
	for(int i=t1*blen+1;i<=t;++i) temp.set(rem[i].second);

	getyi(l,r);

	ans=(temp & yi) | (ans & (~yi));
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	rlen[0].reset();
	rlen[0].set(0);
	for(int i=1;i<20;++i) rlen[i]=rlen[i-1]|(rlen[i-1]<<(1<<(i-1)));

	int T=read();
	int M;

	while(T--) {
		N=read();
		M=read();
		a=read();
		b=read();

		ans.reset();
		for(int i=1;i<=N;++i) A[i]=read();
		for(int i=1;i<=N;++i) {
			B[i]=read();
			rem[i].first=B[i];
			rem[i].second=i;

			if(A[i]>=B[i]) ans.set(i);
		}

		sort(rem+1,rem+N+1);
		bcou=min(N,3000);
		blen=(N+bcou-1)/bcou;

		map1[1].reset();
		for(int i=1,j=1;i<=N;++i) {
			map1[j].set(rem[i].second);
			if(i%blen==0) {
				map1[j+1]=map1[j];
				++j;
			}
		}

		int last=0,l,r,x,t;
		long long ans=0;

		for(int i=1;i<=M;++i) {
			l=rnd(last)%N+1;
			r=rnd(last)%N+1;
			x=rnd(last)+1;
			if(l>r) swap(l,r);

			if((l+0LL+r+x)&1LL) update(l,r,x);
			else {
				last=getans(l,r);
				add(ans,i*(long long)last%mod);
			}
		}

		printf("%d\n",(int)ans);
	}

	return 0;
}
