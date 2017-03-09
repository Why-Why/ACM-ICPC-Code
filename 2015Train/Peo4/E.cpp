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
// Created Time  : 2015年11月29日 星期日 14时51分43秒
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

const int MaxN=1011;
const int MaxM=500*500+2+11;

struct Edge {
	int to,next;
}E[MaxM];

int head[MaxN],Ecou;
int N;
int NN;
char map1[505][505];

int du[MaxN];
bool inque[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(du,0,sizeof(du));
	memset(inque,0,sizeof(inque));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	++du[v];
	head[u]=Ecou++;
}

bool rem[MaxN];

inline bool judgeH(int h) {
	for(int i=1;i<=N;++i)
		if(map1[h][i]=='X') return 0;
	return 1;
}

inline bool judgeL(int l) {
	for(int i=1;i<=N;++i)
		if(map1[i][l]=='O') return 0;
	return 1;
}

inline void show(int x) {
	if(x<=N) printf("C%d",x);
	else printf("R%d",x-N);
}

int cou;
int ans[MaxN];

priority_queue <int,vector<int>,greater<int> > que;

bool getans() {
	cou=0;
	while(!que.empty()) que.pop();
	int t;
	int tcou=0;
	
	for(int i=1;i<=NN;++i)
		if(du[i]==0) que.push(i),inque[i]=1;

	while(!que.empty()) {
		t=que.top();
		que.pop();
		++tcou;
		if(rem[t]==0) ans[cou++]=t;
		for(int i=head[t];i!=-1;i=E[i].next) {
			--du[E[i].to];
			if(du[E[i].to]==0 && inque[E[i].to]==0)
				inque[E[i].to]=1,que.push(E[i].to);
		}
	}

	return tcou==NN;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		init();
		for(int i=1;i<=N;++i) {
			scanf("%s",map1[i]+1);
			for(int j=1;j<=N;++j)
				if(map1[i][j]=='X') addEdge(j,N+i);
				else addEdge(N+i,j);
		}
		NN=N+N;
		memset(rem,0,sizeof(rem));
		for(int i=1;i<=N;++i) if(judgeH(i)) rem[N+i]=1;
		for(int i=1;i<=N;++i) if(judgeL(i)) rem[i]=1;

		if(getans()) {
			show(ans[0]);
			for(int i=1;i<cou;++i) {
				putchar(' ');
				show(ans[i]);
			}
			puts("");
		}
		else 
			puts("No solution");
	}
	
	return 0;
}
