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
// Created Time  : 2016年02月20日 星期六 14时54分09秒
// File Name     : J.cpp

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

const int MaxN=405;

int map1[MaxN][MaxN];
int N,M;
int flag;

int ans[MaxN];

void bfs() {
	queue <int> que;
	int u;
	ans[1]=1;
	que.push(1);

	while(!que.empty()) {
		u=que.front();
		que.pop();

		for(int i=1;i<=N;++i)
			if(map1[u][i]==flag && ans[i]==0) {
				ans[i]=ans[u]+1;
				que.push(i);
			}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	scanf("%d %d",&N,&M);
	while(M--) {
		scanf("%d %d",&a,&b);
		map1[a][b]=map1[b][a]=1;
	}

	flag=1-map1[1][N];

	bfs();
	printf("%d\n",ans[N]-1);

	return 0;
}
