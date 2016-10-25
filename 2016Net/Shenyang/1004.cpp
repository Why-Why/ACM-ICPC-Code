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
// Created Time  : 2016年09月18日 星期日 12时03分36秒
// File Name     : 1004.cpp

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

long long f[1000],g[10000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T=100;
	f[0]=0;
	f[1]=1;
	for(int i=2;i<T;++i) f[i]=f[i-2]+2*f[i-1];

	for(int i=0;i<T;++i) {
		g[i]=0;
		for(int j=0;j<=i;++j) g[i]+=f[i]*f[i];
	}

	for(int i=0;i<T;++i) cout<<f[i]<<' ';
	cout<<endl;
	for(int i=0;i<T;++i) cout<<g[i]<<' ';
	cout<<endl;

	return 0;
}
