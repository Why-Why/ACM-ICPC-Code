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
// Created Time  : 2016年05月02日 星期一 16时07分00秒
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
#include <climits>

using namespace std;

const int MaxN=100005;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	long long key[MaxN];
	int pri[MaxN];		// 键值，优先值。
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。

	int val[MaxN];

	void init()
	{
		tot=1;
		root=0;
		pri[0]=INT_MAX;				// 不能是INF。
		size[0]=0;
	}

	void update(int x)				// 维护size。
	{
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
	}

	void rotate(int &x,int t)		// 节点x按照t方向旋转，0为左。
	{
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;

		update(x);
		update(y);

		x=y;
	}

	void _insert(int &x,long long k,int v)
	{
		if(x)
		{
			if(key[x]==k)
				++cou[x];
			else
			{
				int t=key[x]<k;

				_insert(ch[x][t],k,v);

				if(pri[ch[x][t]]<pri[x])
					rotate(x,t);
			}
		}
		else
		{
			x=tot++;
			key[x]=k;
			cou[x]=1;
			val[x]=v;
			pri[x]=rand();			// !!!
			ch[x][0]=ch[x][1]=0;
		}

		update(x);
	}

	int find(long long k)
	{
		int u=root;

		while(u)
		{
			if(key[u]==k)
				return val[u];

			u=ch[u][key[u]<k];
		}

		return 0;
	}

	void insert(long long k,int v)
	{
		_insert(root,k,v);
	}
}tree;

struct State {
	int r,a,b;

	bool operator < (const State &y) const {
		if(r!=y.r) return r<y.r;
		if(a!=y.a) return a<y.a;
		return b>y.b;
	}
}sta[MaxN];

int N;

int D;
int Dx[MaxN],Dy[MaxN];
int S,T;

struct Edge {
	int to,next;
};

Edge E[10+(MaxN<<4)];
int Ecou,head[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int val[MaxN];
int que[MaxN],first,last;

int x0,Y0,x1,Y1;

void bfs(int u) {
	memset(val,-1,sizeof(val));
	val[u]=0;
	first=last=0;
	que[last++]=u;

	while(last-first) {
		u=que[first++];
		for(int i=head[u];i!=-1;i=E[i].next)
			if(val[E[i].to]==-1) {
				val[E[i].to]=val[u]+1;
				que[last++]=E[i].to;
			}
	}
}

inline void addD(int a,int b,int r) {
	for(int i=a;i<=b;++i) {
		++D;
		Dx[D]=i;
		Dy[D]=r;
		if(i==Y0 && r==x0) S=D;
		if(i==Y1 && r==x1) T=D;
	}
}

const int step[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,-1},{-1,0},{-1,1}};

inline void addE() {
	int nx,ny;
	long long t;
	tree.init();

	for(int i=1;i<=D;++i) {
		for(int k=0;k<8;++k) {
			nx=Dx[i]+step[k][0];
			ny=Dy[i]+step[k][1];
			t=(((long long)nx)<<31LL)+ny;
			if((t=tree.find(t))!=0) {
				addEdge(i,t);
				addEdge(t,i);
			}
		}
		t=(((long long)Dx[i])<<31LL)+Dy[i];
		tree.insert(t,i);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d %d",&x0,&Y0,&x1,&Y1)) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d %d %d",&sta[i].r,&sta[i].a,&sta[i].b);
		sort(sta+1,sta+N+1);

		int da=sta[1].a,db=sta[1].b,dr=sta[1].r;
		D=0;
		S=T=-1;

		for(int i=2;i<=N;++i) {
			if(sta[i].r!=dr) {
				addD(da,db,dr);
				dr=sta[i].r;
				da=sta[i].a;
				db=sta[i].b;
			}
			else {
				if(sta[i].a>db) {
					addD(da,db,dr);
					da=sta[i].a;
					db=sta[i].b;
				}
				else db=max(db,sta[i].b);
			}
		}
		init();
		addD(da,db,dr);
		addE();

		if(S==-1 || T==-1) {
			puts("-1");
			continue;
		}

		bfs(S);

		if(val[T]!=-1) printf("%d\n",val[T]);
		else puts("-1");
	}
	
	return 0;
}
