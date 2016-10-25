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
// Created Time  : 2016年10月03日 星期一 10时56分42秒
// File Name     : J.cpp

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

int r[MaxN*MaxN],d[MaxN*MaxN];
int headx[MaxN],heady[MaxN];
int N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Q,a,b,c,d;

	N=read();
	Q=read();

	for(int i=0;i<N;++i) headx[i]=i*N,heady[i]=i;
	a=0;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j) {
			r[a]=a+1;
			d[a]=a+N;
		}

	while(Q--) {
		a=read(); b=read(); c=read(); d=read();

		if(a==1) {
			if(b==0);
		}
	}

	return 0;
}
