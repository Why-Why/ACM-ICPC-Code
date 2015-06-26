// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月30日 星期六 16时00分19秒
// File Name     : 1002.cpp

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

const int MaxN=2000;
const int INF=0x3f3f3f3f;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	long long key[MaxN],pri[MaxN];		// 键值，优先值。
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

	void _insert(int &x,long long k)
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

	void _erase(int &x,long long k)
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

	int _getKth(int &x,long long k)			// 第k大元素。
	{
		if(k<=size[ch[x][0]])
			return _getKth(ch[x][0],k);

		k-=size[ch[x][0]]+cou[x];

		if(k<=0)
			return key[x];

		return _getKth(ch[x][1],k);
	}

	int find(long long k)
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

	void insert(long long k)
	{
		_insert(root,k);
	}

	void erase(long long k)
	{
		_erase(root,k);
	}

	int getKth(long long k)
	{
		return _getKth(root,k);
	}
};

Treap tree;
int n,m;
long long num[10004];
long long ans[1010];

long long getans(int k)
{
	tree.init();
	long long minn=10000000000000LL,maxn=-1,bucou=0;
	
	for(int i=1;i<=k;++i)
	{
		if(!tree.find(num[i]))
			++bucou;

		tree.insert(num[i]);
		minn=min(minn,num[i]);
		maxn=max(maxn,num[i]);
	}

	long long ret=0;

	if(bucou==maxn-minn+1 && bucou==k)
		++ret;

	for(int i=1;i+k<=n;++i)
	{
		if(tree.find(num[i])==1)
			--bucou;

		tree.erase(num[i]);

		if(tree.find(num[i+k])==0)
			++bucou;

		tree.insert(num[i+k]);

		minn=tree.getKth(1);
		maxn=tree.getKth(k);

		if(maxn-minn+1==bucou && bucou==k)
			++ret;
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	memset(ans,-1,sizeof(ans));

	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;++i)
		scanf("%I64d",&num[i]);

	printf("Case #1:\n");

	while(m--)
	{
		scanf("%d",&a);

		if(a>n)
		{
			puts("0");
			continue;
		}

		if(ans[a]==-1)
			ans[a]=getans(a);

		printf("%I64d\n",ans[a]);
	}
	
	return 0;
}
