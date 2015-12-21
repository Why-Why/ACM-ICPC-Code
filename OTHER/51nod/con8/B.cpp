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
// Created Time  : 2015年11月28日 星期六 10时19分13秒
// File Name     : B.cpp

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

const int MaxN=200005;
const int INF=0x3f3f3f3f;

typedef pair<int,long long> pii;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	int key[MaxN],pri[MaxN];		// 键值，优先值。
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。
	long long sum[MaxN];

	void init()
	{
		tot=1;
		root=0;
		pri[0]=INT_MAX;				// 不能是INF。
		size[0]=0;
		sum[0]=0;
	}

	void update(int x)				// 维护size。
	{
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
		sum[x]=sum[ch[x][0]]+cou[x]*(long long)key[x]+sum[ch[x][1]];
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

	pii getmax(int k) {
		int u=root;
		int ret1=0;
		long long ret2=0;

		while(u) {
			if(key[u]>k) {
				ret1+=cou[u]+size[ch[u][1]];
				ret2+=cou[u]*(long long)key[u]+sum[ch[u][1]];
				u=ch[u][0];
			}
			else u=ch[u][1];
		}

		return pii(ret1,ret2);
	}

	pii getmin(int k) {
		int u=root;
		int ret1=0;
		long long ret2=0;

		while(u) {
			if(key[u]<k) {
				ret1+=cou[u]+size[ch[u][0]];
				ret2+=cou[u]*(long long)key[u]+sum[ch[u][0]];
				u=ch[u][1];
			}
			else u=ch[u][0];
		}
		
		return pii(ret1,ret2);
	}

	long long getnum(int k) {
		pii n1,n2;
		n1=getmax(k);
		n2=getmin(k);

		return n1.second-n1.first*(long long)k+n2.first*(long long)k-n2.second;
	}

	void insert(int k)
	{
		_insert(root,k);
	}

	void erase(int k)
	{
		_erase(root,k);
	}
}tree;

long long ans=0;

void insert(int x) {
	ans+=tree.getnum(x);
	tree.insert(x);
}

void erase(int x) {
	if(tree.find(x)==0) { puts("-1"); return; }
	ans-=tree.getnum(x);
	tree.erase(x);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	tree.init();
	int N,Q;
	int a,b,c;

	scanf("%d %d",&N,&Q);
	while(N--) {
		scanf("%d",&a);
		insert(a);
	}

	while(Q--) {
		scanf("%d",&a);
		if(a==1) {
			scanf("%d",&b);
			insert(b);
		}
		else if(a==2) {
			scanf("%d",&b);
			erase(b);
		}
		else printf("%lld\n",ans);
	}
	
	return 0;
}
