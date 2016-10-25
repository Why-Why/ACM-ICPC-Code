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
// Created Time  : 2016年09月18日 星期日 22时58分25秒
// File Name     : 1001.cpp

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

const int MaxN=3003;

int N;

inline int lowbit(int x) {
	return x&(-x);
}

struct Tree {
	long long C[MaxN][MaxN];
	int id;

	void add(int tx,int ty,long long d) {
		for(int x=tx;x<=N;x+=lowbit(x))
			for(int y=ty;y<=N;y+=lowbit(y))
				C[x][y]^=d;
	}

	long long sum(int tx,int ty) {
		long long ret=0;
		for(int x=tx;x;x-=lowbit(x))
			for(int y=ty;y;y-=lowbit(y))
				ret^=C[x][y];
		return ret;
	}
}tree[4];

inline void update(int x,int y,long long val) {
	if(x==0 || y==0) return;

	if((x&1) && (y&1)) tree[0].add(x,y,val);
	if(x&1) tree[1].add(x,N+1-y,val);
	tree[2].add(N+1-x,N+1-y,val);
	if(y&1) tree[3].add(N+1-x,y,val);
}

inline long long query(int x,int y) {
	if(x==0 || y==0) return 0;

	long long ret=0;

	ret^=tree[0].sum(x,y);
	if(y&1) ret^=tree[1].sum(x,N-y);
	if((x&1) && (y&1)) ret^=tree[2].sum(N-x,N-y);
	if(x&1) ret^=tree[3].sum(N-x,y);

	return ret;
}

inline int read() {
	int c=getchar();
	if(c==-1) return -1;
	while(c<'0' || c>'9') {
		c=getchar();
		if(c==-1) return -1;
	}

	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

inline char readC() {
	int c=getchar();
	while(c!='P' && c!='Q') c=getchar();
	return c;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M;
	char c;
	int x1,x2,y1,y2,k,a,b;
	long long t;

	while((N=read())!=-1) {
		M=read();

		for(int i=0;i<4;++i) {
			tree[i].id=i;
			for(int j=0;j<=N;++j)
				for(int k=0;k<=N;++k)
					tree[i].C[i][j]=0;
		}

		while(M--) {
			c=readC();

			if(c=='P') {
				x1=read(); y1=read();
				x2=read(); y2=read();
				k=read();
				t=0;

				while(k--) {
					a=read(); b=read();
					if(b&1) t^=(1LL<<(long long)a);
				}
				if(t==0) continue;

				update(x2,y2,t);
				update(x1-1,y1-1,t);
				update(x2,y1-1,t);
				update(x1-1,y2,t);
			}
			else {
				x1=read(); y1=read();
				x2=read(); y2=read();

				t=0;
				t^=query(x2,y2);
				t^=query(x1-1,y1-1);
				t^=query(x1-1,y2);
				t^=query(x2,y1-1);

				bool first=1;
				for(int i=1;i<=50;++i) {
					if(t&(1LL<<(long long)i)) putchar('2');
					else putchar('1');
					putchar(' ');
				}
				puts("");
			}
		}
	}

	return 0;
}
