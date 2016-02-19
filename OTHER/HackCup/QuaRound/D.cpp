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
// Created Time  : 2016年01月11日 星期一 19时11分21秒
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

const int MaxN=305*3;
const int INF=0x3f3f3f3f;
const int MaxM=800000;

struct Edge
{
	int to,next,cap,flow,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int pre[MaxN],couNode[MaxN],lowcost[MaxN];
bool vis[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	Ecou=0;
	S=_S;
	T=_T;

	for(int i=1;i<=N;++i)
		head[i]=-1;
}

void addEdge(int u,int v,int cap,int cost)
{
	cout<<u<<' '<<v<<' '<<cap<<' '<<cost<<endl;

	E[Ecou].to=v;
	E[Ecou].cap=cap;
	E[Ecou].cost=cost;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
	E[Ecou].to=u;
	E[Ecou].cap=0;
	E[Ecou].cost=-cost;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

bool SPFA(int N)
{
	queue <int> que;
	int u,v,c;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
		pre[i]=-1;
	}
	vis[S]=1;
	lowcost[S]=0;
	couNode[S]=1;

	que.push(S);

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		vis[u]=0;
		
		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			c=E[i].cost;

			if(E[i].cap>E[i].flow && lowcost[v]>lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;
				pre[v]=i;

				if(!vis[v])
				{
					vis[v]=1;
					++couNode[v];
					que.push(v);

					if(couNode[v]>N)
						return 0;
				}
			}
		}
	}

	if(pre[T]==-1)
		return 0;
	return 1;
}

void update(int remm,int &minCost)
{
	for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
	{
		E[i].flow+=remm;
		E[i^1].flow-=remm;
		minCost+=E[i].cost*remm;
	}
}

int MinCostMaxFlow(int N,int &minCost)		//返回最大流，minCost是在最大流时的最小费用。
{
	int ret=0,remm;
	minCost=0;

	while(SPFA(N))
	{
		remm=INF;

		for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
			remm=min(remm,E[i].cap-E[i].flow);
		update(remm,minCost);
		ret+=remm;
	}

	return ret;
}

int N,K;
string s[MaxN];

int getnum(int a,int b) {
	int i,len=min(s[a].length(),s[b].length());
	for(i=0;i<len;++i)
		if(s[a][i]!=s[b][i]) break;
	return s[a].length()+s[b].length()-i-i;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	int T,cas=1;
	cin>>T;
	while(T--) {
		cin>>N>>K;
		init(2*N+3,2*N+1,2*N+3);
		addEdge(2*N+2,2*N+3,K,0);
		for(int i=1;i<=N;++i) {
			cin>>s[i];
			addEdge(i,i+N,1,0);
			addEdge(2*N+1,i,1,s[i].length());
			addEdge(i+N,2*N+2,1,s[i].length());
		}
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(i!=j) addEdge(i+N,j,1,getnum(i,j));

		int ans;
		MinCostMaxFlow(2*N+3,ans);
		cout<<"Case #"<<cas++<<": "<<ans+K<<endl;
	}
	
	return 0;
}
