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
// Created Time  : 2015年11月23日 星期一 22时30分07秒
// File Name     : J_1.cpp

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

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int MaxN=200005;
const int INF=0x7fffffff;			// !!!!!!

struct Edge {
	int to,next;
	int w;
}E[MaxN<<1];

int head[MaxN],Ecou;

int N,K,M;
int ans;
bool vis[MaxN];
bool cow[MaxN];

inline void init() {
	Ecou=0;
	for(int i=1;i<=N;++i)
		head[i]=-1;
}

inline void addEdge(int u,int v,int w) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].w=w;
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


typedef pair <int,int> pii;
pii rem[MaxN];
int len,clen,dep[MaxN];

inline int getdata(int k,int id) {
	if(k>rem[id].first) k=rem[id].first;
	if(k<0) return -INF;					// !!!!!
	return dep[rem[id].second+k];
}

void getnum(int base) {
	int temp;

	for(int i=1;i<=clen;++i)
		for(int j=0;j<=rem[i].first;++j) {
			temp=getdata(K-base-j,i-1);					// !!!!!!!
			if(dep[rem[i].second+j]>-INF && temp>-INF) ans=max(ans,temp+dep[rem[i].second+j]);
			dep[rem[i].second+j]=max(dep[rem[i].second+j],getdata(j,i-1));
		}
}

void dfsc(int u,int pre,int cou,int dis) {
	if(cow[u]) ++cou;
	if(cou>len) dep[len=cou]=dis;
	else dep[cou]=max(dep[cou],dis);

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsc(E[i].to,u,cou,dis+E[i].w);
}

void calc(int u) {
	int temp;
	clen=len=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {
			temp=len;
			dep[len+1]=-INF;
			dfsc(E[i].to,u,len+1,E[i].w);
			rem[++clen]=pii(len-temp-1,temp+1);
			for(int j=temp+2;j<=len;++j) dep[j]=max(dep[j],dep[j-1]);
		}
	sort(rem+1,rem+clen+1);
	rem[0]=pii(0,0);
	dep[0]=0;

	getnum(cow[u]);
}
/*
typedef pair<int,int> pii;
int F[MaxN],C[MaxN];
int maxnc;

void dfsc1(int u,int pre,int cou) {
	if(cow[u]) ++cou;
	maxnc=max(maxnc,cou);

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsc1(E[i].to,u,cou);
}

void dfsc2(int u,int pre,int cou,int dis) {
	if(cow[u]) ++cou;
	C[cou]=max(C[cou],dis);

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsc2(E[i].to,u,cou,dis+E[i].w);
}

void calc(int u) {
	vector <pii> rem;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {
			maxnc=0;
			dfsc1(E[i].to,u,0);
			rem.push_back(pii(maxnc,i));
		}
	sort(rem.begin(),rem.end());

	int len=rem.size();

	if(len) for(int i=0;i<=rem[len-1].first;++i) F[i]=-INF;

	for(int i=0;i<len;++i) {
		for(int j=0;j<=rem[i].first;++j) C[j]=-INF;
		dfsc2(E[rem[i].second].to,u,0,E[rem[i].second].w);

		if(i)
			for(int j=0;j<=rem[i].first && j<=K-cow[u];++j) {
				int temp=min(rem[i-1].first,K-cow[u]-j);
				if(F[temp]>-INF && C[j]>-INF) ans=max(ans,F[temp]+C[j]);			// !!!!!!!!!!!
			}

		for(int j=0;j<=rem[i].first && j<=K-cow[u];++j) {
			F[j]=max(F[j],C[j]);
			if(j) F[j]=max(F[j],F[j-1]);
			ans=max(ans,F[j]);
		}
	}
}
*/

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

	int a,b,c;

	scanf("%d %d %d",&N,&K,&M);
	init();

	while(M--) {
		scanf("%d",&a);
		cow[a]=1;
	}

	for(int i=1;i<N;++i) {
		scanf("%d %d %d",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	ans=0;
	getans(1);
	printf("%d\n",ans);

	return 0;
}
