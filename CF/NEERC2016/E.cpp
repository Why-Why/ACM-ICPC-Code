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
// Created Time  : 2016年10月27日 星期四 23时05分44秒
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

struct State {
	int a,d;
	int id;

	bool operator < (const State & b) const {
		if(d<0 && b.d>=0) return 0;
		if(d>=0 && b.d<0) return 1;

		bool t;

		if(a==b.a) t=id>b.id;
		else t=a<b.a;

		if(d>=0) return t;
		else return !t;
	}
};

State num[103];
int N;

int rem[103];
int id[103];

inline int sum(int p) {
	int ret=0;

	for(int i=1;i<=N;++i)
		if(i!=p) {
			if(rem[i]>rem[p]) ++ret;
			if(rem[i]==rem[p] && id[i]<id[p]) ++ret;
		}

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d %d",&num[i].a,&num[i].d),num[i].id=i;
	sort(num+1,num+N+1);

	for(int i=1;i<=N;++i) rem[i]=num[i].a,id[i]=num[i].id;

	int ans=0,t;

	for(int i=1;i<=N;++i) {
		t=sum(i);
		rem[i]+=num[i].d;
		ans+=abs(sum(i)-t);
	}

	printf("%d\n",ans);

	return 0;
}
