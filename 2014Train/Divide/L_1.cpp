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
// Created Time  : 2016年01月22日 星期五 17时06分36秒
// File Name     : L_1.cpp

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

const int MaxN=100005<<1;

struct OPE { int l,r,w,id; } ope[MaxN],to1[MaxN],to2[MaxN];

int N,M;
int ans[MaxN];

///////////////////////////////

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct ANS { 
	int num,lnum,rnum; 
	ANS(int a=0,int b=0,int c=0):num(a),lnum(b),rnum(c) {}
};

ANS BIT[MaxN<<2];

ANS merge(int len1,int len2,ANS a1,ANS a2) {
	ANS ret;
	ret.num=max(max(a1.rnum+a2.lnum,a1.num),a2.num);
	ret.lnum=(len1==a1.num) ? len1+a2.lnum : a1.lnum;
	ret.rnum=(len2==a2.num) ? len2+a1.rnum : a2.rnum;
	return ret;
}

inline void pushUP(int len1,int len2,int po) {
	BIT[po]=merge(len1,len2,BIT[lc],BIT[rc]);
}

void update(int up,int ut,int L,int R,int po) {
	if(L==R) {
		BIT[po].num=BIT[po].lnum=BIT[po].rnum=ut;
		return;
	}

	int M=(L+R)>>1;
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);

	pushUP(M-L+1,R-M,po);
}

ANS query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];

	int M=(L+R)>>1;
	if(ql>M) return query(ql,qr,rson);
	if(qr<=M) return query(ql,qr,lson);

	return merge(M-ql+1,qr-M,query(ql,M,lson),query(M+1,qr,rson));		// !!!
}

///////////////////////////////

int tmp[MaxN];

void getans(int ql,int qr,int L,int R) {
	if(ql>qr) return;
	if(L==R) {
		for(int i=ql;i<=qr;++i) ans[ope[i].id]=L;
		return;
	}

	int M=(L+R+1)>>1;
	for(int i=ql;i<=qr;++i)
		if(!ope[i].id && ope[i].w>=M)
			update(ope[i].l,1,1,N,1),tmp[i]=2;
		else if(ope[i].id && ope[i].w<=query(ope[i].l,ope[i].r,1,N,1).num)
			tmp[i]=1;
		else tmp[i]=0;

	int cou1=0,cou2=0;
	for(int i=ql;i<=qr;++i)
		if(tmp[i]) {
			to2[cou2++]=ope[i];
			if(tmp[i]==2) update(ope[i].l,0,1,N,1);
		}
		else to1[cou1++]=ope[i];

	int t=ql;
	for(int i=0;i<cou1;++i) ope[t++]=to1[i];
	for(int i=0;i<cou2;++i) ope[t++]=to2[i];

	getans(ql+cou1,qr,M,R);			// !!! 大的那些要被用到，在小的里面。

	for(int i=ql+cou1;i<=qr;++i)
		if(!ope[i].id)
			update(ope[i].l,1,1,N,1);

	getans(ql,ql+cou1-1,L,M-1);
}

///////////////////////////////

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t,cou=0;
	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d",&t);
		ope[++cou].w=t;
		ope[cou].l=i;
		ope[cou].id=0;
	}
	scanf("%d",&M);
	for(int i=1;i<=M;++i) {
		ope[++cou].id=i;
		scanf("%d %d %d",&ope[cou].l,&ope[cou].r,&ope[cou].w);
	}
	getans(1,cou,1,1000000000);
	for(int i=1;i<=M;++i) printf("%d\n",ans[i]);
	
	return 0;
}
