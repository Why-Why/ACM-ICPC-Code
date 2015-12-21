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
// Created Time  : 2015年09月06日 星期日 22时18分11秒
// File Name     : C.cpp

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

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N;
bool neibu[MaxN];
bool one[MaxN];

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool dfs(int u,int pre)
{
	int v;
	int cou=0;
	bool ok=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			v=E[i].to;

			if(dfs(v,u)==0)
				ok=0;

			++cou;
		}

	cout<<u<<' '<<pre<<' '<<cou<<endl;

	neibu[u]=0;
	if(cou<=2 && ok)
		neibu[u]=1;

	if(cou>=2)
		ok=0;

	one[u]=ok;

	return ok;
}

bool judge(int u,int pre,int xian)
{
	int v;
	int cou=0;
	int cou1=0;
	int zong=0;

	if(xian==2)
		return neibu[u];

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			v=E[i].to;
			++zong;

			if(neibu[v])
				++cou;

			if(one[v])
				++cou1;
		}

	int t;

	if(xian==1)
	{
		t=0;
		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].to!=pre && neibu[E[i].to]==0)
			{
				if(judge(E[i].to,u,1)==0)
					return 0;

				++t;
			}

		if(t>1)
			return 0;
	}
	else
	{
		if(cou!=cou1 || cou1>2) //|| (cou1==cou && cou1==1) || (cou1==cou && cou1==2))
			t=1;
		else
			t=0;

		int tcou=0;
		int tcou1=0;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].to!=pre && neibu[E[i].to]==0)
			{
				if(judge(E[i].to,u,0)==0)
					return 0;
				if(judge(E[i].to,u,1)==0)
					++tcou1;

				++tcou;
			}

		cout<<u<<' '<<tcou<<' '<<tcou1<<' '<<cou<<' '<<cou1<<endl;

		if(tcou>2)
			return 0;

		if(t==1 && tcou1)
			return 0;

		if(t==0 && tcou1>1)
			return 0;

		if(t==0 && tcou1 && tcou-tcou1)
			return 0;
	}

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d",&N);

	init();

	for(int i=1;i<N;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	dfs(1,-1);

	printf("%s\n",judge(1,-1,0) ? "Yes" : "No");

	return 0;
}
