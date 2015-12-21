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
// Created Time  : 2015年11月14日 星期六 20时58分19秒
// File Name     : H.cpp

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

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	int key[MaxN],pri[MaxN];		// 键值，优先值。
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。

	void init()
	{
		tot=1;
		root=0;
		pri[0]=INT_MAX;				// 不能是INF。
		size[0]=0;
	}

	void update(int x)				// 维护size。
	{
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
	}

	void rotate(int &x,int t)		// 节点x按照t方向旋转，0为左。
	{
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;

		update(x);
		update(y);

		x=y;
	}

	void _insert(int &x,int k)
	{
		if(x)
		{
			if(key[x]==k)
				++cou[x];
			else
			{
				int t=key[x]<k;

				_insert(ch[x][t],k);

				if(pri[ch[x][t]]<pri[x])
					rotate(x,t);
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

	void _erase(int &x,int k)
	{
		if(!x)				// ???
			return;

		if(key[x]==k)
			if(cou[x]>1)
				--cou[x];
			else
			{
				if(ch[x][0]==0 && ch[x][1]==0)
				{
					x=0;				// 那一块内存不能用了，所以容量要开大。
					return;
				}

				int t=pri[ch[x][0]]>pri[ch[x][1]];

				rotate(x,t);
				_erase(x,k);
			}
		else
			_erase(ch[x][key[x]<k],k);

		update(x);
	}

	int _getKth(int &x,int k)			// 第k大元素。
	{
		if(k<=size[ch[x][0]])
			return _getKth(ch[x][0],k);

		k-=size[ch[x][0]]+cou[x];

		if(k<=0)
			return key[x];

		return _getKth(ch[x][1],k);
	}

	int find(int k)
	{
		int u=root;

		while(u)
		{
			if(key[u]==k)
				return cou[u];

			u=ch[u][key[u]<k];
		}

		return 0;
	}

	void insert(int k)
	{
		_insert(root,k);
	}

	void erase(int k)
	{
		_erase(root,k);
	}

	int getKth(int k)
	{
		return _getKth(root,k);
	}

	int rank(int k)
	{
		int u=root;
		int ret=0;
    
		while(u)
		{
			if(key[u]==k)
				return ret+cou[u]+size[ch[u][0]];
    
			if(key[u]<k)
			{
				ret+=cou[u]+size[ch[u][0]];
				u=ch[u][1];
			}
			else
				u=ch[u][0];
		}
    
		return ret;
	}

};

/////////////////////////////////

struct Edge
{
	int to,next;
	int w;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N,L,W;
int vis[MaxN];
int sumnode,rsize[MaxN];
int cen,minnC;

long long ans=0;

void init()
{
	Ecou=0;
	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		vis[i]=0;
	}
}

void addEdge(int u,int v,int w)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].w=w;
	head[u]=Ecou++;
}

///////////////////////

int dfsC(int u,int pre)
{
	int ret=1,maxn=0,t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
		{
			t=dfsC(E[i].to,u);
			maxn=max(maxn,t);
			ret+=t;
		}
	maxn=max(maxn,sumnode-ret);

	if(maxn<minnC) { minnC=maxn; cen=u; }

	return ret;
}

int getCenter(int u)
{
	minnC=0x3f3f3f3f;
	dfsC(u,-1);
	return cen;
}

////////////////////////

Treap tree;

typedef pair<int,int> pii;
pii num[MaxN];
int len;

long long getnum()
{
	long long ret=0;

	sort(num,num+len);

	tree.init();

	for(int i=len-1,j=0;i>=0;--i)
	{
		while(j>i) tree.erase(num[--j].second);
		while(j<i && num[j].first+num[i].first<=L) tree.insert(num[j++].second);
		ret+=tree.rank(W-num[i].second);
	}

	return ret;
}

int dfsc(int u,int pre,int dw,int dl)
{
	int ret=1;
	num[len++]=pii(dl,dw);

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			ret+=dfsc(E[i].to,u,dw+E[i].w,dl+1);
	return ret;
}

void getans(int u)
{
	int c=getCenter(u);
	vis[c]=1;
	len=0;
	dfsc(c,-1,0,0);
	ans+=getnum();

	for(int i=head[c],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			len=0;
			sumnode=dfsc(E[i].to,c,E[i].w,1);
			ans-=getnum();
			getans(E[i].to);
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d %d",&N,&L,&W);
	init();

	for(int i=2;i<=N;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,i,b);
		addEdge(i,a,b);
	}

	ans=0;
	sumnode=N;
	getans(1);

	printf("%I64d\n",ans);
	
	return 0;
}
