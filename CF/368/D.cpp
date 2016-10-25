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
// Created Time  : 2016年09月04日 星期日 18时18分46秒
// File Name     : D.cpp

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
#include <bitset>

using namespace std;

const int MaxN=100005;
const int MaxNode=2000000;

int Tcou,TreeRoot[MaxN];
int lson[MaxNode],rson[MaxNode],BIT[MaxNode];

int N,M,Q;

int Bcou;
bitset <1003> Brem[100000+1003];

inline int insert(int old,int p,int &ap) {
	int newRoot=Tcou++,ret=newRoot;
	int L=1,R=N,M;

	while(R>L) {
		M=(L+R)>>1;

		if(p<=M) {
			lson[newRoot]=Tcou++; rson[newRoot]=rson[old];
			newRoot=lson[newRoot]; old=lson[old];
			R=M;
		}
		else {
			lson[newRoot]=lson[old]; rson[newRoot]=Tcou++;
			newRoot=rson[newRoot]; old=rson[old];
			L=M+1;
		}
	}
	Brem[Bcou]=Brem[BIT[old]];
	ap=Bcou;
	BIT[newRoot]=Bcou++;

	return ret;
}

int build(int L,int R) {
	if(L==R) {
		Brem[Bcou].reset();
		lson[Tcou]=rson[Tcou]=-1;
		BIT[Tcou++]=Bcou++;
		return Tcou-1;
	}

	int M=(L+R)>>1;
	lson[Tcou]=build(L,M);
	rson[Tcou]=build(M+1,R);
	++Tcou;
	return Tcou-1;
}

int ans[100005];
bitset <1003> base;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&M,&Q);
	for(int i=1;i<=M;++i) base.set(i);

	ans[0]=0;
	TreeRoot[0]=build(1,N);

	int a,b,c,d,t;

	for(int i=1;i<=Q;++i) {
		scanf("%d %d",&a,&b);
		if(a==1) {
			scanf("%d",&c);
			TreeRoot[i]=insert(TreeRoot[i-1],b,d);

			ans[i]=ans[i-1];
			if(Brem[d][c]==0) Brem[d].set(c),++ans[i];
		}
		else if(a==2) {
			scanf("%d",&c);
			TreeRoot[i]=insert(TreeRoot[i-1],b,d);

			ans[i]=ans[i-1];
			if(Brem[d][c]) Brem[d].reset(c),--ans[i];
		}
		else if(a==3) {
			TreeRoot[i]=insert(TreeRoot[i-1],b,d);

			ans[i]=ans[i-1];
			t=Brem[d].count();
			ans[i]=ans[i]-t+(M-t);
			Brem[d]=(~Brem[d])&base;
		}
		else {
			ans[i]=ans[b];
			BIT[Tcou]=BIT[TreeRoot[b]];			// !!!!
			TreeRoot[i]=Tcou++;
			lson[Tcou-1]=lson[TreeRoot[b]];
			rson[Tcou-1]=rson[TreeRoot[b]];
		}
		printf("%d\n",ans[i]);
	}

	return 0;
}
