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
// Created Time  : 2015年11月02日 星期一 21时45分43秒
// File Name     : A.cpp

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

const int MaxN=40010;

struct Edge
{
	int to,next;
	int cost;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
bool vis[MaxN];

int N,K;
long long ans;

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].cost=c;
	head[u]=Ecou++;
}

int cen,minn;
int sumnode;

int dfsC(int u,int pre)
{
	int sum=1,t,maxn=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
		{
			t=dfsC(E[i].to,u);
			maxn=max(maxn,t);
			sum+=t;
		}
	maxn=max(maxn,sumnode-sum);
	if(maxn<minn)
	{
		minn=maxn;
		cen=u;
	}
	return sum;
}

int getCenter(int u)
{
	minn=0x3f3f3f3f;
	dfsC(u,-1);
	return cen;
}

long long num[MaxN];
int len;

int dfs(int u,int pre,long long d)
{
	int ret=1;
	num[len++]=d;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			ret+=dfs(E[i].to,u,d+E[i].cost);
	return ret;
}

long long calc(int u,long long dis)
{
	long long ret=0;

	len=0;
	sumnode=dfs(u,-1,dis);
	sort(num,num+len);

	for(int l=0,r=len-1;l<r;++l)
	{
		while(r>l && num[l]+num[r]>K) --r;
		ret+=r-l;
	}

	return ret;
}

void getans(int u)
{
	int c=getCenter(u);
	vis[c]=1;
	ans+=calc(c,0);

	for(int i=head[c];i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			ans-=calc(E[i].to,E[i].cost);
			getans(E[i].to);
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M;
	int a,b,c;
	char s[10];

	while(~scanf("%d %d",&N,&M))
	{
		init();
		while(M--)
		{
			scanf("%d %d %d %s",&a,&b,&c,s);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		scanf("%d",&K);

		ans=0;
		sumnode=N;
		getans(1);
		printf("%lld\n",ans);
	}
	
	return 0;
}
