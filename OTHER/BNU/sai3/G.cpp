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
// Created Time  : 2015年10月04日 星期日 14时04分07秒
// File Name     : G.cpp

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
	bool t;
};

Edge E[MaxN*2];
int Ecou,head[MaxN];

int F[MaxN*2];			// dfs遍历的顺序标号。
int P[MaxN];			// P[i]表示i在F中第一次出现的位置。
int cou;

int depth[MaxN];
int zheng[MaxN],fan[MaxN];

int N;

void Edge_init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,bool t)
{
	E[Ecou].t=t;
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre,int dep,int zzz,int fff)
{
	int v;

	F[++cou]=u;
	rmq[cou]=dep;
	P[u]=cou;

	depth[u]=dep;
	zheng[u]=zzz;
	fan[u]=fff;

	int tz,tf;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)
			continue;

		if(E[i].t==0) tz=zzz,tf=dep+1;
		else tz=dep+1,tf=fff;

		dfs(v,u,dep+1,tz,tf);
		
		F[++cou]=u;
		rmq[cou]=dep;
	}
}

void LCA_init(int root,int N)
{
	cou=0;
	dfs(root,root,0,0,0);
	RMQ_init(2*N-1);
}

int query(int u,int v)
{
	return F[RMQ(P[u],P[v])];
}

bool getans(int a,int b)
{
	int c=query(a,b);
	
	if(depth[c]<zheng[a]) return 0;
	if(depth[c]<fan[b]) return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int Q;

	while(~scanf("%d",&N))
	{
		Edge_init();
		for(int i=1;i<N;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b,1);
			addEdge(b,a,0);
		}

		LCA_init(1,N);
		
		scanf("%d",&Q);
		while(Q--)
		{
			scanf("%d %d",&a,&b);
			if(getans(a,b)) puts("Yes");
			else puts("No");
		}
	}
	
	return 0;
}
