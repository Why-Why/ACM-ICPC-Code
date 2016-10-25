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
// Created Time  : 2016年08月18日 星期四 16时21分17秒
// File Name     : 1006_1.cpp

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

struct QUE {
	int x,y1,y2;

	bool operator < (const QUE & b) const {
		return x<b.x;
	}
};

QUE que[MaxN];
int qcou;

struct State {
	int x,h;
	bool t;

	bool operator < (const State & b) const {
		return x<b.x;
	}
};

int N;
State sta[MaxN<<1];
int scou;

int hnum[MaxN*3];
int hcou;

int C[MaxN*3];

inline int hash1(int x) {
	return lower_bound(hnum+1,hnum+hcou+1,x)-hnum;
}

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int p,int d) {
	p=hash1(p);
	for(;p<=hcou;p+=lowbit(p)) C[p]+=d;
}

inline long long getans(int p) {
	long long ret=0;
	for(;p;p-=lowbit(p)) ret+=C[p];
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	int a,b,c,d;

	while(T--) {
		scanf("%d",&N);
		qcou=scou=0;
		memset(C,0,sizeof(C));
		hcou=0;

		for(int i=1;i<=N;++i) {
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(a==c) {
				if(b>d) swap(b,d);

				que[++qcou].x=a;
				que[qcou].y1=b;
				que[qcou].y2=d;

				hnum[++hcou]=b;
				hnum[++hcou]=d;
			}
			else {
				if(a>c) swap(a,c);

				sta[++scou].x=a;
				sta[scou].h=b;
				sta[scou].t=1;

				sta[++scou].x=c+1;
				sta[scou].h=b;
				sta[scou].t=0;

				hnum[++hcou]=b;
			}
		}

		sort(hnum+1,hnum+hcou+1);
		hcou=unique(hnum+1,hnum+hcou+1)-hnum-1;

		sort(sta+1,sta+scou+1);
		sort(que+1,que+qcou+1);

		long long ans=0,p=1;
		for(int i=1;i<=qcou;++i) {
			while(p<=scou && sta[p].x<=que[i].x) {
				if(sta[p].t) add(sta[p].h,1);
				else add(sta[p].h,-1);
				++p;
			}
			ans+=getans(hash1(que[i].y2))-getans(hash1(que[i].y1)-1);
		}
		printf("%I64d\n",ans);
	}

	return 0;
}
