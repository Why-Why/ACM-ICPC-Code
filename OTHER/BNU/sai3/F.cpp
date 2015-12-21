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
// Created Time  : 2015年10月04日 星期日 16时28分47秒
// File Name     : F.cpp

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

const int MaxN=10004;

int N,K;

struct POND
{
	double p,a;
}pond[MaxN];

struct Edge
{
	int to,next;
};

Edge E[100005];
int head[MaxN],Ecou;
int du[MaxN];

int X,Z;
double Y;
int tdu[MaxN];

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(du,0,sizeof(du));
	memset(tdu,0,sizeof(tdu));
}

void addEdge(int u,int v)
{
	++du[u];
	++tdu[v];
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int rem[MaxN];

int que[MaxN],first,last;

void tuopu()
{
	int u,cou=0;

	first=last=0;

	for(int i=1;i<=N;++i)
		if(!tdu[i]) que[last++]=i;

	while(last-first)
	{
		u=que[first++];
		rem[++cou]=u;

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			--tdu[E[i].to];
			if(!tdu[E[i].to])
				que[last++]=E[i].to;
		}
	}
}

void getans()
{
	tuopu();

	double t;

	pond[X].a+=Y;
	
	for(int i=1;i<=N;++i)
		if(pond[rem[i]].a>pond[rem[i]].p)
		{
			t=pond[rem[i]].a-pond[rem[i]].p;
			t/=(double)du[rem[i]];
			pond[rem[i]].a=pond[rem[i]].p;

			for(int j=head[rem[i]];j!=-1;j=E[j].next)
				pond[E[j].to].a+=t;
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&K))
	{
		init();
		for(int i=1;i<=N;++i)
			scanf("%lf %lf",&pond[i].p,&pond[i].a);

		for(int i=1;i<=K;++i)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
		}

		scanf("%d %lf %d",&X,&Y,&Z);

		getans();

		printf("%.10f\n",pond[Z].a);
	}
	
	return 0;
}
