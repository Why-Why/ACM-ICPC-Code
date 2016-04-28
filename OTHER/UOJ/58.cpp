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
// Created Time  : 2016年04月22日 星期五 00时09分35秒
// File Name     : 58.cpp

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
}E[MaxN<<1];

int head[MaxN],Ecou;
int N,M,Q,blen;
long long v[MaxN],w[MaxN];
int C[MaxN],TC[MaxN];

long long ans[MaxN];

///////

int dfsrem[MaxN],dfscou;
int bcou,belong[MaxN];
int stack[MaxN],top;

///////

struct QUE {
	int L,R,T;
	int b1,b2;

	bool operator < (const QUE &b) const {
		if(b1!=b.b1) return b1<b.b1;
		if(b2!=b.b2) return b2<b.b2;
		return T<b.T;
	}

}que[MaxN];

int preC[MaxN],nextC[MaxN],Tcou;

///////

inline void add(int L,int id) {
	++bcou;
	while(top>L) belong[stack[--top]]=bcou;
}

void dfs(int u,int pre) {
	stack[top++]=u;
	int r=top;

	dfsrem[u]=++dfscou;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u);
			if(top-r>=blen) add(r,u);
		}
}

///////

long long tans;
int couP[MaxN],couC[MaxN];

void getans() {
	int dL=1,dR=1,dT=0;
	tans=v[c[1]]*w[1];
	couP[1]=1;
	couC[c[1]]=1;

	for(int i=1;i<=Q;++i) {
		if(dT<que[i].t) for(int j=dT
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	scanf("%d %d %d",&N,&M,&Q);
	blen=(int)pow(N+0.5,2.0/3);
	init();
	for(int i=1;i<=M;++i) scanf("%lld",v+i);
	for(int i=1;i<=N;++i) scanf("%lld",w+i);
	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}
	dfs(1,-1);
	for(int i=1;i<=N;++i) scanf("%d",C+i),TC[i]=C[i];

	for(int i=1;i<=Q;++i) {
		scanf("%d %d %d",&a,&b,&c);
		if(a==0) {
			++Tcou;
			preC[Tcou]=TC[b];
			nextC[Tcou]=c;
			TC[b]=c;
			ans[i]=-1;
		}
		else que[i].L=a,que[i].R=b,que[i].t=Tcou,ans[i]=0;

		que[i].b1=belong[que[i].L];
		que[i].b2=belong[que[i].R];
	}
	sort(que+1,que+Q+1);

	getans();
	for(int i=1;i<=Q;++i) if(ans[i]!=-1) printf("%lld\n",ans[i]);
	
	return 0;
}
