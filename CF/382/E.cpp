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
// Created Time  : 2016年12月01日 星期四 17时26分31秒
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

const int mod=1000000007;
const int MaxN=105;

long long dp[MaxN][23][23];

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N,K;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,int pre) {
	for(int a=0;a<=K;++a) dp[u][a][K]=1;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			dfs(E[i].to,u);
			for(int a=0;a<=K;++a) (dp[u][a][K]*=dp[E[i].to][K][K])%=mod;
		}

	for(int a=1;a<=K;++a) {
		for(int b=0;b<a;++b) {		// !!!
			dp[u][a][b]=1;
			for(int i=head[u];i!=-1;i=E[i].next)
				if(E[i].to!=pre)
					(dp[u][a][b]*=dp[E[i].to][a-1][b+1])%=mod;
		}

		//(dp[u][a][K]+=dp[u][a][K-1])%=mod;
	}

	for(int a=0;a<=K;++a)
		for(int b=a;b<K;++b)
			dp[u][a][b]=((dp[u][b+1][b]-(b ? dp[u][b+1][b-1] : 0))%mod+mod)%mod;			// !!!


	long long base=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			(base*=dp[E[i].to][0][0])%=mod;

	(dp[u][0][0]+=mod-base)%=mod;

	/*
	for(int b=0;b<K;++b) {
		dp[u][0][b]=1;
		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].to!=pre)
				(dp[u][0][b]*=dp[E[i].to][0][b+1])%=mod;

		dp[u][0][b]=(dp[u][0][b]-base+mod)%mod;
	}
	*/

	for(int a=0;a<=K;++a)
		for(int b=a;b<=K;++b)
			if(b) (dp[u][a][b]+=dp[u][a][b-1])%=mod;

	//(dp[u][0][K]+=dp[u][0][K-1])%=mod;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&K);
	int a,b;

	init();
	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	if(K==0) {
		puts("1");
		return 0;
	}

	dfs(1,-1);

	printf("%d\n",(int)dp[1][0][K]);

	return 0;
}
