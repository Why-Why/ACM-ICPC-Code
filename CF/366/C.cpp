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
// Created Time  : 2016年09月09日 星期五 01时24分07秒
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

const int MaxN=300005;

int N,Q;
int rem[MaxN],cou;
int maxn[MaxN],have[MaxN];
int maxnn[MaxN],haven[MaxN];
int ans;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int p=1;

	scanf("%d %d",&N,&Q);
	for(int i=1;i<=Q;++i) {
		scanf("%d %d",&a,&b);
		if(a==1) {
			rem[++cou]=b;
			maxn[b]=cou;
			++maxnn[b];
			++ans;
		}
		else if(a==2) {
			ans-=maxnn[b]-haven[b];
			have[b]=maxn[b];
			haven[b]=maxnn[b];
		}
		else {
			while(p<=b) {
				if(p>have[rem[p]]) have[rem[p]]=p,++haven[rem[p]],--ans;
				++p;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
