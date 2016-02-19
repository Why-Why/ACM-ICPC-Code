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
// Created Time  : 2015年12月25日 星期五 21时31分21秒
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

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int MaxN=100005;
const int mod=1000000007;
const int INF=0x3f3f3f3f;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N;

bool vis[MaxN];

long long mi[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));

	mi[0]=1;
	for(int i=1;i<MaxN;++i)
		mi[i]=(mi[i-1]*2)%mod;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

long long inv(long long a,long long m)
{
	if(a == 1)return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

/////////////////////////

int sumnode,minnC,cen;
int maxson[MaxN],couson[MaxN];

void dfs1(int u,int pre) {
	maxson[u]=0;
	couson[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre) {
			dfs1(E[i].to,u);
			maxson[u]=max(maxson[u],couson[E[i].to]);
			couson[u]+=couson[E[i].to];
		}
}

void dfs2(int u,int pre) {
	int maxn=max(maxson[u],sumnode-couson[u]);
	if(maxn<minnC) {
		minnC=maxn;
		cen=u;
	}

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfs2(E[i].to,u);
}

int getCenter(int u) {
	minnC=INF;
	sumnode=couson[u];
	dfs2(u,-1);
	return cen;
}

/////////////////////////

long long tsum;

void dfs(int u,int pre,int d) {
	++d;
	(tsum+=mi[sumnode-1-d])%=mod;
	
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfs(E[i].to,u,d);
}

long long calc(int u) {
	long long sum=0,sum2=0,ret=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {
			tsum=0;
			dfs(E[i].to,u,0);

			//for(int i=0;i<tcou;++i)
			//	(tsum+=mi[sumnode-1-rem[i]])%=mod;

			(ret+=tsum)%=mod;

			(sum+=tsum)%=mod;
			(sum2+=(tsum*tsum)%mod)%=mod;
		}

	sum=(sum*sum)%mod;
	sum=((sum-sum2)%mod+mod)%mod;
	sum=(sum*inv(mi[sumnode],mod))%mod;
	(ret+=sum)%=mod;

	return ret;
}

/////////////////////////

long long solve(int u) {
	int c=getCenter(u);
	long long sum=0,t;
	int ttt,zzz=sumnode;
	vis[c]=1;
	t=calc(c);

	for(int i=head[c];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) {
			dfs1(E[i].to,c);
			ttt=couson[E[i].to];
			(sum+=(mi[zzz-ttt]*solve(E[i].to))%mod)%=mod;
		}
	(sum+=t)%=mod;
	return sum;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	scanf("%d",&N);
	init();
	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	dfs1(1,-1);
	printf("%d\n",(int)solve(1));

	return 0;
}
