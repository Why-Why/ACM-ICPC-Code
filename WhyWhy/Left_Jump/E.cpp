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
// Created Time  : 2016年04月14日 星期四 00时00分38秒
// File Name     : E.cpp

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

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2],COL[MaxN<<2];
int base,minn;

inline void pushUP(int po) {
	BIT[po]=BIT[lc]+BIT[rc];
}

inline void pushDown(int po) {
	if(COL[po]) {
		BIT[lc]=BIT[rc]=0;
		COL[lc]=COL[rc]=COL[po];
		COL[po]=0;
	}
}

void update(int up,int ut,int L,int R,int po) {
	if(L==R) {
		BIT[po]+=ut;
		return;
	}
	pushDown(po);
	int M=(L+R)>>1;
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);
	pushUP(po);
}

void updateR(int ul,int ur,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		BIT[po]=0;
		COL[po]=1;
		return;
	}
	pushDown(po);
	int M=(L+R)>>1;
	if(ul<=M) updateR(ul,ur,lson);
	if(ur>M) updateR(ul,ur,rson);
	pushUP(po);
}

int query(int k,int L,int R,int po) {
	if(BIT[po]<k) return -1;
	if(L==R) return L-base;
	pushDown(po);
	int M=(L+R)>>1;
	if(BIT[rc]>=k) return query(k,rson);
	else return query(k-BIT[rc],lson);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,a,cou=0;
	char s[10];

	base=100001;
	const int MAXN=300001;

	scanf("%d %d",&N,&minn);
	while(N--) {
		scanf("%s %d",s,&a);
		if(s[0]=='I') {				// !!!
			if(a>=minn) update(base+a,1,1,MAXN,1),++cou;
		}
		else if(s[0]=='A')
			base-=a;
		else if(s[0]=='S') {
			base+=a;
			updateR(1,base+minn-1,1,MAXN,1);
		}
		else
			printf("%d\n",query(a,1,MAXN,1));
	}
	printf("%d\n",cou-BIT[1]);
	
	return 0;
}
