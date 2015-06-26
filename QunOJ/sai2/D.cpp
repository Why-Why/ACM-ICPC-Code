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

int cou;
int dp[100005];
int num[100005];
int N;
int remdp[100005];
bool vis[100005];
bool have[100005];

int find(int x,int R)
{
	int L=1,M;

	while(R>L+1)
	{
		M=(L+R)/2;

		if(dp[M]>=x)
			R=M-1;
		else
			L=M;
	}

	if(dp[R]<x)
		return R;

	return L;
}

int getLIS()
{
	memset(dp,0,sizeof(dp));
	dp[1]=num[1];

	int maxn=1,temp;

	remdp[1]=1;

	for(int i=2;i<=N;++i)
		if(num[i]<=dp[1])
		{
			dp[1]=num[i];
			remdp[i]=1;
		}
		else if(num[i]>dp[maxn])
		{
			dp[++maxn]=num[i];
			remdp[i]=maxn;
		}
		else
		{
			temp=find(num[i],maxn);
			dp[temp+1]=min(dp[temp+1],num[i]);
			remdp[i]=temp+1;
		}

	return maxn;
}

vector <int> E[100005];

void chuli(int x,int y)
{
	for(int i=x;i<y;++i)
		if(vis[i]==0)
		{
			vis[i]=1;
			++cou;
		}
}

void bfs(int x)
{
	queue <int> que;
	int len,temp;
	int v;

	remdp[N+1]=x;
	have[N+1]=1;
	
	que.push(N+1);

	while(!que.empty())
	{
		temp=que.front();
		que.pop();

		if(remdp[temp]==1)
			continue;

		len=E[remdp[temp]-1].size();
		for(int i=len-1;i>=0;--i)
		{
			v=E[remdp[temp]-1][i];
cerr<<v<<' ';
			if(v>=temp)
				continue;

			if(have[v]==0)
			{
				have[v]=1;
				que.push(v);

				cerr<<v<<' ';
				
				if(remdp[v]<remdp[temp]-1)
					chuli(v+1,temp);
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int maxn;

	scanf("%d",&T);

	while(T--)
	{
		cou=0;

		for(int i=1;i<=N;++i)
			E[i].clear();

		scanf("%d",&N);
		memset(vis,0,sizeof(vis));
		memset(have,0,sizeof(have));

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		maxn=getLIS();

		for(int i=1;i<=N;++i)
			E[remdp[i]].push_back(i);

		bfs(maxn+2);

		printf("%d\n",cou);

		if(cou==0)
			printf("\n");

		for(int i=1;i<=N;++i)
			if(vis[i])
				printf("%d\n",i);
	}
	
	return 0;
}
