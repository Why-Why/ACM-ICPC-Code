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
// Created Time  : 2015年12月22日 星期二 21时10分28秒
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

const int MaxN=300005;
const int mod=1000000007;

struct Edge {
	int to,next;
}E[MaxN<<1];

int head[MaxN],Ecou;
int N;
int num[MaxN<<1],first[MaxN],last[MaxN],cou;
int dis[MaxN];

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
	dis[u]=dis[pre]+1;
	first[u]=++cou;
	num[cou]=u;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			dfs(E[i].to,u);

	last[u]=++cou;
	num[cou]=u;
}

long long C1[MaxN<<1],C2[MaxN<<1];

inline int lowbit(int x) {
	return x&(-x);
}

void add(int p,int t,long long C[]) {
	for(;p<=cou;p+=lowbit(p)) (C[p]+=t)%=mod;
}

void update(int L,int R,long long x,long long k,long long d) {
	int t=(x+(d*k)%mod)%mod;
	add(L,t,C1);
	add(R+1,-t,C1);

	add(L,k,C2);
	add(R+1,-k,C2);
}

int query(int p) {
	long long ret1=0,ret2=0;
	long long d=dis[num[p]];
	for(;p;p-=lowbit(p)) {
		(ret1+=C1[p])%=mod;
		(ret2+=C2[p])%=mod;
	}

	return ((ret1-(ret2*d)%mod)%mod+mod)%mod;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d;

	scanf("%d",&N);
	init();

	for(int i=2;i<=N;++i) {
		scanf("%d",&a);
		addEdge(i,a);
		addEdge(a,i);
	}
	cou=0;
	dis[0]=0;
	dfs(1,0);

	int Q;
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d",&a);
		if(a==1) {
			scanf("%d %d %d",&b,&c,&d);
			update(first[b],last[b],c,d,dis[b]);
		}
		else {
			scanf("%d",&b);
			printf("%d\n",query(first[b]));
		}
	}
	
	return 0;
}
