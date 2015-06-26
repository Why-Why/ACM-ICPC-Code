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
// Created Time  : 2015年06月19日 星期五 00时50分42秒
// File Name     : D.cpp

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

const int MaxN=160010;
const int INF=0x3f3f3f3f;

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
};

Treap tree;

struct Point
{
	int x,y;

	Point() {}
	Point(int a,int b):x(a),y(b) {}
};

Point P[2010];
int N;
int rem[2010];

int gcd(int a,int b)
{
	if(!a)
		return b;

	return gcd(b%a,a);
}

long long getans(int x)
{
	tree.init();

	int temp;
	int dx,dy;

	for(int i=1;i<=N;++i)
	{
		if(i==x)
			continue;

		dx=P[i].x-P[x].x;
		dy=P[i].y-P[x].y;

		temp=gcd(dx,dy);
		dx/=temp;
		dy/=temp;

		rem[i]=dy*1000+dx;
		tree.insert(rem[i]);
	}

	long long ret=0;

	for(int i=x+1;i<=N;++i)
		ret+=N-1LL-tree.find(rem[i]);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d %d",&P[i].x,&P[i].y);

	long long ans=0;

	for(int i=1;i<=N;++i)
		ans+=getans(i);

	cout<<ans/3<<endl;
	
	return 0;
}
