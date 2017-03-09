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

////////////////////////

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	long long key[MaxN];
	int pri[MaxN];		// 键值，优先值。
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。

	void init() { tot=1; root=0; pri[0]=INT_MAX; size[0]=0; }
	void update(int x) { size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]]; }
	void rotate(int &x,int t)		// 节点x按照t方向旋转，0为左。
	{
		int y=ch[x][t];
		ch[x][t]=ch[y][1-t]; ch[y][1-t]=x;
		update(x); update(y); x=y;
	}
	int da(long long k)
	{
		int x=root,ret=0;

		while(x)
		{
			if(k<key[x]) { ret+=size[ch[x][1]]+cou[x]; x=ch[x][0]; }
			else if(k==key[x]) { ret+=size[ch[x][1]]; break; }
			else if(k>key[x]) x=ch[x][1];
		}
		return ret;
	}
	void _insert(int &x,long long k)
	{
		if(x)
		{
			if(key[x]==k) ++cou[x];
			else
			{
				int t=key[x]<k;
				_insert(ch[x][t],k);
				if(pri[ch[x][t]]<pri[x]) rotate(x,t);
			}
		}
		else
		{
			x=tot++;
			key[x]=k;
			cou[x]=1;
			pri[x]=rand();			// !!!
			ch[x][0]=ch[x][1]=0;
		}
		update(x);
	}
	void insert(long long k) { _insert(root,k); }
}tree;

////////////////////////////////

struct Edge { int to,next,c; };
Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N;
int lowcost[MaxN],ans[MaxN];
int lowf[MaxN];
int dist[MaxN];

bool vis[MaxN];
bool gvis[MaxN];
int sumnode;

typedef pair <int,double> pii;
pii num[MaxN];
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
	num[len++]=pii(u,(lowcost[u]-dis)*FLG+lowf[u]);
	dist[u]=dis;

	int ret=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			ret+=dfsSum(E[i].to,u,dis+E[i].c);
	return ret;
}

void getnum(int L,int R,int t)
{
	sort(num+L,num+R);

	tree.init();
	for(int i=L;i<R;++i)
	{
		ans[num[i].first]+=t*tree.da(dist[num[i].first]*FLG+num[i].first);
		tree.insert(num[i].second);
	}

	tree.init();
	for(int i=R-1;i>=L;--i)
	{
		ans[num[i].first]+=t*tree.da(dist[num[i].first]*FLG+num[i].first);
		tree.insert(num[i].second);
	}
}

int rsize[MaxN];

void calc(int u)
{
	len=1;
	dist[u]=0;
	num[0]=pii(u,lowcost[u]*FLG+lowf[u]);
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
		for(int i=1;i<=N;++i) if(lowcost[i]) maxn=max(maxn,ans[i]+1);
		printf("%d\n",maxn);
	}
	
	return 0;
}
