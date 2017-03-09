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
// Created Time  : 2017年02月17日 星期五 11时20分35秒
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

const int MaxN=100005;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N;

typedef pair<int,int> pii;
pii rem[MaxN];

void init() {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1;
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int num[MaxN],Index,pos[MaxN];
int LL[MaxN],RR[MaxN];

void dfs(int u,int pre) {
	cout<<"# "<<u<<endl;
	num[++Index]=u;
	pos[u]=Index;
	LL[u]=Index;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs(E[i].to,u);

	RR[u]=Index;
}

/////////////////

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int col[MaxN<<2];

int bit[MaxN<<2];
bool col1[MaxN<<2];

inline void pushDown(int po) {
	if(col[po]) {
		col[lc]=col[rc]=col[po];
		col[po]=0;
	}

	if(col1[po]) {
		col1[po]=0;
		col1[lc]=col1[rc]=1;
		bit[lc]=bit[rc]=0;
	}
}

inline void pushUP(int po) {
	bit[po]=bit[lc]+bit[rc];
}

void build(int L,int R,int po) {
	col[po]=0;
	col1[po]=0;

	if(L==R) {
		bit[po]=1;
		return;
	}

	int M=(L+R)>>1;
	build(lson);
	build(rson);

	pushUP(po);
}

void update(int ul,int ur,int ut,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		col[po]=ut;
		return;
	}

	pushDown(po);

	int M=(L+R)>>1;
	if(ul<=M) update(ul,ur,ut,lson);
	if(ur>M) update(ul,ur,ut,rson);
}

int query(int qp,int L,int R,int po) {
	if(L==R) return col[po];

	pushDown(po);
	int M=(L+R)>>1;

	if(qp<=M) return query(qp,lson);
	if(qp>M) return query(qp,rson);
}

void update(int ul,int ur,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		bit[po]=0;
		col1[po]=1;
		return;
	}

	pushDown(po);

	int M=(L+R)>>1;
	if(ul<=M) update(ul,ur,lson);
	if(ur>M) update(ul,ur,rson);

	pushUP(po);
}

int query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return bit[po];

	pushDown(po);

	int M=(L+R)>>1;
	int ret=0;
	if(ql<=M) ret+=query(ql,qr,lson);
	if(qr>M) ret+=query(ql,qr,rson);

	return ret;
}

/////////////////

int start[MaxN];
int ans[MaxN];

inline void solve(int u) {
	int fa=query(pos[u],1,N,1);

	cout<<u<<' '<<fa<<' '<<start[fa]<<endl;

	if(fa==u) return;

	int sum=query(LL[u],RR[u],1,N,1);
	cout<<sum<<endl;

	start[u]=start[fa];
	start[fa]+=sum;

	cout<<start[u]<<' '<<start[fa]<<endl;

	update(LL[u],RR[u],u,1,N,1);
	update(LL[u],RR[u],1,N,1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int p;

	while(~scanf("%d",&N)) {
		init();
		Index=0;
		for(int i=2;i<=N;++i) {
			scanf("%d",&p);
			addEdge(p,i);
			addEdge(i,p);
		}
		for(int i=1;i<=N;++i) {
			scanf("%d",&p);
			rem[i]=pii(p,i);
		}
		sort(rem+1,rem+N+1);

		dfs(1,-1);

		build(1,N,1);
		col[1]=1;
		start[1]=1;
		for(int i=1;i<=N;++i) solve(rem[i].second);
		for(int i=1;i<=N;++i) ans[start[i]]=i;
		for(int i=1;i<=N;++i) printf("%d ",ans[i]);
		puts("");
	}

	return 0;
}
