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
// Created Time  : 2015年11月03日 星期二 23时46分16秒
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

using namespace std;

const int MaxN=10010;

struct Edge
{
	int to,next;
	int c;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
bool vis[MaxN];

int N;
int sumnode;

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].c=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int M;
int que[110];
bool ans[110];

int rsize[MaxN];
int NUM[2][MaxN],*num1,*tnum,num2[MaxN],len2;

int dfs(int u,int pre,int d)
{
	int ret=1;
	num2[len2++]=d;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			ret+=dfs(E[i].to,u,d+E[i].c);

	return ret;
}

bool judge(int len1,int len2,int v)
{
	for(int l1=len1-1,l2=0;l1>=0;--l1)
	{
		while(l2<len2 && num2[l2]+num1[l1]<v) ++l2;
		if(l2<len2 && num2[l2]+num1[l1]==v) return 1;
	}
	return 0;
}

void merge(int len1,int len2)
{
	int len=len1+len2;
	for(int i=0,l1=0,l2=0;i<len;++i)
		if(l1==len1 || (l2<len2 && num2[l2]<num1[l1]))
			tnum[i]=num2[l2++];
		else tnum[i]=num1[l1++];
	swap(num1,tnum);
}

void calc(int u)
{
	num1=NUM[0];
	tnum=NUM[1];
	int len1=1;
	num1[0]=0;

	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			len2=0;
			rsize[j++]=dfs(E[i].to,u,E[i].c);
			sort(num2,num2+len2);

			for(int k=1;k<=M;++k)
				if(!ans[k] && judge(len1,len2,que[k])) ans[k]=1;

			merge(len1,len2);
			len1+=len2;
		}
}

int cen,minn;

int dfsC(int u,int pre)
{
	int sum=1;
	int maxn=0,t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
		{
			t=dfsC(E[i].to,u);
			maxn=max(maxn,t);
			sum+=t;
		}
	maxn=max(maxn,sumnode-sum);

	if(maxn<minn)
	{
		minn=maxn;
		cen=u;
	}
	
	return sum;
}

int getCen(int u)
{
	minn=0x3f3f3f3f;
	dfsC(u,-1);
	return cen;
}

void getans(int u)
{
	int c=getCen(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c],j=0;i!=-1;i=E[i].next)
		if(!vis[E[i].to])
		{
			sumnode=rsize[j++];
			getans(E[i].to);
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d",&N) && N)
	{
		init();
		for(int i=1;i<=N;++i)
			while(~scanf("%d",&a) && a)
			{
				scanf("%d",&b);
				addEdge(a,i,b);
				addEdge(i,a,b);
			}

		M=0;
		while(~scanf("%d",&a) && a) que[++M]=a,ans[M]=0;

		sumnode=N;
		getans(1);

		for(int i=1;i<=M;++i) puts(ans[i] ? "AYE" : "NAY");
		puts(".");
	}
	
	return 0;
}
