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
// Created Time  : 2017年01月17日 星期二 17时24分32秒
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

const int MaxN=100005;
const int INF=0x3f3f3f3f;

void gcd(long long a,long long b,long long &x,long long &y) {
	if(a==0 && b==0) return;
	if(b==0) { x=1; y=0; return; }
	gcd(b,a%b,y,x);
	y-=a/b*x;
}

long long inv(long long a,long long m) {
	long long x,y;
	gcd(a,m,x,y);

	return (x%m+m)%m;
}

struct Edge {
	int to,next,w;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N,M;
long long rinv[MaxN],p10[MaxN];

bool vis[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	for(long long i=0,base=1;i<MaxN;++i,(base*=10)%=M) {
		rinv[i]=inv(base,M);
		p10[i]=base;
	}
}

void addEdge(int u,int v,int w) {
	E[Ecou].to=v;
	E[Ecou].w=w;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

///////////////////////////////

int sumnode;
int cen,minnC;
int maxson[MaxN],couson[MaxN];

void dfsC1(int u,int pre) {
	couson[u]=1;
	maxson[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre) {
			dfsC1(E[i].to,u);
			couson[u]+=couson[E[i].to];
			maxson[u]=max(maxson[u],couson[E[i].to]);
		}
}

void dfsC2(int u,int pre) {
	int maxn=max(maxson[u],sumnode-couson[u]);
	if(maxn<minnC) { minnC=maxn; cen=u; }

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsC2(E[i].to,u);
}

int getCenter(int u) {
	dfsC1(u,-1);
	sumnode=couson[u];
	minnC=INF;
	cen=u;
	dfsC2(u,-1);
	return cen;
}

////////////////////////////

long long rem1[MaxN],rem1L[MaxN],rem2[MaxN],rcou;
long long tr1[MaxN],tr1L[MaxN],tr2[MaxN],trcou;

void dfsc(int u,int pre,int dis,long long w1,long long w2) {
	++trcou;
	tr1[trcou]=w1;
	tr1L[trcou]=dis;
	tr2[trcou]=w2;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsc(E[i].to,u,dis+1,(w1*10+E[i].w)%M,(E[i].w*p10[dis]+w2)%M);
}

inline long long count(long long num[],int len,long long y,long long x) {
	y=M-y;
	x=rinv[x];
	x=x*y%M;

	return upper_bound(num+1,num+len+1,x)-lower_bound(num+1,num+len+1,x);
}

long long calc(int u) {
	long long ret=0;
	rcou=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {
			trcou=0;
			dfsc(E[i].to,u,1,E[i].w%M,E[i].w%M);

			sort(tr2+1,tr2+trcou+1);
			for(int i=1;i<=trcou;++i) {
				ret-=count(tr2,trcou,tr1[i],tr1L[i]);
				++rcou;
				rem1[rcou]=tr1[i];
				rem1L[rcou]=tr1L[i];
				rem2[rcou]=tr2[i];
			}
		}

	++rcou;
	rem1[rcou]=rem1L[rcou]=rem2[rcou]=0;
	sort(rem2+1,rem2+rcou+1);
	for(int i=1;i<=rcou;++i) ret+=count(rem2,rcou,rem1[i],rem1L[i]);

	return ret-1;
}

////////////////////////////

long long ans;

void getans(int u) {
	int c=getCenter(u);
	vis[c]=1;
	ans+=calc(c);

	for(int i=head[c];i!=-1;i=E[i].next)
		if(!vis[E[i].to])
			getans(E[i].to);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);

	if(M==1) {
		printf("%I64d\n",N*(N-1LL));
		return 0;
	}

	init();

	int a,b,c;
	for(int i=1;i<N;++i) {
		scanf("%d %d %d",&a,&b,&c);
		++a,++b;
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	ans=0;
	getans(1);

	printf("%I64d\n",ans);

	return 0;
}
