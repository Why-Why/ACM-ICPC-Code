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
// Created Time  : 2015年12月03日 星期四 23时31分18秒
// File Name     : A_2.cpp

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

const int MaxN=50005;

struct Edge {
	int to,next;
};

struct Node {
	int id,v1,v2;

	bool operator < (const Node &b) const {
		if(v2==b.v2) return v1>b.v1;
		return v2<b.v2;
	}
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

Node node[MaxN<<1];
int fir[MaxN],las[MaxN],cou;

int N,M;
int ans[MaxN];

void init() {
	Ecou=cou=0;
	for(int i=0;i<=N;++i) head[i]=-1;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

//////////////

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<3];

inline void pushUP(int po) {
	BIT[po]=max(BIT[lc],BIT[rc]);
}

int query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];

	int M=(L+R)>>1,ret=-1;
	if(ql<=M) ret=max(ret,query(ql,qr,lson));
	if(qr>M) ret=max(ret,query(ql,qr,rson));
	return ret;
}

void update(int up,int ut,int L,int R,int po) {
	if(L==R) {
		BIT[po]=max(BIT[po],ut);
		return;
	}

	int M=(L+R)>>1;
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);
	pushUP(po);
}

//////////////

struct State {
	int a,b,c;
	State() {}
	State(int _,int __,int ___):a(_),b(__),c(___) {}
}buf[MaxN];

int bcou;

void update() {
	for(int i=0;i<bcou;++i) {
		update(buf[i].a,buf[i].c,1,cou,1);
		update(buf[i].b,buf[i].c,1,cou,1);
	}
}

void dfs(int u,int pre) {
	fir[u]=++cou;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs(E[i].to,u);
	las[u]=++cou;
}

int hash1[1000005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b,c;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		init();
		node[0].id=0;
		node[0].v1=node[0].v2=-1;
		for(int i=1;i<N;++i) {
			scanf("%d %d %d",&a,&node[i].v1,&node[i].v2);
			addEdge(a,i); addEdge(i,a);
			node[i].id=i;
			hash1[node[i].v1]=i;
		}
		dfs(0,-1);
		sort(node+1,node+N);

		bcou=0;
		memset(BIT,-1,sizeof(BIT));
		for(int i=N-1;i>0;--i) {
			ans[node[i].id]=query(fir[node[i].id],las[node[i].id],1,cou,1);
			buf[bcou++]=State(fir[node[i].id],las[node[i].id],node[i].v1);
			if(node[i].v2!=node[i-1].v2) { update(); bcou=0; }
		}

		while(M--) {
			scanf("%d",&a);
			if(ans[a]!=-1) printf("%d\n",hash1[ans[a]]);
			else puts("-1");
		}
	}
	
	return 0;
}
