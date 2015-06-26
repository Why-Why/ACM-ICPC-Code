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

int rem[MaxN];
bool vis[MaxM*2];

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

int remdian[MaxN];
int remcou;

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

int F[MaxN*2];			// dfs遍历的顺序标号。
int P[MaxN];			// P[i]表示i在F中第一次出现的位置。
int cou;

void dfs(int u,int pre,int dep)
{
	int v;

	cout<<u<<' '<<pre<<endl;

	F[++cou]=u;
	rmq[cou]=dep;
	Dep[u]=dep;
	P[u]=cou;

	remdian[remcou++]=u;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(rem[E[i].to]==0)
		{
			vis[i]=vis[i^1]=1;
			v=E[i].to;
			rem[v]=1;

			if(v==pre)
				continue;

			dfs(v,u,dep+1);
		
			F[++cou]=u;
			rmq[cou]=dep;
		}
}

int query(int u,int v)
{
	int t;
	t=F[RMQ(P[u],P[v])];

	return Dep[u]+Dep[v]-Dep[t]-Dep[t];
}

void getans()
{
	int u,v;
	int t;

	for(int i=0;i<remcou;++i)
	{
		u=remdian[i];

		for(int j=head[u];j!=-1;j=E[j].next)
			if(vis[j]==0)
			{
				v=E[j].to;

				cout<<u<<' '<<v<<' '<<LCA::query(u,v)<<endl;

				if(LCA::query(u,v)%2)
					ans2=1;
				else
					ans1=1;
			}
	}
}

}
/////////////////////////////////////////////////////////////////

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;
	int num;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init(N);
		ans1=ans2=0;

		for(int i=0;i<M;++i)
		{
			vis[i*2]=vis[i*2+1]=0;

			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		for(int i=1;i<=N;++i)
			if(rem[i]==0)
			{
				remcou=0;
				rem[i]=1;

				LCA::cou=0;
				LCA::dfs(i,i,0);

				LCA::RMQ_init(LCA::cou);

				LCA::getans();

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
