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
// Created Time  : 2016年05月02日 星期一 14时52分55秒
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

const int MaxN=805;

int N;
int map1[MaxN][MaxN];

int fa[MaxN];

int find(int x) {
	if(fa[x]==-1) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

inline bool judge(int M) {
	int cou=N;
	for(int i=1;i<=N;++i) fa[i]=-1;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(i!=j && map1[i][j]<M) {
				if(find(i)!=find(j)) {
					--cou;
					fa[find(i)]=find(j);
				}
			}

	if(cou>1) return 1;
	return 0;
}

int getans() {
	int L=0,R=1000000,M;

	while(R>L) {
		M=(L+R+1)>>1;
		if(judge(M)) L=M;
		else R=M-1;
	}
	return L;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&map1[i][j]);
		printf("%d\n",getans());
	}
	
	return 0;
}
