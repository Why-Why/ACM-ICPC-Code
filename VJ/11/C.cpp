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

const int MaxN=400;
const int MaxM=160000;
const int INF=10e8;

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int cur[MaxN],gap[MaxN],dis[MaxN],pre[MaxN];
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
		dis[i]=0;
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

void update(int remm)
{
	for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
	{
		E[i].flow+=remm;
		E[i^1].flow-=remm;
	}
}

int SAP(int N)
{
	for(int i=1;i<=N;++i)
		cur[i]=head[i];

	int u,v,ret=0,remm=INF,mindis;

	pre[S]=-1;
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
				pre[v]=i;
				cur[u]=i;
				u=v;

				if(u==T)
				{
					for(int i=pre[u];i!=-1;i=pre[E[i^1].to])
						remm=min(remm,E[i].cap-E[i].flow);

					ret+=remm;
					update(remm);

					u=S;
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
			u=E[pre[u]^1].to;
	}

	return ret;
}

char ns[110][30],ms1[110][30],ms2[110][30],ks1[110][30],ks2[110][30];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M,K;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%s",ns[i]);

	scanf("%d",&M);

	for(int i=1;i<=M;++i)
		scanf("%s %s",ms1[i],ms2[i]);

	scanf("%d",&K);

	for(int i=1;i<=K;++i)
		scanf("%s %s",ks1[i],ks2[i]);

	init(N+M+K+2,N+M+K+1,N+M+K+2);

	for(int i=1;i<=N;++i)
		addEdge(N+M+K+1,i,1);

	for(int i=1;i<=M;++i)
		addEdge(N+i,N+M+K+2,1);

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(strcmp(ms2[j],ns[i])==0)
				addEdge(i,N+j,1);

	for(int i=1;i<=N;++i)
		for(int j=1;j<=K;++j)
			if(strcmp(ns[i],ks2[j])==0)
				addEdge(i,N+M+j,1);

	for(int i=1;i<=K;++i)
		for(int j=1;j<=K;++j)
			if(i!=j && strcmp(ks1[i],ks2[j])==0)
				addEdge(N+M+i,N+M+j,1);

	for(int i=1;i<=K;++i)
		for(int j=1;j<=M;++j)
			if(strcmp(ks1[i],ms2[j])==0)
				addEdge(N+M+i,N+j,1);

	printf("%d\n",M-SAP(N+M+K+2));
	
	return 0;
}
