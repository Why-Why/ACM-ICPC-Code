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
// Created Time  : 2016年04月22日 星期五 20时47分11秒
// File Name     : K.cpp

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

#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std;

const int MaxN=100005;
const int INF=0x3f3f3f3f;			// !!!!!!
const int mod=1000003;

struct Edge {
	int to,next;
}E[MaxN<<1];

int head[MaxN],Ecou;

int N,K;
int ansx,ansy;
bool vis[MaxN];

long long val[MaxN];
int rem[mod];

inline void init() {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1,vis[i]=0;
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

//////////////////////////////

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
	cen=u;			/////
	dfsC2(u,-1);
	return cen;
}

//////////////////////////////

long long rrr[MaxN],rrp[MaxN],rcou;
long long trrr;
int trem;

inline void update(int a,int b) {
	if(a==b) return;
	if(a==b) return;
	if(a>b) swap(a,b);

	if(a<ansx) { ansx=a; ansy=b; }
	else if(a==ansx) ansy=min(ansy,b);
}

long long inv(long long a,long long m)
{
	if(a == 1)return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

void gcd(long long a,long long b,long long &d,long long &x,long long &y) {
	if(!b) { d=a; x=1; y=0; }
	else {
		gcd(b,a%b,d,y,x);
		y-=(a/b)*x;
	}
}

inline long long getnum(long long a) {
	if(K==0) return 0;

	long long d,x,y;
	gcd(a,-mod,d,x,y);

	return ((d*x*K)%mod+mod)%mod;
}

void dfsc(int u,int pre,long long dis) {
	rrr[rcou]=dis;
	rrp[rcou++]=u;

	long long a=(dis*trrr)%mod;
	if(a) {
		long long t=getnum(a);
		if(rem[t]!=INF) update(u,rem[t]);
	}
	else if(a==0 && K==0) {
		update(u,trem);
	}

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsc(E[i].to,u,(dis*val[E[i].to])%mod);
}

void calc(int u) {
	int last;
	rcou=0;
	rem[1]=u;
	trrr=val[u];

	trem=min(trem,u);

	if(val[u]==K) update(u,u);

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {
			last=rcou;
			dfsc(E[i].to,u,val[E[i].to]);

			for(int j=last;j<rcou;++j) rem[rrr[j]]=min((long long)rem[rrr[j]],rrp[j]),trem=min((long long)trem,rrp[j]);
		}

	for(int i=0;i<rcou;++i) rem[rrr[i]]=INF;
	rem[1]=INF;
	trem=INF;
}

//////////////////////////////

void getans(int u) {
	int c=getCenter(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c];i!=-1;i=E[i].next)
		if(!vis[E[i].to])
			getans(E[i].to);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&K)) {
		init();
		trem=INF;
		memset(rem,0x3f,sizeof(rem));
		for(int i=1;i<=N;++i) scanf("%I64d",val+i);
		for(int i=1;i<N;++i) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		ansx=ansy=INF;
		getans(1);

		if(ansx==INF) puts("No solution");
		else printf("%d %d\n",ansx,ansy);
	}
	
	return 0;
}
