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
// Created Time  : 2015年11月08日 星期日 19时10分55秒
// File Name     : F.cpp

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
#include <climits>

using namespace std;

const int MaxN=100005;
const int INF=0x3f3f3f3f;
const long long FLG=1000000;

struct Edge { int to,next,c; };
Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N;
int lowcost[MaxN],lowf[MaxN],ans[MaxN];

bool vis[MaxN],gvis[MaxN];
int sumnode;

struct pii
{
	int id;
	long long v;
	pii(int a=0,long long b=0):id(a),v(b) {}
	bool operator < (const pii & b) const { return v<b.v; }
};
pii num[MaxN];
long long nval[MaxN];
int len;

////////////////////////////////

void init() { Ecou=0; for(int i=1;i<=N;++i) { head[i]=-1; gvis[i]=vis[i]=ans[i]=0; lowf[i]=lowcost[i]=INF; } }
void addEdge(int u,int v,int c) { E[Ecou].to=v; E[Ecou].c=c; E[Ecou].next=head[u]; head[u]=Ecou++; }

//////////////////////////////////

int cen,minnC;

int dfsC(int u,int pre)
{
	int maxn=0,t,sum=1;

	for(int i=head[u];i!=-1;i=E[i].next) if(!vis[E[i].to] && E[i].to!=pre) { t=dfsC(E[i].to,u); maxn=max(maxn,t); sum+=t; }
	maxn=max(sumnode-sum,maxn);
	if(maxn<minnC) { minnC=maxn; cen=u; }

	return sum;
}

int getCenter(int u) { minnC=INF; dfsC(u,-1); return cen; }

//////////////////////////////////

int dfsSum(int u,int pre,int dis)
{
	nval[len]=(lowcost[u]-dis)*FLG+lowf[u]; num[len++]=pii(u,dis*FLG+u);

	int ret=1;
	for(int i=head[u];i!=-1;i=E[i].next) if(!vis[E[i].to] && E[i].to!=pre) ret+=dfsSum(E[i].to,u,dis+E[i].c);
	return ret;
}

void getnum(int L,int R,int t)
{
	sort(num+L,num+R);
	sort(nval+L,nval+R);

	for(int i=L,j=L;i<R;++i)
	{
		while(j<R && nval[j]<=num[i].v) ++j;
		ans[num[i].id]+=t*(R-j);
	}
}

int rsize[MaxN];

void calc(int u)
{
	len=1;
	nval[0]=lowcost[u]*FLG+lowf[u]; num[0]=pii(u,u);
	int pre=1;

	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			rsize[j++]=dfsSum(E[i].to,u,E[i].c);
			getnum(pre,len,-1);
			pre=len;
		}
	getnum(0,len,1);
}

void getans(int u)
{
	int c=getCenter(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			sumnode=rsize[j++];
			getans(E[i].to);
		}
}

////////////////////////////////////

struct Node
{
	int id,v;
	Node(int a=0,int b=0):id(a),v(b) {}
	bool operator < (const Node & b) const { return v>b.v; }
};

priority_queue <Node> que;

void getlowcost()
{
	Node temp;
	int u;

	while(!que.empty())
	{
		temp=que.top(); que.pop(); u=temp.id;

		if(gvis[u]) continue;
		gvis[u]=1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(lowcost[E[i].to]>lowcost[u]+E[i].c)
			{
				lowf[E[i].to]=lowf[u];
				lowcost[E[i].to]=lowcost[u]+E[i].c;
				que.push(Node(E[i].to,lowcost[E[i].to]));
			}
			else if(lowcost[E[i].to]==lowcost[u]+E[i].c)
				lowf[E[i].to]=min(lowf[E[i].to],lowf[u]);
	}
}

//////////////////////////////////////

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	while(~scanf("%d",&N))
	{
		while(!que.empty()) que.pop();
		init();
		for(int i=1;i<N;++i) { scanf("%d %d %d",&a,&b,&c); addEdge(a,b,c); addEdge(b,a,c); }
		for(int i=1;i<=N;++i) { scanf("%d",&a); if(a) { lowf[i]=i; lowcost[i]=0; que.push(Node(i,0)); } }
		getlowcost();

		sumnode=N;
		getans(1);

		int maxn=0;
		for(int i=1;i<=N;++i) if(lowcost[i]) maxn=max(maxn,ans[i]);
		printf("%d\n",maxn);
	}
	
	return 0;
}
