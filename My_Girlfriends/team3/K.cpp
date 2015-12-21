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
// Created Time  : 2015年12月08日 星期二 21时47分06秒
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
#include <climits>

using namespace std;

const int MaxN=100005;
const int INF=0x3f3f3f3f;

/////////////////////////////////

struct Treap {
	int tot,root;
	int ch[MaxN][2];
	int key[MaxN],pri[MaxN];
	int maxn[MaxN],rem[MaxN];

	void init() {
		tot=1;
		root=0;
		pri[0]=INT_MAX;
		maxn[0]=rem[0]=-INF;		// !!!
	}

	void update(int x) {
		maxn[x]=max(maxn[ch[x][0]],max(maxn[ch[x][1]],rem[x]));
	}

	void rotate(int &x,int t) {
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;
		update(x);
		update(y);
		x=y;
	}

	void _insert(int &x,int k,int v) {
		if(x) {
			if(key[x]==k) rem[x]=max(rem[x],v);
			else {
				int t=key[x]<k;
				_insert(ch[x][t],k,v);
				if(pri[ch[x][t]]<pri[x]) rotate(x,t);
			}
		}
		else {
			x=tot++;
			key[x]=k;
			rem[x]=v;
			pri[x]=rand();
			ch[x][0]=ch[x][1]=0;
		}
		update(x);
	}

	void insert(int k,int v) {
		_insert(root,k,v);
	}

	int getmin(int k) {
		int x=root,ret=-INF;		// !!!
		
		while(x) {
			if(key[x]==k) return max(ret,max(maxn[ch[x][0]],rem[x]));
			if(key[x]<k) { ret=max(ret,max(maxn[ch[x][0]],rem[x])); x=ch[x][1]; }
			else x=ch[x][0];
		}
		return ret;
	}

	int getmax(int k) {
		int x=root,ret=-INF;		// !!!

		while(x) {
			if(key[x]==k) return max(ret,max(maxn[ch[x][1]],rem[x]));
			if(key[x]<k) x=ch[x][1];
			else { ret=max(ret,max(maxn[ch[x][1]],rem[x])); x=ch[x][0]; }
		}
		return ret;
	}
}tree1,tree2;

/////////////////////////////////

struct Edge {
	int to,next;
}E[MaxN<<1];

int N,D;
int head[MaxN],Ecou;
int val[MaxN];
bool vis[MaxN];
int ans;

void init() {
	Ecou=0;
	for(int i=0;i<=N;++i) vis[i]=0,head[i]=-1;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

/////////////////////////////////

int sumnode,cen,minnC;
int maxson[MaxN],couson[MaxN];

void dfsC1(int u,int pre) {
	couson[u]=1;
	maxson[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre) {
			dfsC1(E[i].to,u);
			couson[u]+=couson[E[i].to];
			maxson[u]=max(maxson[u],couson[E[i].to]);
		}
}

void dfsC2(int u,int pre) {
	int maxn=max(maxson[u],sumnode-couson[u]);
	if(maxn<minnC) {
		minnC=maxn;
		cen=u;
	}

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsC2(E[i].to,u);
}

int getCenter(int u) {
	dfsC1(u,-1);
	sumnode=couson[u];
	minnC=INF;
	dfsC2(u,-1);
	return cen;
}

/////////////////////////////////

int RD1[MaxN],RA1[MaxN],LEN1;
int RD2[MaxN],RA2[MaxN],LEN2;

void dfsc1(int u,int pre,int d) {
	RD1[LEN1]=d;
	RA1[LEN1++]=val[u];

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			if(val[E[i].to]>=val[u])
				dfsc1(E[i].to,u,d+1);
}

void dfsc2(int u,int pre,int d) {
	RD2[LEN2]=d;
	RA2[LEN2++]=val[u];

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			if(val[E[i].to]<=val[u])
				dfsc2(E[i].to,u,d+1);
}

inline void getans1() {
	for(int i=0;i<LEN1;++i)
		ans=max(ans,RD1[i]+tree2.getmax(RA1[i]-D));
}

inline void getans2() {
	for(int i=0;i<LEN2;++i)
		ans=max(ans,RD2[i]+tree1.getmin(D+RA2[i]));
}

inline void merge() {
	for(int i=0;i<LEN1;++i) tree1.insert(RA1[i],RD1[i]);
	for(int i=0;i<LEN2;++i) tree2.insert(RA2[i],RD2[i]);
}

void calc(int u) {
	tree1.init();
	tree2.init();
	tree1.insert(val[u],0);
	tree2.insert(val[u],0);

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {
			LEN1=LEN2=0;
			if(val[E[i].to]>=val[u]) {
				dfsc1(E[i].to,u,1);
				getans1();
			}
			if(val[E[i].to]<=val[u]) {
				dfsc2(E[i].to,u,1);
				getans2();
			}
			merge();			// !!! 在最后。
		}
}

/////////////////////////////////

void solve(int u) {
	int c=getCenter(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c];i!=-1;i=E[i].next)
		if(!vis[E[i].to])
			solve(E[i].to);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b;
	scanf("%d",&T);
	
	while(T--) {
		scanf("%d %d",&N,&D);
		for(int i=1;i<=N;++i) scanf("%d",val+i);
		init();
		for(int i=1;i<N;++i) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		ans=0;
		solve(1);
		printf("Case #%d: %d\n",cas++,ans+1);
	}
	
	return 0;
}
