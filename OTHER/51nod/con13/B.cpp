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
// Created Time  : 2016年04月29日 星期五 21时49分44秒
// File Name     : B.cpp

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

#pragma comment(linker, "/STACK:10240000,10240000") 

const int MaxN=100005;
const int mod=1000000007;

// 输入：边集，root。
// 输出：最近公共祖先。
// 注意：先Edge_init，然后addEdge，然后LCA_init，然后query就可。
// 原理：dfs把LCA转化为RMQ问题求解。

int logN[2*MaxN];
int dp[2*MaxN][20];
int rmq[2*MaxN];			// 某序号的深度。

void RMQ_init(int N)
{
	logN[0]=-1;

	for(int i=1;i<=N;++i)
	{
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
		dp[i][0]=i;
	}

	for(int j=1;j<=logN[N];++j)
		for(int i=1;i+(1<<j)-1<=N;++i)
			dp[i][j]=rmq[dp[i][j-1]]<rmq[dp[i+(1<<(j-1))][j-1]] ? dp[i][j-1] : dp[i+(1<<(j-1))][j-1];
}

int RMQ(int a,int b)
{
	if(a>b)
		swap(a,b);

	int k=logN[b-a+1];

	return rmq[dp[a][k]]<=rmq[dp[b-(1<<k)+1][k]] ? dp[a][k] : dp[b-(1<<k)+1][k];
}

struct Edge
{
	int to,next;
};

Edge E[MaxN*2];
int Ecou,head[MaxN];

int F[MaxN*2];			// dfs遍历的顺序标号。
int P[MaxN];			// P[i]表示i在F中第一次出现的位置。
int cou;

int ye[MaxN],ycou;
int LL[MaxN],RR[MaxN];
int dis[MaxN];

int zhi[MaxN];

void Edge_init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre,int dep)
{
	int v;

	F[++cou]=u;
	rmq[cou]=dep;
	P[u]=cou;

	dis[u]=dep;

	bool ok=0;
	zhi[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre) continue;
		ok=1;
		++zhi[u];

		dfs(v,u,dep+1);
		
		F[++cou]=u;
		rmq[cou]=dep;
	}

	if(!ok) ye[++ycou]=u;
}

void LCA_init(int root,int N)
{
	cou=0;
	dfs(root,root,0);
	RMQ_init(2*N-1);
}

int query(int u,int v)
{
	return F[RMQ(P[u],P[v])];
}

////////////////////////

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];

inline void pushUP(int po) {
	BIT[po]=max(BIT[lc],BIT[rc]);
}

void insert(int p,int t,int L,int R,int po) {
	if(L==R) {
		BIT[po]=t;
		return;
	}

	int M=(L+R)>>1;
	if(p<=M) insert(p,t,lson);
	else insert(p,t,rson);
	pushUP(po);
}

int findmax(int &p,int L,int R,int po) {
	if(L==R) {
		p=L;
		return BIT[po];
	}

	int M=(L+R)>>1;
	if(BIT[lc]>BIT[rc]) return findmax(p,lson);
	else return findmax(p,rson);
}

////////////////////////

int N;

int find(int p) {
	int rL=-1,rR=-1;

	if(LL[p]!=-1) rL=query(ye[p],ye[LL[p]]);
	if(RR[p]!=-1) rR=query(ye[p],ye[RR[p]]);

	if(rL==-1 && rR==-1) return dis[ye[p]]-dis[1]+1;

	if(rL==-1) return dis[ye[p]]-dis[rR];
	if(rR==-1) return dis[ye[p]]-dis[rL];
	return dis[ye[p]]-max(dis[rR],dis[rL]);
}

inline void change(int p) {
	insert(p,find(p),1,ycou,1);
}

void update(int p) {
	insert(p,-1,1,ycou,1);

	int rL=-1,rR=-1;

	if(LL[p]!=-1) rL=query(ye[p],ye[LL[p]]),RR[LL[p]]=RR[p];
	if(RR[p]!=-1) rR=query(ye[p],ye[RR[p]]),LL[RR[p]]=LL[p];

	if(rL==-1 && rR==-1) return;
	if(rL==-1 || dis[rL]<dis[rR]) {
		--zhi[rR];
		if(zhi[rR]==1) change(RR[p]);
	}
	else {
		--zhi[rL];
		if(zhi[rL]==1) change(LL[p]);
	}
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
	for(int i=1;i<=ycou;++i) LL[i]=i-1,RR[i]=i+1;
	LL[1]=RR[ycou]=-1;

	memset(BIT,-1,sizeof(BIT));
	for(int i=1;i<=ycou;++i) insert(i,find(i),1,ycou,1);

	long long ans=1;
	long long t=1,tt;
	int p;

	while(t<=N) {
		tt=findmax(p,1,ycou,1);

		cout<<tt<<' '<<p<<' '<<ye[p]<<endl;

		(ans*=t)%=mod;
		t+=tt;
		update(p);
	}
	printf("%lld\n",ans);
	
	return 0;
}
