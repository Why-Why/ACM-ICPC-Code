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
// Created Time  : 2016年08月16日 星期二 14时30分43秒
// File Name     : 1012.cpp

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

const int MaxN=410;
const int MaxM=1510;
const int INF=10e8;

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int Ecou;
int head[MaxN];
int gap[MaxN],dis[MaxN],pre[MaxN],cur[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		gap[i]=dis[i]=0;
	}
}

void addEdge(int u,int v,int c,int rc=0)		// 单向边三个参数，双向边四个。
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
	int u=T;

	while(u!=S)
	{
		E[pre[u]].flow+=remm;
		E[pre[u]^1].flow-=remm;

		u=E[pre[u]^1].to;
	}
}

int SAP(int N)
{
	for(int i=1;i<=N;++i)
		cur[i]=head[i];				/////

	int u,v,ret=0,remm=INF,mindis;
	
	u=S;
	pre[S]=-1;
	gap[0]=N;

	while(dis[S]<N)
	{
		loop:
		for(int i=cur[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(E[i].cap-E[i].flow && dis[u]==dis[v]+1)	//!!!
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
					u=S;				// ???
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

struct State {
	int id,t;

	bool operator < (const State &b) const {
		return t<b.t;
	}

}sta[205];

int N,M,L;
vector<int> rem[205];
int pay[205];

int rrb[205],rra[205];

int pro[205],k[205];
int sum;

inline void change(int p) {
	E[rra[p]].cap=pay[p];

	int len=rem[p].size();
	for(int i=0;i<len;++i) {
		--k[rem[p][i]];
		if(k[rem[p][i]]==0) {
			E[rrb[rem[p][i]]].cap=pro[rem[p][i]];
			sum+=pro[rem[p][i]];
		}
	}
}

int judge(int p) {
	for(int i=0;i<Ecou;++i) E[i].flow=0;
	for(int i=1;i<=p;++i) E[rra[i]].cap=pay[i];
	for(int i=p+1;i<=N;++i) E[rra[i]].cap=INF;

	return sum-SAP(N+M+2);
}

bool getans() {
	int L=1,R=N,mid;

	while(R>L) {
		mid=(L+R)>>1;
		if(judge(mid)>=::L) R=mid;
		else L=mid+1;
	}

	int t=judge(L);
	if(t>=::L) {
		printf("%d %d\n",sta[L].t,t);
		return 1;
	}

	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1,a;
	scanf("%d",&T);

	while(T--) {
		sum=0;
		scanf("%d %d %d",&N,&M,&L);
		init(N+M+2,N+M+1,N+M+2);
		for(int i=1;i<=N;++i) {
			scanf("%d %d",pay+i,&sta[i].t);
			sta[i].id=i;

			rra[i]=Ecou;
			addEdge(M+i,N+M+2,0);
		}
		sort(sta+1,sta+N+1);

		for(int i=1;i<=M;++i) {
			scanf("%d",pro+i);
			scanf("%d",k+i);
			for(int j=0;j<k[i];++j) {
				scanf("%d",&a);

				addEdge(i,M+a,INF);
			}

			rrb[i]=Ecou;
			addEdge(N+M+1,i,pro[i]);
			sum+=pro[i];
		}

		printf("Case #%d: ",cas++);
		if(!getans()) puts("impossible");
	}

	return 0;
}
