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
// Created Time  : 2015年10月07日 星期三 11时23分47秒
// File Name     : J.cpp

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
	int cost;
};

Edge E[MaxN*2];
int Ecou,head[MaxN];

int F[MaxN*2];			// dfs遍历的顺序标号。
int P[MaxN];			// P[i]表示i在F中第一次出现的位置。
int cou;

int dis[MaxN];
int fa[MaxN];
int belong[MaxN];

void Edge_init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre,int dep,int ddd)
{
	int v;

	F[++cou]=u;
	rmq[cou]=dep;
	P[u]=cou;

	dis[u]=ddd;
	fa[u]=pre;
	belong[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)
			continue;

		dfs(v,u,dep+1,ddd+E[i].cost);
		
		F[++cou]=u;
		rmq[cou]=dep;
	}
}

void LCA_init(int root,int N)
{
	cou=0;
	dfs(root,root,0,0);
	RMQ_init(2*N-1);
}

int query(int u,int v)
{
	return F[RMQ(P[u],P[v])];
}

int N,Q;
int rex[MaxN],rey[MaxN],rec[MaxN];
int jin[MaxN];
int sum;
int RA,RB,RC;

void dfs111(int u,int be)
{
	jin[u]=be;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=fa[u])
			if(belong[E[i].to]) dfs111(E[i].to,E[i].to);
			else dfs111(E[i].to,be);
}

void chuli()
{
	belong[RA]=1;
	for(int u=RB;u!=RA;u=fa[u])
		belong[u]=1;
	dfs111(RA,RA);
}

inline int sheng(int u,int v)
{
	int d=abs(dis[u]-dis[v]);
	int td=min(d,sum-d);
	return d-td;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b,c;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&Q);
		for(int i=1;i<N;++i)
			scanf("%d %d %d",rex+i,rey+i,rec+i);
		scanf("%d %d %d",&RA,&RB,&RC);

		Edge_init();
		for(int i=1;i<N;++i)
		{
			addEdge(rex[i],rey[i],rec[i]);
			addEdge(rey[i],rex[i],rec[i]);
		}
		LCA_init(RA,N);

		chuli();
		sum=dis[RB]+RC;

		printf("Case #%d:\n",cas++);

		while(Q--)
		{
			scanf("%d %d",&a,&b);
			if(belong[a]==0 && belong[b]==0)
			{
				c=query(a,b);
				if(belong[c]==0) puts("0");
				else printf("%d\n",sheng(jin[a],jin[b]));
			}
			else if(belong[a] && belong[b])
				printf("%d\n",sheng(a,b));
			else
				printf("%d\n",sheng(jin[a],jin[b]));
		}
	}
	
	return 0;
}
