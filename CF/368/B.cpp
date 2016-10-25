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
// Created Time  : 2016年09月04日 星期日 17时28分20秒
// File Name     : B.cpp

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
	int u,v,w;
};

Edge E[100005];
int N,M,K;
bool vis[100005];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&M,&K);
	if(K==0 || K==N) {
		puts("-1");
		return 0;
	}

	for(int i=1;i<=M;++i) scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);

	int a;
	while(K--) {
		scanf("%d",&a);
		vis[a]=1;
	}

	int ans=0x3f3f3f3f;
	for(int i=1;i<=M;++i)
		if((vis[E[i].u]^vis[E[i].v])) ans=min(ans,E[i].w);

	if(ans==0x3f3f3f3f) ans=-1;
	printf("%d\n",ans);

	return 0;
}
