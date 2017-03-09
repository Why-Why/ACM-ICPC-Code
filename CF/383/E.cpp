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
// Created Time  : 2016年12月08日 星期四 23时28分04秒
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

const int MaxN=100005;

int N;
int fa[MaxN<<1];

int find(int x) {
	if(fa[x]==-1) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int ans[MaxN<<1];
int A[MaxN],B[MaxN];

inline void marjor(int a,int b) {
	if(find(a)!=find(b))
		fa[find(a)]=find(b);
}

int vis[MaxN<<1];

inline void addAns(int p) {
	if(p<=N) ans[(p<<1)-1]=1,ans[(p<<1)]=2;
	else {
		p-=N;
		ans[(p<<1)-1]=2;
		ans[(p<<1)]=1;
	}
}

inline int change(int p) {
	if(p<=N) return p+N;
	return p-N;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	memset(fa,-1,sizeof(fa));

	scanf("%d",&N);
	int a,b,x,y;

	for(int i=1;i<=N;++i) {
		scanf("%d %d",&a,&b);
		A[i]=a;
		B[i]=b;

		x=(a+1)>>1;
		y=(b+1)>>1;
		a&=1;
		b&=1;

		if(a==b) {
			marjor(x,y+N);
			marjor(x+N,y);
		}
		else {
			marjor(x,y);
			marjor(x+N,y+N);
		}
	}

	int T=find(1);

	for(int i=1;i<=(N<<1);++i)
		if(vis[find(i)]==0) {
			addAns(i);
			vis[find(i)]=1;
			vis[find(change(i))]=-1;
		}
		else if(vis[find(i)]==1)
			addAns(i);

	for(int i=1;i<=N;++i)
		printf("%d %d\n",ans[A[i]],ans[B[i]]);

	return 0;
}
