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
// Created Time  : 2015年09月19日 星期六 16时07分10秒
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

const int MaxN=500005;
const int MaxM=500100*2;

#pragma comment(linker, "/STACK:1024000000,1024000000")

namespace CUT
{

// Tarjan算法求无向图的割点与桥，复杂度 O(N+M)(注意：使用 NlogN 进行去重。)
// 输入：边集E，n (使用getCUTP函数。)。
// 输出：bridge，cutp(bool类型，判断是否是桥或割点。)，couBridge(桥的数量。)，add_block(删除该点后增加的连通块的数目。)
// 注意：先使用init函数初始化，然后使用addEdge函数加边，然后使用getCUTP函数获得结果，注意重边的处理(本函数使用排序进行处理，也可使用临接矩阵去重。)


struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int LOW[MaxN],DFN[MaxN];
int couBridge;
bool bridge[MaxM],cutp[MaxN];
int add_block[MaxN];		// The number of bolcks that is added by deleting a point.(not the number of blocks of this new graph!!!)
int Index;

struct newEdge
{
	int u,v,num;

	newEdge(int _u=0,int _v=0,int _num=0):u(_u),v(_v),num(_num) {};

	bool operator < (const newEdge &a) const
	{
		if(u==a.u)
			return v<a.v;

		return u<a.u;
	}

	bool operator == (const newEdge &a) const
	{
		return u==a.u && v==a.v;
	}
};

bool chongE[MaxM];			// Parallel edge.
newEdge remE[MaxM];

void Tarjan(int u,int pre)
{
	int v;
	int couSon=0;

	LOW[u]=DFN[u]=++Index;

	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)			// !!!
			continue;

		if(!DFN[v])
		{
			++couSon;
			Tarjan(v,u);

			if(LOW[v]<LOW[u])
				LOW[u]=LOW[v];

			if(DFN[u]<LOW[v] && !chongE[i])
			{
				bridge[i]=1;
				bridge[i^1]=1;		//
				++couBridge;
			}
			if(u!=pre && DFN[u]<=LOW[v])
			{
				cutp[u]=1;
				++add_block[u];
			}
		}
		else if(DFN[v]<LOW[u])
			LOW[u]=DFN[v];
	}

	if(u==pre && couSon>1)
	{
		cutp[u]=1;
		add_block[u]=couSon-1;
	}
}

void getCUTP(int n)
{
	sort(remE,remE+Ecou);

	for(int i=1;i<Ecou;++i)
		if(remE[i]==remE[i-1])
			chongE[remE[i].num]=chongE[remE[i-1].num]=1;

	for(int i=1;i<=n;++i)
		if(!DFN[i])
			Tarjan(i,i);
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	bridge[Ecou]=0;

	chongE[Ecou]=0;
	remE[Ecou]=newEdge(u,v,Ecou);

	head[u]=Ecou++;
}

void init(int n)
{
	Ecou=couBridge=Index=0;

	for(int i=1;i<=n;++i)
	{
		head[i]=-1;
		cutp[i]=DFN[i]=add_block[i]=0;
	}
}

};

///////////////////////
int N,M,Q;

namespace SHU
{

// 树链剖分进行边权维护，复杂度 O(klogN)。
// 输入：一颗树，N。
// 输出：fa[i](i的父亲)，son[i](i的重儿子，没有为-1)，dep[i](i的深度，dep[1]=1)，siz[i](i及其所有子节点的个数)，top[i](i所在重链最顶端的点)，w[i](i节点与其父亲的连边在线段树等中的位置，w[1]=1)，fw[i](线段树等中位置i在树中的节点)。
// 注意：从1开始，无向边添加两次，先init，然后addEdge，然后dfs1(1,-1,1)，dfs2(1)，建线段树等，稍微不同于维护点权。
// 其他：树上更新方法，f1=top[u]，f2=top[v]，若f1!=f2，更新dep大的那个重链，然后一直循环直到f1=f2。
// 原理：通过两次dfs获得树中各边在数据结构中的位置。

struct Edge
{
	int to,next,cost;
};

Edge E[MaxN*2];
int head[MaxN],Ecou;

int fa[MaxN],dep[MaxN],son[MaxN],siz[MaxN],top[MaxN],w[MaxN],fw[MaxN];
int Tcou;

void init()
{
	Ecou=Tcou=0;			// 不同于点权。
	w[1]=0;
	top[1]=1;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].cost=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs1(int u,int pre,int d)
{
	int v;

	dep[u]=d;
	fa[u]=pre;
	siz[u]=1;
	son[u]=-1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			v=E[i].to;
			dfs1(v,u,d+1);
			siz[u]+=siz[v];

			if(son[u]==-1 || siz[son[u]]<siz[v])
				son[u]=v;
		}
}

void dfs2(int u)
{
	if(son[u]==-1)
		return;

	top[son[u]]=top[u];
	w[son[u]]=++Tcou;
	fw[w[son[u]]]=son[u];

	dfs2(son[u]);

	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=son[u] && E[i].to!=fa[u])
		{
			v=E[i].to;
			top[v]=v;
			w[v]=++Tcou;

			dfs2(v);
		}
}

///// 线段树部分。
#define lc po*2
#define rc po*2+1
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN*4];
int COL[MaxN*4];

void pushUP(int po)
{
	BIT[po]=BIT[lc]+BIT[rc];
}

void pushDown(int po)
{
	if(COL[po])
	{
		COL[po]=0;
		COL[lc]=COL[rc]=1;
		BIT[lc]=BIT[rc]=0;
	}
}

int query_BIT(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return BIT[po];

	pushDown(po);

	int M=(L+R)/2;

	if(ql>M)
		return query_BIT(ql,qr,rson);
	if(qr<=M)
		return query_BIT(ql,qr,lson);

	return query_BIT(ql,qr,lson)+query_BIT(ql,qr,rson);
}

void update_BIT(int ul,int ur,int L,int R,int po)
{
	if(ul<=L && ur>=R)
	{
		BIT[po]=0;
		COL[po]=1;
		return;
	}

	pushDown(po);
	int M=(L+R)/2;

	if(ul<=M)
		update_BIT(ul,ur,lson);
	if(ur>M)
		update_BIT(ul,ur,rson);

	pushUP(po);
}

void update(int u,int v)
{
	int f1=top[u],f2=top[v];

	while(f1!=f2)
	{
		if(dep[f1]<dep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}

		update_BIT(w[f1],w[u],1,N-1,1);

		u=fa[f1];
		f1=top[u];
	}

	if(u==v)						//!!!
		return;

	if(dep[u]>dep[v])
		swap(u,v);

	update_BIT(w[son[u]],w[v],1,N-1,1);
}


int query(int u,int v)
{
	int f1=top[u],f2=top[v];
	int ret=0;

	while(f1!=f2)
	{
		if(dep[f1]<dep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}

		ret+=query_BIT(w[f1],w[u],1,N-1,1);		// N-1。

		u=fa[f1];
		f1=top[u];
	}

	if(u==v)						//!!!
		return ret;

	if(dep[u]>dep[v])
		swap(u,v);

	ret+=query_BIT(w[son[u]],w[v],1,N-1,1);

	return ret;
}

void Build(int L,int R,int po)
{
	COL[po]=0;
	BIT[po]=R-L+1;

	if(L==R) return;

	int M=(L+R)>>1;
	Build(lson);
	Build(rson);
}

};

struct SE
{
	int u,v;
	bool operator < (const SE &b) const
	{
		if(u==b.u) return v<b.v;
		return u<b.u;
	}
};

struct Ope
{
	int op;
	int a,b;
};

Ope ope[100005];

SE se[MaxM];
bool vis[MaxM];

int belong[MaxN];
int coudian;
int couBri;
SE rem[MaxN];

void shanchu(int u,int v)
{
	if(u>v)
		swap(u,v);

	SE t;
	t.u=u;
	t.v=v;

	int tt=lower_bound(se+1,se+M+1,t)-se;
	vis[tt]=1;
}

int que[MaxN];
int first,last;

void bfs(int u)
{
	using namespace CUT;

	first=last=0;
	int bee=++coudian;
	
	belong[u]=bee;
	que[last++]=u;

	while(last-first)
	{
		u=que[first++];
		for(int i=head[u];i!=-1;i=E[i].next)
			if(belong[E[i].to]==-1)
			{
				if(bridge[i])
				{
					rem[couBri].u=u;
					rem[couBri++].v=E[i].to;
				}
				else
				{
					belong[E[i].to]=bee;
					que[last++]=E[i].to;
				}
			}
	}
}

int zans[100005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&N,&M,&Q);
		memset(belong,-1,sizeof(belong));

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&se[i].u,&se[i].v);
			if(se[i].u>se[i].v)
				swap(se[i].u,se[i].v);
			vis[i]=0;
		}
		sort(se+1,se+M+1);
		for(int i=1;i<=Q;++i)
		{
			scanf("%d %d %d",&ope[i].op,&ope[i].a,&ope[i].b);
			if(ope[i].op==1)
				shanchu(ope[i].a,ope[i].b);
		}

		{
			using namespace CUT;

			init(N);
			for(int i=1;i<=M;++i)
				if(vis[i]==0)
				{
					addEdge(se[i].u,se[i].v);
					addEdge(se[i].v,se[i].u);
				}

			getCUTP(N);

			couBri=0;
			coudian=0;

			for(int i=1;i<=N;++i)
				if(belong[i]==-1)
					bfs(i);
		}

		int couans=0;
		printf("Case #%d:\n",cas++);

		if(coudian==1)
		{
			for(int i=1;i<=Q;++i)
				if(ope[i].op==2)
					printf("0\n");
			continue;
		}

		{
			using namespace SHU;

			init();
			for(int i=0;i<couBri;++i)
			{
				addEdge(rem[i].u,rem[i].v,1);
				addEdge(rem[i].v,rem[i].u,1);
			}

			dfs1(1,-1,1);
			dfs2(1);

			Build(1,N-1,1);
			for(int i=Q;i>=1;--i)
			{
				if(ope[i].op==2)
					zans[couans++]=query(ope[i].a,ope[i].b);
				else update(ope[i].a,ope[i].b);
			}
		}

		for(int i=couans-1;i>=0;--i)
			printf("%d\n",zans[i]);
	}
	
	return 0;
}
