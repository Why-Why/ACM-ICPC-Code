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
// Created Time  : 2017年03月02日 星期四 18时40分55秒
// File Name     : M_1.cpp

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
const int MaxDim=2;
const int INF=0x3f3f3f3f;

struct Point {
	int x[MaxDim],id;

	Point() {}
	Point(int a,int b) {
		x[0]=a;
		x[1]=b;
	}
};

struct Node {
	int ch[2];
	int x,y,id;
	int minx,miny,maxx,maxy;

	int minn,val,col;
	int ans;

	void init() {
		ch[0]=ch[1]=0;
		minn=val=INF;
		col=0;
		ans=0;

		minx=maxx=x;
		miny=maxy=y;
	}


	inline void add(int x) {
		col+=x;
		if(val<INF) val-=x;
		if(minn<INF) minn-=x;
	}

	inline void change();
	inline void pushDown();
	inline void pushUP();
};

Point P[MaxN];
int Dim=2;
int cur;

int root;
Node node[MaxN];

int frem[MaxN];

inline bool cmp(const Point &a,const Point &b) {
	return a.x[cur]<b.x[cur];
}

inline void Node::change() {
	minx=min(minx,node[ch[0]].minx);
	miny=min(miny,node[ch[0]].miny);
	maxx=max(maxx,node[ch[0]].maxx);
	maxy=max(maxy,node[ch[0]].maxy);

	minx=min(minx,node[ch[1]].minx);
	miny=min(miny,node[ch[1]].miny);
	maxx=max(maxx,node[ch[1]].maxx);
	maxy=max(maxy,node[ch[1]].maxy);
}

int build(int L,int R,int dep) {
	if(L==R) {
		node[L].x=P[L].x[0];
		node[L].y=P[L].x[1];
		node[L].init();
		node[L].id=P[L].id;

		frem[P[L].id]=L;

		return L;
	}
	if(L>R) return 0;

	cur=dep;
	int M=(L+R)>>1;
	nth_element(P+L,P+M,P+R+1,cmp);

	node[M].x=P[M].x[0];
	node[M].y=P[M].x[1];
	node[M].init();
	node[M].id=P[M].id;

	frem[P[M].id]=M;

	node[M].ch[0]=build(L,M-1,dep^1);
	node[M].ch[1]=build(M+1,R,dep^1);

	node[M].change();

	return M;
}

inline void Node::pushDown() {
	if(col) {
		node[ch[0]].add(col);
		node[ch[1]].add(col);
		col=0;
	}
}

inline void Node::pushUP() {
	int t=min(node[ch[0]].minn,node[ch[1]].minn);
	if(node[ch[0]].minn<node[ch[1]].minn) ans=node[ch[0]].ans;
	else ans=node[ch[1]].ans;
	minn=min(val,t);
	if(val<t) ans=id;
}

void update(int p,int v,int u) {
	if(u==0) return;

	node[u].pushDown();
	if(u==p) {
		node[u].val=v;
		node[u].pushUP();
		return;
	}

	if(p<u) update(p,v,node[u].ch[0]);
	else update(p,v,node[u].ch[1]);

	node[u].pushUP();
}

void del(int xx,int u) {
	if(!u) return;
	if(node[u].minx>xx || node[u].maxy<xx) return;

	if(node[u].maxx<=xx && node[u].miny>=xx) {
		node[u].add(1);
		return;
	}

	if(node[u].x<=xx && node[u].y>=xx && node[u].val!=INF) --node[u].val;
	node[u].pushDown();
	del(xx,node[u].ch[0]);
	del(xx,node[u].ch[1]);
	node[u].pushUP();
}

///////////////////////////////

struct QUE {
	bool type;
	int a,b,c;
};

int N,M;
QUE que[MaxN];
int ans[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int pcou;
	char s[10];
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		pcou=0;

		for(int i=1;i<=N;++i) {
			scanf("%s",s);
			if(s[0]=='C') {
				que[i].type=0;
				scanf("%d %d %d",&que[i].a,&que[i].b,&que[i].c);

				++pcou;
				P[pcou].x[0]=que[i].a;
				P[pcou].x[1]=que[i].b;
				P[pcou].id=i;
			}
			else {
				que[i].type=1;
				scanf("%d",&que[i].a);
			}
		}

		node[0].minn=node[0].val=INF;
		node[0].col=0;
		node[0].ans=-1;
		node[0].minx=node[0].miny=INF;
		node[0].maxx=node[0].maxy=-INF;
		root=build(1,pcou,0);

		printf("Case #%d:\n",cas++);

		int BASE=0,t;
		for(int i=1;i<=N;++i)
			if(!que[i].type) update(frem[i],que[i].c,root);
			else {
				que[i].a^=BASE;
				del(que[i].a,root);

				int acou=0;
				while(node[root].minn==0) {
					t=node[root].ans;

					ans[acou++]=t;
					BASE^=t;

					update(frem[t],INF,root);
				}

				if(acou) {
					sort(ans,ans+acou);
					printf("%d",i);
					for(int i=0;i<acou;++i) printf(" %d",ans[i]);
					puts("");
				}
			}
	}

	return 0;
}
