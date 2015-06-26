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
// Created Time  : 2015年05月31日 星期日 18时57分31秒
// File Name     : E.cpp

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

const int MaxN=10100;
const int INF=0x3f3f3f3f;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	long long key[MaxN],second[MaxN];
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

	void _insert(int &x,long long k,long long sec)
	{
		if(x)
		{
			if(key[x]==k)
				++cou[x];
			else
			{
				int t=key[x]<k;

				_insert(ch[x][t],k,sec);

				if(pri[ch[x][t]]<pri[x])
					rotate(x,t);
			}
		}
		else
		{
			x=tot++;
			key[x]=k;
			second[x]=sec;
			cou[x]=1;
			pri[x]=rand();			// !!!
			ch[x][0]=ch[x][1]=0;
		}

		update(x);
	}

	long long find(long long k)
	{
		int u=root;

		while(u)
		{
			if(key[u]==k)
				return second[u];

			u=ch[u][key[u]<k];
		}

		return -1;
	}

	void insert(long long k,long long sec)
	{
		_insert(root,k,sec);
	}
};

Treap sta[26][26];
int n,k;
long long s;
long long num[30];
long long jie1[30];

void init()
{
	jie1[0]=1;

	for(int i=1;i<=19;++i)
		jie1[i]=jie1[i-1]*i;
}

long long getans(int n,int k,long long s)
{
	if(n==0)
		return s==0;

	long long iter;

	iter=sta[n][k].find(s);

	if(iter!=-1)
		return iter;

	long long ret=0;

	if(num[n]<=19 && jie1[num[n]]<=s && k)
		ret+=getans(n-1,k-1,s-jie1[num[n]]);

	ret+=getans(n-1,k,s);
	
	if(s>=num[n])
		ret+=getans(n-1,k,s-num[n]);

	sta[n][k].insert(s,ret);

	return ret;
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	init();

	cin>>n>>k>>s;

	for(int i=1;i<=n;++i)
		cin>>num[i];

	cout<<getans(n,k,s)<<endl;
	
	return 0;
}
