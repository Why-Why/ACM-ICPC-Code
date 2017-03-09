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
// Created Time  : 2017年02月27日 星期一 18时25分43秒
// File Name     : 2966.cpp

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
const int MaxDim=2;

struct Point {
	int x[MaxDim];
};

Point P[MaxN];			// 顺序在build时会改变。
int Dim=2;					// 维度，from 0。
int cur;

inline bool cmp(const Point &a,const Point &b) {
	return a.x[cur]<b.x[cur];
}

void build(int L,int R,int dep) {
	if(L>=R) return;

	cur=dep%Dim;
	int M=(L+R)>>1;

	nth_element(P+L,P+M,P+R+1,cmp);
	build(L,M-1,dep+1);
	build(M+1,R,dep+1);
}

const long long INF=3000000000000000000LL;

inline long long k_dist(const Point &a,const Point &b,int cur) {			// 可定制!!!
	return (a.x[cur]-b.x[cur])*(long long)(a.x[cur]-b.x[cur]);
}

inline long long dist(const Point &a,const Point &b) {						// 可定制!!!
	long long ret=0;
	for(int i=0;i<Dim;++i) ret+=k_dist(a,b,i);
	if(ret==0) ret=INF;
	return ret;
}

long long query(const Point &q,int L,int R,int dep) {
	if(L>=R) {
		if(L==R) return dist(q,P[L]);
		return INF;
	}

	int tcur=dep%Dim;						// 不能用共有变量cur!!!
	int M=(L+R)>>1;
	long long ret=dist(q,P[M]),tmp;			// can be changed.

	if(q.x[tcur]<P[M].x[tcur]) {
		tmp=query(q,L,M-1,dep+1);

		if(tmp>k_dist(q,P[M],tcur))		// or >=
			tmp=min(tmp,query(q,M+1,R,dep+1));
	}
	else {
		tmp=query(q,M+1,R,dep+1);

		if(tmp>k_dist(q,P[M],tcur))
			tmp=min(tmp,query(q,L,M-1,dep+1));
	}

	return min(tmp,ret);
}

////////////////////

int N;
Point rem[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		Dim=2;
		for(int i=1;i<=N;++i) {
			for(int j=0;j<Dim;++j)
				scanf("%d",&rem[i].x[j]);
			P[i]=rem[i];
		}

		build(1,N,1);
		for(int i=1;i<=N;++i)
			printf("%I64d\n",query(rem[i],1,N,1));
	}

	return 0;
}
