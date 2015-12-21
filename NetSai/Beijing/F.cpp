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
// Created Time  : 2015年09月21日 星期一 23时30分54秒
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

using namespace std;

const int MaxN=100005;
const int MaxNode=2200006;

int N;

struct Chair_Tree
{
	int Tcou;
	int TreeRoot[MaxN];
	int lson[MaxNode],rson[MaxNode];
	int BIT[MaxNode];

	void insert(int old,int ne,int id)
	{
		old=TreeRoot[old];

		int newRoot=Tcou++;
		int L=1,R=N,M;

		TreeRoot[ne]=newRoot;
		BIT[newRoot]=max(id,BIT[old]);
		while(R>L)
		{
			M=(L+R)>>1;
			if(id<=M)
			{
				lson[newRoot]=Tcou++;
				rson[newRoot]=rson[old];
				newRoot=lson[newRoot];
				old=lson[old];
				R=M;
			}
			else
			{
				lson[newRoot]=lson[old];
				rson[newRoot]=Tcou++;
				newRoot=rson[newRoot];
				old=rson[old];
				L=M+1;
			}
			BIT[newRoot]=max(id,BIT[old]);
		}
	}

	int query(int ql,int qr,int L,int R,int po)
	{
		if(ql<=L && qr>=R)
			return BIT[po];

		int M=(L+R)>>1;
		int ret=0;

		if(ql<=M) ret=max(ret,query(ql,qr,L,M,lson[po]));
		if(qr>M) ret=max(ret,query(ql,qr,M+1,R,rson[po]));

		return ret;
	}

	int query(int tree,int ql,int qr)
	{
		return query(ql,qr,1,N,TreeRoot[tree]);
	}

	int Build(int L,int R)
	{
		int root=Tcou++;

		BIT[root]=0;
		if(L!=R)
		{
			int M=(L+R)>>1;
			lson[root]=Build(L,M);
			rson[root]=Build(M+1,R);
		}
		return root;
	}

	void show(int u)
	{
		int r=TreeRoot[u];
	}

	void init()
	{
		Tcou=0;
		TreeRoot[0]=Build(1,N);
	}
}tree;

int fa1[MaxN],fa2[MaxN];
int dep1[MaxN],dep2[MaxN];

struct Edge
{
	int to,next;
};

Edge E[MaxN*2];
int Ecou,head[MaxN];

int fa[MaxN],dep[MaxN],son[MaxN],siz[MaxN],top[MaxN],w[MaxN],fw[MaxN];
int Tcou;

void init()
{
	Ecou=0;
	Tcou=1;
	w[1]=1;				//!!!
	fw[1]=1;			//!!!
	top[1]=1;			//!!!
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
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
			fw[w[v]]=v;					// !!!
			
			dfs2(v);
		}
}

int query(int tr,int u)
{
	int f=top[u];
	int ret;

	while((ret=tree.query(tr,w[f],w[u]))==0)
	{
		u=fa[f];
		f=top[u];
	}

	return fw[ret];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Q;
	int a,b;
	int t;

	while(~scanf("%d %d",&N,&Q))
	{
		t=0;
		tree.init();
		init();
		fa1[1]=fa2[1]=0;
		dep1[1]=dep2[1]=0;

		for(int i=2;i<=N;++i)
		{
			scanf("%d",&a);
			addEdge(a,i);
			addEdge(i,a);
			dep1[i]=dep1[a]+1;
		}
		dfs1(1,-1,1);
		dfs2(1);

		tree.insert(0,1,1);
		for(int i=2;i<=N;++i)
		{
			scanf("%d",&a);
			dep2[i]=dep2[a]+1;
			tree.insert(a,i,w[i]);
		}

		tree.show(3);

		while(Q--)
		{
			scanf("%d %d",&a,&b);
			a=(a+t)%N+1;
			b=(b+t)%N+1;
			t=query(b,a);
			printf("%d %d %d\n",t,dep1[a]-dep1[t]+1,dep2[b]-dep2[t]+1);
		}
	}
	
	return 0;
}
