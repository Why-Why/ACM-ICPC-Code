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
// Created Time  : 2015年12月10日 星期四 00时43分25秒
// File Name     : D.cpp

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

/*

4 3
1 0
1 1
1 1

3 3
1 0
1 1
1 1

*/

const int MaxN=100005;

struct Edge {
	int u,v,id,w,b;
}E[MaxN];

int rem[MaxN];
int N,M;

bool cmp1(const Edge &x,const Edge &y) {
	if(x.w==y.w) return x.b>y.b;
	return x.w<y.w;
}

bool cmp2(const Edge &x,const Edge &y) {
	return x.id<y.id;
}

bool getans() {
	int tot=1;
	int tp=1;

	for(int i=1;i<=M;++i) {
		if(E[i].b) {
			E[i].u=tot;
			E[i].v=++tot;
		}
		else {
			while(tp<=tot && rem[tp]>=tp-2) ++tp;
			if(tp>tot) return 0;
			++rem[tp];
			E[i].u=tp;
			E[i].v=rem[tp];
		}
	}
	if(tot<N) return 0;
	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;++i) scanf("%d %d",&E[i].w,&E[i].b),E[i].id=i;
	sort(E+1,E+M+1,cmp1);
	if(getans()) {
		sort(E+1,E+M+1,cmp2);
		for(int i=1;i<=M;++i) printf("%d %d\n",E[i].u,E[i].v);
	}
	else puts("-1");
	
	return 0;
}
