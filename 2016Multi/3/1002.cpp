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
// Created Time  : 2016年07月26日 星期二 12时34分40秒
// File Name     : 1002.cpp

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

int N;
int C[MaxN];

double getG(int x,int p) {
	if(p>1 && p<N) {
		if(x<=2) return 0;
		return (x-1.0)*(x-2.0)*C[p]/(N*(N-1.0)*(N-2.0));
	}
	else {
		if(x<=1) return 0;
		return (x-1.0)*C[p]/(N*(N-1.0));
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		double ans=0;
		for(int i=1;i<=N;++i) scanf("%d",C+i);
		if(N==1) {
			printf("%.6f\n",(double)C[1]);
			continue;
		}
		for(int x=1;x<=N;++x)
			for(int p=1;p<=N;++p)
				ans+=getG(x,p);
		printf("%.6f\n",ans);
	}

	return 0;
}
