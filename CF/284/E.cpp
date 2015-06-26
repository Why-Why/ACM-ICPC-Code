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
// Created Time  : 2015年05月21日 星期四 23时24分36秒
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

using namespace std;

const int MaxN=10015;
const int MaxM=300105;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int gap[MaxN],dis[MaxN],cur[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		gap[i]=0;
		dis[i]=-1;
	}
}

void addEdge(int u,int v,int c,int rc=0)
{
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=rc;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

int que[MaxN],front,last;

void BFS()
{
	int u,v;

	gap[0]=1;
	dis[T]=0;
	front=last=0;
	que[last++]=T;

	while(front!=last)
	{
		u=que[front++];

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(dis[v]!=-1)
				continue;

			dis[v]=dis[u]+1;
			++gap[dis[v]];
			que[last++]=v;
		}
	}
}

int stack[MaxN],top;

inline void update(int remm)
{
	for(int i=0;i<top;++i)
	{
		E[stack[i]].flow+=remm;
		E[stack[i]^1].flow-=remm;
	}
}

int SAP(int N)
{
	BFS();

	for(int i=1;i<=N;++i)
		cur[i]=head[i];

	int u,v,ret=0,remm=INF,mindis,inser;

	top=0;
	u=S;
	gap[0]=N;

	while(dis[S]<N)
	{
loop:
		for(int i=cur[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(E[i].cap-E[i].flow && dis[u]==dis[v]+1)
			{
				cur[u]=i;
				stack[top++]=i;
				u=v;

				if(u==T)
				{
					for(int i=0;i<top;++i)
						if(remm>E[stack[i]].cap-E[stack[i]].flow)
						{
							remm=E[stack[i]].cap-E[stack[i]].flow;
							inser=i;
						}

					ret+=remm;
					update(remm);
					top=inser;
					u=E[stack[top]^1].to;
					remm=INF;
				}

				goto loop;
			}
		}

		mindis=N-1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].cap-E[i].flow && mindis>dis[E[i].to])
			{
				cur[u]=i;
				mindis=dis[E[i].to];
			}

		if(--gap[dis[u]]==0)
			break;

		dis[u]=mindis+1;
		++gap[dis[u]];

		if(u!=S)
			u=E[stack[--top]^1].to;
	}

	return ret;
}

bool vis[100005];
int prime[10000],pcou;
int remi[110],remj[110];
int zongdian[110];

struct number
{
	int pri[12],cou[12];
	int zong;
};

number num[110];

inline void chuli(int id,int x)
{
	int p=0;
	int cou;

	num[id].zong=0;

	while(x!=1 && p<pcou)
	{
		cou=0;
		while(x%prime[p]==0)
		{
			x/=prime[p];
			++cou;
		}

		if(cou)
		{
			num[id].pri[num[id].zong]=prime[p];
			num[id].cou[num[id].zong++]=cou;
		}

		++p;
	}

	if(p==pcou && x!=1)
	{
		num[id].pri[num[id].zong]=x;
		num[id].cou[num[id].zong++]=1;
	}

	zongdian[id]=zongdian[id-1]+num[id].zong;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;

	for(int i=2;i<=100000;++i)
		if(!vis[i])
		{
			prime[pcou++]=i;
		
			for(int j=i+i;j<=100000;j+=i)
				vis[j]=1;
		}

	int n,m;
	int a,b;
	int zong;

	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;++i)
	{
		scanf("%d",&t);
		chuli(i,t);
	}

	zong=zongdian[n];

	init(zong+2,zong+1,zong+2);

	for(int i=1;i<=n;i+=2)
		for(int j=0;j<num[i].zong;++j)
			addEdge(zong+1,zongdian[i-1]+j+1,num[i].cou[j]);

	for(int i=2;i<=n;i+=2)
		for(int j=0;j<num[i].zong;++j)
			addEdge(zongdian[i-1]+j+1,zong+2,num[i].cou[j]);

	while(m--)
	{
		scanf("%d %d",&a,&b);

		if(b&1)
			swap(a,b);

		for(int i=0;i<num[a].zong;++i)
			for(int j=0;j<num[b].zong;++j)
				if(num[a].pri[i]==num[b].pri[j])
					addEdge(zongdian[a-1]+i+1,zongdian[b-1]+j+1,min(num[a].cou[i],num[b].cou[j]));
	}

	printf("%d\n",SAP(zong+2));
	
	return 0;
}
