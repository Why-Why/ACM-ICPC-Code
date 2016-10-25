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
// Created Time  : 2016年05月06日 星期五 19时31分57秒
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

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const int MaxN=100005;

struct Edge {
	int to,next;
	int type;
	int id;
};

Edge E[MaxN*6];
int head[MaxN],Ecou;
int Evis[MaxN*6];

int N,M;
int ans[MaxN*6];

int inde[MaxN],outde[MaxN];

void init() {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1,inde[i]=outde[i]=0;
}

void addEdge(int u,int v,int t,int i) {
	Evis[Ecou]=0;
	E[Ecou].to=v;
	E[Ecou].type=t;
	E[Ecou].id=i;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void dfs(int u,bool t) {
	bool ok=0;

	while(head[u]!=-1 && Evis[head[u]]) head[u]=E[head[u]].next;
	for(int i=head[u];i!=-1;i=E[i].next) {
		if(Evis[i]) continue;
		else {
			ans[E[i].id]=t^E[i].type;
			Evis[i]=Evis[i^1]=1;
			dfs(E[i].to,t);
			ok=1;
		}
		while(E[i].next!=-1 && Evis[E[i].next]) E[i].next=E[E[i].next].next;

		if(ok) break;
	}
}

int trema[MaxN*6],tremb[MaxN*6];

bool judge() {
	for(int i=1;i<=N;++i) inde[i]=outde[i]=0;
	for(int i=1;i<=M;++i) {
		if(ans[i]==1) ++inde[tremb[i]],++outde[trema[i]];
		else if(ans[i]==0) ++inde[trema[i]],++outde[tremb[i]];
	}

	for(int i=1;i<=N;++i)
		if(abs(inde[i]-outde[i])>1) return 0;
	return 1;
}

void getans(int u) {
	int t;
	if(inde[u]>outde[u]) t=1;
	else t=0;

	while(head[u]!=-1 && Evis[head[u]]) head[u]=E[head[u]].next;
	for(int i=head[u];i!=-1;i=E[i].next) {
		if(Evis[i]) continue;
		else {
			ans[E[i].id]=t^E[i].type;
			if(t) ++outde[u],++inde[E[i].to];
			else ++inde[u],++outde[E[i].to];

			Evis[i]=Evis[i^1]=1;
			dfs(E[i].to,t);
			t^=1;
		}
		while(E[i].next!=-1 && Evis[E[i].next]) E[i].next=E[E[i].next].next;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		init();
		for(int i=1;i<=M;++i) {
			scanf("%d %d",&a,&b);
			if(a==b) ans[i]=1;
			else {
				addEdge(a,b,0,i);
				addEdge(b,a,1,i);
			}

			trema[i]=a;
			tremb[i]=b;
		}
		for(int i=1;i<=N;++i)
			getans(i);

//		if(judge()==0) cerr<<"NO\n";
//		else cerr<<"YES\n";

		for(int i=1;i<=M;++i)
			printf("%d\n",ans[i]);
	}
	
	return 0;
}
