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
// Created Time  : 2016年01月28日 星期四 16时41分41秒
// File Name     : K.cpp

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

const int MaxN=1005;
const int MaxM=4000006;

struct Edge {
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int Stack[MaxN],top;
int belong[MaxN],bcou;
int Index,DFN[MaxN],LOW[MaxN];
bool inStack[MaxN];
int N;

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

void init() {
	Ecou=top=bcou=Index=0;
	for(int i=1;i<=2*N;++i) inStack[i]=DFN[i]=0,head[i]=-1;
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

	int v;
	if(LOW[u]==DFN[u]) {
		++bcou;
		do {
			v=Stack[--top];
			inStack[v]=0;
			belong[v]=bcou;
		}while(v!=u);
	}
}

void getSCC() {
	for(int i=1;i<=2*N;++i) if(!DFN[i]) Tarjan(i);
}

inline int zhuan(int a) {
	return a>N ? a-N : a+N;
}

inline void add(int a,int b) {
	addEdge(a,zhuan(b));
	addEdge(b,zhuan(a));
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[10];
	int a,b,c,M;

	while(~scanf("%d %d",&N,&M)) {
		init();
		while(M--) {
			scanf("%d %d %d %s",&a,&b,&c,s);
			++a; ++b;
			if(s[0]=='A') {
				if(c) add(a,b),add(a,b+N),add(a+N,b);
				else add(a+N,b+N);
			}
			else if(s[0]=='X') {
				if(c) add(a,b),add(a+N,b+N);
				else add(a,b+N),add(a+N,b);
			}
			else {
				if(c) add(a,b);
				else add(a+N,b+N),add(a,b+N),add(a+N,b);
			}
		}
		getSCC();
		
		bool ok=1;
		for(int i=1;i<=N;++i) if(belong[i]==belong[i+N]) { ok=0; break; }
		if(ok) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
