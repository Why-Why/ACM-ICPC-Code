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
// Created Time  : 2016年10月03日 星期一 10时32分12秒
// File Name     : F.cpp

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
};

Edge E[MaxN*3];
int head[MaxN],Ecou;

int logN[2*MaxN];
int dp[2*MaxN][20];
int rmq[2*MaxN];			// 某序号的深度。

int N;

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

int F[MaxN*2];			// dfs遍历的顺序标号。
int P[MaxN];			// P[i]表示i在F中第一次出现的位置。
int cou;

int dep[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool vis[MaxN],need[MaxN];
int remn[MaxN],rcou;

int dis[203][MaxN];

void dfs(int u,int pre,int dep)
{
	int v;
	vis[u]=1;

	F[++cou]=u;
	rmq[cou]=dep;
	P[u]=cou;

	::dep[u]=dep;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)
			continue;

		if(vis[v]) {
			if(need[v]==0) {
				need[v]=1;
				remn[++rcou]=v;
			}
			continue;
		}

		dfs(v,u,dep+1);
		
		F[++cou]=u;
		rmq[cou]=dep;
	}
}

void LCA_init(int root,int N)
{
	cou=0;
	dfs(root,root,0);
	RMQ_init(2*N-1);
}

int query(int u,int v) {
	return F[RMQ(P[u],P[v])];
}

int que[MaxN],first,last;

void bfs(int u,int dis[]) {
	first=last=0;
	que[last++]=u;

	dis[u]=1;

	while(last-first) {
		u=que[first++];
		for(int i=head[u];i!=-1;i=E[i].next)
			if(dis[E[i].to]==0) {
				dis[E[i].to]=dis[u]+1;
				que[last++]=E[i].to;
			}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int m,q,a,b;

	scanf("%d %d %d",&N,&m,&q);
	init();

	while(m--) {
		scanf("%d %d",&a,&b);
		if(a!=b) {
			addEdge(a,b);
			addEdge(b,a);
		}
	}
	LCA_init(1,N);

	for(int i=1;i<=rcou;++i)
		bfs(remn[i],dis[i]);

	int ans,c;

	while(q--) {
		scanf("%d %d",&a,&b);
		c=query(a,b);
		ans=dep[a]-dep[c]+dep[b]-dep[c];

		for(int i=1;i<=rcou;++i)
			ans=min(ans,dis[i][a]+dis[i][b]-2);

		printf("%d\n",ans);
	}

	return 0;
}
