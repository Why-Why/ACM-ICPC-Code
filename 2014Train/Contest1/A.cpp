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
// Created Time  : 2015年09月25日 星期五 09时20分29秒
// File Name     : A.cpp

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
		{
			cou[x]=0;
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

	void insert(int k)
	{
		_insert(root,k);
	}

	void erase(int k)
	{
		_erase(root,k);
	}

	int getMin(int & tcou)
	{
		int u=root;
		while(ch[u][0])
			u=ch[u][0];
		tcou=cou[u];
		return key[u];
	}

}tree;

int rem[MaxN],cou=0;

void chuli(int x,int n)
{
	int tcou=0;
	while(x)
	{
		if(x&1) tree.insert(n+tcou);
		++tcou;
		x>>=1;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	int N;
	long long a,ans=0;
	int t;

	cin>>N;
	tree.init();

	for(int i=1;i<=N;++i)
	{
		cin>>a;
		tree.insert(a);
	}

	int tcou;

	while(tree.size[tree.root])
	{
		t=tree.getMin(tcou);
		tree.erase(t);

		if(tcou==1) rem[++cou]=t;
		else if(tcou>1)
			chuli(tcou,t);
	}

	rem[0]=-1;
	for(int i=1;i<=cou;++i)
		ans+=rem[i]-rem[i-1]-1;
	cout<<ans<<endl;
	
	return 0;
}
