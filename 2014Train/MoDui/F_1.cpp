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
// Created Time  : 2016年04月12日 星期二 14时18分17秒
// File Name     : F_1.cpp

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

const int MaxN=40004;

struct Edge {
	int to,next;
}E[MaxN<<1];

int head[MaxN],Ecou;

int N,M,blen;
int val[MaxN];

////////////////////

int hrem[MaxN],Hcou;

inline int HASH(int x) {
	return lower_bound(hrem+1,hrem+Hcou+1,x)-hrem;
}

////////////////////

int rem[MaxN<<1],rcou;
int LEFT[MaxN],RIGHT[MaxN];

////////////////////

int logN[MaxN<<1];
int dp[MaxN<<1][20];
int rmq[MaxN<<1];

int F[MaxN<<1],P[MaxN],lcacou=0;

void RMQ_init(int N) {
	logN[0]=-1;
	for(int i=1;i<=N;++i) {
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
		dp[i][0]=i;
	}
	for(int j=1;j<=logN[N];++j)
		for(int i=1;i+(1<<j)-1<=N;++i) {
			dp[i][j]=rmq[dp[i][j-1]]<rmq[dp[i+(1<<(j-1))][j-1]] ? dp[i][j-1] : dp[i+(1<<(j-1))][j-1];
		}
}

int RMQ(int a,int b) {
	if(a>b) swap(a,b);
	int k=logN[b-a+1];

	return rmq[dp[a][k]]<=rmq[dp[b-(1<<k)+1][k]] ? dp[a][k] : dp[b-(1<<k)+1][k];
}

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre,int dep) {
	rem[++rcou]=u;
	LEFT[u]=rcou;

	F[++lcacou]=u;
	rmq[lcacou]=dep;
	P[u]=lcacou;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u,dep+1);

			F[++lcacou]=u;
			rmq[lcacou]=dep;
		}

	rem[++rcou]=u;
}

void solve() {
	rcou=0;
	dfs(1,-1,0);
	RMQ_init(2*N-1);
}

inline int lca(int a,int b) {
	return F[RMQ(P[a],P[b])];
}

inline int zhuan(int x) {
	return (x-1)/blen;
}

struct QUE {
	int L,R,id;

	bool operator < (const QUE &b) const {
		int x=zhuan(L),y=zhuan(b.L);
		return x==y ? R<b.R : x<y;
	}
}que[100005];

int ans[100005];
int tans;

int cou[MaxN],mar[MaxN];

inline void update(int p,int t) {
	cou[p]+=t;
	if(cou[p]&1) {
		++mar[val[p]];
		if(mar[val[p]]==1) ++tans;
	}
	else {
		--mar[val[p]];
		if(mar[val[p]]==0) --tans;
	}
}

inline int change1(int p,int q) {
	if(p==q) return tans;
	int ret=tans;
	if(!(cou[p]&1) && mar[val[p]]==0) ++ret;
	else if((cou[p]&1) && mar[val[p]]==1) --ret;
	if(!(cou[q]&1) && mar[val[q]]==0) ++ret;
	else if((cou[q]&1) && mar[val[q]]==1) --ret;
	return ret;
}

int ttans;

inline void update1(int p,int t) {
	int tcou=cou[p];
	tcou+=t;
	if(tcou&1) {
		if(mar[val[p]]==0) ++ttans;
	}
	else {
		if(mar[val[p]]==1) --ttans;
	}
}

inline int change(int a,int b,int c) {
	if(a==c) return tans;
	ttans=tans;
	update1(a,1);
	if(val[a]!=val[c])				// !!! 如果val[a]==val[c]的时候会出问题，下面这组数据就是！
		update1(c,1);
	int ret=ttans;
	return ret;
}

/*

8 2
1 2 3 4 1 6 7 8
1 2        
1 3
1 4
3 5
3 6
3 7
4 8
2 5
7 8

*/

void getans() {
	int dL=1,dR=1;
	tans=1;
	cou[1]=1;
	mar[val[1]]=1;

	for(int i=1;i<=M;++i) {
		if(dR>que[i].R) for(int j=dR;j>que[i].R;--j) update(rem[j],-1);
		else for(int j=dR+1;j<=que[i].R;++j) update(rem[j],1);
		dR=que[i].R;

		if(dL>que[i].L) for(int j=dL-1;j>=que[i].L;--j) update(rem[j],1);
		else for(int j=dL;j<que[i].L;++j) update(rem[j],-1);
		dL=que[i].L;

		ans[que[i].id]=change(rem[que[i].L],rem[que[i].R],lca(rem[que[i].L],rem[que[i].R]));
		//ans[que[i].id]=change1(rem[que[i].L],lca(rem[que[i].L],rem[que[i].R]));
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&N,&M);
	init();

	Hcou=0;
	for(int i=1;i<=N;++i) scanf("%d",val+i),hrem[++Hcou]=val[i];
	sort(hrem+1,hrem+Hcou+1);
	Hcou=unique(hrem+1,hrem+Hcou+1)-hrem-1;
	for(int i=1;i<=N;++i) val[i]=HASH(val[i]);

	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	solve();

	for(int i=1;i<=M;++i) {
		scanf("%d %d",&que[i].L,&que[i].R);
		que[i].L=LEFT[que[i].L];
		que[i].R=LEFT[que[i].R];
		if(que[i].L>que[i].R) swap(que[i].L,que[i].R);
		que[i].id=i;
	}
	blen=sqrt((double)rcou);
	sort(que+1,que+M+1);

	getans();

	for(int i=1;i<=M;++i) printf("%d\n",ans[i]);
	
	return 0;
}
