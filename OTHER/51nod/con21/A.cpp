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
// Created Time  : 2017年01月09日 星期一 19时16分54秒
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

const int MaxN=100005;

struct Edge {
	int to,next;
	int c;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N;

void init() {
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v,int c) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].c=c;
	head[u]=Ecou++;
}

long long ans;

int dfs(int u,int pre) {
	int ret=1,t;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			t=dfs(E[i].to,u);
			ans+=E[i].c*(long long)min(t,N-t);
			ret+=t;
		}

	return ret;
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

	dfs(1,-1);
	cout<<ans<<endl;

	return 0;
}
