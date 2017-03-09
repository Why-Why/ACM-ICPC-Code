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
// Created Time  : 2015年12月03日 星期四 21时08分35秒
// File Name     : A_1.cpp

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

struct Node {
	int id,v1,v2,f,l;
	bool q;
}node[MaxN];

int head[MaxN],Ecou;

int N,M,cou;
int hash1[1000005];

int que[MaxN],ans[MaxN];

void init() {
	Ecou=cou=0;
	for(int i=0;i<=N;++i) head[i]=-1;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre) {
	node[u].f=++cou;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs(E[i].to,u);
	node[u].l=++cou;
}

inline bool cmp(const Node &a,const Node &b) {
	return a.v2<b.v2;
}

////////////////////

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<3];

inline void pushUP(int po) {
	BIT[po]=max(BIT[lc],BIT[rc]);
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

int query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];

	int M=(L+R)>>1,ret=-1;
	if(ql<=M) ret=max(ret,query(ql,qr,lson));
	if(qr>M) ret=max(ret,query(ql,qr,rson));
	return ret;
}

////////////////////

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T,a,b,c;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		init();
		memset(BIT,-1,sizeof(BIT));
		for(int i=1;i<N;++i) {
			scanf("%d %d %d",&a,&node[i].v1,&node[i].v2);
			addEdge(i,a); addEdge(a,i);
			hash1[node[i].v1]=i;
			node[i].id=i;
			node[i].q=0;
		}

		for(int i=1;i<=M;++i) {
			scanf("%d",&a);
			que[i]=a;
			node[a].q=1;
		}

		dfs(0,-1);
		node[0].v2=-1;
		sort(node+1,node+N,cmp);

		int tmaxn=-1;

		for(int i=N-1;i>=1;--i) {
			if(node[i].q) ans[node[i].id]=query(node[i].f,node[i].l,1,cou,1);
			if(node[i].v2!=node[i-1].v2) {
				tmaxn=max(tmaxn,node[i].v1);
				update(node[i].f,tmaxn,1,cou,1);
				update(node[i].l,tmaxn,1,cou,1);
				tmaxn=-1;
			}
			else tmaxn=max(tmaxn,node[i].v1);
		}

		for(int i=1;i<=M;++i)
			if(ans[que[i]]==-1) puts("-1");
			else printf("%d\n",hash1[ans[que[i]]]);
	}
	
	return 0;
}
