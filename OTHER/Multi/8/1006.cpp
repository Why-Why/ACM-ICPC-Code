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
// Created Time  : 2015年08月13日 星期四 16时44分37秒
// File Name     : 1006.cpp

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

struct Edge
{
	int to,next;
	int from;
	int id;
};

Edge E[MaxN];
int head[MaxN],Ecou;

int N,M;
int ans[MaxN];

void init(int N)
{
	Ecou=0;
	for(int i=0;i<=N;++i)
		head[i]=-1;
}

void addEdge(int u,int v,int id)
{
	E[Ecou].from=u;
	E[Ecou].to=v;
	E[Ecou].id=id;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

const int INF=0x3f3f3f3f;

struct SBT
{
	int tot,root;
	int size[MaxN],ch[MaxN][2];
	int key[MaxN];
	int val[MaxN];

	void init()
	{
		tot=1; root=0; size[0]=0;
		ch[0][0]=ch[0][1]=0;
	}
	void update(int x)
	{
		size[x]=size[ch[x][0]]+size[ch[x][1]]+(x!=0);
	}
	void rotate(int &x,int t)
	{
		int y=ch[x][t];
		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;
		update(x); update(y);
		x=y;
	}
	void maintain(int &x,int t)
	{
		if(size[ch[ch[x][t]][t]]>size[ch[x][1-t]]) rotate(x,t);
		else if(size[ch[ch[x][t]][1-t]]>size[ch[x][1-t]])
		{
			rotate(ch[x][t],1-t); rotate(x,t);
		}
		else return;

		maintain(ch[x][0],0);
		maintain(ch[x][1],1);
		maintain(x,0);
		maintain(x,1);
	}
	void _insert(int &x,int k,int v)
	{
		if(!x)
		{
			x=tot++; key[x]=k; size[x]=1; val[x]=v;
			ch[x][0]=ch[x][1]=0;
		}
		else
		{
			++size[x];
			_insert(ch[x][k>=key[x]],k,v);
			maintain(x,k>=key[x]);
		}
	}
	int _erase(int &x,int k)
	{
		int temp;
		
		--size[x];
		if(k==key[x] || ch[x][k>=key[x]]==0)
		{
			temp=key[x];
			if(!ch[x][0] || !ch[x][1])					// 不能互换位置。
				x=ch[x][0]+ch[x][1];
			else key[x]=_erase(ch[x][0],k+1);			// 小心k+1越界。
		}
		else temp=_erase(ch[x][k>=key[x]],k);
		return temp;
	}
	int min(int &v)
	{
		int u=root;

		while(ch[u][0]) u=ch[u][0];
		v=val[u];

		return key[u];
	}
	int max(int &v)
	{
		int u=root;

		while(ch[u][1]) u=ch[u][1];
		v=val[u];

		return key[u];
	}
	void insert(int k,int v)
	{
		_insert(root,k,v);
	}
	int erase(int k)
	{
		if(root) return _erase(root,k);
		return 0;
	}
	int getSize()
	{
		return size[root];
	}
}tree;

long long lowcost[MaxN];
bool vis[MaxN];

void getans()
{
	int p1=1,p2=N;
	int u,v,pre;
	long long len=0;

	tree.init();
	
	for(int i=1;i<=N;++i) lowcost[i]=-1,vis[i]=0;
	tree.insert(1,-1);
	vis[1]=1;

	while(tree.getSize())
	{
		u=tree.min(pre);
		if(u==p1) ++p1;
		else { --p2; u=tree.max(pre); }
		tree.erase(u);

		if(lowcost[u]!=-1) continue;
		lowcost[u]=len++;
		if(pre!=-1) ans[E[pre].id]=lowcost[u]-lowcost[E[pre].from];

		for(int i=head[u];i!=-1;i=E[i].next)
			if(vis[E[i].to]==0)
			{
				v=E[i].to;
				tree.insert(v,i);
				vis[E[i].to]=1;
			}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init(N);

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b,i);
			ans[i]=0;
		}

		getans();
		for(int i=1;i<=M;++i)
			printf("%d\n",ans[i]==0 ? N : ans[i]);
	}
	
	return 0;
}
