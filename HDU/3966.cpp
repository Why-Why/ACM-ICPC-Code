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

const int MaxN=50010;

struct Edge
{
	int to,next;
};

Edge E[MaxN*2];
int Ecou,head[MaxN];

int fa[MaxN],son[MaxN],dep[MaxN],siz[MaxN],top[MaxN],w[MaxN],fw[MaxN];
int Tcou;

void init()
{
	Ecou=0;
	Tcou=1;
	w[1]=1;				//!!!
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
	fw[w[son[u]]]=u;

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

///////

inline int lowbit(int x)
{
	return x&(-x);
}

int C[MaxN];
int N;

int sum(int x)
{
	int ret=0;

	while(x>0)
	{
		ret+=C[x];
		x-=lowbit(x);
	}

	return ret;
}

void add(int x,int d)
{
	while(x<=N)
	{
		C[x]+=d;
		x+=lowbit(x);
	}
}

void update(int u,int v,int d)
{
	int f1=top[u],f2=top[v];

	while(f1!=f2)
	{
		if(dep[f1]<dep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}

		add(w[f1],d);
		add(w[u]+1,-d);
		u=fa[f1];
		f1=top[u];
	}

	if(dep[u]>dep[v])
		swap(u,v);

	add(w[u],d);
	add(w[v]+1,-d);
}

int num[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,P;
	int a,b,c;
	char s[10];

	while(~scanf("%d %d %d",&N,&M,&P))
	{
		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		init();

		while(M--)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		dfs1(1,-1,1);
		dfs2(1);

		memset(C,0,sizeof(C));

		for(int i=1;i<=N;++i)
		{
			add(w[i],num[i]);
			add(w[i]+1,-num[i]);
		}
		
		while(P--)
		{
			scanf("%s",s);

			if(s[0]=='Q')
			{
				scanf("%d",&a);
				printf("%d\n",sum(w[a]));
			}
			else
			{
				scanf("%d %d %d",&a,&b,&c);

				if(s[0]=='D')
					c=-c;

				update(a,b,c);
			}
		}
	}
	
	return 0;
}
