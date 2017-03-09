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
// Created Time  : 2017年02月03日 星期五 13时46分20秒
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

const int MaxN=100005;

struct Edge {
	int to,next;
};

Edge E[MaxN<<1];
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

int N;
int c[MaxN];
int rc[MaxN];

inline int he(int a,int b) {
	if(a==b) return a;
	return 0;
}

int dfs1(int u,int pre) {
	int rem=c[u],t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			t=dfs1(E[i].to,u);
			rem=he(rem,t);
		}

	rc[u]=rem;
	return rem;
}

int dfs2(int u,int pre,int pc) {
	int len,t,tt,r0=0;
	vector <int> rem,frem;

	rem.clear();
	frem.clear();

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			rem.push_back(rc[E[i].to]),frem.push_back(rc[E[i].to]);
			if(rc[E[i].to]==0) ++r0;
		}

	len=rem.size();
	for(int i=len-2;i>=0;--i) frem[i]=he(frem[i],frem[i+1]);
	for(int i=1;i<len;++i) rem[i]=he(rem[i],rem[i-1]);

	if(pc && r0==0) return u;
	pc=he(pc,c[u]);

	for(int i=head[u],j=0;i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			if(len==1) t=pc;
			else if(j==0) t=frem[j+1];
			else if(j==len-1) t=rem[j-1];
			else t=he(rem[j-1],frem[j+1]);

			if(tt=dfs2(E[i].to,u,he(pc,t))) return tt;

			++j;			// !!!
		}

	return 0;
}

inline bool judge(int tans) {
	for(int i=head[tans];i!=-1;i=E[i].next)
		if(dfs1(E[i].to,tans)==0) return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d",&N);
	init();
	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	for(int i=1;i<=N;++i) scanf("%d",c+i);

	dfs1(1,-1);
	int ans=dfs2(1,-1,c[1]);

	if(ans) {
		if(judge(ans)) {
			printf("YES\n%d\n",ans);
			return 0;
		}
	}
	puts("NO");

	return 0;
}
