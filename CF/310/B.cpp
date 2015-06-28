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
// Created Time  : 2015年06月27日 星期六 22时40分32秒
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

const int MaxN=500000;
const long long INF=2000000000000000000LL;

struct state
{
	long long num;
	int id;

	bool operator < (const state &b) const
	{
		if(num!=b.num)
			return num<b.num;

		return id<b.id;
	}

	bool operator == (const state &b) const
	{
		return num==b.num && id==b.id;
	}
};

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	state key[MaxN];
	int pri[MaxN];		// 键值，优先值。
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

	void _insert(int &x,const state & k)
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

	void _erase(int &x,const state & k)
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
			return x;

		return _getKth(ch[x][1],k);
	}

	int find(const state & k)
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

	void insert(const state & k)
	{
		_insert(root,k);
	}

	void erase(const state & k)
	{
		_erase(root,k);
	}

	state getKth(int k)
	{
		return key[_getKth(root,k)];
	}
};

Treap tree;
int N,M;
state temp;

struct range
{
	long long L,R;
	int id;

	bool operator < (const range &b) const
	{
		if(R!=b.R)
			return R<b.R;

		return L<b.L;
	}
};

range Ran[300005];
int ans[300005];
state nothing;

state find(long long x,int R)
{
	int L=1,Mid;
	state ttt;

	ttt=tree.getKth(R);

	if(ttt.num<x)
		return nothing;

	while(R>L)
	{
		Mid=(L+R)>>1;

		ttt=tree.getKth(Mid);

		if(ttt.num<x)
			L=Mid+1;
		else
			R=Mid;
	}

	return tree.getKth(L);
}

bool getans()
{
	state ttt;

	for(int i=1;i<=N;++i)
	{
		ttt=find(Ran[i].L,M-i+1);

		if(ttt.num==-1)
			return 0;

		if(ttt.num>Ran[i].R)
			return 0;

		ans[Ran[i].id]=ttt.id;
		tree.erase(ttt);
	}

	return 1;
}

long long remL[300000],remR[300000];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	nothing.num=-1;

	cin>>N>>M;

	if(N-1>M)
	{
		cout<<"No"<<endl;
		return 0;
	}

	for(int i=1;i<=N;++i)
		cin>>remL[i]>>remR[i];

	for(int i=1;i<N;++i)
	{
		Ran[i].L=remL[i+1]-remR[i];
		Ran[i].R=remR[i+1]-remL[i];
		Ran[i].id=i;
	}

	--N;

	sort(Ran+1,Ran+N+1);

	tree.init();

	for(int i=1;i<=M;++i)
	{
		cin>>temp.num;
		temp.id=i;

		tree.insert(temp);
	}

	if(getans())
	{
		cout<<"Yes"<<endl;

		for(int i=1;i<=N;++i)
			cout<<ans[i]<<' ';
		cout<<endl;
	}
	else
		cout<<"No"<<endl;
	
	return 0;
}
