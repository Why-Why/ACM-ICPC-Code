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
// Created Time  : 2016年09月02日 星期五 16时42分10秒
// File Name     : 1009.cpp

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

const int MaxN=5005;
const int MaxM=100005;

struct Edge {
	int to,next;
};

Edge E[MaxM],Ep[MaxN];
int head[MaxN],Ecou;
int headp[MaxN],Epcou;
int du[MaxN];

int SG[MaxN];
int que[MaxN],first,last;

int vis[MaxN],flag;
int rr[MaxN];

int N,M,K;

void init() {
	Ecou=Epcou=0;
	memset(headp,-1,sizeof(headp));
	memset(head,-1,sizeof(head));
	memset(du,0,sizeof(du));
}

inline void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

inline void addEdgep(int u,int v) {
	Ep[Epcou].to=v;
	Ep[Epcou].next=headp[u];
	headp[u]=Epcou++;
}

void getSG(int u) {
	++flag;
	int num=0;

	for(int i=head[u];i!=-1;i=E[i].next) {
		if(vis[SG[E[i].to]]==flag) continue;
		vis[SG[E[i].to]]=flag;
		if(vis[SG[E[i].to]+1]!=flag) rr[SG[E[i].to]]=SG[E[i].to]+1;
		else rr[SG[E[i].to]]=rr[SG[E[i].to]+1];

		if(num==SG[E[i].to]) num=rr[SG[E[i].to]];
	}

	SG[u]=num;
}

int rem[305];

long long getans(int s,int sum) {
	long long ret=0;
	for(int i=s;i<=K;++i)
		for(int j=head[rem[i]];j!=-1;j=E[j].next)
			if((sum-SG[rem[i]]+SG[E[j].to])%3) ++ret;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d %d",&N,&M,&K)) {
		init();
		while(M--) {
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdgep(b,a);
			++du[a];
		}

		first=last=0;
		for(int i=1;i<=N;++i)
			if(du[i]==0)
				que[last++]=i;

		while(last-first) {
			a=que[first++];
			getSG(a);
			for(int i=headp[a];i!=-1;i=Ep[i].next) {
				--du[Ep[i].to];
				if(du[Ep[i].to]==0) que[last++]=Ep[i].to;
			}
		}

		int sum=0;
		for(int i=1;i<=K;++i) scanf("%d",rem+i),sum+=SG[rem[i]];

		long long ans=0;
		for(int i=1;i<=K;++i) {
			for(int j=head[rem[i]];j!=-1;j=E[j].next) {
				if((SG[E[j].to]-SG[rem[i]]+sum)%3) ++ans;
				ans+=getans(i+1,sum-SG[rem[i]]+SG[E[j].to]);
			}
		}
		printf("%I64d\n",ans);
	}

	return 0;
}
