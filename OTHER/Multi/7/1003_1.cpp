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
// Created Time  : 2015年08月11日 星期二 19时44分33秒
// File Name     : 1003_1.cpp

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

const int MaxN=100006;
const int INF=0x3f3f3f3f;

int num[MaxN];
int N;

int Mt[MaxN*2];			// a temp string.
int Mp[MaxN*2];

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
}tree;

void Manacher(int len,int s[])
{
	int Mx=0,id=0,l=0;

	Mt[l++]=-3;		// !!!
	Mt[l++]=-1;
	for(int i=0;i<len;++i)
	{
		Mt[l++]=s[i];
		Mt[l++]=-1;
	}
	Mt[l]=-2;			// !!!

	for(int i=1;i<l;++i)
	{
		if(Mx>i)
			Mp[i]=min(Mp[2*id-i],Mx-i);
		else
			Mp[i]=1;

		while(Mt[i+Mp[i]]==Mt[i-Mp[i]])
			++Mp[i];

		if(Mp[i]+i>Mx)
		{
			Mx=Mp[i]+i;
			id=i;
		}
	}
}

struct state
{
	int wei,val;

	bool operator < (const state &b) const
	{
		return val>b.val;
	}
};

state sta[MaxN];

int getans()
{
	Manacher(N,num);
	for(int i=1;i<=N;++i)
	{
		sta[i].wei=i;
		sta[i].val=(Mp[i*2+1]-1)/2;
	}
	sort(sta+1,sta+N+1);
	tree.init();

	int t;
	int ret=0;

	for(int i=1;i<=N;++i)
	{
		if(sta[i].val==0) break;
		tree.insert(sta[i].wei);
		t=tree.preNum(sta[i].wei+sta[i].val+1);
		if(t>=sta[i].wei)
			ret=max(ret,t-sta[i].wei);
		t=tree.nextNum(sta[i].wei-sta[i].val-1);
		if(t<=sta[i].wei)
			ret=max(ret,sta[i].wei-t);
	}

	return ret*3;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;++i)
			scanf("%d",&num[i]);

		printf("Case #%d: %d\n",cas++,getans());
	}
	
	return 0;
}
