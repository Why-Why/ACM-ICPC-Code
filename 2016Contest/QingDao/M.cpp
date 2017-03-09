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
// Created Time  : 2017年03月02日 星期四 12时45分20秒
// File Name     : M.cpp

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

const int MaxN=200005;
const int MaxM=10004;
const int INF=0x3f3f3f3f;

typedef pair<int,int> pii;

struct BIT2 {
	HASHMAP rem;
	int M;
	int t1[MaxM],t2[MaxM];
	int t3[MaxN],t4[MaxN];

	void init(int _M) {
		rem.init();
		M=_M;
	}

	int dividR(int x,int t[],int &ttcou,int tt[]) {
		int L=1,R=M,Mid,po=1;
		int tcou=0;
		ttcou=0;

		while(1) {
			if(R<=x) {
				t[tcou++]=po;
				break;
			}

			Mid=(L+R)>>1;

			if(Mid<x) {
				t[tcou++]=(po<<1);
				L=Mid+1;
				po=(po<<1)|1;
			}
			else {
				R=Mid;
				po<<=1;
			}
		}

		return tcou;
	}

	void update(int x,int L,int R,int po) {
		if(x>=R) {
			update1(M+1-x,1,M,1);
			return;
		}
	}

	void updateR(int x) {
		int len1=dividR(x,t1);
		int len2=dividR(M+1-x,t2);

		for(int i=0;i<len1;++i)
			for(int j=0;j<len2;++j)
				rem.del(t1[i],t2[j]);
	}

	int dividD(int x,int t[]) {
		int L=1,R=M,Mid,po=1;
		int tcou=0;

		while(1) {
			t[tcou++]=po;
			if(L==R) break;

			Mid=(L+R)>>1;

			if(x<=Mid) {
				po<<=1;
				R=Mid;
			}
			else {
				po=(po<<1)|1;
				L=Mid+1;
			}
		}

		return tcou;
	}

	void updateD(int x,int y,int d) {
		y=M+1-y;
		int len1=dividD(x,t1);
		int len2=dividD(y,t2);

		for(int i=0;i<len1;++i)
			for(int j=0;j<len2;++j)
				rem.update(t1[i],t2[j],d);
	}

	bool query(int &x,int &y) {
		if(rem.query(1,1)) return 0;

		int L=1,R=M,Mid,po=1;

		while(R>L) {
			Mid=(L+R)>>1;
			if(rem.query(po<<1,1)) {
				po=(po<<1)|1;
				L=Mid+1;
			}
			else {
				po<<=1;
				R=Mid;
			}
		}

		x=L;
		int tx=po;

		L=1,R=M,po=1;

		while(R>L) {
			Mid=(L+R)>>1;
			if(rem.query(tx,po<<1)) {
				po=(po<<1)|1;
				L=Mid+1;
			}
			else {
				po<<=1;
				R=Mid;
			}
		}

		y=M+1-L;

		return 1;
	}

}tree2;

//////////////

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct BIT1 {
	int bit[MaxM<<2];

	void init() {
		memset(bit,0,sizeof(bit));
	}

	void add(int p,int L,int R,int po) {
		++bit[po];
		if(L==R) return;
		int M=(L+R)>>1;
		if(p<=M) add(p,lson);
		else add(p,rson);
	}

	int sum(int ql,int qr,int L,int R,int po) {
		if(ql<=L && qr>=R) return bit[po];
		int M=(L+R)>>1;
		int ret=0;
		if(ql<=M) ret+=sum(ql,qr,lson);
		if(qr>M) ret+=sum(ql,qr,rson);
		return ret;
	}

}tree1;

//////////////

struct RSET {
	set <pii> buf[MaxN];
	int bcou;
	HASHMAP rem;

	void init() {
		rem.init();
		bcou=0;
	}

	int find(int x,int y) {
		return rem.find(x,y);
	}

	void insert(int id,int x,int y,int v) {
		int t=rem.insert(x,y);
		if(t>=bcou) {
			bcou=t;
			buf[t].clear();
		}
		buf[t].insert(pii(v,id));
	}
}rset;

int ans[MaxN],acou;

inline void getans(int x) {
	acou=0;
	int a,b,t,tt;
	tree2.updateR(x);

	while(tree2.query(a,b)) {
		t=rset.find(a,b);

		tt=(*rset.buf[t].begin()).first;
		while(rset.buf[t].size() && ((*rset.buf[t].begin()).first==tt)) {
			ans[acou++]=(*rset.buf[t].begin()).second;
			rset.buf[t].erase(rset.buf[t].begin());
		}

		if(rset.buf[t].size()==0) tt=INF;
		else tt=(*rset.buf[t].begin()).first-tt;
		tree2.updateD(a,b,tt);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int BASE=0;
	int N,M,a,b,c;
	char s[10];
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		tree1.init();
		tree2.init(M);
		rset.init();

		printf("Case #%d:\n",cas++);

		for(int i=1;i<=N;++i) {
			scanf("%s %d",s,&a);
			if(s[0]=='C') {
				scanf("%d %d",&b,&c);
				tree2.updateD(a,b,c);
				c+=tree1.sum(a,b,1,M,1);
				rset.insert(i,a,b,c);
			}
			else {
				tree1.add(a,1,M,1);
				getans(a);

				if(acou) {
					sort(ans,ans+acou);
					printf("%d",i);
					for(int i=0;i<acou;++i) printf(" %d",ans[i]);
					puts("");
				}
			}
		}
	}

	return 0;
}
