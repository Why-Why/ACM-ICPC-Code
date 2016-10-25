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
// Created Time  : 2016年09月10日 星期六 12时49分47秒
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

const int MaxN=6100;
const int INF=0x3f3f3f3f;
const long long TTT=10000000;

int N,M;
int s;

int ans[MaxN+5];
int que[MaxN*2000],first,last;

typedef pair<int,int> pii;
set <pii> rem;

inline bool hasE(int a,int b) {
	if(a>b) swap(a,b);
	return rem.count(pii(a,b));
}

void getans() {
	for(int i=1;i<=N;++i) ans[i]=INF;
	ans[s]=0;

	first=last=0;
	que[last++]=s;

	int t;

	while(last-first) {
		t=que[first++];
		for(int i=1;i<=N;++i)
			if(ans[i]>ans[t]+1 && i!=t && 0==hasE(t,i)) {
				ans[i]=min(ans[i],ans[t]+1);
				que[last++]=i;
			}
	}

	bool fff=1;
	for(int i=1;i<=N;++i)
		if(i!=s) {
			if(fff) fff=0;
			else printf(" ");

			if(ans[i]>=INF) ans[i]=-1;

			printf("%d",ans[i]);
		}
	puts("");
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		rem.clear();
		for(int i=1;i<=M;++i) {
			scanf("%d %d",&a,&b);

			if(a>b) swap(a,b);
			rem.insert(pii(a,b));
		}

		scanf("%d",&s);

		if(N>=6000 && N-1>M) {
			bool fff=1;

			for(int i=1;i<=N;++i)
				if(i!=s) {
					if(fff) fff=0;
					else printf(" ");

					if(hasE(i,s)) printf("2");
					else printf("1");
				}
			puts("");
		}
		else getans();
	}

	return 0;
}
