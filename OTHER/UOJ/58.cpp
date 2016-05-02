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
	int L,R,T,id;
	int b1,b2;

	bool operator < (const QUE &b) const {
		if(b1!=b.b1) return b1<b.b1;
		if(b2!=b.b2) return b2<b.b2;
		return T<b.T;
	}

}que[MaxN];

int Qcou;
int preC[MaxN],nextC[MaxN],remP[MaxN],Tcou;

///////

int dp[MaxN<<1][20];
int logN[MaxN<<1];
int rmq[MaxN<<1];

void RMQ_init(int n) {
	logN[0]=-1;
	for(int i=1;i<=n;++i) {
		dp[i][0]=i;
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
	}
	for(int j=1;j<=logN[n];++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			dp[i][j]=rmq[dp[i][j-1]]<rmq[dp[i+(1<<(j-1))][j-1]] ? dp[i][j-1] : dp[i+(1<<(j-1))][j-1];
}

int RMQ(int a,int b) {
	if(a>b) swap(a,b);
	int k=logN[b-a+1];

	return rmq[dp[a][k]]<=rmq[dp[b-(1<<k)+1][k]] ? dp[a][k] : dp[b-(1<<k)+1][k];
}

int F[MaxN<<1];
int P[MaxN],cou;

int lca(int u,int v) {
	return F[RMQ(P[u],P[v])];
}

///////

int dep[MaxN],fa[MaxN];

inline void add(int L,int id) {
	++bcou;
	while(top>L) belong[stack[--top]]=bcou;
}

void dfs(int u,int pre,int dis) {
	stack[top++]=u;
	int r=top;

	dep[u]=dis;
	fa[u]=pre;

	F[++cou]=u;
	rmq[cou]=dis-1;
	P[u]=cou;

	dfsrem[u]=++dfscou;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u,dis+1);
			if(top-r>=blen) add(r,u);

			F[++cou]=u;
			rmq[cou]=dis-1;
		}
}

///////

long long tans;
int couP[MaxN],couC[MaxN];

inline void updateT(int p,int t) {
	int r=C[remP[p]];
	if(t) C[remP[p]]=nextC[p];
	else C[remP[p]]=preC[p];

	if(couP[remP[p]]) {
		tans-=w[couC[r]]*v[r];
		tans-=w[couC[C[remP[p]]]]*v[C[remP[p]]];			// !!!

		--couC[r];
		++couC[C[remP[p]]];

		tans+=w[couC[r]]*v[r];
		tans+=w[couC[C[remP[p]]]]*v[C[remP[p]]];			// !!!
	}
}

inline void update(int p) {
	couP[p]^=1;
	tans-=v[C[p]]*w[couC[C[p]]];

	if(couP[p]) ++couC[C[p]];
	else --couC[C[p]];

	tans+=v[C[p]]*w[couC[C[p]]];
}

inline void change(int u,int v) {
	if(dep[u]>dep[v]) swap(u,v);

	while(dep[u]<dep[v]) {
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
	int dL=1,dR=1,dT=0;
	int t;
	tans=0;

	for(int i=1;i<=Qcou;++i) {
		if(dT<que[i].T) for(int j=dT+1;j<=que[i].T;++j) updateT(j,1);
		else for(int j=dT;j>que[i].T;--j) updateT(j,0);
		dT=que[i].T;

		change(dL,que[i].L);
		dL=que[i].L;
		change(dR,que[i].R);
		dR=que[i].R;

		update(t=lca(que[i].L,que[i].R));
		ans[que[i].id]=tans;
		update(t);
	}
}

////////

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	scanf("%d %d %d",&N,&M,&Q);
	blen=(int)pow(N+0.5,2.0/3);
	init();
	for(int i=1;i<=M;++i) scanf("%lld",v+i);
	for(int i=1;i<=N;++i) scanf("%lld",w+i),w[i]+=w[i-1];
	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}
	cou=0;
	dfs(1,-1,1);
	RMQ_init(2*N-1);
	for(int i=1;i<=N;++i) scanf("%d",C+i),TC[i]=C[i];

	for(int i=1;i<=Q;++i) {
		scanf("%d %d %d",&a,&b,&c);
		if(a==0) {
			++Tcou;
			preC[Tcou]=TC[b];
			nextC[Tcou]=c;
			remP[Tcou]=b;
			TC[b]=c;
			ans[i]=-1;
		}
		else {
			++Qcou;
			que[Qcou].L=b;
			que[Qcou].R=c;
			que[Qcou].T=Tcou;
			que[Qcou].id=Qcou;
			ans[Qcou]=0;

			que[Qcou].b1=belong[b];
			que[Qcou].b2=belong[c];
		}
	}
	sort(que+1,que+Qcou+1);

	getans();
	for(int i=1;i<=Qcou;++i) if(ans[i]!=-1) printf("%lld\n",ans[i]);
	
	return 0;
}
