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
// Created Time  : 2016年04月30日 星期六 11时31分10秒
// File Name     : B_1.cpp

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

#pragma comment(linker, "/STACK:10240000,10240000")

using namespace std;

const int MaxN=100005;

int logN[2*MaxN];
int dp[2*MaxN][20];
int rmq[2*MaxN];

void RMQ_init(int N) {
	logN[0]=-1;

	for(int i=1;i<=N;++i) {
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
		dp[i][0]=i;
	}

	for(int j=1;j<=logN[N];++j)
		for(int i=1;i+(1<<j)-1<=N;++i)
			dp[i][j]=rmq[dp[i][j-1]]<rmq[dp[i+(1<<(j-1))][j-1]] ? dp[i][j-1] : dp[i+(1<<(j-1))][j-1];
}

int RMQ(int a,int b) {
	if(a>b) swap(a,b);
	int k=logN[b-a+1];
	return rmq[dp[a][k]]<=rmq[dp[b-(1<<k)+1][k]] ? dp[a][k] : dp[b-(1<<k)+1][k];
}

struct Edge {
	int to,next;
};

Edge E[MaxN*2];
int Ecou,head[MaxN];

int F[MaxN*2];
int P[MaxN];
int cou;

//////////

const int mod=1000000007;

int dis[MaxN];
int ycou,ye[MaxN];

long long DP[(1<<20)+5];
long long num[(1<<20)+5];
long double DDP[(1<<20)+5];

//////////

void Edge_init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre,int dep) {
	F[++cou]=u;
	rmq[cou]=dep;
	P[u]=cou;

	dis[u]=dep;

	bool ok=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
		ok=1;

		dfs(E[i].to,u,dep+1);
		
		F[++cou]=u;
		rmq[cou]=dep;
	}
	if(!ok) ye[++ycou]=u;
}

void LCA_init(int root,int N) {
	cou=0;
	dfs(root,root,0);
	RMQ_init(2*N-1);
}

int lca(int u,int v) {
	return F[RMQ(P[u],P[v])];
}

int N;

inline int getnum(int a,int b,int c) {
	int L=-1,R=-1;
	if(a!=-1) L=lca(ye[a],ye[b]);
	if(c!=-1) R=lca(ye[b],ye[c]);

	if(L==-1 && R==-1) return dis[ye[b]]-dis[1]+1;
	if(L==-1 || (R!=-1 && dis[L]<dis[R])) return dis[ye[b]]-dis[R];
	else return dis[ye[b]]-dis[L];
}

void getans(int sta) {
	int rem[21]={};
	rem[ycou]=-2;
	for(int i=ycou-1;i>=0;--i)
		if(sta&(1<<i)) rem[i]=rem[i+1];
		else rem[i]=i;

	int p=-2,t;
	for(int i=0;i<ycou;++i)
		if(sta&(1<<i)) {
			t=getnum(p+1,i+1,rem[i]+1);
			num[sta]=num[sta^(1<<i)]+t;
			if(DDP[sta]<DDP[sta^(1<<i)]*num[sta^(1<<i)]) {
				DDP[sta]=DDP[sta^(1<<i)]*num[sta^(1<<i)];
				DP[sta]=(DP[sta^(1<<i)]*num[sta^(1<<i)])%mod;
			}
		}
		else p=i;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	scanf("%d",&N);
	Edge_init();

	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}
	LCA_init(1,N);

	num[0]=1;
	DP[0]=1;
	DDP[0]=1;
	for(int i=1;i<(1<<ycou);++i) getans(i);
	printf("%d\n",(int)(DP[(1<<ycou)-1]%mod));

	return 0;
}
