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

/*
const int INF=10e8;
const int MaxN=50;;

struct Edge
{
	int u,v,cost;

	Edge(int _u=0,int _v=0,int _cost=0):u(_u),v(_v),cost(_cost) {}
};

vector <Edge> E;

bool Bellman_Ford(int lowcost[],int n,int start)
{
	bool ok;
	int u,v,c;
	int len=E.size();

	for(int i=1;i<=n;++i)
		lowcost[i]=INF;
	lowcost[start]=0;

	for(int i=0;i<n-1;++i)
	{
		ok=0;

		for(int j=0;j<len;++j)
		{
			u=E[j].u;
			v=E[j].v;
			c=E[j].cost;

			if(lowcost[v]>lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;
				ok=1;
			}
		}

		if(!ok)
			return 1;
	}

	for(int j=0;j<len;++j)
		if(lowcost[E[j].v]>lowcost[E[j].u]+E[j].cost)
			return 0;

	return 1;
}

inline void addEdge(int u,int v,int c)
{
	E.push_back(Edge(u,v,c));
}*/

int N;
char s[30][1000];
int map1[30][30];
int maxn;

/*
void floyd()
{
	for(int i=1;i<=N+1;++i)
		for(int j=1;j<=N+1;++j)
			cost[i][j]=map1[i][j];

	for(int k=1;k<=N+1;++k)
		for(int i=1;i<=N+1;++i)
			for(int j=1;j<=N+1;++j)
				cost[i][j]=max(cost[i][j],cost[i][k]+cost[k][j]);
}*/

bool vis[30];

void dfs(int x,int rem)
{
	maxn=max(maxn,rem);

	for(int i=1;i<=N;++i)
		if(x!=i && map1[x][i] && vis[i]==0)
		{
			vis[i]=1;
			dfs(i,rem+map1[x][i]);
			vis[i]=0;
		}
}

int getans(int x,int y)
{
	int p=0;
	int len1=strlen(s[x]),len2=strlen(s[y]);
	bool ok;

	for(p=1;p<=min(len1,len2);++p)
	{
		ok=1;

		for(int i=0;i<p;++i)
		{
			if(s[x][len1-p+i]!=s[y][i])
			{
				ok=0;
				break;
			}
		}

		if(ok)
			break;
	}

	if(p==0)
		return 0;

	char *t1,*t2;

	if(len1>len2)
		t1=s[y],t2=s[x];
	else
		t1=s[x],t2=s[y];

	if(strstr(t2,t1))
		return 0;

	if(p>=min(len1,len2))
		return 0;

	return len2-p;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int len;
	char st;
	bool ok;

	while(~scanf("%d",&N))
	{
		memset(map1,0,sizeof(map1));
		memset(vis,0,sizeof(vis));

		for(int i=1;i<=N+1;++i)
			scanf("%s",s[i]);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(i!=j)
					map1[i][j]=getans(i,j);

		ok=0;

		for(int i=1;i<=N;++i)
			if(s[i][0]==s[N+1][0])
			{
				map1[N+1][i]=strlen(s[i])-1;
				ok=1;
			}

		maxn=0;

		dfs(N+1,0);

//		for(int i=1;i<=N;++i)
//			maxn=max(maxn,cost[N+1][i]);

//		for(int i=1;i<=N+1;++i,cout<<endl)
//			for(int j=1;j<=N+1;++j)
//				cout<<map1[i][j]<<' ';

		if(ok)
			printf("%d\n",maxn+1);
		else
			printf("0\n");
	}
	
	return 0;
}
