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
// Created Time  : 2016年10月02日 星期日 15时40分58秒
// File Name     : H.cpp

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
	int to,next,c;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

inline void addEdge(int u,int v,int c) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].c=c;
	head[u]=Ecou++;
}

long long dfs(int u,int pre) {
	long long ret=0,t;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			t=dfs(E[i].to,u);

		}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	scanf("%d",&N);
	init();
	for(int i=1;i<N;++i) {
		scanf("%d %d %d",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	printf("%lld\n",dfs(1,-1));

	return 0;
}
