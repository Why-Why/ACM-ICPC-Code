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
// Created Time  : 2017年02月27日 星期一 19时39分04秒
// File Name     : K.cpp

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
const int MaxDim=4;
const long long INF=3000000000000000000LL;

struct Point {
	int x[MaxDim];
};

Point P[MaxN];			// 顺序在build时会改变。

int minV[MaxN];

int Dim=2;					// 维度，from 0。
int cur;

inline bool cmp(const Point &a,const Point &b) {
	return a.x[cur]<b.x[cur];
}

int build(int L,int R,int dep) {
	if(L>=R) {
		if(L==R) {
			minV[L]=P[L].x[2];
			return minV[L];
		}
		return 0x3f3f3f3f;
	}

	cur=dep%Dim;
	int M=(L+R)>>1;

	minV[M]=0x3f3f3f3f;
	nth_element(P+L,P+M,P+R+1,cmp);
	minV[M]=min(minV[M],build(L,M-1,dep+1));
	minV[M]=min(minV[M],build(M+1,R,dep+1));
	return minV[M];
}

inline long long k_dist(const Point &a,const Point &b,int cur) {			// 可定制!!!
	return (a.x[cur]-b.x[cur])*(long long)(a.x[cur]-b.x[cur]);
}

inline long long dist(const Point &a,const Point &b) {						// 可定制!!!
	long long ret=0;
	for(int i=0;i<Dim;++i) ret+=k_dist(a,b,i);
	return ret;
}

inline int getMin(int a,int b,const Point &p) {
	if(a==-1) return b;
	if(b==-1) return a;

	long long x=dist(P[a],p),y=dist(P[b],p);

	if(x==y) {
		if(P[a].x[3]<P[b].x[3]) return a;
		return b;
	}

	if(x<y) return a;
	return b;
}

int query(const Point &q,int L,int R,int dep) {
	if(L>=R) {
		if(L==R && q.x[2]>=P[L].x[2]) return L;
		return -1;
	}

	int tcur=dep%Dim;						// 不能用共有变量cur!!!
	int M=(L+R)>>1;

	int ret=q.x[2]>=P[M].x[2] ? M : -1;
	int tmp;

	if(q.x[tcur]<P[M].x[tcur]) {
		tmp=query(q,L,M-1,dep+1);

		if(tmp==-1 || dist(P[tmp],q)>=k_dist(q,P[M],tcur))
			tmp=getMin(tmp,query(q,M+1,R,dep+1),q);
	}
	else {
		tmp=query(q,M+1,R,dep+1);

		if(tmp==-1 || dist(P[tmp],q)>=k_dist(q,P[M],tcur))
			tmp=getMin(tmp,query(q,L,M-1,dep+1),q);
	}

	return getMin(tmp,ret,q);
}

///////////////////////////////

int N,M;
Point rem[MaxN],que;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,t;
	scanf("%d",&T);

	while(T--) {
		Dim=2;
		scanf("%d %d",&N,&M);

		for(int i=1;i<=N;++i) {
			for(int j=0;j<3;++j)
				scanf("%d",&rem[i].x[j]);
			rem[i].x[3]=i;
			P[i]=rem[i];
		}
		build(1,N,1);

		while(M--) {
			for(int i=0;i<3;++i) scanf("%d",&que.x[i]);
			t=query(que,1,N,1);

			printf("%d %d %d\n",P[t].x[0],P[t].x[1],P[t].x[2]);
		}
	}

	return 0;
}
