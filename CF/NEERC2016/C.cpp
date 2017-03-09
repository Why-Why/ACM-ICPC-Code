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
// Created Time  : 2016年10月25日 星期二 22时14分42秒
// File Name     : C.cpp

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

const int MaxN=5005;

struct Edge {
	int to,next;
};

struct State {
	int k,p,next;

	bool operator < (const State & b) const {
		return p<b.p;
	}
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

State S[MaxN];
int headS[MaxN],Scou;

int N;

void init() {
	Ecou=0;
	Scou=0;
	memset(headS,-1,sizeof(headS));
	memset(head,-1,sizeof(head));
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

inline void addState(int u,int k,int p) {
	S[Scou].k=k;
	S[Scou].p=p;
	S[Scou].next=headS[u];
	headS[u]=Scou++;
}

int que[MaxN],first,last;
int vis[MaxN],flag;
int dis[MaxN];

priority_queue <State> rem;
int sum;
long long price;

inline bool solve(int u,int r,int a) {
	for(int i=headS[u];i!=-1;i=S[i].next) {
		sum+=S[i].k;
		price+=S[i].k*(long long)S[i].p;

		rem.push(S[i]);
	}

	if(sum<r) return 0;
	if(sum>=r && price<=a) return 1;

	State t;

	while(sum>r) {
		t=rem.top();
		rem.pop();

		if(sum-t.k>=r) {
			sum-=t.k;
			price-=t.k*(long long)t.p;
		}
		else {
			t.k-=sum-r;
			price-=(sum-r+0LL)*t.p;
			sum=r;

			rem.push(t);
		}
	}

	if(price<=a) return 1;
	return 0;
}

inline int bfs(int u,int r,int a) {
	while(!rem.empty()) rem.pop();			// !!!
	sum=0;
	price=0;

	++flag;
	first=last=0;

	que[last++]=u;
	vis[u]=flag;
	dis[u]=0;

	while(last-first) {
		u=que[first++];
		if(solve(u,r,a)) return dis[u];

		for(int i=head[u];i!=-1;i=E[i].next)
			if(vis[E[i].to]!=flag) {
				vis[E[i].to]=flag;
				que[last++]=E[i].to;
				dis[E[i].to]=dis[u]+1;
			}
	}

	return -1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,W,a,b,c;

	scanf("%d %d",&N,&M);
	init();

	while(M--) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	scanf("%d",&W);
	while(W--) {
		scanf("%d %d %d",&a,&b,&c);
		addState(a,b,c);
	}

	int Q;
	scanf("%d",&Q);

	while(Q--) {
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",bfs(a,b,c));
	}

	return 0;
}
