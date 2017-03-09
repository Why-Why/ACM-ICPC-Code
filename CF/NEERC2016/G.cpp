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
// Created Time  : 2016年10月25日 星期二 21时57分47秒
// File Name     : G.cpp

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

const int MaxN=203;

int L[MaxN],R[MaxN];
int N;

inline bool judge(int l,int r,int p) {
	for(int i=1;i<p;++i)
		if(L[i]>r || R[i]<l);
		else return 0;
	return 1;
}

inline int find(int d,int p) {
	if(judge(1,d,p)) return 1;

	int x=0x3f3f3f3f;

	for(int i=1;i<p;++i)
		if(judge(R[i]+1,R[i]+d,p))
			x=min(x,R[i]+1);

	return x;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int s,d;

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d %d",&s,&d);

		if(judge(s,s+d-1,i)) L[i]=s,R[i]=s+d-1;
		else L[i]=find(d,i),R[i]=L[i]+d-1;
	}

	for(int i=1;i<=N;++i) printf("%d %d\n",L[i],R[i]);

	return 0;
}
