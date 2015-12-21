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
// Created Time  : 2015年10月14日 星期三 23时11分11秒
// File Name     : F_1.cpp

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
const int INF=0x3f3f3f3f;

struct SBT
{
	int tot,root;
	int size[MaxN],ch[MaxN][2];
	int key[MaxN];

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
	void _insert(int &x,int k)
	{
		if(!x)
		{
			x=tot++; key[x]=k; size[x]=1;
			ch[x][0]=ch[x][1]=0;
		}
		else
		{
			++size[x];
			_insert(ch[x][k>=key[x]],k);
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
	bool find(int k)
	{
		int x=root;

		while(x)
		{
			if(key[x]==k) return 1;
			x=ch[x][k>=key[x]];
		}
		return 0;
	}
	int rank(int k)					// 比k小的个数。
	{
		int x=root,ret=0;

		while(x)
		{
			if(k>=key[x]) ret+=size[ch[x][0]]+(key[x]!=k);
			x=ch[x][k>=key[x]];
		}
		return ret;
	}
	int getKth(int k)				// 找第K大，如果不存在返回0。
	{
		int x=root;

		while(x)
		{
			if(k<=size[ch[x][0]]) x=ch[x][0];
			else
			{
				k-=size[ch[x][0]]+1;
				if(k) x=ch[x][1];
				else return key[x];
			}
		}
		return 0;
	}
	int maxNum()
	{
		int x=root;

		while(ch[x][1])
			x=ch[x][1];
		return key[x];
	}
	int preNum(int k)				// 比k小的最大数，不存在返回-INF。
	{
		int x=root,ret=-INF;

		while(x)
		{
			if(key[x]<k) ret=max(ret,key[x]);
			x=ch[x][key[x]<k];
		}
		return ret;
	}
	int nextNum(int k)				// 比k大的最小数，不存在返回INF。
	{
		int x=root,ret=INF;

		while(x)
		{
			if(key[x]>k) ret=min(ret,key[x]);
			x=ch[x][key[x]<=k];
		}
		return ret;
	}
	void insert(int k)
	{
		_insert(root,k);
	}
	int erase(int k)
	{
		if(root) return _erase(root,k);
		return 0;
	}
}tree;

int N,M,K;
bool vis[MaxN];
priority_queue <int> que;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T;
	int n,t;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&N,&M,&K);
		tree.init();
		for(int i=1;i<=N;++i)
		{
			scanf("%d",&n);
			tree.insert(n);
		}
		while(!que.empty()) que.pop();

		while(tree.size[tree.root])
		{
			t=tree.maxNum();
			tree.erase(t);
			n=tree.preNum(K+1-t);

			if(n!=-INF)
			{
				que.push(n*t);
				tree.erase(n);
			}
		}

		long long ans=0;
		for(;M && !que.empty();--M,que.pop())
			ans+=que.top();
		printf("%lld\n",ans);
	}
	
	return 0;
}
