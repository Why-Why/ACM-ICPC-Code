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
// Created Time  : 2016年01月23日 星期六 13时42分39秒
// File Name     : C.cpp

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

const int MaxN=111;
const int MaxM=MaxN*MaxN;

struct Edge {
	int to,next;
	int u;
}E[MaxM];

int N;
int head[MaxN],Ecou;
int DFN[MaxN],LOW[MaxN];
int Index;
int Belong[MaxN],bcou;
bool inStack[MaxN];
int ru[MaxN],chu[MaxN];
int Stack[MaxN],top;

void init() {
	Ecou=Index=bcou=top=0;
	for(int i=1;i<=N;++i) head[i]=-1,Belong[i]=DFN[i]=inStack[i]=ru[i]=chu[i]=0;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].u=u;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void Tarjan(int u) {
	int t;

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
		++bcou;
		do {
			t=Stack[--top];
			inStack[t]=0;
			Belong[t]=bcou;
		}while(t!=u);
	}
}

void getSCC() {
	for(int i=1;i<=N;++i) if(!DFN[i]) Tarjan(i);
}

void getans(int &a1,int &a2) {
	int x,y;
	for(int i=0;i<Ecou;++i) {
		x=Belong[E[i].u];
		y=Belong[E[i].to];
		if(x!=y) {
			++ru[y];
			++chu[x];
		}
	}
	a1=a2=0;
	for(int i=1;i<=bcou;++i) {
		if(ru[i]==0) ++a1;
		if(chu[i]==0) ++a2;
	}
	a2=max(a1,a2);
	if(bcou==1) a2=0;			// !!!!!!!
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;
	while(~scanf("%d",&N)) {
		init();
		for(int i=1;i<=N;++i) while(~scanf("%d",&t) && t) addEdge(i,t);
		getSCC();
		int a1=0,a2=0;
		getans(a1,a2);
		printf("%d\n%d\n",a1,a2);
	}
	
	return 0;
}
