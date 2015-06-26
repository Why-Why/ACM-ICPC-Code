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

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int MaxN=100005;
const int MaxM=300005;

struct Edge
{
	int to,next;
};

Edge E[MaxM*2];
int head[MaxN],Ecou;

bool vis[MaxM*2];
int rem[MaxN];

void init(int N)
{
	Ecou=0;
	
	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		rem[i]=0;
	}
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int N,M;
bool ans1,ans2;
int que[MaxN];
int first,last;

/////////////////////////////////////////////////////////////////////
namespace LCA
{

int logN[2*MaxN];
int dp[2*MaxN][20];
int rmq[2*MaxN];			// 某序号的深度。
int Dep[MaxN];

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
	Dep[u]=dep;
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
	int t;
	t=F[RMQ(P[u],P[v])];

	return Dep[u]+Dep[v]-Dep[t]-Dep[t];
}

}
/////////////////////////////////////////////////////////////////

int que1[MaxN];
int first1,last1;

int bfs(int x)
{
	int ret=1;
	int u,v;

	first1=last1=0;
	que1[last1++]=x;
	rem[x]=1;
	que[last++]=x;

	while(last1-first1)
	{
		u=que1[first1++];

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(rem[v]==0)
			{
				vis[i]=vis[i^1]=1;
				LCA::addEdge(u,v);
				LCA::addEdge(v,u);
				rem[v]=1;
				que[last++]=v;
				que1[last1++]=v;
				++ret;
			}
		}
	}

	return ret;
}

void getans()
{
	int u,v;
	int t;

	for(int i=first;i<last;++i)
	{
		u=que[i];

		for(int j=head[u];j!=-1;j=E[j].next)
			if(vis[j]==0)
			{
				v=E[j].to;

				if(LCA::query(u,v)%2)
					ans2=1;
				else
					ans1=1;
			}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;
	int flag;
	int num;

	scanf("%d",&T);

	while(T--)
	{
		flag=1;
		scanf("%d %d",&N,&M);
		init(N);
		memset(vis,0,sizeof(vis));
		ans1=ans2=0;

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		for(int i=1;i<=N;++i)
			if(rem[i]==0)
			{
				first=last=0;
				LCA::Edge_init();
				num=bfs(i);

				LCA::LCA_init(1,num);

				getans();

				if(ans1 && ans2)
					break;
			}

		if(ans1)
			printf("YES\n");
		else
			printf("NO\n");

		if(ans2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
