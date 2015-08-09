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
// Created Time  : 2015年07月16日 星期四 11时34分26秒
// File Name     : 2352.cpp

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

const int MaxN=20000;
const int INF=0x3f3f3f3f;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];
	int key[MaxN],pri[MaxN];
	int cou[MaxN],size[MaxN];

	void init()
	{
		tot=1;
		root=0;
		pri[0]=INT_MAX;
		size[0]=0;
	}

	void update(int x)
	{
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
	}

	void rotate(int &x,int t)
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
			pri[x]=rand();
			ch[x][0]=ch[x][1]=0;
		}

		update(x);
	}

	void insert(int k)
	{
		_insert(root,k);
	}

	int find(int k)
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

	void dis(int u)
	{
		if(!u)
			return;

		cout<<u<<' '<<key[u]<<endl;
		dis(ch[u][0]);
		dis(ch[u][1]);
	}

	void display()
	{
		dis(root);
	}
};

Treap tree;

int N;

struct Point
{
	int x,y;

	bool operator < (const Point &b) const
	{
		if(x==b.x)
			return y<b.y;

		return x<b.x;
	}
};

Point P[MaxN];
int ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Rp;

	while(~scanf("%d",&N))
	{
		tree.init();

		for(int i=1;i<=N;++i)
			scanf("%d %d",&P[i].x,&P[i].y);

		sort(P+1,P+N+1);

		memset(ans,0,sizeof(ans));
		Rp=1;

		for(int i=1;i<=N;++i)
		{
			while(Rp<=N && P[Rp].x<=P[i].x)
			{
				tree.insert(P[Rp].y);
				++Rp;
			}
			
			++ans[tree.find(P[i].y)];
		}

		for(int i=1;i<=N;++i)
			printf("%d\n",ans[i]);
	}
	
	return 0;
}
