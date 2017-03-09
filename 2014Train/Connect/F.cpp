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
// Created Time  : 2016年01月25日 星期一 18时23分33秒
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

using namespace std;

const int MaxN=1005;

struct Edge {
	int to,next;
}E[MaxN*MaxN];

int head[MaxN],Ecou;
int N;
int LOW[MaxN],DFN[MaxN],Index;
int Stack[MaxN],top;
bool instack[MaxN];

int belong[MaxN],bcou;
bool vis[MaxN];
int ans;

int color[MaxN],cflag=0;

void init() {
	Ecou=Index=top=bcou=0;
	ans=N;
	for(int i=1;i<=N;++i) head[i]=-1,instack[i]=DFN[i]=belong[i]=vis[i]=0;
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int rem[MaxN],rcou;

bool dfs(int u,int col) {
	rem[rcou++]=u;
	color[u]=cflag+col;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(belong[E[i].to]==bcou)
			if(color[E[i].to]>=cflag && color[E[i].to]-cflag==col) return 0;
			else if(color[E[i].to]<cflag && dfs(E[i].to,col^1)==0) return 0;
	return 1;
}

void process() {
	for(int i=0;i<rcou;++i) vis[rem[i]]=1;
}

void Tarjan(int u,int pre) {
	LOW[u]=DFN[u]=++Index;
	Stack[top++]=u;
	instack[u]=1;
	int t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			if(!DFN[E[i].to]) {
				Tarjan(E[i].to,u);
				LOW[u]=min(LOW[u],LOW[E[i].to]);
				if(DFN[u]<=LOW[E[i].to]) {
					++bcou;
					rcou=0;
					do {
						t=Stack[--top];
						rem[rcou++]=t;			// !!!
						belong[t]=bcou;
						instack[t]=0;
					}while(t!=E[i].to);
					belong[u]=bcou;
					rem[rcou++]=u;

					cflag+=2;
					if(!dfs(u,0)) process();
				}
			}
			else if(instack[E[i].to]) LOW[u]=min(LOW[u],DFN[E[i].to]);
}

void getans() {
	for(int i=1;i<=N;++i) if(!DFN[i]) Tarjan(i,i);
}

int map1[MaxN][MaxN],flag=0;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b;
	while(~scanf("%d %d",&N,&M) && N+M) {
		++flag;
		while(M--) {
			scanf("%d %d",&a,&b);
			map1[a][b]=map1[b][a]=flag;
		}

		init();
		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				if(map1[i][j]!=flag) {
					addEdge(i,j);
					addEdge(j,i);
				}
		getans();
		for(int i=1;i<=N;++i) if(vis[i]) --ans;
		printf("%d\n",ans);
	}
	
	return 0;
}
