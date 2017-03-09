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
// Created Time  : 2017年03月02日 星期四 15时59分37秒
// File Name     : tM.cpp

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

const int MaxM=10003;
const int MaxNode=15*200000+3;
const int INF=0x3f3f3f3f;

struct TreapForest {
	int tot;
	int root[MaxM<<2];
	int ch[MaxNode][2];
	short key[MaxNode];
	int pri[MaxNode];

	int col[MaxNode],minn[MaxNode];

	void init() {
		pri[0]=INT_MAX;
		col[0]=0;
		minn[0]=INF;
	}

	void pushDown(int x) {
		if(col[x]) {
			if(ch[x][0]) col[ch[x][0]]+=col[x],minn[ch[x][0]]-=col[x];
			if(ch[x][1]) col[ch[x][1]]+=col[x],minn[ch[x][1]]-=col[x];
		}
	}

	void update(int x) {
		pushDown(x);
		minn[x]=min(minn[ch[x][0]],minn[ch[x][1]]);
	}

	void rotate(int &x,int t) {
		int y=ch[x][t];
		pushDown(x);
		pushDown(y);

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;
		update(x);
		update(y);
		x=y;
	}

	void _insert(int &x,int k,int v) {
		if(x) {
			if(key[x]==k) minn[x]=min(minn[x],v);
			else {
				int t=key[x]<k;
				pushDown(x);
				_insert(ch[x][t],k,v);
				if(pri[ch[x][t]]<pri[x]) rotate(x,t);
			}
		}
		else {
			x=tot++;
			key[x]=k;
			pri[x]=rand();
			col[x]=0;
			minn[x]=v;
			ch[x][0]=ch[x][1]=0;
		}

		update(x);
	}

	void insert(int id,int k,int v) {
		_insert(root[id],k,v);
	}

	void update(int id,int k) {
		int u=root[id];

		while(u) {
			if(key[u]==k) {
				--minn[u];
				++col[ch[u][0]];
				--minn[ch[u][0]];
				break;
			}

			pushDown(u);

			if(key[u]<k) {
				--minn[u];
				++col[ch[u][0]];
				--minn[ch[u][0]];
				u=ch[u][1];
			}
			else u=ch[u][0];
		}
	}

};

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct BIT2 {
	TreapForest tree;
	int col[MaxM<<2];
	int M;

	void build(int L,int R,int po) {
		tree.root[po]=0;
		col[po]=0;
		if(L==R) return;

		int M=(L+R)>>1;
		build(lson);
		build(rson);
	}

	void init() {
		tree.init();
		build(1,M,1);
	}

	void pushDown(int po) {
		if(col[po]) {
			col[lc]+=col[po];
			tree.update(lc,
		}
	}

	void updateR(int x,int L,int R,int po) {
		if(x>=R) {
			tree.update(po,M+1-x);
			++col[po];
			return;
		}

		pushDown(po);
		int M=(L+R)>>1;
	}

}ttt;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cout<<(sizeof(ttt)+0.0)/1024<<endl;

	return 0;
}
