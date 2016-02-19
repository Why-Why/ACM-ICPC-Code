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
// Created Time  : 2016年01月29日 星期五 15时29分16秒
// File Name     : L_1.cpp

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
const int MaxM=2000000;

struct Edge {
	int to,next;
}E[MaxM];

int head[MaxN],Ecou;
int LOW[MaxN],DFN[MaxN],Index;
int Stack[MaxN],top;
bool inStack[MaxN];
int belong[MaxN],bcou;
int N;

void init() {
	Ecou=Index=top=bcou=0;
	for(int i=1;i<=(N<<1);++i) head[i]=-1,DFN[i]=inStack[i]=0;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void Tarjan(int u) {
	DFN[u]=LOW[u]=++Index;
	Stack[top++]=u;
	inStack[u]=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!DFN[E[i].to]) {
			Tarjan(E[i].to);
			LOW[u]=min(LOW[u],LOW[E[i].to]);
		}
		else if(inStack[E[i].to]) LOW[u]=min(LOW[u],DFN[E[i].to]);

	if(DFN[u]==LOW[u]) {
		++bcou;
		int v;
		do {
			v=Stack[--top];
			inStack[v]=0;
			belong[v]=bcou;
		}while(v!=u);
	}
}

inline void getSCC() {
	for(int i=1;i<=(N<<1);++i) if(!DFN[i]) Tarjan(i);
}

int fan[MaxN];
int rl[MaxN],rr[MaxN];

inline int zhuan(int x) {
	return x<=N ? x+N : x-N;
}

inline void add(int a,int b) {
	addEdge(a,zhuan(b));
	addEdge(b,zhuan(a));
}

inline bool judge(int M) {
	init(); 
	for(int i=1;i<=M;++i) add(zhuan(fan[rl[i]]),zhuan(fan[rr[i]]));
	getSCC();
	for(int i=1;i<=N;++i) if(belong[i]==belong[i+N]) return 0;
	return 1;
}

int getans(int L,int R) {
	int M;
	while(R>L) {
		M=(L+R+1)>>1;
		if(judge(M)) L=M;
		else R=M-1;
	}
	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b;

	while(~scanf("%d %d",&N,&M) && N+M) {
		for(int i=1;i<=N;++i) {
			scanf("%d %d",&a,&b);
			fan[a]=i;
			fan[b]=i+N;
		}
		for(int i=1;i<=M;++i) scanf("%d %d",rl+i,rr+i);
		printf("%d\n",getans(0,M));
	}
	
	return 0;
}
