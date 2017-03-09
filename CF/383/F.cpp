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
// Created Time  : 2016年12月09日 星期五 11时39分21秒
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

const int MaxN=300005;

struct Edge {
	int to,next,v;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N;

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

struct State {
}num[MaxN];

int dfs(int u,int pre) {
	int ret=1,t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			t=dfs(E[i].to,u);

			if(t>ret) {
			}
			else {
			}
		}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int p;
	char s[10];

	scanf("%d",&N);
	init();

	for(int i=1;i<=N;++i) {
		PPP[i]=new int[1];
		len[i]=1;
		PPP[i][0]=0;
		yan[i]=0;
	}

	for(int i=2;i<=N;++i) {
		scanf("%d %s",&p,s);
		addEdge(i,p,s[0]-'a');
		addEdge(p,i,s[0]-'a');
	}

	dfs(1,-1);

	retur 0;
}
