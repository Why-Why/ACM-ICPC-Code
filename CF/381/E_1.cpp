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
// Created Time  : 2016年12月03日 星期六 22时15分02秒
// File Name     : E_1.cpp

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

const int MaxN=300005;

int N,A[MaxN];

struct ST {
	long long C[MaxN];

	inline int lowbit(int x) {
		return x&(-x);
	}

	inline void add(int x,long long d) {
		for(;x<=N;x+=lowbit(x)) C[x]+=d;
	}

	inline void init() {
		memset(C,0,sizeof(C));
	}

	inline void update(int L,int R,long long d) {
		if(R<L) return;
		add(L,d);
		add(R+1,-d);
	}

	inline long long query(int x) {
		if(x<1 || x>N) return 0;
		long long ret=0;			// !!!
		for(;x;x-=lowbit(x)) ret+=C[x];
		return ret;
	}
}LX,RX,H;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct BIT {
	long long bit[MaxN<<2],col[MaxN<<2];

	inline void pushUP(int po) {
		bit[po]=max(bit[lc],bit[rc]);
	}

	inline void pushDonw(int po) {
		if(col[po]) {
			col[lc]+=col[po];
			col[rc]+=col[po];
			bit[lc]+=col[po];
			bit[rc]+=col[po];
			col[po]=0;
		}
	}

	inline void update(int ul,int ur,long long ud,int L,int R,int po) {
		if(ul<=L && ur>=R) {
			col[po]+=ud;
			bit[po]+=ud;
			return;
		}

		pushDonw(po);
		int M=(L+R)>>1;

		if(ul<=M) update(ul,ur,ud,lson);
		if(ur>M) update(ul,ur,ud,rson);

		pushUP(po);
	}

	inline void update(int L,int R,int d) {
		if(R<L) return;
		update(L,R,d,1,N,1);
	}

	inline int getans() {
		return bit[1]-1;
	}
}ans;

inline int findL(int x,int y) {
	if(y<x) return x-1;
	int L=x,R=y,M;

	while(R>L) {
		M=(L+R+1)>>1;
		if(M+1-LX.query(M)<=x) L=M;
		else R=M-1;
	}

	return L;
}

inline int findR(int x,int y) {
	if(y<x) return y+1;
	int L=x,R=y,M;

	while(R>L) {
		M=(L+R)>>1;
		if(M-1+RX.query(M)>=y) R=M;
		else L=M+1;
	}

	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d",A+i);
		H.update(i,i,A[i]);
	}
	A[0]=A[N+1]=0;

	long long t=0;
	for(int i=1;i<=N;++i) {
		if(A[i]>A[i-1]) ++t;
		else t=1;

		LX.update(i,i,t);
		ans.update(i,i,t);
	}

	t=0;
	for(int i=N;i>=1;--i) {
		if(A[i]>A[i+1]) ++t;
		else t=1;

		RX.update(i,i,t);
		ans.update(i,i,t);
	}

	int M,a,b,c;
	long long b1,b2,b3,b4;
	long long ta,tb;

	scanf("%d",&M);
	while(M--) {
		scanf("%d %d %d",&a,&b,&c);
		b1=a-1 ? H.query(a-1) : 0;
		b2=H.query(a);
		b3=H.query(b);
		b4=b+1<=N ? H.query(b+1) : 0;

		H.update(a,b,c);

		////////////////////

		ta=LX.query(a-1);
		tb=LX.query(b);

		if(b2<=b1 && b2+c>b1) {
			t=findL(a,b);
			LX.update(a,t,ta);
			ans.update(a,t,ta);

			if(t==b && b4>b3+c) {
				t=findL(b+1,N);
				LX.update(b+1,t,ta);
				ans.update(b+1,t,ta);
			}
		}

		if(b4>b3 && b4<=b3+c) {
			t=findL(b+1,N);
			LX.update(b+1,t,-tb);
			ans.update(b+1,t,-tb);
		}

		////////////////////

		ta=RX.query(a);
		tb=b+1<=N ? RX.query(b+1) : 0;

		if(b3<=b4 && b3+c>b4) {
			t=findR(a,b);
			RX.update(t,b,tb);
			ans.update(t,b,tb);

			if(t==a && b1>b2+c) {
				t=findR(1,a-1);
				RX.update(t,a-1,tb);
				ans.update(t,a-1,tb);
			}
		}

		if(b1>b2 && b1<=b2+c) {
			t=findR(1,a-1);
			RX.update(t,a-1,-ta);
			ans.update(t,a-1,-ta);
		}

		////////////////////

		/*
		for(int i=1;i<=N;++i) cout<<H.query(i)<<' ';
		cout<<endl;
		for(int i=1;i<=N;++i) cout<<LX.query(i)<<' ';
		cout<<endl;
		for(int i=1;i<=N;++i) cout<<RX.query(i)<<' ';
		cout<<endl;
		cout<<endl;
		*/

		printf("%d\n",ans.getans());
	}

	return 0;
}
