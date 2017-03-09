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
// Created Time  : 2016年03月22日 星期二 23时48分10秒
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

const int MaxN=100005;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

long long BIT[MaxN<<2];
long long MAXN[MaxN<<2];
int N;

inline void pushUP(int po) {
	BIT[po]=BIT[lc]+BIT[rc];
	MAXN[po]=max(MAXN[lc],MAXN[rc]);
}

void update(int up,int ut,int L,int R,int po) {
	if(L==R) {
		MAXN[po]=ut;
		BIT[po]=ut;
		return;
	}

	int M=(L+R)>>1;
	if(up<=M) update(up,ut,lson);
	if(up>M) update(up,ut,rson);
	pushUP(po);
}

long long query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];

	int M=(L+R)>>1;
	long long ret=0;
	if(ql<=M) ret+=query(ql,qr,lson);
	if(qr>M) ret+=query(ql,qr,rson);
	return ret;
}

void update(int ul,int ur,int ut,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		if(MAXN[po]<ut) return;
		if(L==R) {
			MAXN[po]=MAXN[po]%ut;
			BIT[po]=MAXN[po];
			return;
		}
	}

	int M=(L+R)>>1;
	if(ul>M) update(ul,ur,ut,rson);
	if(ur<=M) update(ul,ur,ut,lson);

}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	return 0;
}
