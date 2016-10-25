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
// Created Time  : 2016年07月28日 星期四 23时51分42秒
// File Name     : 1002.cpp

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

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int N,head[MaxN],Ecou;

int val[MaxN];
int ANS[2][MaxN],*ans;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

inline int count(int u) {
	int ret=0;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(val[E[i].to]==N) ++ret;
	return ret;
}

inline int xiao(int a[],int b[]) {
	if(b[0]==-1) return 0;
	if(a[0]==-1) return 1;

	for(int i=1;i<=N;++i)
		if(a[i]!=b[i]) {
			if(a[i]<b[i]) return 0;
			return 1;
		}

	return 0;
}

//////////////////////

struct State {
	int dep,val,u;

	bool operator < (const State & b) const {
		if(val!=b.val) return val>b.val;
		return dep>b.dep;
	}
};

State rem[MaxN];
bool vis[MaxN],use[MaxN];
int fa[MaxN];

void getans(int u) {
	for(int i=1;i<=N;++i) {
		vis[i]=0;
		ans[i]=0;
		use[i]=0;
	}

	dfs(u,-1);
	sort(rem+1,rem+N+1);

	int last=1;

	rem[N+1].val=0;

	for(int i=2;i<=N+1;++i)
		if(rem[i].val==rem[i-1].val) {
			if(fa[rem[i-1].u]!=rem[i].u) {
				ans[0]=-1;
				return;
			}
			vis[rem[i-1].u]=1;
		}
		else {
			if(fa[rem[i-1].u]!=-1 && vis[fa[rem[i-1].u]]==0) {
				ans[0]=-1;
				return;
			}
			vis[rem[i-1].u]=1;
			ans[rem[last].u]=rem[last].val;
			use[rem[last].val]=1;
			last=i;
		}

	for(int i=1;i<=N;++i)
		if(ans[rem[i].u]==0)
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);

		init();

		int cou=0;
		for(int i=1;i<=N;++i) {
			scanf("%d",val+i);
			if(val[i]==N) ++cou;
		}
		for(int i=1;i<N;++i) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		printf("Case #%d:",cas++);
		if(!cou) {
			puts(" Impossible");
			continue;
		}

		for(int i=1,j=0;i<=N,j<2;++i)
			if(val[i]==N && count(i)<=1) {
				ans=ANS[j++];
				ans[0]=0;
				getans(i);
			}

		if(ANS[0][0]==-1 && ANS[1][0]==-1) {
			puts(" Impossible");
			continue;
		}

		ans=ANS[xiao(ANS[0],ANS[1])];
		for(int i=1;i<=N;++i) printf(" %d",ans[i]);
		puts("");
	}

	return 0;
}
