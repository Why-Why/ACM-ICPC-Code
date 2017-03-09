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
// Created Time  : 2015年12月03日 星期四 20时09分12秒
// File Name     : A.cpp

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
}E[MaxN<<1];

int head[MaxN],Ecou;
int N,M;

struct Node {
	int id;
	bool q;
}node[MaxN];

int val1[MaxN],val2[MaxN];
int fir[MaxN],las[MaxN];
int cou;

int que[MaxN],ans[MaxN];

int BIT[MaxN<<3];
bool COL[MaxN<<3];
int hash1[1000005];

void init(int N) {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre) {
	fir[u]=++cou;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs(E[i].to,u);
	las[u]=++cou;
}

inline bool cmp(const Node &a, const Node &b) {
	return val2[a.id]<val2[b.id];
}

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

inline void pushUP(int po) {
	BIT[po]=max(BIT[lc],BIT[rc]);
}

inline void pushDown(int po) {
	if(COL[po]) {
		COL[po]=0;
		COL[lc]=COL[rc]=1;
		BIT[lc]=BIT[rc]=-1;
	}
}

int query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];

	pushDown(po);
	int ret=-1,M=(L+R)>>1;
	if(ql<=M) ret=max(ret,query(ql,qr,lson));
	if(qr>M) ret=max(ret,query(ql,qr,rson));
	return ret;
}

void update(int up,int ut,int L,int R,int po) {
	if(L==R) {
		BIT[po]=max(BIT[po],ut);
		return;
	}

	pushDown(po);
	int M=(L+R)>>1;
	update(up,ut,lson);
	update(up,ut,rson);
	pushUP(po);
}

inline int getans(int id) {
	return query(fir[id],las[id],1,cou,1);
}

inline void update(int id) {
	update(fir[id],val1[id],1,cou,1);
	update(las[id],val1[id],1,cou,1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	int a,b,c;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		init(N);
		cou=0;
		for(int i=2;i<=N;++i) {
			scanf("%d %d %d",&a,&b,&c);
			addEdge(i,a+1);
			addEdge(a+1,i);
			node[i].id=i;
			node[i].q=0;
			val1[i]=b;
			val2[i]=c;
			hash1[b]=i-1;
		}

		for(int i=1;i<=M;++i) {
			scanf("%d",&a);
			que[i]=a+1;
			node[a+1].q=1;
		}

		dfs(1,-1);
		COL[1]=1;
		sort(node+1,node+N+1,cmp);

		for(int i=N;i>=2;--i) {
			if(node[i].q==1) ans[node[i].id]=getans(node[i].id);
			update(node[i].id);
		}

		for(int i=1;i<=M;++i)
			if(ans[que[i]]!=-1) printf("%d\n",hash1[ans[que[i]]]);
			else puts("-1");
	}
	
	return 0;
}
