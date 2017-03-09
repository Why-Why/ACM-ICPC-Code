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
// Created Time  : 2015年12月23日 星期三 23时48分48秒
// File Name     : F.cpp

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

const int MaxN=10005;

struct OPE {
	bool type;
	int id,i,f;
};

OPE ope[MaxN];
int N,M;
int T[111][5005],F[111][5005];
int ans[111][5005];

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

const int NN=105005;
const int INF=0x3f3f3f3f;
int BIT[110000<<2];
int COL[110000<<2];

inline void pushUP(int po) {
	BIT[po]=min(BIT[lc],BIT[rc]);
}

inline void pushDown(int po) {
	if(COL[po]!=-1) {
		COL[lc]=COL[rc]=COL[po];
		BIT[lc]=BIT[rc]=COL[po];
		COL[po]=-1;
	}
}

void update(int p,int t,int L,int R,int po) {
	if(L==R) {
		BIT[po]=min(BIT[po],t);
		return;
	}
	pushDown(po);
	int M=(L+R)>>1;
	if(p<=M) update(p,t,lson);
	else update(p,t,rson);
	pushUP(po);
}

int query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];
	pushDown(po);
	int M=(L+R)>>1;
	int ret=INF;

	if(ql<=M) ret=min(ret,query(ql,qr,lson));
	if(qr>M) ret=min(ret,query(ql,qr,rson));
	return ret;
}

void getans(int hang) {
	COL[1]=INF;
	for(int i=1;i<=M;++i) {
		update(i+F[hang-1][i],ans[hang-1][i],1,NN,1);
		ans[hang][i]=query(max(1,i-F[hang][i]),NN,1,NN,1);
	}
	COL[1]=INF;
	for(int i=M;i>=1;--i) {			// !!!
		ans[hang][i]=T[hang][i]+min(ans[hang][i],query(1,F[hang][i]+i,1,NN,1));	//!!!
		update(max(1,i-F[hang-1][i]),ans[hang-1][i],1,NN,1);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&M) && N+M) {
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j) scanf("%d",&T[i][j]);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j) scanf("%d",&F[i][j]);
		for(int i=1;i<=M;++i) ans[1][i]=T[1][i];

		for(int i=2;i<=N;++i) getans(i);
		int zans=INF;
		for(int i=1;i<=M;++i) zans=min(zans,ans[N][i]);
		printf("%d\n",zans);
	}
	
	return 0;
}
