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
// Created Time  : 2015年07月18日 星期六 16时48分36秒
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

const int MaxN=40005;

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

const int INF=0x3f3f3f3f;

int val[MaxN];
int N;

int count(int t)
{
	int ret=0;

	while(t)
	{
		if(t&1)
			++ret;

		t>>=1;
	}

	return ret;
}

void show(int t)
{
	int cou=0;
	int first=0;

	while(t)
	{
		if(t&1)
		{
			if(first)
				printf(" ");
			else
				first=1;

			printf("%d",cou+1);
		}

		++cou;
		t>>=1;
	}

	printf("\n");
}

int rem[MaxN];
int rcou[MaxN];

bool judge(int t)
{
	int f;

	for(int i=1;i<=N;++i)
	{
		rcou[i]=0;
		rem[i]=0;
	}

	int cou=0;

	while(t)
	{
		if(t&1)
			rem[cou+1]=1;

		++cou;
		t>>=1;
	}

	for(int i=1;i<=N;++i)
		for(int j=i+1;j<=N;++j)
		{
			f=query(i,j);

			if(rem[i] && rem[j])
				++rcou[f];
		}

	for(int i=1;i<=N;++i)
		if(rcou[i]<val[i])
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=INF,rem;
	int a,b;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d",&val[i]);

	Edge_init();

	for(int i=1;i<N;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	LCA_init(1,N);

	for(int t=0;t<(1<<N);++t)
	{
		if(ans>count(t) && judge(t))
		{
			ans=count(t);
			rem=t;
		}
	}

	if(ans==INF)
		ans=-1;

	printf("%d\n",ans);

	if(ans>0)
		show(rem);
	
	return 0;
}
