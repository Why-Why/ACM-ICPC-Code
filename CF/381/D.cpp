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
// Created Time  : 2016年12月03日 星期六 15时06分34秒
// File Name     : D.cpp

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

struct QUE {
	int id,l,r;
	long long v;				// !!!

	bool operator < (const QUE & b) const {
		return v<b.v;
	}
};

struct Edge {
	int to,next,w;
};

Edge E[200005<<1];
int head[200005],Ecou;

QUE que[200005];
int N;
int A[200005];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int w) {
	E[Ecou].to=v;
	E[Ecou].w=w;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int cou;

typedef pair<long long,int> pii;
pii rem[200005];

void dfs(int u,int pre,long long dep) {
	++cou;

	int L=cou+1;

	rem[cou].first=dep-A[u];
	rem[cou].second=cou;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs(E[i].to,u,dep+E[i].w);

	que[u].id=u;
	que[u].l=L;
	que[u].r=cou;
	que[u].v=dep;
}

int ans[200005];
int C[200005];

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int x) {
	for(;x<=N;x+=lowbit(x)) ++C[x];
}

inline int query(int x) {
	int ret=0;
	for(;x;x-=lowbit(x)) ret+=C[x];
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	init();
	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",A+i);
	for(int i=2;i<=N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(i,a,b);
		addEdge(a,i,b);
	}

	dfs(1,-1,0);

	sort(rem+1,rem+N+1);
	sort(que+1,que+N+1);

	int p=1;
	for(int i=1;i<=N;++i) {
		while(p<=N && rem[p].first<=que[i].v) {
			add(rem[p].second);
			++p;
		}

		ans[que[i].id]=query(que[i].r)-query(que[i].l-1);
	}

	for(int i=1;i<=N;++i) printf("%d ",ans[i]);
	puts("");

	return 0;
}
