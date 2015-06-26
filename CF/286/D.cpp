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
// Created Time  : 2015年05月22日 星期五 18时45分42秒
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

using namespace std;

struct Edge
{
	int to,next;
};

Edge E[100005],E1[200005];
int head[100005],Ecou;
int head1[100005],E1cou;
int n;
int m;
bool vis[100005];
int ru[100005];
int remcou=0;

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;

	memset(head1,-1,sizeof(head1));
	E1cou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void addEdge1(int u,int v)
{
	E1[E1cou].to=v;
	E1[E1cou].next=head1[u];
	head1[u]=E1cou++;
}

int que[100005];
int first,last;

int que1[100005];
int first1,last1;

bool tuopu(int zong,int you)
{
	int cou=0;
	int t,v;

	cou=you;

	while(last1-first1)
	{
		t=que1[first1++];

		for(int i=head[t];i!=-1;i=E[i].next)
		{
			--ru[E[i].to];

			if(ru[E[i].to]==0)
			{
				que1[last1++]=E[i].to;
				++cou;
			}
		}
	}

	return cou==zong;
}

int bfsrem[100005];
int flag=1;

int bfs(int u,int &ans)
{
	first=last=0;
	first1=last1=0;
	int t,v;
	int ret=0;
	int you=1;

	++flag;

	que[last++]=u;
	que1[last1++]=u;
	bfsrem[u]=flag;
	ret=1;

	while(last-first)
	{
		t=que[first++];

		for(int i=head1[t];i!=-1;i=E1[i].next)
			if(bfsrem[E1[i].to]!=flag)
			{
				bfsrem[E1[i].to]=flag;
				que[last++]=E1[i].to;

				if(ru[E1[i].to]==0)
				{
					que1[last1++]=E1[i].to;
					++you;
				}

				++ret;
			}
	}

	ans+=ret;

	if(tuopu(ret,you))
		--ans;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&n,&m);
	init();

	int a,b;

	while(m--)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge1(a,b);
		addEdge1(b,a);
		++ru[b];

		if(!vis[a])
		{
			++remcou;
			vis[a]=1;
		}

		if(!vis[b])
		{
			++remcou;
			vis[b]=1;
		}
	}

	int ans=0;
	int tcou=0,temp;

	for(int i=1;i<=n;++i)
		if(bfsrem[i]==0 && vis[i] && ru[i]==0)
		{
			temp=bfs(i,ans);
			tcou+=temp;
		}

	ans+=remcou-tcou;

	printf("%d\n",ans);
	
	return 0;
}
