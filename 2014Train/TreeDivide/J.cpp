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
// Created Time  : 2015年11月16日 星期一 23时08分45秒
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

const int MaxN=200005;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next;
	int w;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N,K,M;
int ans;
bool vis[MaxN];
bool cow[MaxN];

void init()
{
	Ecou=0;
	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		vis[i]=cow[i]=0;
	}
}

void addEdge(int u,int v,int i)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].w=i;
	head[u]=Ecou++;
}

//////////////////

int sumnode;
int minnC,cen;
int maxson[MaxN],couson[MaxN];

void dfsC1(int u,int pre)
{
	couson[u]=1;
	maxson[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
		{
			dfsC1(E[i].to,u);
			couson[u]+=couson[E[i].to];
			maxson[u]=max(maxson[u],couson[E[i].to]);
		}
}

void dfsC2(int u,int pre)
{
	int maxt=max(maxson[u],sumnode-couson[u]);
	if(maxt<minnC) { minnC=maxt; cen=u; }

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsC2(E[i].to,u);
}

int getCenter(int u)
{
	dfsC1(u,-1);
	sumnode=couson[u];
	minnC=INF;
	dfsC2(u,-1);
	return cen;
}

////////////////////

int C[MaxN];
typedef pair<int,int> pii;
pii remc[MaxN];
int clen;

inline int lowbit(int x) { return x&(-x); }

int query(int t)
{
	int ret=0;

	while(t)
	{
		ret=max(ret,C[t]);
		t-=lowbit(t);
	}
	
	return ret;
}

void update(int x,int w)
{
	while(x<=M)
	{
		C[x]=max(C[x],w);
		x+=lowbit(x);
	}
}

void getnum(int base)
{
	for(int i=0;i<clen;++i)
		cout<<remc[i].first<<' '<<remc[i].second<<endl;

	for(int i=0;i<clen;++i) ans=max(ans,query(K-base-remc[i].first)+remc[i].second);
	for(int i=0;i<clen;++i) update(remc[i].first,remc[i].second);
}

void dfsc(int u,int pre,int dis,int rcow)
{
	rcow+=cow[u];
	remc[clen++]=pii(rcow,dis);

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsc(E[i].to,u,dis+E[i].w,rcow);
}

void calc(int u)
{
	cout<<u<<endl;
	memset(C,0,sizeof(C));

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			clen=0;
			dfsc(E[i].to,-1,E[i].w,cow[u]);
			getnum(cow[u]);
		}
}

void getans(int u)
{
	int c=getCenter(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c];i!=-1;i=E[i].next)
		if(!vis[E[i].to])
			getans(E[i].to);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	scanf("%d %d %d",&N,&K,&M);
	init();

	while(M--)
	{
		scanf("%d",&a);
		cow[a]=1;
	}

	for(int i=1;i<N;++i)
	{
		scanf("%d %d %d",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	ans=0;
	getans(1);
	printf("%d\n",ans);
	
	return 0;
}
