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
// Created Time  : 2016年01月22日 星期五 15时49分23秒
// File Name     : L.cpp

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

const int MaxN=100005;

struct OPE {
	int l,r,w;
	int id;
}ope[MaxN<<1],opel[MaxN<<1],oper[MaxN<<1];

int N,M;
int ans[MaxN];
int tmp[MaxN<<1];

int BIT[MaxN<<2];
int lmost[MaxN<<2],rmost[MaxN<<2];

inline void pushUP(int len1,int len2,int po) {
	BIT[po]=max(BIT[lc],BIT[rc]);
	BIT[po]=max(BIT[po],lmost[rc]+rmost[lc]);

	if(lmost[lc]==len1) lmost[po]=len1+lmost[rc];
	else lmost[po]=lmost[lc];

	if(rmost[rc]==len2) rmost[po]=len2+rmost[lc];
	else rmost[po]=rmost[rc];
}

inline void update(int up,int ut,int L,int R,int po) {
	if(L==R) {
		BIT[po]=lmost[po]=rmost[po]=ut;
		return;
	}

	int M=(L+R)>>1;
	update(up,ut,lson);
	update(up,ut,rson);
	pushUP(M-L+1,R-M,po);
}

struct ANS {
	int ans,lans,rans;
};

ANS merge(int len1,int len2,ANS a1,ANS a2) {
	ANS ret;
	ret.ans=max(a1.ans,a2.ans);
	ret.ans=max(ret.ans,a1.rans+a2.lans);

	if(len1==a1.ans) ret.lans=len1+a2.lans;
	else ret.lans=a1.lans;

	if(len2==a2.ans) ret.rans=len2+a1.rans;
	else ret.rans=a2.rans;

	return ret;
}

ANS query(int ql,int qr,int L,int R,int po) {
	if(po==1) cerr<<"# "<<ql<<' '<<qr<<' '<<L<<' '<<R<<endl;

	if(ql<=L && qr>=R) {
		ANS t;
		t.ans=BIT[po];
		t.lans=lmost[po];
		t.rans=rmost[po];
		return t;
	}
	
	int M=(L+R)>>1;
	if(ql>M) return query(ql,qr,rson);
	if(qr<=M) return query(ql,qr,lson);

	return merge(M-L+1,R-M,query(ql,qr,lson),query(ql,qr,rson));
}

void getans(int ql,int qr,int L,int R) {
	cout<<ql<<' '<<qr<<' '<<L<<' '<<R<<endl;

	if(ql>qr) return;
	if(L==R) {
		for(int i=ql;i<=qr;++i) ans[ope[i].id]=L;
		return;
	}

	int M=(L+R+1)>>1;
	for(int i=ql;i<=qr;++i)
		if(!ope[i].id && ope[i].w>=M)
			update(ope[i].l,1,1,N,1),tmp[i]=2;
		else if(ope[i].id && ope[i].w<=query(ope[i].l,ope[i].r,1,N,1).ans)
			tmp[i]=1;
		else tmp[i]=0;

	for(int i=ql;i<=qr;++i)
		if(tmp[i]==2)
			update(ope[i].l,0,1,N,1);

	int cou1=0,cou2=0;
	for(int i=ql;i<=qr;++i)
		if(tmp[i]) oper[cou2++]=ope[i];
		else opel[cou1++]=ope[i];
	int t=ql;
	for(int i=0;i<cou1;++i) ope[t++]=opel[i];
	for(int i=0;i<cou2;++i) ope[t++]=oper[i];

	getans(ql,ql+cou1-1,L,M-1);
	getans(ql+cou1,qr,M,R);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;
	int cou=0;

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d",&t);
		ope[++cou].id=0;
		ope[cou].l=i;
		ope[cou].w=t;
	}
	scanf("%d",&M);
	for(int i=1;i<=M;++i) {
		++cou;
		scanf("%d %d %d",&ope[cou].l,&ope[cou].r,&ope[cou].w);
		ope[cou].id=i;
	}
	getans(1,cou,1,1000000000);

	for(int i=1;i<=M;++i)
		printf("%d\n",ans[i]);
	
	return 0;
}
