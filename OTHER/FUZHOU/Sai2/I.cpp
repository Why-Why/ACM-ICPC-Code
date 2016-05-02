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
// Created Time  : 2016年05月02日 星期一 15时01分29秒
// File Name     : I.cpp

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

const int MaxN=50005;

// 对树进行分块，复杂度O(N)。
// 输入：树。
// 输出：belong数组，mid数组。
// 注意：先init，然后addEdge，然后dfs(1,-1)，然后要把栈里面剩下的标为另一个bcou；belong从1开始。
// 原理：dfs，记录栈的当前底。
// 其他：树的分块：三种，1，直接按照2N长的dfs序分块，2，分成每个3B大小以内的块，块通过省会连接，3，关键树分法。

struct Edge {
    int to,next,w;
}E[MaxN<<1];
 
int head[MaxN],Ecou;
int N,B;
int Q;

int dfsnum[MaxN<<1],dfscou;
 
int bcou,belong[MaxN],mid[MaxN];
int stack[MaxN],top;
 
void init() {
	dfscou=0;
    Ecou=0;
    memset(head,-1,sizeof(head));
}
 
void addEdge(int u,int v,int w) {
	E[Ecou].w=w;
    E[Ecou].to=v;
    E[Ecou].next=head[u];
    head[u]=Ecou++;
}
 
void add(int L,int id) {
    ++bcou;
    mid[bcou]=id;
 
    while(top>L) belong[stack[--top]]=bcou;
}

int fa[MaxN],val[MaxN];
int dis[MaxN];
 
void dfs(int u,int pre,int dep,int w) {
	dis[u]=dep;
	fa[u]=pre;
	val[u]=w;

	dfsnum[u]=++dfscou;

    stack[top++]=u;
    int r=top;
 
    for(int i=head[u];i!=-1;i=E[i].next)
        if(E[i].to!=pre) {
            dfs(E[i].to,u,dep+1,E[i].w);
            if(top-r>=B) add(r,u);
        }
}

int ans[MaxN];
int tans;
int cou[MaxN];

struct QUE {
	int u,v;
	int id;

	bool operator < (const QUE &b) const {
		int b1=belong[u],b2=belong[b.u];
		if(b1==b2) return dfsnum[v]<dfsnum[b.v];
		return b1<b2;
	}
}que[MaxN];

inline int lowbit(int x) { return x&(-x); }

int C[100005];

int tadd(int p,int d) {
	for(;p<=100001;p+=lowbit(p))
		C[p]+=d;
}

int tfind(int x)		// 寻找树状数组中和为x的第一个位置。
{
	int ans=0,sum=0;

	for(int i=18;i>=0;--i)
	{
		ans+=(1<<i);

		if(ans>N || sum+C[ans]>=x)
			ans-=(1<<i);
		else
			sum+=C[ans];
	}

	return ans+1;
}

inline void update(int u) {
	cou[u]^=1;
	if(cou[u]) {
		++tans;
		tadd(val[u]+1,1);
	}
	else {
		--tans;
		tadd(val[u]+1,-1);
	}
}

void moveto(int u,int v) {
	if(dis[u]>dis[v]) swap(u,v);
	while(dis[u]<dis[v]) {
		update(v);
		v=fa[v];
	}
	while(u!=v) {
		update(u);
		update(v);
		u=fa[u];
		v=fa[v];
	}
}

void getans() {
	int dL=1,dR=1;
	tans=0;
	memset(cou,0,sizeof(cou));

	for(int i=1;i<=Q;++i) {
		moveto(dL,que[i].u);
		moveto(dR,que[i].v);
		dL=que[i].u;
		dR=que[i].v;
		ans[que[i].id]=tfind((tans+1)/2)-1;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	while(~scanf("%d %d",&N,&Q)) {
		memset(C,0,sizeof(C));
		init();
		B=sqrt((double)N);
		for(int i=1;i<N;++i) {
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		dfs(1,-1,0,0);

		for(int i=1;i<=Q;++i) scanf("%d %d",&que[i].u,&que[i].v),que[i].id=i;
		sort(que+1,que+Q+1);
		getans();
		for(int i=1;i<=Q;++i) printf("%d\n",ans[i]);
	}
	
	return 0;
}
