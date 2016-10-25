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
// Created Time  : 2016年08月18日 星期四 15时37分53秒
// File Name     : 1005.cpp

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

const int MaxN=200005;

const int INF=0x3f3f3f3f;

int maxn[MaxN<<2],minn[MaxN<<2];
int col1[MaxN<<2],col2[MaxN<<2];

int N;
int num[MaxN];

typedef pair<int,int> pii;
pii rem[MaxN<<1];

inline void pushDown(int po) {
	if(col1[po]) {
		col1[lc]=max(col1[lc],col1[po]);
		col1[rc]=max(col1[rc],col1[po]);

		maxn[lc]=max(maxn[lc],col1[lc]);
		maxn[rc]=max(maxn[rc],col1[rc]);
		col1[po]=0;
	}

	if(col2[po]!=INF) {
		col2[lc]=min(col2[lc],col2[po]);
		col2[rc]=min(col2[rc],col2[po]);

		minn[lc]=min(maxn[lc],col2[lc]);
		minn[rc]=min(maxn[rc],col2[rc]);
		col2[po]=INF;
	}
}

void update(int ul,int ur,int ut,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		minn[po]=min(minn[po],ut);
		maxn[po]=max(maxn[po],ut);

		col1[po]=max(col1[po],ut);
		col2[po]=min(col2[po],ut);

		return;
	}

	pushDown(po);

	int M=(L+R)>>1;
	if(ul<=M) update(ul,ur,ut,lson);
	if(ur>M) update(ul,ur,ut,rson);
}

void query(int p,int &a,int &b,int L,int R,int po) {
	if(L==R) {
		a=minn[po];
		b=maxn[po];
		return;
	}

	pushDown(po);

	int M=(L+R)>>1;
	if(p<=M) query(p,a,b,lson);
	else query(p,a,b,rson);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b;

	while(~scanf("%d %d",&N,&M)) {
		for(int i=2;i<=N;++i) scanf("%d",num+i);
		num[1]=0;

		memset(maxn,0,sizeof(maxn));
		memset(minn,0x3f,sizeof(minn));
		memset(col1,0,sizeof(col1));
		memset(col2,0x3f,sizeof(col2));

		for(int i=1;i<=M;++i) {
			scanf("%d %d",&a,&b);
			if(a>b) swap(a,b);

			update(a+1,b,i,1,N,1);
		}

		int cou=0;

		for(int i=2;i<=N;++i) {
			query(i,a,b,1,N,1);

			if(a>b) continue;
			rem[cou++]=pii(a,num[i]);
			rem[cou++]=pii(b+1,-num[i]);
		}

		int sum=0;
		int p=0;

		sort(rem,rem+cou);
		for(int i=1;i<=M;++i) {
			while(p<cou && rem[p].first<=i) {
				sum+=rem[p].second;
				++p;
			}
			printf("%d\n",sum);
		}
	}

	return 0;
}
