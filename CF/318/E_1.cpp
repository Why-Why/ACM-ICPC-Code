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
// Created Time  : 2015年09月07日 星期一 21时29分09秒
// File Name     : C_1.cpp

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

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool line[MaxN],dan[MaxN];
bool zhi[MaxN];

bool dfs(int u,int pre,bool ttt)
{
	zhi[u]=ttt;

	bool ok=1;
	int cou=0;
	int zong=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			++zong;

	if(zong>1)
		ttt=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			if(dfs(E[i].to,u,ttt)==0)
				ok=0;
			++cou;
		}

	if(ok && cou<=2)
		line[u]=1;
	else line[u]=0;

	if(cou>1)
		ok=0;

	dan[u]=ok;

	return ok;
}

bool judge(int u,int pre,int xian)
{
	int v;
	int cou0=0,cou1=0,cou2=0,cou3=0,cou=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			v=E[i].to;
			++cou;
			if(line[v])
				++cou2;
			if(dan[v])
				++cou3;

		}

	if(pre!=-1 && zhi[pre]==0)
		xian=1;
	
	if(xian==1)
	{
		if(cou-cou2>1)
			return 0;

		if(cou-cou2==0)
			return 1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].to!=pre && line[E[i].to]==0)
				if(judge(v,u,1)==0)
					return 0;
	}
	else
	{
		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].to!=pre)
			{
				v=E[i].to;

				if(judge(v,u,0)==0)
					return 0;
				else ++cou0;
                
				if(judge(v,u,1))
					++cou1;
			}

	//	cout<<"# "<<u<<' '<<cou<<' '<<cou0<<' '<<cou1<<' '<<cou2<<' '<<cou3<<endl;

		if(cou0-cou1>=2)
			return 0;
		if(cou0-cou1==1)
		{
			if(cou1-cou2)
				return 0;

			if(cou2-cou3)
				return 0;

			if(cou3>2)
				return 0;
		}
		if(cou0-cou1==0)
		{
			if(cou1-cou2>2)
				return 0;
		}
	}

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int a,b;

	scanf("%d",&N);
	init();

	for(int i=1;i<N;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	dfs(1,-1,1);

	printf("%s\n",judge(1,-1,0) ? "Yes" : "No");
	
	return 0;
}
