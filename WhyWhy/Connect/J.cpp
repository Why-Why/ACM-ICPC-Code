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
// Created Time  : 2016年01月28日 星期四 16时09分29秒
// File Name     : J.cpp

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

const int MaxN=2005;
const int MaxM=200005;

struct Edge {
	int u,to,next;
	int num;
}E[MaxM],E1[MaxM];

int head[MaxN],head1[MaxN],Ecou,E1cou;
int N;
int sortrem[MaxN],Index;
bool vis[MaxN];
int belong[MaxN],bcou;

void init() {
	Ecou=E1cou=Index=bcou=0;
	for(int i=1;i<=N;++i) vis[i]=belong[i]=0,head[i]=head1[i]=-1;
}

void addEdge(int u,int v,int n) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].u=u;
	E[Ecou].num=n;
	head[u]=Ecou++;

	E1[E1cou].to=u;
	E1[E1cou].next=head1[v];
	head1[v]=E1cou++;
}

void dfs1(int u) {
	vis[u]=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to]) dfs1(E[i].to);
	sortrem[++Index]=u;
}

void dfs2(int u) {
	belong[u]=bcou;
	for(int i=head1[u];i!=-1;i=E1[i].next)
		if(!belong[E1[i].to]) dfs2(E1[i].to);
}

void getSCC() {
	for(int i=1;i<=N;++i) if(!vis[i]) dfs1(i);
	for(int i=N;i>=1;--i) if(!belong[sortrem[i]]) { ++bcou; dfs2(sortrem[i]); }
}

int ans[MaxN][MaxN],acou[MaxN];
int fan[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	while(~scanf("%d",&N)) {
		init();
		for(int i=1;i<=N;++i) {
			scanf("%d",acou+i);
			for(int j=1;j<=acou[i];++j)
				scanf("%d",&ans[i][j]);
		}
		for(int i=1;i<=N;++i) {
			scanf("%d",&a);
			fan[a]=i;
			for(int j=1;j<=acou[i];++j)
				if(ans[i][j]!=a) addEdge(a,ans[i][j],ans[i][j]);
			acou[i]=1;
			ans[i][0]=a;
		}
		getSCC();

		for(int i=0;i<Ecou;++i)
			if(belong[E[i].u]==belong[E[i].to])
				ans[fan[E[i].u]][acou[fan[E[i].u]]++]=E[i].num;
		for(int i=1;i<=N;++i) {
			sort(ans[i],ans[i]+acou[i]);
			//acou[i]=unique(ans[i],ans[i]+acou[i])-ans[i];
			printf("%d",acou[i]);
			for(int j=0;j<acou[i];++j) printf(" %d",ans[i][j]);
			puts("");
		}
	}
	
	return 0;
}
