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
// Created Time  : 2016年01月28日 星期四 22时27分16秒
// File Name     : L.cpp

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

const int MaxN=6000;
const int MaxM=1<<22;

struct Edge {
	int u,to,next;
}E[MaxM];

int head[MaxN],Ecou;
int Stack[MaxN],top;
bool inStack[MaxN];
int belong[MaxN],bcou;
int LOW[MaxN],DFN[MaxN],Index;
int N;

void init() {
	Ecou=top=Index=bcou=0;
	for(int i=1;i<=2*N;++i) inStack[i]=DFN[i]=0,head[i]=-1;
}

void addEdge(int u,int v) {
	E[Ecou].u=u;
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void Tarjan(int u) {
	LOW[u]=DFN[u]=++Index;
	Stack[top++]=u;
	inStack[u]=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!DFN[E[i].to]) {
			Tarjan(E[i].to);
			LOW[u]=min(LOW[u],LOW[E[i].to]);
		}
		else if(inStack[E[i].to]) LOW[u]=min(LOW[u],DFN[E[i].to]);
	if(LOW[u]==DFN[u]) {
		int v;
		++bcou;
		do {
			v=Stack[--top];
			inStack[v]=0;
			belong[v]=bcou;
		}while(v!=u);
	}
}

void getSCC() {
	for(int i=1;i<=N;++i) if(!DFN[i]) Tarjan(i);
}

int rem[MaxN];
int rl[MaxN],rr[MaxN];

inline int zhuan(int x) {
	return x>N ? x-N : x;
}

inline void add(int a,int b) {
	addEdge(a,zhuan(b));
	addEdge(b,zhuan(a));
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int K,a,b;
	while(~scanf("%d %d",&K,&N)) {
		init();
		for(int i=1;i<=K;++i) {
			scanf("%d %d",&a,&b);
			rem[a]=b;
			rem[b]=a;
		}
		for(int i=1;i<=N;++i) scanf("%d %d",rl+i,rr+i);
		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j) {
				if(rem[rl[i]]==rl[j]) add(i,j);
				if(rem[rl[i]]==rr[j]) add(i,j+N);
				if(rem[rr[i]]==rl[j]) add(i+N,j);
				if(rem[rr[i]]==rr[j]) add(i+N,j+N);
			}
		getSCC();
		printf("%d\n",getans());
	}
	
	return 0;
}
