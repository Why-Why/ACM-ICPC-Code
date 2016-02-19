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
// Created Time  : 2015年12月21日 星期一 21时02分53秒
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

using namespace std;

const int MaxN=100005;
const int INF=0x3f3f3f3f;
const double eps=1e-5;

struct Edge {
	int to,next;
	long long v;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
bool vis[MaxN];
int N,L,U;
double ans;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,long long c) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].v=c;
	head[u]=Ecou++;
}

/////////////////////////

int size[MaxN],maxson[MaxN];
int sumnode,minnC,cen;

void dfs1(int u,int pre) {
	size[u]=1;
	maxson[u]=0;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre) {
			dfs1(E[i].to,u);
			size[u]+=size[E[i].to];
			maxson[u]=max(maxson[u],size[E[i].to]);
		}
}

void dfs2(int u,int pre) {
	int maxn=max(maxson[u],sumnode-size[u]);
	if(maxn<minnC) { minnC=maxn; cen=u; }
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfs2(E[i].to,u);
}

int getCenter(int u) {
	dfs1(u,-1);
	sumnode=size[u];
	minnC=INF;
	dfs2(u,-1);
	return cen;
}

/////////////////////////

int pre[MaxN],dis[MaxN];
long long sumV[MaxN];
int remS[MaxN],Sflag=1;
int remu[MaxN],cou;

int que[MaxN],first,last;

void bfs(int u,long long d) {
	first=last=0;
	que[last++]=u;
	dis[u]=1;
	sumV[u]=d;
	pre[u]=0;			// !!!

	while(last-first) {
		u=que[first++];
		remu[cou++]=u;
		for(int i=head[u];i!=-1;i=E[i].next)
			if(!vis[E[i].to] && E[i].to!=pre[u]) {
				que[last++]=E[i].to;
				pre[E[i].to]=u;
				dis[E[i].to]=dis[u]+1;
				sumV[E[i].to]=sumV[u]+E[i].v;
			}
	}
}

int acou;
double rans[MaxN];

struct YQUE {
	double num[MaxN];
	int id[MaxN];
	int first,last;

	void init() {
		first=last=0;
	}

	void push(double a,int b) {
		while(last-first && a>=num[last-1]) --last;
		num[last]=a;
		id[last++]=b;
	}

	void pop(int b) {
		while(last-first && id[first]>b) ++first;
	}

	double top() {
		if(last-first) return num[first];
		else return -1e50;
	}
}yque;

void update(int L,int R,double M) {			// !!! 倒着来可能错过一些最大。
	for(int i=L;i<=R;++i) {
		if(dis[remu[i]]>acou) rans[dis[remu[i]]]=sumV[remu[i]]-M*dis[remu[i]],acou=dis[remu[i]];
		else rans[dis[remu[i]]]=max(rans[dis[remu[i]]],sumV[remu[i]]-M*dis[remu[i]]);
	}
}

bool judge(double M) {
	int p,las=0;
	acou=0;
	rans[0]=0;
	for(int i=0;i<cou;++i) {
		if(remS[i]==Sflag) update(las,i-1,M),yque.init(),p=acou,las=i;
		while(p>=0 && dis[remu[i]]+p>=L) {
			yque.push(rans[p],p);
			--p;
		}
		yque.pop(U-dis[remu[i]]);
		if(sumV[remu[i]]-M*dis[remu[i]]+yque.top()>=0) return 1;
	}
	return 0;
}

void calc(int u) {
	double L=ans,R=1000001.0,M;
	++Sflag;

	cou=0;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {
			remS[cou]=Sflag;
			bfs(E[i].to,E[i].v);
		}

	if(!cou) return;

	while(R-L>eps) {
		M=(L+R)/2.0;
		if(judge(M)) L=M;
		else R=M;
	}
	ans=L;
}

/////////////////////////

void solve(int u) {
	int c=getCenter(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c];i!=-1;i=E[i].next)
		if(!vis[E[i].to])
			solve(E[i].to);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&L,&U);
	init();
	
	int a,b,c;

	for(int i=1;i<N;++i) {
		scanf("%d %d %d",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	ans=0;
	solve(1);
	printf("%.3f\n",ans);
	
	return 0;
}
