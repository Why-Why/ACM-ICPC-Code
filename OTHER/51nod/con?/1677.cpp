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
// Created Time  : 2016年12月06日 星期二 00时53分58秒
// File Name     : 1677.cpp

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

const int mod=1000000007;

long long C[MaxN];
long long ans=0;

long long inv(long long a,long long m) {
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

int dfs(int u,int pre) {
	int ret=1,t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			t=dfs(E[i].to,u);
			ans=(ans+C[N]+mod-C[t]+mod-C[N-t])%mod;
			ret+=t;
		}

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&N,&K);

	C[K]=1;
	for(int i=K;i<N;++i) C[i+1]=C[i]*(i+1)%mod*inv(i+1-K,mod)%mod;

	init();
	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	dfs(1,-1);

	printf("%d\n",(int)ans);

	return 0;
}
