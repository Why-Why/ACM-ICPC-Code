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
// Created Time  : 2015年07月21日 星期二 16时07分37秒
// File Name     : 1009.cpp

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

struct Edge
{
	int to,next,cost;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N,Q;
int dis[MaxN];
int rem[MaxN];
int xu[MaxN];
int xcou;

void init()
{
	xcou=0;
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(dis,-1,sizeof(dis));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int len)
{
	dis[u]=len;
	rem[u]=++xcou;
	xu[xcou]=u;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(dis[E[i].to]==-1)
			dfs(E[i].to,len+E[i].cost);
}

bool jihe[MaxN];
set <int> sta;
set <int> ::iterator iter;

void add(int u)
{
	jihe[u]=1;
	sta.insert(rem[u]);
}

void dele(int u)
{
	jihe[u]=0;
	sta.erase(rem[u]);
}

namespace LCA
{

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

int F[MaxN*2];			// dfs遍历的顺序标号。
int P[MaxN];			// P[i]表示i在F中第一次出现的位置。
int cou;

void dfs(int u,int pre,int dep)
{
	int v;

	F[++cou]=u;
	rmq[cou]=dep;
	P[u]=cou;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)
			continue;

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

int query(int u,int v)
{
	return F[RMQ(P[u],P[v])];
}

};

int lca(int u, int v)
{
	return LCA::query(u,v);
}

int getans(int u)
{
	if(sta.empty())
		return 0;

	int a=*sta.begin(),b=*sta.rbegin();

	if(rem[u]<b && rem[u]>a)
	{
		iter=sta.lower_bound(rem[u]);
		b=*iter;
		--iter;
		a=*iter;
	}

	a=xu[a];
	b=xu[b];

	return dis[u]-dis[lca(u,a)]-dis[lca(u,b)]+dis[lca(a,b)];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b,c;
	int ans;

	scanf("%d",&T);

	while(T--)
	{
		ans=0;
		sta.clear();
		scanf("%d %d",&N,&Q);
		init();
		memset(jihe,0,sizeof(jihe));

		for(int i=1;i<N;++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		dfs(1,0);
		LCA::LCA_init(1,N);

		printf("Case #%d:\n",cas++);

		while(Q--)
		{
			scanf("%d %d",&a,&b);

			if(a==1)
				if(jihe[b])
					printf("%d\n",ans);
				else
				{
					ans+=getans(b);
					printf("%d\n",ans);
					add(b);
				}
			else
				if(!jihe[b])
					printf("%d\n",ans);
				else
				{
					dele(b);
					ans-=getans(b);
					printf("%d\n",ans);
				}
		}
	}
	
	return 0;
}
