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
// Created Time  : 2016年11月11日 星期五 17时59分15秒
// File Name     : A.cpp

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
const int MaxM=20004;

struct Edge {
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int belong[MaxN],vis[MaxN];
int N;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
	memset(belong,0,sizeof(belong));
	memset(vis,0,sizeof(vis));
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int que[MaxN],first,last;
int rema[MaxN],coua,remb[MaxN],coub;

inline bool bfs(int u) {
	first=last=0;
	que[last++]=u;
	vis[u]=1;

	coua=coub=0;
	rema[coua++]=u;

	while(last-first) {
		u=que[first++];
		for(int i=head[u];i!=-1;i=E[i].next) {
			if(vis[E[i].to]==0) {
				vis[E[i].to]=-vis[u];
				if(vis[E[i].to]==1) rema[coua++]=E[i].to;
				else remb[coub++]=E[i].to;

				que[last++]=E[i].to;
			}
			else if(vis[E[i].to]==vis[u]) return 0;
		}
	}

	if(coua+coub==1) {
		if(coua && belong[rema[0]]) return 1;
		if(coub && belong[remb[0]]) return 1;
		return 0;
	}

	int ba=0,bb=0;
	for(int i=0;i<coua;++i)
		if(belong[rema[i]]) {
			if(ba==0) ba=belong[rema[i]];
			else if(ba!=belong[rema[i]]) return 0;
		}
	for(int i=0;i<coub;++i)
		if(belong[remb[i]]) {
			if(bb==0) bb=belong[remb[i]];
			else if(bb!=belong[remb[i]]) return 0;
		}

	if(ba && bb && ba==bb) return 0;

	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,X,Y,a,b;

	while(~scanf("%d %d %d %d",&N,&M,&X,&Y)) {
		init();
		while(M--) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		while(X--) {
			scanf("%d",&a);
			belong[a]=1;
		}
		while(Y--) {
			scanf("%d",&a);
			belong[a]=2;
		}

		bool ok=1;

		for(int i=1;i<=N;++i)
			if(vis[i]==0) {
				if(bfs(i)==0) {
					ok=0;
					break;
				}
			}

		puts(ok ? "YES" : "NO");
	}

	return 0;
}
