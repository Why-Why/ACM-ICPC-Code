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
// Created Time  : 2016年04月29日 星期五 20时57分42秒
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

const int INF=0x3f3f3f3f;
const int MaxN=100005;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	int key[MaxN],pri[MaxN];		// 键值，优先值。
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。

	int maxn[MaxN],rem[MaxN];

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

	int max1(int t) {
		int u=root;
		int ret=-INF;
		while(u) {
			if(key[u]<=t) ret=max(ret,key[u]),u=ch[u][1];
			else u=ch[u][0];
		}
		return ret;
	}

	int max1() {
		int u=root;
		while(ch[u][1]) u=ch[u][1];
		return key[u];
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
}tree;

int tadd;

int N,P;
int num[5][MaxN];

int getans(int d) {
	int dd=P-d-1;
	int t=tree.max1(dd),tt=tree.max1();
	if(t<0) return (tt+d)%P;
	else return max((tt+d)%P,(t+d)%P);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&P);
	tree.init();
	for(int i=1;i<=3;++i)
		for(int j=1;j<=N;++j)
			scanf("%d",&num[i][j]);

	int sum=0;
	int tsum=0,ttsum=0;
	for(int i=1;i<=N;++i) (sum+=num[1][i])%=P;
	tadd=0;

	int ans=-1;
	for(int i=N;i>=1;--i) {
		(tadd+=num[2][i])%=P;
		(tsum+=num[3][i])%=P;
		tree.insert(((tsum-ttsum)%P+P)%P);

		ans=max(ans,getans((sum+tadd)%P));				// !!!

		(ttsum+=num[2][i])%=P;
		sum=((sum-num[1][i])%P+P)%P;
	}

	printf("%d\n",ans);
	
	return 0;
}
