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
// Created Time  : 2016年03月19日 星期六 01时31分13秒
// File Name     : D.cpp

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

Edge E[MaxN];
int head[MaxN],Ecou;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int couru,couchu;
int N,M;
int ru[MaxN],chu[MaxN];
set<int> remru;

int que[MaxN],first,last;

bool vis[MaxN];

bool chuli() {
	int t;
	first=last=0;
	que[last++]=*remru.begin();

	while(last-first) {
		t=que[first++];
		remru.erase(t);
		--couru;

		vis[t]=1;

		for(int i=head[t];i!=-1;i=E[i].next) {
			--ru[E[i].to];
			if(ru[E[i].to]==0) {
				remru.insert(E[i].to);
				++couru;
				que[last++]=E[i].to;
			}
		}

		if(couru>1) return 0;
	}
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	init();

	scanf("%d %d",&N,&M);
	couru=couchu=N;
	for(int i=1;i<=N;++i) remru.insert(i);

	for(int i=1;i<=M;++i) {
		scanf("%d %d",&a,&b);
		if(vis[a] || vis[b]) continue;
		addEdge(a,b);
		++chu[a];
		++ru[b];
		if(chu[a]==1) --couchu;
		if(ru[b]==1) {
			remru.erase(b);
			--couru;
		}

		if(couchu==1 && couru==1) {
			if(chuli()) {
				printf("%d\n",i);
				return 0;
			}
		}
	}
	puts("-1");
	
	return 0;
}
