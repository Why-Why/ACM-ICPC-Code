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
// Created Time  : 2017年03月09日 星期四 00时00分29秒
// File Name     : G.cpp

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

int rem[MaxN];

// 注意：构建树的时候可以使用link来构建，但是注意加的新点的初始化，第一个点连接到0上面。

struct LCT {
	// Splay.
	int ch[MaxN][2],rev[MaxN];
	int que[MaxN];

	// 对于一棵Splay的根来说是原树中当前链的最顶端的父亲节点，其他节点来说是Splay中的父亲节点。
	int Fa[MaxN];

	// 判断u是否是Splay的根。
	bool isRoot(int u) {
		if(!Fa[u]) return 1;
		return ch[Fa[u]][0]!=u && ch[Fa[u]][1]!=u;
	}

	void Rotate(int u) {
		int k=(ch[Fa[u]][1]==u);
		int x=Fa[u],y=Fa[x];
		Fa[u]=y;
		if(!isRoot(x)) ch[y][ch[y][1]==x]=u;
		ch[x][k]=ch[u][!k];
		Fa[ch[u][!k]]=x;
		ch[u][!k]=x;
		Fa[x]=u;

		// pushUP(x);
		// pushUP(u);
	}

	void pushDown(int u) {
		if(rev[u]) {
			rev[ch[u][0]]^=1;
			swap(ch[ch[u][0]][0],ch[ch[u][0]][1]);
			rev[ch[u][1]]^=1;
			swap(ch[ch[u][1]][0],ch[ch[u][1]][1]);
			rev[u]^=1;
		}

		// 其他需要维护的值。
	}

	// 使u成为其所在的Splay的根节点。
	void Splay(int u) {
		int top=0,x,y;

		que[top++]=u;
		for(int i=u;!isRoot(i);i=Fa[i]) que[top++]=Fa[i];
		while(top) pushDown(que[--top]);

		while(!isRoot(u)) {
			x=Fa[u];
			y=Fa[x];

			if(!isRoot(x)) {
				if((ch[y][0]==x)==(ch[x][0]==u)) Rotate(x);		// yes or not ?
				else Rotate(u);
			}
			Rotate(u);
		}
	}

	////////

	void initNode(int u) {
		ch[u][0]=ch[u][1]=0;
		rev[u]=0;
		Fa[u]=0;
	}

	void init() {
		initNode(0);
	}

	void access(int u) {
		int t=0;
		while(u) {
			Splay(u);
			ch[u][1]=t;
			// pushUP(u);
			t=u;
			u=Fa[u];
		}
	}

	int findMin(int u) {
		while(ch[u][0]) u=ch[u][0];
		return u;
	}

	int query(int a) {
		access(a);
		while(Fa[a]) a=Fa[a];
		return findMin(a);
	}

	void link(int a,int b) {
		if(query(b)==a) return;
		access(a);
		Splay(a);
		Fa[a]=b;
	}

	void cut(int a) {
		access(a);
		Splay(a);

		int t=findMin(a);

		Fa[ch[a][0]]=0;
		ch[a][0]=0;
		Fa[a]=0;

		if(rem[t]) link(t,rem[t]);
	}

	void merge(int a,int b) {
		if(rem[a]==b) return;
		if(rem[a]) cut(a);
		if(b) link(a,b);
		else Fa[a]=0;
		rem[a]=b;
	}

}tree;

inline int read() {
	char c=0;
	while(c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

int N,M;

int fa[MaxN];

int find(int x) {
	if(!fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	N=read();
	M=read();

	tree.init();
	for(int i=1;i<=N;++i) {
		rem[i]=read();
		tree.initNode(i);

		if(rem[i]) {
			a=find(i);
			b=find(rem[i]);
			if(a!=b) {
				tree.Fa[i]=rem[i];
				fa[a]=b;
			}
		}
	}

	while(M--) {
		a=read();
		b=read();
		if(a==1) {
			c=read();
			tree.merge(b,c);
		}
		else {
			c=tree.query(b);
			if(rem[c]) c=-1;
			printf("%d\n",c);
		}
	}

	return 0;
}
