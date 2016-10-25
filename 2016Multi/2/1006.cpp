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
// Created Time  : 2016年07月22日 星期五 14时19分22秒
// File Name     : 1006.cpp

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
const int MaxM=200005<<1;
const int mod=1000000007;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int LOW[MaxN],DFN[MaxN];
bool cutp[MaxN];
int add_block[MaxN];
int Index;

int N,M;

long long sum,bans;
long long ans[MaxN];
long long w[MaxN];

inline void add(long long & a,long long b) {
	a+=b; if(a>=mod) a-=mod;
}

inline void del(long long & a,long long b) {
	a-=b; if(a<0) a+=mod;
}

long long inv(long long a,long long m) {
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

long long Tarjan(int u,int pre) {
	int v;
	int couSon=0;
	long long tsum=0,tmul=w[u],t,ret=w[u],t0=0;

	LOW[u]=DFN[u]=++Index;

	for(int i=head[u];i!=-1;i=E[i].next) {
		v=E[i].to;
		if(v==pre) continue;

		if(!DFN[v]) {
			t=Tarjan(v,u);
			++couSon;
			add(t0,t);

			(ret*=t)%=mod;

			if(LOW[v]<LOW[u]) LOW[u]=LOW[v];

			if(u!=pre && DFN[u]<=LOW[v]) {
				cutp[u]=1;

				(tmul*=t)%=mod;
				add(tsum,t);
				//++add_block[u];
			}
		}
		else if(DFN[v]<LOW[u])
			LOW[u]=DFN[v];
	}

	if(u==pre && couSon>1) {
		cutp[u]=1;
		add_block[u]=couSon-1;
	}

	ans[u]=bans;
	if(u==pre) add(ans[u],t0);
	else add(ans[u],(tsum+sum*inv(tmul,mod)%mod)%mod);

	return ret;
}

long long dsum[MaxN],dans;
int belong[MaxN],bcou;
bool vis[MaxN];

long long dfs(int u) {
	long long ret=w[u];

	belong[u]=bcou;
	vis[u]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to])
			(ret*=dfs(E[i].to))%=mod;

	return ret;
}

void getCUTP(int n) {
	bcou=0;
	dans=0;
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=1;i<=n;++i)
		if(!vis[i]) {
			dsum[bcou]=dfs(i);
			add(dans,dsum[bcou]);
			++bcou;
		}

	for(int i=1;i<=n;++i)
		if(!DFN[i]) {
			sum=dsum[belong[i]];
			bans=dans;
			del(bans,dsum[belong[i]]);

			Tarjan(i,i);
		}
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void init(int n) {
	Ecou=Index=0;

	for(int i=1;i<=n;++i) {
		head[i]=-1;
		cutp[i]=DFN[i]=add_block[i]=0;
	}
}

inline int read() {
	char c=0;
	int ret=0;

	while(c<'0' || c>'9') c=getchar();
	ret=c-'0';
	while(c=getchar(),c>='0' && c<='9')
		ret=ret*10+c-'0';

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a,b;
	T=read();

	while(T--) {
		N=read();
		M=read();
		sum=1;
		for(int i=1;i<=N;++i) w[i]=read(),(sum*=w[i])%=mod,ans[i]=0;

		init(N);
		while(M--) {
			a=read();
			b=read();
			addEdge(a,b);
			addEdge(b,a);
		}

		getCUTP(N);

		long long zans=0;
		for(int i=1;i<=N;++i) add(zans,i*ans[i]%mod);
		printf("%d\n",(int)zans);
	}

	return 0;
}
