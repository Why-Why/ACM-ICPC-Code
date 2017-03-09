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
// Created Time  : 2016年11月18日 星期五 21时49分24秒
// File Name     : C.cpp

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

bool rem[40004];
map <long long,bool> E;
map <long long,bool> ::iterator iter;
typedef pair<long long,bool> pii;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,M,a,b,c,d;

	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		memset(rem,0,sizeof(rem));

		E.clear();

		for(int i=1;i<N;++i) {
			scanf("%d %d %d",&a,&b,&c);
			if(c) rem[a]^=1,rem[b]^=1;
			if(a>b) swap(a,b);
			E.insert(pii(a*100000LL+b,c));
		}

		while(M--) {
			scanf("%d %d",&a,&b);

			if(a==0) {
				if(rem[b]) puts("Girls win!");
				else puts("Boys win!");
			}
			else {
				scanf("%d %d",&c,&d);
				if(b>c) swap(b,c);
				iter=E.find(b*100000LL+c);
				if(iter->second!=d) {
					iter->second^=1;
					rem[b]^=1;
					rem[c]^=1;
				}
			}
		}
	}

	return 0;
}
