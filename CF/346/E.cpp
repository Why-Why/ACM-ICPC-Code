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
// Created Time  : 2016年03月31日 星期四 22时44分17秒
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

const int MaxN=100005;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
int Ecou,head[MaxN];
int N,M;
bool vis[MaxN];
bool visE[MaxN<<1];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool bfs(int u) {
	queue <int> que;
	int temp;
	int cou=0,ccou=0;

	que.push(u);
	vis[u]=1;

	while(!que.empty()) {
		temp=que.front();
		que.pop();
		++ccou;

		for(int i=head[temp];i!=-1;i=E[i].next) {
			if(!visE[i]) ++cou,visE[i]=visE[i^1]=1;

			if(!vis[E[i].to]) {
				que.push(E[i].to);
				vis[E[i].to]=1;
			}
		}
	}

	return cou==ccou-1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&N,&M);
	init();
	while(M--) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	int ans=0;
	for(int i=1;i<=N;++i)
		if(!vis[i])
			if(bfs(i)) ++ans;
	printf("%d\n",ans);
	
	return 0;
}
