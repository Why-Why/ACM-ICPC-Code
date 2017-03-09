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
// Created Time  : 2015年09月13日 星期日 11时10分08秒
// File Name     : 1008.cpp

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

const int MaxN=1010;

int N,Q;
int ch[MaxN][2];
char ans[MaxN][MaxN];

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

void init()
{
	tree.init();
	memset(ch,0,sizeof(ch));
	for(int i=0;i<=1000;++i)
		ans[i][0]=0;
}

int num[MaxN];
int root;

void chuli()
{
	root=num[1];
	tree.insert(root);

	int t;

	for(int i=2;i<=N;++i)
	{
		t=tree.preNum(num[i]);
		if(t!=-INF && ch[t][0]==0)
		{
			ch[t][0]=num[i];
			tree.insert(num[i]);
			continue;
		}

		t=tree.nextNum(num[i]);
		if(t!=INF && ch[t][1]==0)
		{
			ch[t][1]=num[i];
			tree.insert(num[i]);
			continue;
		}
	}
}

void getans(int x)
{
	int cou=0;
	int u=root;
	
	while(u!=x)
	{
		if(u>x)
		{
			u=ch[u][1];
			ans[x][cou++]='E';
		}
		else
		{
			u=ch[u][0];
			ans[x][cou++]='W';
		}
	}
	ans[x][cou++]=0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		init();

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		chuli();

		scanf("%d",&Q);
		int a;

		while(Q--)
		{
			scanf("%d",&a);
			if(ans[a][0])
				puts(ans[a]);
			else getans(a);
			puts(ans[a]);
		}
	}
	
	return 0;
}
