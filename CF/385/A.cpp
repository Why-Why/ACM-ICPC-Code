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
// Created Time  : 2017年01月16日 星期一 21时52分52秒
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

const int MaxN=1003;

int fa[MaxN];
int num[MaxN];

int N,M,K;
bool vis[MaxN];
int use[MaxN];

int find(int x) {
	if(fa[x]==-1) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

inline void merge(int a,int b) {
	a=find(a);
	b=find(b);

	if(a!=b) {
		fa[a]=b;
		num[b]+=num[a];
	}
}

inline int cal(int x) {
	return x*(x-1)/2;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&M,&K);

	for(int i=1;i<=N;++i) fa[i]=-1,num[i]=1;

	int a,b;

	for(int i=1;i<=K;++i) {
		scanf("%d",&a);
		vis[a]=1;
	}

	for(int i=1;i<=M;++i) {
		scanf("%d %d",&a,&b);
		merge(a,b);
	}

	int ans=0,maxn=0,sum=0;

	for(int i=1;i<=N;++i) {
		if(use[find(i)]) continue;

		if(vis[i]) {
			use[find(i)]=1;
			maxn=max(maxn,num[find(i)]);
			ans+=cal(num[find(i)]);
		}
	}

	for(int i=1;i<=N;++i)
		if(use[find(i)]==0) {
			use[find(i)]=2;
			sum+=num[find(i)];
		}
	ans+=cal(sum);
	ans+=maxn*sum;

	printf("%d\n",ans-M);

	return 0;
}
