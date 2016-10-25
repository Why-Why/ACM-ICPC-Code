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
// Created Time  : 2016年08月09日 星期二 14时12分21秒
// File Name     : 1005.cpp

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

const int MaxN=1005;

int N,a[MaxN],vis[MaxN];
int u[MaxN*MaxN],v[MaxN*MaxN];
int cou;

inline void update(int p) {
	for(int i=1;i<=N;++i)
		if(a[i]) {
			--a[i];
			++cou;
			u[cou]=i;
			v[cou]=p;
		}
}

inline int find() {
	for(int i=1;i<=N;++i)
		if(a[i]==0 && vis[i]==0) {
			vis[i]=1;
			return i;
		}
	return -1;
}

bool getans() {
	cou=0;
	int t;
	for(int i=1;i<=N;++i) {
		t=find();
		if(t==-1) return 0;
		update(t);
	}

	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1,t;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",a+i),vis[i]=0;

		printf("Case #%d: ",cas++);
		if(getans()) {
			puts("Yes");
			printf("%d\n",cou);
			for(int i=1;i<=cou;++i)
				printf("%d %d\n",u[i],v[i]);
		}
		else puts("No");
	}

	return 0;
}
