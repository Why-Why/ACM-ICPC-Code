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
// Created Time  : 2017年02月23日 星期四 13时21分55秒
// File Name     : G.cpp

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

struct Edge {
	int to,next,w;
};

Edge E[8005];
int head[8005],Ecou;
int N;

map <long long,int> sta;

void init() {
	N=Ecou=0;
	sta.clear();
	memset(head,-1,sizeof(head));
}

inline void addEdge(int u,int v,int w) {
	E[Ecou].to=v;
	E[Ecou].w=w;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

inline int getP(long long x,long long y) {
	long long t=(x+10000)*100000+y+10000;
	if(sta.count(t)) return sta[t];
	++N;
	sta[t]=N;
	return N;
}

const long long INF=100000000000000000LL;

bool vis[8005];
long long lowcost[8005];

queue <int> que;

int flag;

void SPFA(int start) {
	while(!que.empty()) que.pop();

	int u,v,c;

	for(int i=1;i<=N;++i) lowcost[i]=INF,vis[i]=0;
	vis[start]=1;
	lowcost[start]=0;
	que.push(start);

	while(!que.empty()) {
		u=que.front();
		que.pop();

		vis[u]=0;

		for(int i=head[u];i!=-1;i=E[i].next) {
			if(i==flag || (i^1)==flag) continue;

			v=E[i].to;
			c=E[i].w;

			if(lowcost[v]>lowcost[u]+c) {
				lowcost[v]=lowcost[u]+c;

				if(!vis[v]) {
					vis[v]=1;
					que.push(v);
				}
			}
		}
	}
}

long long ans;

inline long long getans(int bcou) {
	if(E[bcou].w>=ans) return INF;
	flag=bcou;
	SPFA(E[bcou].to);
	return lowcost[E[bcou^1].to]+E[bcou].w;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int M;
	int x1,x2,y1,y2,w,a,b;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&M);
		init();
		for(int i=1;i<=M;++i) {
			scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&w);
			a=getP(x1,y1);
			b=getP(x2,y2);
			addEdge(a,b,w);
			addEdge(b,a,w);
		}

		ans=INF;
		for(int i=0;i<Ecou;i+=2) ans=min(ans,getans(i));
		if(ans==INF) ans=0;
		printf("Case #%d: %I64d\n",cas++,ans);
	}

	return 0;
}
