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
// Created Time  : 2016年09月06日 星期二 00时34分35秒
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

const int MaxN=2003;

int N,M,K;
long long C[MaxN][MaxN];
int rem[MaxN][MaxN],rcou[MaxN];
bool vis[MaxN];

struct GAR {
	int x,y,w;
}gar[MaxN][MaxN];

int len[MaxN];

struct QUE {
	int x1,y1,x2,y2;
}que[MaxN];

int qcou;

long long ans[MaxN];

inline int lowbit(int x) {
	return x&(-x);
}

inline int read() {
	char c=0;
	while(c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

inline char reads() {
	char c=0;
	while(c!='A' && c!='S') c=getchar();
	getchar();
	getchar();
	return c;
}

inline void add(int tx,int ty,long long w) {
	for(int x=tx;x<=N;x+=lowbit(x))
		for(int y=ty;y<=M;y+=lowbit(y))
			C[x][y]+=w;
}

inline long long sum(int tx,int ty) {
	long long ret=0;
	for(int x=tx;x;x-=lowbit(x))
		for(int y=ty;y;y-=lowbit(y))
			ret+=C[x][y];
	return ret;
}

inline void push(int p) {
	GAR *g=gar[p];

	for(int i=1;i<=len[p];++i)
		add(g[i].x,g[i].y,g[i].w);
}

inline void pop(int p) {
	GAR *g=gar[p];

	for(int i=1;i<=len[p];++i)
		add(g[i].x,g[i].y,-g[i].w);
}

inline long long getans(int p) {
	return sum(que[p].x2,que[p].y2)-sum(que[p].x1-1,que[p].y2)-sum(que[p].x2,que[p].y1-1)+sum(que[p].x1-1,que[p].y1-1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[20];
	int a,b,c,d;

	N=read(); M=read(); K=read();
	for(int i=1;i<=K;++i) {
		len[i]=read();
		for(int j=1;j<=len[i];++j) {
			gar[i][j].x=read();
			gar[i][j].y=read();
			gar[i][j].w=read();
		}
	}

	int Q=read();
	memset(vis,1,sizeof(vis));

	while(Q--) {
		s[0]=reads();
		if(s[0]=='A') {
			++qcou;
			que[qcou].x1=read(); que[qcou].y1=read();
			que[qcou].x2=read(); que[qcou].y2=read();

			for(int i=1;i<=K;++i)
				if(vis[i])
					rem[i][++rcou[i]]=qcou;
		}
		else {
			a=read();
			vis[a]^=1;
		}
	}

	for(int i=1;i<=K;++i) {
		push(i);
		for(int j=1;j<=rcou[i];++j) ans[rem[i][j]]+=getans(rem[i][j]);
		pop(i);
	}

	for(int i=1;i<=qcou;++i)
		printf("%I64d\n",ans[i]);

	return 0;
}
